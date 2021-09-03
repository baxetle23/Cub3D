#include "../cub.h"

unsigned int	color_pix_texture(t_img *img, int x, int y)
{
	char			*addr;
	unsigned int	color;

	addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)addr;
	return (color);
}

void	get_color_from_image(t_all *general, int ***color, char *path)
{
	int		a;
	int		b;
	int		x;
	int		y;
	t_img	img;

	x = -1;
	img.img = mlx_xpm_file_to_image(general->window.mlx, path, &a, &b);
	if (!img.img)
	{
		printf("Invalid pixel in %s\n", path);
		close_win(general);
	}
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	(*color) = (int **)malloc(sizeof(int *) * a);
	while (++x < TEX_WIDTH)
	{
		y = -1;
		(*color)[x] = (int *)malloc(sizeof(int) * b);
		while (++y < TEX_HEIGHT)
			(*color)[x][y] = color_pix_texture(&img, x, y);
	}
}

void	get_image_texture(t_all *general)
{
	get_color_from_image(general, &general->color.east, general->cub->ea);
	get_color_from_image(general, &general->color.west, general->cub->we);
	get_color_from_image(general, &general->color.north, general->cub->no);
	get_color_from_image(general, &general->color.south, general->cub->so);
}
