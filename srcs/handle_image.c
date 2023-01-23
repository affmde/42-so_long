/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:41:30 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/22 09:11:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int	handle_image(t_so_long *sl, char *filename, int	x, int y)
{
	sl->img = ft_calloc(1, sizeof(t_img));
	if (!sl->img)
		return (0);
	sl->img->img_ptr = mlx_xpm_file_to_image(sl->ptr, filename, &sl->img->height, &sl->img->width);
	if (!sl->img->img_ptr)
	{
		ft_printf("Failed to read image!\n");
		return (0);
	}
	mlx_put_image_to_window(sl->ptr, sl->win, sl->img->img_ptr, y * sl->img->height, x * sl->img->width);
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
	else if (sl->map[i][j] == 'E')
		return (ft_strdup("textures/tile.xpm")); // STILL CHANGE THIS TO PROPER EXIT SPRITE!!!!
	else
		return (ft_strdup("textures/ground.xpm"));
	return (NULL);
}

int	populate_window(t_so_long *sl)
{
	int	i;
	int	j;
	char *texture;

	i = 0;
	while (i < sl->height)
	{
		j = 0;
		while (j < sl->width)
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
			j++;
		}
		i++;
	}
	return (1);
}
