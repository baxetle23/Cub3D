/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:04:00 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:04:02 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	map_validation(t_cub *cub, char *argv)
{
	fill_struct(cub);
	check_fd_and_get_buff(argv, cub);
	get_paths_colors_map_info(cub);
	get_starting_position(cub);
	check_starting_position(cub);
	if (cub->lines_num < 3)
		errors(0, cub);
	check_walls(cub);
	change_spaces(cub);
}

void	check_fd_and_get_buff(char *argv, t_cub *cub)
{
	int	file_length;
	int	fd;
	int	read_ret;

	if (argv[ft_strlen(argv) - 1] != 'b' || argv[ft_strlen(argv) - 2] != 'u'
		|| argv[ft_strlen(argv) - 3] != 'c' || argv[ft_strlen(argv) - 4] != '.')
		errors("File with .cub extension is missing", cub);
	file_length = get_file_length(argv, cub);
	cub->buff = (char *)malloc(sizeof(char) * (file_length + 1));
	if (cub->buff == NULL)
		errors(0, cub);
	cub->buff[file_length] = '\0';
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		errors(0, cub);
	read_ret = read(fd, cub->buff, file_length);
	if (read_ret < 0)
	{
		close(fd);
		errors(0, cub);
	}
	close(fd);
}

int	get_file_length(char *str, t_cub *cub)
{
	int		fd;
	int		read_ret;
	char	buff[1024];
	int		file_length;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		errors("Provide an existing file with .cub extension", cub);
	file_length = 0;
	read_ret = read(fd, buff, sizeof(buff));
	while (read_ret != 0)
	{
		if (read_ret < 0)
		{
			close(fd);
			errors(0, cub);
		}
		file_length = file_length + read_ret;
		read_ret = read(fd, buff, sizeof(buff));
	}
	close(fd);
	return (file_length);
}

void	count_lines_in_map(t_cub *cub, int map_start)
{
	int	temp;

	temp = map_start;
	while (cub->buff[map_start] != '\0')
	{
		if (cub->buff[map_start] == '\n')
		{
			if (cub->buff[map_start + 1] == '\n')
				errors(0, cub);
			cub->lines_num++;
		}
		map_start++;
	}
	if (map_start > temp && cub->buff[map_start - 1] != '\n')
		cub->lines_num++;
	cub->map = (int **)malloc(sizeof(int *) * cub->lines_num);
	if (cub->map == NULL)
		errors(0, cub);
	null_map(cub);
	find_longest_line(cub, temp);
	map_maker(cub, temp);
}

void	find_longest_line(t_cub *cub, int map_start)
{
	int	longest;
	int	j;
	int	x;

	longest = 0;
	j = 0;
	x = 0;
	while (j < cub->lines_num)
	{
		x = map_start;
		while (cub->buff[map_start] != '\n' && cub->buff[map_start] != '\0')
			map_start++;
		if (map_start - x > longest)
			longest = map_start - x;
		j++;
		map_start++;
	}
	cub->line_length = longest;
	j = -1;
	while (++j < cub->lines_num)
	{
		cub->map[j] = (int *)malloc(sizeof(int) * cub->line_length);
		if (cub->map[j] == NULL)
			errors(0, cub);
	}
}
