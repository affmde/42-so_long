/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:59:50 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/25 10:04:21 by andrferr         ###   ########.fr       */
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
#include <sys/time.h>

void	handle_errors(char *msg);
int		map_setup(char *argc, t_so_long *sl);
int		check_validaty(t_so_long *sl);
void	free_map(char **map);
void	free_struct(t_so_long *sl);
int		handle_window(t_so_long *sl);
int		handle_image(t_so_long *sl, char *filename, int	x, int y);
int		is_valid_path(t_so_long *sl, char target, char objective);
int		populate_window(t_so_long *sl);
void	free_visited(int **arr, int height);
int		deal_key(int keycode, t_so_long *sl);
void	count_steps(t_so_long *sl);
int		move_left(t_so_long *sl);
int		move_right(t_so_long *sl);
int		move_down(t_so_long *sl);
int		move_up(t_so_long *sl);
void	show_exit(t_so_long *sl);
int		is_collectable(t_so_long *sl, int i, int j);
int		can_exit(t_so_long *sl, int i, int j);
void	keep_exit_hidden(t_so_long *sl);
int		map_env_setup(t_so_long *sl);
int		killed_by_enemy(t_so_long *sl);
int		enemy_AI(t_so_long *sl);
unsigned long	timestamp(void);
int		refresh_window(t_so_long *sl, char instruction);
void	replace_imgs(t_so_long *sl, t_img_change img1, t_img_change img2);
int		handle_end(t_so_long *sl, int win);

#endif
