/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:41:30 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/15 14:39:22 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_image(t_so_long *sl)
{
	char path[] = "../textures/character.xpm";
	sl->img = ft_calloc(1, sizeof(t_img));
	if (!sl->img)
		return (0);
	sl->img->img_ptr = mlx_xpm_file_to_image(sl->ptr, path, &sl->img->height, &sl->img->width);
	if (!sl->img->img_ptr)
	{
		ft_printf("Failed to read image\n");
		return (0);
	}
	ft_printf("img w: %d\n", sl->img->width);
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img->img_ptr, 50, 50);
	return (1);
}