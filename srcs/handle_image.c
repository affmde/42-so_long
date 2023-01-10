/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:41:30 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/10 08:52:50 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_image(t_so_long *sl)
{
	t_img *img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (0);
	img->img = mlx_xpm_file_to_image(sl->ptr, "../textures/tile.xpm", &sl->img->height, &sl->img->width);
	if (!img)
		return (0);
	sl->img = img;
	ft_printf("img w: %d\n", sl->img->width);
	return (1);
}