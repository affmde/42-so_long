/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:59:50 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 19:32:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include "structs.h"
#include "../libft/libft.h"

void	handle_errors(char *msg);
void	map_setup(char *argc, t_so_long *sl);

#endif