/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_check_starting_position.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:04:58 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:05:00 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	map_maker(t_cub *cub, int map_start)
{
	int	j;
	int	x;
	int	k;

	j = 0;
	while (j < cub->lines_num)
	{
		x = map_start;
		while (cub->buff[map_start] != '\n' && cub->buff[map_start] != '\0')
			map_start++;
		k = 0;
		while (x < map_start)
			if (cub->buff[x] == '1' || cub->buff[x] == '0'
				|| cub->buff[x] == 'S' || cub->buff[x] == 'W'
				|| cub->buff[x] == 'N'
				|| cub->buff[x] == 'E' || cub->buff[x] == ' ')
				cub->map[j][k++] = cub->buff[x++] - 48;
		else
			errors(0, cub);
		while (k < cub->line_length)
			cub->map[j][k++] = -16;
		j++;
		map_start++;
	}
}

void	get_starting_position(t_cub *cub)
{
	int	i;
	int	j;
	int	only_one_player;

	i = -1;
	only_one_player = 0;
	while (++i < cub->lines_num - 1)
	{
		j = 0;
		while (j < cub->line_length)
		{
			if (cub->map[i][j] == 30 || cub->map[i][j] == 35
				|| cub->map[i][j] == 39 || cub->map[i][j] == 21)
			{
				if (only_one_player != 0)
					errors(0, cub);
				cub->x = j;
				cub->y = i;
				cub->view = cub->map[i][j] + 48;
				only_one_player = 1;
				cub->map[i][j] = 0;
			}
			j++;
		}
	}
}

void	check_starting_position(t_cub *cub)
{
	if (cub->x == 0 || cub->y == 0 || cub->x == cub->line_length - 1
		|| cub->y == cub->lines_num - 1)
		errors(0, cub);
	if (cub->map[cub->y][cub->x - 1] == -16
		|| cub->map[cub->y][cub->x + 1] == -16
		|| cub->map[cub->y - 1][cub->x] == -16
		|| cub->map[cub->y + 1][cub->x] == -16
		|| cub->map[cub->y - 1][cub->x - 1] == -16
		|| cub->map[cub->y - 1][cub->x + 1] == -16
		|| cub->map[cub->y + 1][cub->x + 1] == -16
		|| cub->map[cub->y + 1][cub->x - 1] == -16)
		errors(0, cub);
}
