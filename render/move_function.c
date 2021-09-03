#include "../cub.h"

void	go_up(t_all *g, double moveSpeed)
{
	if (g->cub->map[(int)(g->rc_var.posX
			+ g->rc_var.dirX * moveSpeed)][(int)(g->rc_var.posY)] == 0)
		g->rc_var.posX += g->rc_var.dirX * moveSpeed;
	if (g->cub->map[(int)(g->rc_var.posX)][(int)(g->rc_var.posY
		+ g->rc_var.dirY * moveSpeed)] == 0)
		g->rc_var.posY += g->rc_var.dirY * moveSpeed;
}

void	go_down(t_all *g, double moveSpeed)
{
	if (g->cub->map[(int)(g->rc_var.posX
			- g->rc_var.dirX * moveSpeed)][(int)(g->rc_var.posY)] == 0)
		g->rc_var.posX -= g->rc_var.dirX * moveSpeed;
	if (g->cub->map[(int)(g->rc_var.posX)][(int)(g->rc_var.posY
			- g->rc_var.dirY * moveSpeed)] == 0)
		g->rc_var.posY -= g->rc_var.dirY * moveSpeed;
}

void	go_left(t_all *g, double moveSpeed)
{
	if (g->cub->map[(int)(g->rc_var.posX
			- g->rc_var.dirY * moveSpeed)][(int)(g->rc_var.posY)] == 0)
		g->rc_var.posX -= g->rc_var.dirY * moveSpeed;
	if (g->cub->map[(int)(g->rc_var.posX)][(int)(g->rc_var.posY
			+ g->rc_var.dirX * moveSpeed)] == 0)
		g->rc_var.posY += g->rc_var.dirX * moveSpeed;
}

void	go_right(t_all *g, double moveSpeed)
{
	if (g->cub->map[(int)(g->rc_var.posX
			+ g->rc_var.dirY * moveSpeed)][(int)(g->rc_var.posY)] == 0)
		g->rc_var.posX += g->rc_var.dirY * moveSpeed;
	if (g->cub->map[(int)(g->rc_var.posX)][(int)(g->rc_var.posY
			- g->rc_var.dirX * moveSpeed)] == 0)
		g->rc_var.posY -= g->rc_var.dirX * moveSpeed;
}
