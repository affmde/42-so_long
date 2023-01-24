/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:36:51 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 18:19:01 by andrferr         ###   ########.fr       */
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
			handle_end(sl, 1);
			return (0);
		}
		is_collectable(sl, sl->pos->i, sl->pos->j - 1);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i][sl->pos->j - 1] = 'P';
		keep_exit_hidden(sl);
		refresh_window(sl, 'l');
		sl->pos->j--;
		if (killed_by_enemy(sl))
		{
			handle_end(sl, 0);
			return (0);
		}
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
			handle_end(sl, 1);
			return (0);
		}
		is_collectable(sl, sl->pos->i, sl->pos->j + 1);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i][sl->pos->j + 1] = 'P';
		keep_exit_hidden(sl);
		refresh_window(sl, 'r');
		sl->pos->j++;
		if (killed_by_enemy(sl))
		{
			handle_end(sl, 0);
			return (0);
		}
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
			handle_end(sl, 1);
			return (0);
		}
		is_collectable(sl, sl->pos->i + 1, sl->pos->j);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i + 1][sl->pos->j] = 'P';
		keep_exit_hidden(sl);
		refresh_window(sl, 'd');
		sl->pos->i++;
		if (killed_by_enemy(sl))
		{
			handle_end(sl, 0);
			return (0);
		}
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
			handle_end(sl, 1);
			return (0);
		}
		is_collectable(sl, sl->pos->i - 1, sl->pos->j);
		sl->map[sl->pos->i][sl->pos->j] = '0';
		sl->map[sl->pos->i - 1][sl->pos->j] = 'P';
		keep_exit_hidden(sl);
		refresh_window(sl, 'u');
		sl->pos->i--;
		if (killed_by_enemy(sl))
		{
			handle_end(sl, 0);
			return (0);
		}
		return (1);
	}
	return (0);
}
