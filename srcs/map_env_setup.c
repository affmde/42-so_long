/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_env_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:18:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 18:11:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_enemies_pos(t_so_long *sl, int i, int j)
{
	t_enemy *opon;
	opon = ft_calloc(1, sizeof(t_enemy));
	if (!opon)
		return (0);
	t_pos	*enemy;
	enemy = ft_calloc(1, sizeof(t_pos));
	if (!enemy)
		return (0);
	enemy->i = i;
	enemy->j = j;
	opon->pos = enemy;
	sl->enemy = opon;
	return (0);
}

int	get_player_pos(t_so_long *sl, int i, int j)
{
	t_pos *pos;
	pos = (t_pos *)malloc(sizeof(t_pos));
	if (!pos)
		return (1);
	pos->i = i;
	pos->j = j;
	sl->pos = pos;
	return (0);
}	

int	get_exit_pos(t_so_long *sl, int i, int j)
{
	t_pos	*exit;
	exit = (t_pos *)malloc(sizeof(t_pos));
	if (!exit)
		return (1);
	exit->i = i;
	exit->j = j;
	sl->exit_pos = exit;
	return (0);
}
	
int	map_env_setup(t_so_long *sl)
{
	int	i;
	int j;

	i = -1;
	while (++i < sl->height)
	{
		j = -1;
		while (++j < sl->width)
		{
			if (sl->map[i][j] == 'G')
				if (get_enemies_pos(sl, i, j))
					return (1);
			if (sl->map[i][j] == 'P')
				if (get_player_pos(sl, i, j))
					return (1);
			if (sl->map[i][j] == 'E')
				if (get_exit_pos(sl, i, j))
					return (1);
		}
	}
	return (0);
}