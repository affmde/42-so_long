/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_end_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:29:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/25 09:06:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keys(int keycode, t_so_long *sl)
{
	if (keycode == 113 || keycode == 65307 || keycode == 53)
		exit (sl->nbr_exits);
	return (0);
}

int	handle_end(t_so_long *sl, int win)
{
	char *str;
	
	str = ft_itoa(sl->steps_counter);
	mlx_clear_window(sl->ptr, sl->win);
	if (win)
	{
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.45, HEIGHT *0.4, 0xffffff, "You won!!");
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.45, HEIGHT *0.6, 0xffffff, "Number of steps: ");
		mlx_string_put(sl->ptr, sl->win, WIDTH / 2, HEIGHT *0.62, 0xffffff, str);
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.40, HEIGHT *0.72, 0xffffff, "Feel free to restart and play again.");
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.45, HEIGHT *0.7, 0xffffff, "Press Q or ESC to quit!");
		mlx_key_hook(sl->win, handle_keys, sl);
	}
	else
	{
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.45, HEIGHT *0.4, 0xffffff, "You lost!!");
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.45, HEIGHT *0.6, 0xffffff, "Number of steps: ");
		mlx_string_put(sl->ptr, sl->win, WIDTH / 2, HEIGHT *0.62, 0xffffff, str);
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.40, HEIGHT *0.72, 0xffffff, "Feel free to restart and play again.");
		mlx_string_put(sl->ptr, sl->win, WIDTH * 0.45, HEIGHT *0.7, 0xffffff, "Press Q or ESC to quit!");
		mlx_key_hook(sl->win, handle_keys, sl);
	}
	free(str);
	return (0);
}