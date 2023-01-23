/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:25:45 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/23 09:13:45 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int	deal_key(int keycode, t_so_long *sl)
{
	if (keycode == 65307) // escape
	{
		mlx_destroy_window(sl->ptr, sl->win);
		exit (1);
	}
	else if (keycode == 65361) //left arrow
		move_left(sl);
	else if (keycode == 65363) //right arrow
		move_right(sl);
	else if (keycode == 65364) //down arrow
		move_down(sl);
	else if (keycode == 65362) //up arrow
		move_up(sl);
	return (0);
}