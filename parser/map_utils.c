/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:02:42 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:02:46 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	errors(char *error, t_cub *cub)
{
	write(2, "Error\n", 6);
	if (errno != 0)
		perror(error);
	if (error == 0)
	{
		write(2, "Invalid file\n1. The map must be composed of only: ", 50);
		write(2, "0, 1 and one of N, S, E or W.\n2. The file must provide ", 55);
		write(2, "the following information:\nNO ./path_to_the_north_textu", 55);
		write(2, "re\nSO ./path_to_the_south_texture\nWE ./path_to_the_west", 55);
		write(2, "_texture\nEA ./path_to_the_east_texture\n", 39);
		write(2, "Floor ('F') and ceiling ('C') R,G,B colors", 42);
		write(2, " in range [0,255]: 0, 255, 255\n", 31);
		write(2, "3. Textures are expected with the .xpm extension.\n", 50);
		write(2, "4. The map must be closed/surrounded by walls.\n", 47);
	}
	else if (errno == 0)
	{
		write(2, error, ft_my_strlen(error));
		write(2, "\n", 1);
	}
	ft_free(cub);
	exit(1);
}

int	ft_my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_free(t_cub *cub)
{
	int	i;

	if (cub->buff)
		free(cub->buff);
	i = 0;
	if (cub->map)
	{
		while (i < cub->lines_num)
		{
			if (cub->map[i])
				free(cub->map[i]);
			i++;
		}
		free(cub->map);
	}
	if (cub->so)
		free(cub->so);
	if (cub->no)
		free(cub->no);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
}

void	fill_struct(t_cub *cub)
{
	cub->lines_num = 0;
	cub->line_length = 0;
	cub->x = 0;
	cub->y = 0;
	cub->buff = NULL;
	cub->map = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->f_color[0] = -1;
	cub->c_color[0] = -1;
}

void	null_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->lines_num)
	{
		cub->map[i] = NULL;
		i++;
	}
}
