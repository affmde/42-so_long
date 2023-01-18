/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:06:38 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/18 09:28:23 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(1);
}

int	handle_window(t_so_long *sl)
{	
	sl->ptr = mlx_init();
	if (!sl->ptr)
		return (0);
	sl->win = mlx_new_window(sl->ptr, HEIGHT, WIDTH, "So Long");
	if (!sl->win)
		return (0);
	populate_window(sl);
	mlx_hook(sl->win, 17, 0, close_window, NULL);
	mlx_loop(sl->ptr);
	return (1);
}