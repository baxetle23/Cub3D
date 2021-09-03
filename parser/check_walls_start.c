/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:03:28 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:03:46 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_walls(t_cub *cub)
{
	int	**array;

	array = (int **)malloc(sizeof(int *) * cub->lines_num);
	if (array == NULL)
		errors(0, cub);
	create_temp_array(cub, array);
	copy_map_to_array(cub, array);
	check_zero_neighbors(cub, array);
	fill_map_around_pers(cub, array, cub->x, cub->y);
	check_whats_left_on_map(cub, array);
	ft_free_temp_array(cub, array);
}

void	create_temp_array(t_cub *cub, int **array)
{
	int	i;

	i = 0;
	while (i < cub->lines_num)
	{
		array[i] = NULL;
		i++;
	}
	i = 0;
	while (i < cub->lines_num)
	{
		array[i] = (int *)malloc(sizeof(int) * cub->line_length);
		if (array[i] == NULL)
		{
			ft_free_temp_array(cub, array);
			errors(0, cub);
		}
		i++;
	}
}

void	ft_free_temp_array(t_cub *cub, int **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < cub->lines_num)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
		free(array);
	}
}

void	copy_map_to_array(t_cub *cub, int **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->lines_num)
	{
		j = 0;
		while (j < cub->line_length)
		{
			array[i][j] = cub->map[i][j];
			j++;
		}
		i++;
	}
}

void	check_zero_neighbors(t_cub *cub, int **array)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->lines_num)
	{
		j = 0;
		while (j < cub->line_length)
		{
			if (array[i][j] == 0)
			{
				if (i == 0 || j == 0 || j == cub->line_length - 1
					|| i == cub->lines_num - 1 || array[i][j - 1] == -16
					|| array[i][j + 1] == -16 || array[i - 1][j] == -16
					|| array[i + 1][j] == -16 || array[i - 1][j - 1] == -16
					|| array[i - 1][j + 1] == -16 || array[i + 1][j + 1] == -16
					|| array[i + 1][j - 1] == -16)
				{
					ft_free_temp_array(cub, array);
					errors(0, cub);
				}
			}
			j++;
		}
	}
}
