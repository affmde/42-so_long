/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:41:30 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 15:19:32 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	img_init(t_so_long *sl)
{
	t_img **img_arr;
	
	img_arr = ft_calloc(sl->height * sl->width, sizeof(t_img *));
	if (!img_arr)
		return (1);
	sl->img = img_arr;
	return (0);
}

int	handle_image(t_so_long *sl, char *filename, int	y, int x)
{
	int	index;

	index = y * sl->width + x;
	sl->img[index] = ft_calloc(1, sizeof(t_img));
	if (!sl->img)
		return (0);
	sl->img[index]->img_ptr = mlx_xpm_file_to_image(sl->ptr, filename, &sl->img[index]->height, &sl->img[index]->width);
	if (!sl->img[index]->img_ptr)
	{
		ft_printf("Failed to read image!\n");
		return (0);
	}
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img[index]->img_ptr, x * sl->img[index]->height, y * sl->img[index]->width);
	//mlx_destroy_image(sl->ptr, sl->img->img_ptr);
	//free(sl->img);
	return (1);
}

static char	*get_texture(t_so_long *sl, int i, int j)
{
	if (sl->map[i][j] == '1')
		return (ft_strdup("textures/wall.xpm"));
	else if (sl->map[i][j] == 'P')
		return (ft_strdup("textures/rogue.xpm"));
	else if (sl->map[i][j] == 'C')
		return (ft_strdup("textures/colectable.xpm"));
	else if (sl->map[i][j] == 'G')
		return (ft_strdup("textures/ghost.xpm"));
	else if (sl->map[i][j] == 'E')
		return (ft_strdup("textures/exit.xpm"));
	else
		return (ft_strdup("textures/ground.xpm"));
	return (NULL);
}

int	populate_window(t_so_long *sl)
{
	int	i;
	int	j;
	char *texture;

	img_init(sl);
	i = -1;
	while (++i < sl->height)
	{
		j = -1;
		while (++j < sl->width)
		{
			texture = get_texture(sl, i, j);
			if (!texture)
				return (0);
			if (!handle_image(sl, texture, i, j))
			{
				ft_strdel(&texture);
				return (0);
			}
			ft_strdel(&texture);
		}
	}
	return (1);
}
