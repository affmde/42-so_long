/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:06:38 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 18:26:08 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(1);
}

static void	map_edit(t_so_long *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->height)
	{
		j = -1;
		while (++j < sl->width)
			if (sl->map[i][j] == 'E')
				sl->map[i][j] = 'e';
	}
}

int	handle_window(t_so_long *sl)
{
	sl->ptr = mlx_init();
	if (!sl->ptr)
		return (0);
	sl->win = mlx_new_window(sl->ptr, HEIGHT, WIDTH, "So Long");
	if (!sl->win)
		return (0);
	map_edit(sl);
	if (sl->nbr_enemies)
		sl->enemy->last_move = timestamp();
	populate_window(sl);
	if (sl->nbr_enemies)
		mlx_loop_hook(sl->ptr, enemy_AI, sl);
	mlx_key_hook(sl->win, deal_key, sl);
	mlx_hook(sl->win, 17, 0, close_window, NULL);
	mlx_loop(sl->ptr);
	mlx_destroy_display(sl->ptr);
	return (1);
}
