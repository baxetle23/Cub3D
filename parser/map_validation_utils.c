/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:04:21 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:04:23 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	skip_spaces(t_cub *cub, int i)
{
	while (cub->buff[i] == ' ')
		i++;
	if (cub->buff[i] == '\0')
		errors(0, cub);
	return (i);
}

int	skip_lines(t_cub *cub, int i)
{
	while (cub->buff[i] == '\n')
		i++;
	if (cub->buff[i] == '\0')
		errors(0, cub);
	return (i);
}

int	ft_my_atoi(t_cub *cub, int *color, int color_num, int i)
{
	color[color_num] = 0;
	while (cub->buff[i] <= '9' && cub->buff[i] >= '0')
	{
		color[color_num] = color[color_num] * 10 + (cub->buff[i] - 48);
		if (color[color_num] > 255)
			errors(0, cub);
		i++;
	}
	return (i);
}

void	change_spaces(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->lines_num)
	{
		j = 0;
		while (j < cub->line_length)
		{
			if (cub->map[i][j] == -16)
				cub->map[i][j] = 0;
			j++;
		}
		i++;
	}
}
