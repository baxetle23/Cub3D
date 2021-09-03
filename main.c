/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:03:07 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:03:10 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	t_cub	cub;

	errno = 0;
	if (argc != 2)
	{
		printf("Usage: ./cub3D *.cub\n");
		exit(1);
	}
	map_validation(&cub, argv[1]);
	main_alex(&cub);
	return (0);
}
