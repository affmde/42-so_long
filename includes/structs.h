/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:00:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/22 10:42:38 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <mlx.h>

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}		t_img;

typedef struct s_current_pos
{
	int	i;
	int	j;
}	t_curr_pos;

typedef struct s_mlx_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;	
}	t_mlx_img;

typedef struct s_so_long
{
	char		**map;
	int			height;
	int			width;
	int			nbr_exits;
	int			nbr_players;
	int			nbr_collectibles;
	int			steps_counter;
	void		*ptr;
	void		*win;
	t_img		*img;
	t_curr_pos	*pos;
}		t_so_long;

#endif