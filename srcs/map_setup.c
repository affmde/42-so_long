/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:24:19 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/21 11:02:21 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_width(char *line)
{
	int	width;
	
	width = 0;
	while(*line)
	{
		if ((!ft_isspace(*line) && ft_isspace(*(line + 1))) || (!ft_isspace(*line) && *(line + 1) == '\0'))
			width++;
		line++;
	}
	return (width);
}

static int	get_map_dimensions(char *argc, t_so_long *sl)
{
	int	fd;
	int	count;
	char *str;
	int	width;
	
	if((fd = open(argc, O_RDONLY)) < 0)
		return (0);
	count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		count++;
		width = get_width(str);
		free(str);
	}
	sl->height = count;
	sl->width = width;
	close(fd);
	return (1);
}

static char	**remove_spaces(char **map, t_so_long *sl)
{
	int		i;
	int		j;
	int		k;
	char	*line;
	char	**new_map;
	
	i = 0;
	new_map = ft_calloc(sl->height + 1, sizeof(char *));
	if (!new_map)
		return (0);
	while (map[i])
	{
		j = 0;
		k = 0;
		line = ft_calloc(get_width(map[i]) + 1, sizeof(char *));
		if (!line)
			return (0);
		while (map[i][k])
		{
			if (map[i][k] == 'P')
			{
				sl->pos->i = i;
				sl->pos->j = j;
			}
			if (!ft_isspace(map[i][k]))
				line[j++] = map[i][k];
			k++;
		}
		new_map[i] = line;
		i++;
	}
	return (new_map);
}

static int	get_map(char *argc, t_so_long *sl)
{
	int		fd;
	char	*str;
	char	**map;
	int		i;
	
	if ((fd = open(argc, O_RDONLY)) < 0)
		return (0);
	map = ft_calloc(sl->height + 1, sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while ((str = get_next_line(fd)))
	{
		map[i] = ft_strdup(str);
		if (!map[i])
		{
			free_map(map);
			return (0);
		}
		free(str);
		i++;
	}
	map[i] = NULL;
	sl->map = remove_spaces(map, sl);
	free_map(map);
	close(fd);
	return (1);
}

int	map_setup(char *argc, t_so_long *sl)
{
	t_curr_pos *pos;
	pos = (t_curr_pos *)malloc(sizeof(t_curr_pos));
	if (!pos)
		return (0);
	sl->pos = pos;
	if (!get_map_dimensions(argc, sl))
	{
		free(pos);
		return (0);
	}
	if (!get_map(argc, sl))
	{
		free(pos);
		return (0);
	}
	return (1);
}