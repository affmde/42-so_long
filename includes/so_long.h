/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:59:50 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/15 13:41:15 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define HEIGHT 1000
# define WIDTH 1000

#include <unistd.h>
#include <fcntl.h>
#include "structs.h"
#include "../libft/libft.h"

void	handle_errors(char *msg);
int		map_setup(char *argc, t_so_long *sl);
int		check_validaty(t_so_long *sl);
void	free_map(char **map);
void	free_struct(t_so_long *sl);
int		handle_window(t_so_long *sl);
int		handle_image(t_so_long *sl);
int		is_valid_path(t_so_long *sl);

#endif