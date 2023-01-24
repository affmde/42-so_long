/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:00:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 16:05:23 by andrferr         ###   ########.fr       */
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

typedef struct s_pos
{
	int	i;
	int	j;
}	t_pos;

typedef struct s_mlx_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}	t_mlx_img;

typedef struct s_enemy
{
	t_pos			*pos;
	unsigned long	last_move;
	int				dead;
	int				nbr_moves;
}	t_enemy;

typedef struct s_so_long
{
	char		**map;
	int			height;
	int			width;
	int			nbr_exits;
	int			nbr_players;
	int			nbr_collectibles;
	int			nbr_enemies;
	int			steps_counter;
	void		*ptr;
	void		*win;
	t_img		**img;
	t_pos		*pos;
	t_pos		*exit_pos;
	t_enemy		*enemy;
}		t_so_long;

typedef struct s_img_change
{
	int		x;
	int		y;
	char	*sprite;
}	t_img_change;

#endif
