/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:24:19 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 19:42:08 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_map_heigth(char *argc, t_so_long *sl)
{
	int	fd;
	int	count;
	char *str;
	char buf[20+1];
	if ((fd = open(argc, O_RDONLY) < 0))
		return (0);
	count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		count++;
		free(str);
	}
	sl->height = count;
	close(fd);
	return (1);
}

static int get_map_width(char *argc, t_so_long *sl)
{
	int	fd;
	char *str;
	
	if ((fd = open(argc, O_RDONLY) < 0))
		return (0);
	str = get_next_line(fd);
	sl->width = ft_strlen(str);
	free(str);
	close(fd);
	return (1);
}

void	map_setup(char *argc, t_so_long *sl)
{
		get_map_heigth(argc, sl);
		get_map_width(argc, sl);
		ft_printf("height: %d\nwidth: %d\n", sl->height, sl->width);
}