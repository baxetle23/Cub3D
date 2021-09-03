/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_colors_map_info.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:04:42 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:04:44 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_paths_colors_map_info(t_cub *cub)
{
	int	i;
	int	info_counter;

	i = -1;
	info_counter = 6;
	while (cub->buff[++i] != '\0' && info_counter > 0)
	{
		i = skip_lines(cub, i);
		i = skip_spaces(cub, i);
		if (cub->buff[i] == '\0')
			errors(0, cub);
		else if ((cub->buff[i] == 'S' && cub->buff[i + 1] == 'O')
			|| (cub->buff[i] == 'N' && cub->buff[i + 1] == 'O')
			|| (cub->buff[i] == 'W' && cub->buff[i + 1] == 'E')
			|| (cub->buff[i] == 'E' && cub->buff[i + 1] == 'A'))
			i = get_paths_info(cub, i, cub->buff[i]);
		else if (cub->buff[i] == 'F' || cub->buff[i] == 'C')
			i = get_floor_ceiling_info(cub, i, cub->buff[i]);
		else
			errors(0, cub);
		i = skip_spaces(cub, i);
		info_counter--;
	}
	i = skip_lines(cub, i);
	count_lines_in_map(cub, i);
}

int	get_paths_info(t_cub *cub, int i, char c)
{
	if (c == 'S' && cub->so == NULL)
		i = malloc_and_save_path(cub, i + 2, c);
	else if (c == 'N' && cub->no == NULL)
		i = malloc_and_save_path(cub, i + 2, c);
	else if (c == 'E' && cub->ea == NULL)
		i = malloc_and_save_path(cub, i + 2, c);
	else if (c == 'W' && cub->we == NULL)
		i = malloc_and_save_path(cub, i + 2, c);
	else
		errors(0, cub);
	return (i);
}

int	malloc_and_save_path(t_cub *cub, int i, char c)
{
	int	start;

	if (cub->buff[i] != ' ')
		errors(0, cub);
	i = skip_spaces(cub, i);
	start = i;
	while (cub->buff[i] != ' ' && cub->buff[i] != '\0' && cub->buff[i] != '\n')
		i++;
	if (c == 'S')
		get_so(cub, i, start);
	else if (c == 'N')
		get_no(cub, i, start);
	else if (c == 'W')
		get_we(cub, i, start);
	else if (c == 'E')
		get_ea(cub, i, start);
	return (i);
}

int	get_floor_ceiling_info(t_cub *cub, int i, char c)
{
	if (c == 'F' && cub->f_color[0] == -1)
		i = save_color(cub, i + 1, cub->f_color);
	else if (c == 'C' && cub->c_color[0] == -1)
		i = save_color(cub, i + 1, cub->c_color);
	else
		errors(0, cub);
	return (i);
}

int	save_color(t_cub *cub, int i, int *color)
{
	int	j;

	if (cub->buff[i] != ' ')
		errors(0, cub);
	i = skip_spaces(cub, i);
	j = -1;
	while (++j < 3)
	{
		if (cub->buff[i] == '+')
			i++;
		if (cub->buff[i] <= '9' && cub->buff[i] >= '0')
			i = ft_my_atoi(cub, color, j, i);
		else
			errors(0, cub);
		i = skip_spaces(cub, i);
		if (j != 2)
		{
			if (cub->buff[i] != ',')
				errors(0, cub);
			i++;
		}
		i = skip_spaces(cub, i);
	}
	return (i);
}
