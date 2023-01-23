/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:13:19 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/23 09:13:54 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_exit(t_so_long *sl)
{
	int	i;
	int	j;

	if (sl->nbr_collectibles == 0)
	{
		i = -1;
		while (++i < sl->height)
		{
			j = -1;
			while (++j < sl->width)
				if (sl->map[i][j] == 'e')
					sl->map[i][j] = 'E';
		}
	}
}

int	is_collectable(t_so_long *sl, int i, int j)
{
	if (sl->map[i][j] == 'C')
	{
		sl->nbr_collectibles--;
		show_exit(sl);
		return (1);
	}
	return(0);
}

int	can_exit(t_so_long *sl, int i, int j)
{
	if (sl->map[i][j] == 'E' && sl->nbr_collectibles == 0)
		return (1);
	return (0);
}