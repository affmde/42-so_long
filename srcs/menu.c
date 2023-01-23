/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:09:11 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/23 17:57:18 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	my_put_pixel(t_mlx_img *image, int x, int y, int color)
// {
// 	int		offset;

// 	offset = y * (image->size_l / 4) + x;
// 	if ((x >= 0 && x < WIDTH - WIDTH * 0.8) && (y >= 0 && y < HEIGHT))
// 		image->data[offset] = color;
// }

// static void draw_rectangle(t_mlx_img *img)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < 100)
// 	{
// 		j = -1;
// 		while (++j < WIDTH - WIDTH * 0.8)
// 		{
// 			my_put_pixel(img, j, i, 0xFFFFFF);
// 		}
// 	}
// }

// int	menu_put(t_so_long *sl)
// {
// 	t_mlx_img	*img;
// 	img = (t_mlx_img *)malloc(sizeof(t_mlx_img));
// 	if (!img)
// 		return (0);
// 	img->img_ptr = mlx_new_image(sl->ptr, HEIGHT, WIDTH - WIDTH * 0.8);
// 	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
// 	draw_rectangle(img);
// 	mlx_put_image_to_window(sl->ptr, sl->win, img->img_ptr, WIDTH * 0.8, 0);
// 	mlx_string_put(sl->ptr, sl->win, HEIGHT*0.8, WIDTH*0.8, 0x0000FF, ft_itoa(sl->steps_counter));
// 	return (0);
// }
