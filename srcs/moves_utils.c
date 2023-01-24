/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:13:19 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 16:13:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_exit(t_so_long *sl)
{
	int	i;
	int	j;
	int	index;

	if (sl->nbr_collectibles == 0)
	{
		i = -1;
		while (++i < sl->height)
		{
			j = -1;
			while (++j < sl->width)
				if (sl->map[i][j] == 'e')
				{
					index = i * sl->width + j;
					sl->map[i][j] = 'E';
					mlx_destroy_image(sl->ptr, sl->img[index]->img_ptr);
					sl->img[index]->img_ptr = mlx_xpm_file_to_image(sl->ptr, "textures/exit.xpm", &sl->img[index]->width, &sl->img[index]->height);
					mlx_put_image_to_window(sl->ptr, sl->win, sl->img[index]->img_ptr, j * sl->img[index]->width, i * sl->img[index]->height);
					return ;
				}
		}
	}
}

int	is_collectable(t_so_long *sl, int i, int j)
{
	ft_printf("c remaining: %d\n", sl->nbr_collectibles);
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

void	keep_exit_hidden(t_so_long *sl)
{
	if (sl->nbr_collectibles && sl->pos->i != sl->exit_pos->i && sl->pos->j != sl->exit_pos->j)
		sl->map[sl->exit_pos->i][sl->exit_pos->j] = 'e';
}

int	killed_by_enemy(t_so_long *sl)
{
	if (!sl->nbr_enemies)
		return (0);
	if (sl->pos->i == sl->enemy->pos->i && sl->pos->j == sl->enemy->pos->j)
		return (1);
	return (0);
}