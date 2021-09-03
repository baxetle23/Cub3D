#include "../cub.h"

void	turn_left(t_all *g, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = g->rc_var.dirX;
	oldPlaneX = g->rc_var.planeX;
	g->rc_var.dirX = g->rc_var.dirX * cos(-rotSpeed)
		- g->rc_var.dirY * sin(-rotSpeed);
	g->rc_var.dirY = oldDirX * sin(-rotSpeed) + g->rc_var.dirY * cos(-rotSpeed);
	g->rc_var.planeX = g->rc_var.planeX * cos(-rotSpeed)
		- g->rc_var.planeY * sin(-rotSpeed);
	g->rc_var.planeY = oldPlaneX * sin(-rotSpeed)
		+ g->rc_var.planeY * cos(-rotSpeed);
}

void	turn_right(t_all *g, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = g->rc_var.dirX;
	oldPlaneX = g->rc_var.planeX;
	g->rc_var.dirX = g->rc_var.dirX * cos(rotSpeed)
		- g->rc_var.dirY * sin(rotSpeed);
	g->rc_var.dirY = oldDirX * sin(rotSpeed)
		+ g->rc_var.dirY * cos(rotSpeed);
	g->rc_var.planeX = g->rc_var.planeX * cos(rotSpeed)
		- g->rc_var.planeY * sin(rotSpeed);
	g->rc_var.planeY = oldPlaneX * sin(rotSpeed)
		+ g->rc_var.planeY * cos(rotSpeed);
}

void	moves(t_all *general, int key)
{
	double	moveSpeed;
	double	rotSpeed;

	rotSpeed = 0.05;
	moveSpeed = 0.4;
	if (key == 126 || key == 13)
		go_up(general, moveSpeed);
	if (key == 125 || key == 1)
		go_down(general, moveSpeed);
	if (key == 124)
		turn_left(general, rotSpeed);
	if (key == 123)
		turn_right(general, rotSpeed);
	if (key == 0)
		go_left(general, moveSpeed);
	if (key == 2)
		go_right(general, moveSpeed);
}

int	close_win(t_all *general)
{
	(void)general;
	ft_putendl_fd("Bye", 1);
	ft_free(general->cub);
	exit(0);
}

int	key_hook(int key, t_all *g)
{
	if (key == 53)
		close_win(g);
	mlx_destroy_image(g->window.mlx, g->img.img);
	g->img.img = mlx_new_image(g->window.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	g->img.addr = mlx_get_data_addr(
			g->img.img,
			&g->img.bits_per_pixel,
			&g->img.line_length,
			&g->img.endian);
	render_map(g);
	moves(g, key);
	return (0);
}
