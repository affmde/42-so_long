/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:41:30 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/17 10:05:32 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_image(t_so_long *sl, char *filename, int	x, int y)
{
	char path[] = "textures/colectable.xpm";
	sl->img = ft_calloc(1, sizeof(t_img));
	if (!sl->img)
		return (0);
	sl->img->img_ptr = mlx_xpm_file_to_image(sl->ptr, path, &sl->img->height, &sl->img->width);
	if (!sl->img->img_ptr)
		return (0);
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img->img_ptr, 50, 50);
	return (1);
}

int	populate_window(t_so_long *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->height)
	{
		j = 0;
		while (j < sl->width)
		{
			handle_image(sl, )
		}
	}
}