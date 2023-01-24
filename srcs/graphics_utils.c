/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:02:40 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 15:42:35 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	replace_imgs(t_so_long *sl, t_img_change img1, t_img_change img2)
{
	int	img1_index;
	int	img2_index;

	img1_index = img1.y * sl->width + img1.x;
	img2_index = img2.y * sl->width + img2.x;

	mlx_destroy_image(sl->ptr, sl->img[img1_index]->img_ptr);
	mlx_destroy_image(sl->ptr, sl->img[img2_index]->img_ptr);
	sl->img[img1_index]->img_ptr = mlx_xpm_file_to_image(sl->ptr, img1.sprite, &sl->img[img1_index]->width, &sl->img[img1_index]->height);
	sl->img[img2_index]->img_ptr = mlx_xpm_file_to_image(sl->ptr, img2.sprite, &sl->img[img2_index]->width, &sl->img[img2_index]->height);
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img[img1_index]->img_ptr, img1.x * sl->img[img1_index]->width, img1.y * sl->img[img1_index]->height);
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img[img2_index]->img_ptr, img2.x * sl->img[img2_index]->width, img2.y * sl->img[img2_index]->height);
}

int	refresh_window(t_so_long *sl, char instruction)
{
	t_img_change img1;
	t_img_change img2;
	
	if (instruction == 'l')
	{
		img1.x = sl->pos->j;
		img1.y = sl->pos->i;
		img1.sprite = "textures/ground.xpm";
		img2.x = sl->pos->j - 1;
		img2.y = sl->pos->i;
		img2.sprite = "textures/rogue.xpm";
		replace_imgs(sl, img1, img2);
	}
	else if (instruction == 'r')
	{
		img1.x = sl->pos->j;
		img1.y = sl->pos->i;
		img1.sprite = "textures/ground.xpm";
		img2.x = sl->pos->j + 1;
		img2.y = sl->pos->i;
		img2.sprite = "textures/rogue.xpm";
		replace_imgs(sl, img1, img2);
	}
	else if (instruction == 'u')
	{
		img1.x = sl->pos->j;
		img1.y = sl->pos->i;
		img1.sprite = "textures/ground.xpm";
		img2.x = sl->pos->j;
		img2.y = sl->pos->i - 1;
		img2.sprite = "textures/rogue.xpm";
		replace_imgs(sl, img1, img2);
	}
	else if (instruction == 'd')
	{
		img1.x = sl->pos->j;
		img1.y = sl->pos->i;
		img1.sprite = "textures/ground.xpm";
		img2.x = sl->pos->j;
		img2.y = sl->pos->i + 1;
		img2.sprite = "textures/rogue.xpm";
		replace_imgs(sl, img1, img2);
	}
	return (0);
}