#include "../cub.h"

void	start_manewr(t_all *general)
{
	general->start = 1;
	turn_left(general, 0.1);
	go_left(general, 0.01);
	go_left(general, 0.01);
	go_up(general, 0.01);
	go_right(general, 0.01);
	go_right(general, 0.01);
	go_down(general, 0.01);
	turn_right(general, 0.1);
}

void	steps(t_all *general, int x)
{
	step_1(general, x);
	step_2(general);
	step_3(general);
	step_4(general);
	step_5(general);
	if (!general->start)
		start_manewr(general);
}

void	render_map(t_all *general)
{
	int	x;

	x = 0;
	init_raycast_variable(general);
	while (x < SCREEN_WIDTH)
	{
		steps(general, x);
		print_to_image(general, x);
		x++;
	}
	mlx_put_image_to_window(general->window.mlx,
		general->window.win,
		general->img.img,
		0, 0);
}
