#include "../cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	print_sky(t_all *general, int x, int i)
{
	if (i < general->rc_var.drawStart)
	{
		while (i < general->rc_var.drawStart)
		{
			my_mlx_pixel_put(&general->img,
				x,
				i,
				general->cub->c_color[0] << 16
				| general->cub->c_color[1] << 8
				| general->cub->c_color[2]);
			i++;
		}
	}
	return (i);
}

int	print_texture(t_all *g, int x, int i)
{
	while (i < g->rc_var.drawEnd)
	{
		g->rc_var.texY = (int)g->rc_var.texPos & (64 - 1);
		g->rc_var.texPos += g->rc_var.step;
		if (g->rc_var.side == 0)
		{
			if (g->rc_var.stepX > 0)
				g->rc_var.color = g->color.south
				[g->rc_var.texX][g->rc_var.texY];
			else
				g->rc_var.color = g->color.north
				[g->rc_var.texX][g->rc_var.texY];
		}
		else
		{
			if (g->rc_var.stepY < 0)
				g->rc_var.color = g->color.west[g->rc_var.texX][g->rc_var.texY];
			else
				g->rc_var.color = g->color.east[g->rc_var.texX][g->rc_var.texY];
			g->rc_var.color = (g->rc_var.color >> 1) & 8355711;
		}
		my_mlx_pixel_put(&g->img, x, i, g->rc_var.color);
		i++;
	}
	return (i);
}

void	print_floor(t_all *general, int x, int i)
{
	while (i < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(&general->img,
			x,
			i,
			(general->cub->f_color[0] << 16
				| general->cub->f_color[1] << 8
				| general->cub->f_color[2]));
		i++;
	}
}

void	print_to_image(t_all *general, int x)
{
	print_floor(general, x,
		print_texture(general, x,
			print_sky(general, x, 0)));
}
