#include "../cub.h"

void	template_init_v2(t_all *general)
{
	if (general->cub->view == 'S')
	{
		general->rc_var.dirX = 0.998295;
		general->rc_var.dirY = -0.058374;
		general->rc_var.planeX = -0.038527;
		general->rc_var.planeY = -0.658875;
	}
	else
	{
		general->rc_var.dirX = 0.012389;
		general->rc_var.dirY = -0.999923;
		general->rc_var.planeX = -0.659949;
		general->rc_var.planeY = -0.008177;
	}
}

void	template_init(t_all *general)
{
	general->rc_var.posX = general->cub->y;
	general->rc_var.posY = general->cub->x;
	if (general->cub->view == 'N')
	{
		general->rc_var.dirX = -1.0;
		general->rc_var.dirY = 0;
		general->rc_var.planeX = 0;
		general->rc_var.planeY = 0.66;
	}
	else if (general->cub->view == 'E')
	{
		general->rc_var.dirX = 0.029200;
		general->rc_var.dirY = 0.999574;
		general->rc_var.planeX = 0.659719;
		general->rc_var.planeY = -0.019272;
	}
	else
		template_init_v2(general);
}

void	init_raycast_variable(t_all *general)
{
	general->rc_var.cameraX = 0;
	general->rc_var.rayDirX = 0;
	general->rc_var.rayDirY = 0;
	general->rc_var.mapX = 0;
	general->rc_var.mapY = 0;
	general->rc_var.sideDistX = 0;
	general->rc_var.sideDistY = 0;
	general->rc_var.deltaDistX = 0;
	general->rc_var.deltaDistY = 0;
	general->rc_var.perpWallDist = 0;
	general->rc_var.stepX = 0;
	general->rc_var.stepY = 0;
	general->rc_var.hit = 0;
	general->rc_var.side = 0;
	general->rc_var.lineHeight = 0;
	general->rc_var.drawEnd = 0;
	general->rc_var.drawStart = 0;
	general->rc_var.texNum = 0;
	general->rc_var.wallX = 0;
	general->rc_var.texX = 0;
	general->rc_var.texY = 0;
	general->rc_var.color = 0;
	general->start = 0;
}

void	initzilization(t_all *general)
{
	general->window.mlx = mlx_init();
	general->window.win = mlx_new_window(general->window.mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"Cub3D");
	general->img.img = mlx_new_image(general->window.mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);
	general->img.addr = mlx_get_data_addr(general->img.img,
			&general->img.bits_per_pixel,
			&general->img.line_length,
			&general->img.endian);
	init_raycast_variable(general);
	template_init(general);
}
