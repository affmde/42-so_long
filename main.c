/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:01:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 16:02:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_so_long *sl;

	sl = (t_so_long *)ft_calloc(1, sizeof(t_so_long));
	if (!sl)
		return (0);
	if (argc != 2)
	{
		handle_errors("Not right number of arguments\n");
		return (1);
	}
	if (!map_setup(argv[1], sl))
		return (0);
	if (!check_validaty(sl))
	{
		free_struct(sl);
		return (0);
	}
	if (map_env_setup(sl))
	{
		free_struct(sl);
		return (1);
	}
	handle_window(sl);
	free_struct(sl);
	return (0);
}
