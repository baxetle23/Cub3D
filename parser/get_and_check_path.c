/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:04:32 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:04:34 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_so(t_cub *cub, int i, int start)
{
	int	j;

	cub->so = (char *)malloc(sizeof(char) * (i - start + 1));
	if (cub->so == NULL)
		errors(0, cub);
	cub->so[i - start] = '\0';
	j = 0;
	while (i - start > 0)
	{
		cub->so[j] = cub->buff[start++];
		j++;
	}
	check_path(cub->so, cub);
}

void	get_no(t_cub *cub, int i, int start)
{
	int	j;

	cub->no = (char *)malloc(sizeof(char) * (i - start + 1));
	if (cub->no == NULL)
		errors(0, cub);
	cub->no[i - start] = '\0';
	j = 0;
	while (i - start > 0)
	{
		cub->no[j] = cub->buff[start++];
		j++;
	}
	check_path(cub->no, cub);
}

void	get_ea(t_cub *cub, int i, int start)
{
	int	j;

	cub->ea = (char *)malloc(sizeof(char) * (i - start + 1));
	if (cub->ea == NULL)
		errors(0, cub);
	cub->ea[i - start] = '\0';
	j = 0;
	while (i - start > 0)
	{
		cub->ea[j] = cub->buff[start++];
		j++;
	}
	check_path(cub->ea, cub);
}

void	get_we(t_cub *cub, int i, int start)
{
	int	j;

	cub->we = (char *)malloc(sizeof(char) * (i - start + 1));
	if (cub->we == NULL)
		errors(0, cub);
	cub->we[i - start] = '\0';
	j = 0;
	while (i - start > 0)
	{
		cub->we[j] = cub->buff[start++];
		j++;
	}
	check_path(cub->we, cub);
}

void	check_path(char *path, t_cub *cub)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		errors(0, cub);
	close(fd);
	if (path[ft_strlen(path) - 1] != 'm' || path[ft_strlen(path) - 2] != 'p'
		|| path[ft_strlen(path) - 3] != 'x' || path[ft_strlen(path) - 4] != '.')
		errors("Provide textures with .xpm extension", cub);
}
