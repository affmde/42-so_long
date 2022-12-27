/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:01:17 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 19:30:51 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_so_long sl;
	
	if (argc != 2)
	{
		handle_errors("Not right number of arguments");
		return (1);
	}
	map_setup(argv[1], &sl);
	return (0);
}
