/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_AI.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:45:28 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 10:57:02 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	get_closer(t_so_long *sl)
{
	int	dx;
	int	dy;
	char	signal;
	
	dx = sl->pos->j - sl->enemy->pos->j;
	dy = sl->pos->i - sl->enemy->pos->i;
	if (ft_abs(dx) > ft_abs(dy))
		signal = 'h';
	else
		signal = 'v';
	if (signal == 'h' && dx < 0)
		return ('l');
	else if (signal == 'h' && dx > 0)
		return ('r');
	else if (signal == 'v' && dy < 0)
		return ('u');
	else
		return ('d');
	
}

static void left(t_so_long *sl, int x, int y)
{
	sl->enemy->pos->j = x - 1;
	sl->map[sl->enemy->pos->i][sl->enemy->pos->j] = 'G';
	sl->map[y][x] = '0';
}

static void right(t_so_long *sl, int x, int y)
{
	sl->enemy->pos->j = x + 1;
	sl->map[sl->enemy->pos->i][sl->enemy->pos->j] = 'G';
	sl->map[y][x] = '0';
}

static void up(t_so_long *sl, int x, int y)
{
	sl->enemy->pos->i = y - 1;
	sl->map[sl->enemy->pos->i][sl->enemy->pos->j] = 'G';
	sl->map[y][x] = '0';
}

static void down(t_so_long *sl, int x, int y)
{
	sl->enemy->pos->i = y + 1;
	sl->map[sl->enemy->pos->i][sl->enemy->pos->j] = 'G';
	sl->map[y][x] = '0';
}

int	enemy_AI(t_so_long *sl)
{
	int	x;
	int	y;
	static char	direction = 'l';
	
	y = sl->enemy->pos->i;
	x = sl->enemy->pos->j;
	
	if (x > 0 && x < sl->width && y > 0 && y < sl->height && sl->enemy->last_move + 1000 < timestamp())
	{
		direction = get_closer(sl);
		if (direction == 'l' && sl->map[y][x - 1] != '1' && sl->map[y][x - 1] != 'C' && sl->map[y][x - 1] != 'E')
			left(sl, x, y);
		else if (direction == 'r' && sl->map[y][x + 1] != '1' && sl->map[y][x + 1] != 'C' && sl->map[y][x + 1] != 'E')
			right(sl, x, y);
		else if (direction == 'u' && sl->map[y - 1][x] != '1' && sl->map[y - 1][x] != 'C' && sl->map[y - 1][x] != 'E')
			up(sl, x, y);
		else if (direction == 'd' && sl->map[y + 1][x] != '1' && sl->map[y + 1][x] != 'C' && sl->map[y + 1][x] != 'E')
			down(sl, x, y);
		if (killed_by_enemy(sl))
			exit (1);
		mlx_clear_window(sl->ptr, sl->win);
		populate_window(sl);
		sl->enemy->last_move = timestamp();
	}
	return (0);
}