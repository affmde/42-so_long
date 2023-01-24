/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:36:51 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 09:39:04 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_left(t_so_long *sl)
{
	if (sl->map[sl->pos->i][sl->pos->j - 1] != '1')
	{
		count_steps(sl);
		if (can_exit(sl, sl->pos->i, sl->pos->j - 1))
		{
			mlx_destroy_window(sl->ptr, sl->win);
			exit (1);
		}
		is_collectable(sl, sl->pos->i, sl->pos->j - 1);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i][sl->pos->j - 1] = 'P';
		keep_exit_hidden(sl);
		sl->pos->j--;
		if (killed_by_enemy(sl))
			exit(1);
		mlx_clear_window(sl->ptr, sl->win);
		populate_window(sl);
		return (1);
	}
	return (0);
}

int	move_right(t_so_long *sl)
{
	if (sl->map[sl->pos->i][sl->pos->j + 1] != '1')
	{
		count_steps(sl);
		if (can_exit(sl, sl->pos->i, sl->pos->j + 1))
		{
			mlx_destroy_window(sl->ptr, sl->win);
			exit (1);
		}
		is_collectable(sl, sl->pos->i, sl->pos->j + 1);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i][sl->pos->j + 1] = 'P';
		keep_exit_hidden(sl);
		sl->pos->j++;
		if (killed_by_enemy(sl))
			exit(1);
		mlx_clear_window(sl->ptr, sl->win);
		populate_window(sl);
		return (1);
	}
	return (0);
}

int	move_down(t_so_long *sl)
{
	if (sl->map[sl->pos->i + 1][sl->pos->j] != '1')
	{
		count_steps(sl);
		if (can_exit(sl, sl->pos->i + 1, sl->pos->j))
		{
			mlx_destroy_window(sl->ptr, sl->win);
			exit (1);
		}
		is_collectable(sl, sl->pos->i + 1, sl->pos->j);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i + 1][sl->pos->j] = 'P';
		keep_exit_hidden(sl);
		sl->pos->i++;
		if (killed_by_enemy(sl))
			exit(1);
		mlx_clear_window(sl->ptr, sl->win);
		populate_window(sl);
		return (1);
	}
	return (0);
}

int	move_up(t_so_long *sl)
{
	if (sl->map[sl->pos->i - 1][sl->pos->j] != '1')
	{
		count_steps(sl);
		if (can_exit(sl, sl->pos->i - 1, sl->pos->j))
		{
			mlx_destroy_window(sl->ptr, sl->win);
			exit (1);
		}
		is_collectable(sl, sl->pos->i - 1, sl->pos->j);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i - 1][sl->pos->j] = 'P';
		keep_exit_hidden(sl);
		sl->pos->i--;
		if (killed_by_enemy(sl))
			exit(1);
		mlx_clear_window(sl->ptr, sl->win);
		populate_window(sl);
		return (1);
	}
	return (0);
}
