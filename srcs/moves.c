/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:36:51 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/23 17:54:45 by andrferr         ###   ########.fr       */
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
		mlx_clear_window(sl->ptr, sl->win);
		populate_window(sl);
		return (1);
	}
	return (0);
}

// void	AI_move(t_so_long *sl)
// {
// 	int	cx;
// 	int	cy;
// 	int	dx;
// 	int	dy;
// 	int	xsignal;
// 	int	ysignal;

// 	cx = 3;
// 	cy = 1;
// 	if (cx < sl->pos->j)
// 		xsignal = -1;
// 	else
// 		xsignal = 1;
// 	if (cy < sl->pos->i)
// 		ysignal = -1;
// 	else
// 		ysignal = 1;

// 	dx = ft_abs(cx - sl->pos->j);
// 	dy = ft_abs(cy - sl->pos->i);
// 	if (dx > dy)
// 	{
// 		if (xsignal > 0)
// 		{
// 			if (!move_right(sl))
// 			{
// 				if (ysignal > 0)
// 				{
// 					if (!move_down(sl))
// 						move_up(sl);
// 				}
// 				else
// 					if (!move_up(sl))
// 						move_down(sl);
// 			}
// 			else
// 				move_left(sl);
// 		}
// 		else
// 			if(!move_left(sl))
// 			{
// 				if (ysignal > 0)
// 				{
// 					if (!move_down(sl))
// 						move_up(sl);
// 				}
// 				else
// 				{
// 					if (!move_up(sl))
// 						move_down(sl);
// 				}
// 			}
// 			else
// 				move_right(sl);
// 	}
// 	else
// 	{
// 		if (ysignal > 0)
// 		{
// 			if (!move_down(sl))
// 			{
// 				if (xsignal > 0)
// 				{
// 					if (!move_right(sl))
// 						move_left(sl);
// 				}
// 				else
// 				if (!move_left(sl))
// 					move_right(sl);
// 			}
// 			else
// 				move_up(sl);
// 		}
// 		else
// 		{
// 			if (!move_up(sl))
// 			{
// 				if (xsignal > 0)
// 				{
// 					if (!move_right(sl))
// 						move_left(sl);
// 				}
// 				else
// 				{
// 					if (!move_left(sl))
// 						move_right(sl);
// 				}
// 			}
// 			else
// 				move_down(sl);
// 		}
// 	}
// }
