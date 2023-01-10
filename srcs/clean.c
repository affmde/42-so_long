/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:47:15 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/09 18:54:06 by andrferr         ###   ########.fr       */
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
		if (sl)
			free(sl);
	}
}