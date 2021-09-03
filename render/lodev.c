#include "../cub.h"

void	step_1(t_all *g, int x)
{
	g->rc_var.cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	g->rc_var.rayDirX = g->rc_var.dirX + g->rc_var.planeX * g->rc_var.cameraX;
	g->rc_var.rayDirY = g->rc_var.dirY + g->rc_var.planeY * g->rc_var.cameraX;
	g->rc_var.mapX = (int)g->rc_var.posX;
	g->rc_var.mapY = (int)g->rc_var.posY;
	g->rc_var.deltaDistX = fabs(1 / g->rc_var.rayDirX);
	g->rc_var.deltaDistY = fabs(1 / g->rc_var.rayDirY);
	g->rc_var.hit = 0;
}

void	step_2(t_all *g)
{
	if (g->rc_var.rayDirX < 0)
	{
		g->rc_var.stepX = -1;
		g->rc_var.sideDistX = (g->rc_var.posX - g->rc_var.mapX)
			* g->rc_var.deltaDistX;
	}
	else
	{
		g->rc_var.stepX = 1;
		g->rc_var.sideDistX = (g->rc_var.mapX + 1 - g->rc_var.posX)
			* g->rc_var.deltaDistX;
	}
	if (g->rc_var.rayDirY < 0)
	{
		g->rc_var.stepY = -1;
		g->rc_var.sideDistY = (g->rc_var.posY - g->rc_var.mapY)
			* g->rc_var.deltaDistY;
	}
	else
	{
		g->rc_var.stepY = 1;
		g->rc_var.sideDistY = (g->rc_var.mapY + 1 - g->rc_var.posY)
			* g->rc_var.deltaDistY;
	}
}

void	step_3(t_all *g)
{
	while (g->rc_var.hit == 0)
	{
		if (g->rc_var.sideDistX < g->rc_var.sideDistY)
		{
			g->rc_var.sideDistX += g->rc_var.deltaDistX;
			g->rc_var.mapX += g->rc_var.stepX;
			g->rc_var.side = 0;
		}
		else
		{
			g->rc_var.sideDistY += g->rc_var.deltaDistY;
			g->rc_var.mapY += g->rc_var.stepY;
			g->rc_var.side = 1;
		}
		if (g->cub->map[g->rc_var.mapX][g->rc_var.mapY] > 0)
			g->rc_var.hit = 1;
	}
}

void	step_4(t_all *g)
{
	if (g->rc_var.side == 0)
		g->rc_var.perpWallDist = (g->rc_var.mapX - g->rc_var.posX
				+ (1 - g->rc_var.stepX) / 2) / g->rc_var.rayDirX;
	else
		g->rc_var.perpWallDist = (g->rc_var.mapY - g->rc_var.posY
				+ (1 - g->rc_var.stepY) / 2) / g->rc_var.rayDirY;
	g->rc_var.lineHeight = (int)(SCREEN_HEIGHT / g->rc_var.perpWallDist);
	g->rc_var.drawStart = -g->rc_var.lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (g->rc_var.drawStart < 0)
		g->rc_var.drawStart = 0;
	g->rc_var.drawEnd = g->rc_var.lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (g->rc_var.drawEnd >= SCREEN_HEIGHT)
		g->rc_var.drawEnd = SCREEN_HEIGHT - 1;
	g->rc_var.texNum = g->cub->map[g->rc_var.mapX][g->rc_var.mapY] - 1;
	if (g->rc_var.side == 0)
		g->rc_var.wallX = g->rc_var.posY
			+ g->rc_var.perpWallDist * g->rc_var.rayDirY;
	else
		g->rc_var.wallX = g->rc_var.posX
			+ g->rc_var.perpWallDist * g->rc_var.rayDirX;
	g->rc_var.wallX -= floor((g->rc_var.wallX));
}

void	step_5(t_all *g)
{
	g->rc_var.texX = (int)(g->rc_var.wallX * (double)(TEX_WIDTH));
	if (g->rc_var.side == 0 && g->rc_var.rayDirX > 0)
		g->rc_var.texX = TEX_WIDTH - g->rc_var.texX - 1;
	if (g->rc_var.side == 1 && g->rc_var.rayDirY < 0)
		g->rc_var.texX = TEX_WIDTH - g->rc_var.texX - 1;
	g->rc_var.step = 1.0 * TEX_HEIGHT / g->rc_var.lineHeight;
	g->rc_var.texPos = (g->rc_var.drawStart - SCREEN_HEIGHT / 2
			+ g->rc_var.lineHeight / 2) * g->rc_var.step;
	g->rc_var.texY = 0;
}
