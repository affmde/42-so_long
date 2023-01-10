/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:00:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/09 18:48:41 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <mlx.h>

typedef struct  s_img
{
	void	*img;
	int		height;
	int		width;
}		t_img;

typedef struct s_so_long
{
	char	**map;
	int		height;
	int		width;
	int		nbr_exits;
	int		nbr_players;
	int		nbr_collectibles;
	void	*ptr;
	void	*win;
	t_img	*img;
}		t_so_long;


#endif