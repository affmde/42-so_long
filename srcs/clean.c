/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:47:15 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 10:46:19 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_strdel(&map[i++]);
	free(map);
}

void	free_struct(t_so_long *sl)
{
	if (sl)
	{
		if (sl->map)
			free_map(sl->map);
		if (sl->ptr)
			ft_memdel(&sl->ptr);
		if (sl->win)
			ft_memdel(&sl->win);
		if (sl->img)
			free(sl->img);
		if (sl->pos)
			free(sl->pos);
		if (sl->exit_pos)
			free(sl->exit_pos);
		if (sl->enemy)
		{
			if (sl->enemy->pos)
				free(sl->enemy->pos);
			free(sl->enemy);
		}
		if (sl)
			free(sl);
	}
}

void	free_visited(int **arr, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
