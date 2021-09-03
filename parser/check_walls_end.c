/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:04:11 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:04:12 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	fill_map_around_pers(t_cub *cub, int **array, int x, int y)
{
	if (array[y][x] == -16)
		;
	else if (array[y][x] >= 0 && check_x_y(cub, x, y) == 1)
		array[y][x] = -3;
	else if (array[y][x] >= 0 && (y == 0 || y == cub->lines_num - 1))
	{
		array[y][x] = -3;
		fill_map_around_pers(cub, array, x - 1, y);
		fill_map_around_pers(cub, array, x + 1, y);
	}
	else if (array[y][x] >= 0 && (x == 0 || x == cub->line_length - 1))
	{
		array[y][x] = -3;
		fill_map_around_pers(cub, array, x, y - 1);
		fill_map_around_pers(cub, array, x, y + 1);
	}
	else if (array[y][x] >= 0)
	{
		array[y][x] = -3;
		fill_map_around_pers(cub, array, x - 1, y);
		fill_map_around_pers(cub, array, x + 1, y);
		fill_map_around_pers(cub, array, x, y - 1);
		fill_map_around_pers(cub, array, x, y + 1);
	}
}

int	check_x_y(t_cub *cub, int x, int y)
{
	if ((y == cub->lines_num - 1 && x == cub->line_length - 1)
		|| (y == 0 && x == cub->line_length - 1)
		|| (y == cub->lines_num - 1 && x == 0)
		|| (x == 0 && y == 0))
		return (1);
	return (0);
}

void	check_whats_left_on_map(t_cub *cub, int **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->lines_num)
	{
		j = 0;
		while (j < cub->line_length)
		{
			if (array[i][j] == 1 || array[i][j] == 0)
				fill_whats_left(cub, array, j, i);
			j++;
		}
		i++;
	}
}

void	fill_whats_left(t_cub *cub, int **array, int x, int y)
{
	if (array[y][x] == -3)
		;
	else if (x == 0 || y == 0 || y == cub->lines_num - 1
		|| x == cub->line_length - 1)
	{
		ft_free_temp_array(cub, array);
		errors(0, cub);
	}
	else
	{
		array[y][x] = -3;
		fill_whats_left(cub, array, x - 1, y);
		fill_whats_left(cub, array, x + 1, y);
		fill_whats_left(cub, array, x, y - 1);
		fill_whats_left(cub, array, x, y + 1);
	}
}
