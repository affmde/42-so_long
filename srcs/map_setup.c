/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:24:19 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 22:28:00 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_map_heigth(char *argc, t_so_long *sl)
{
	int	fd;
	int	count;
	char *str;
	
	if((fd = open(argc, O_RDONLY)) < 0)
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
	int		fd;
	char	*str;
	char	**arr;
	int		count;

	if ((fd = open(argc, O_RDONLY)) < 0)
		return (0);
	str = get_next_line(fd);
	if (!str)
		return (0);
	arr = ft_split(str, ' ');
	ft_strdel(&str);
	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
	{
		ft_strdel(&arr[count]);
		count++;
	}
	sl->width = count;
	free(arr);
	close(fd);
	return (1);
}

static int	get_map(char *argc, t_so_long *sl)
{
	int		fd;
	int		i;
	char	**map;
	if ((fd = open(argc, O_RDONLY)) < 0)
		return (0);
	map = (char **)malloc(sizeof(char *) * (sl->height + 1));
	if (map)
		return (0);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i])
			break ;
		i++;
	}
	map[i] = NULL;
	sl->map = map;
	while (map)
		ft_printf("%s", map++);
	close(fd);
	return (1);
}

void	map_setup(char *argc, t_so_long *sl)
{
	get_map_heigth(argc, sl);
	get_map_width(argc, sl);
	get_map(argc, sl);
	
}