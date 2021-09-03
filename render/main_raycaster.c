#include "../cub.h"

void	raycaster(t_all *general)
{
	initzilization(general);
	get_image_texture(general);
	render_map(general);
	mlx_hook(general->window.win, 2, 1L << 0, key_hook, general);
	mlx_hook(general->window.win, 17, 1L << 0, close_win, general);
	mlx_loop(general->window.mlx);
}

void	main_alex(t_cub *cub)
{
	t_all	general;

	general.cub = cub;
	raycaster(&general);
}
