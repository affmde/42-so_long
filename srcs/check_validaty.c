/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validaty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:13:18 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/25 11:20:02 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	confirm_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'G')
		return (1);
	return (0);
}

static int	check_chars(t_so_long *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->height)
	{
		j = -1;
		while (++j < sl->width)
		{
			if (!confirm_char(sl->map[i][j]))
				return (0);
		}
	}
	return (1);
}

static int	check_amounts(t_so_long *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->height)
	{
		j = 0;
		while (j < sl->width)
		{
			if (sl->map[i][j] == 'P')
				sl->nbr_players++;
			if (sl->map[i][j] == 'E')
				sl->nbr_exits++;
			if (sl->map[i][j] == 'C')
				sl->nbr_collectibles++;
			if (sl->map[i][j] == 'G')
				sl->nbr_enemies++;
			j++;
		}
		i++;
	}
	if (sl->nbr_exits != 1 || sl->nbr_players != 1)
		return (0);
	return (1);
}

static int	check_walls(t_so_long *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->height)
	{
		j = 0;
		while (j < sl->width)
		{
			if (sl->map[0][j] != '1' || sl->map[sl->height - 1][j] != '1')
				return (0);
			j++;
		}
		if (sl->map[i][0] != '1' || sl->map[i][sl->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_dimensions(t_so_long *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j])
		{
			if (j >= sl->width)
				return (1);
			j++;
		}
		i++;
	}
	if (i > sl->height)
		return (1);
	return (0);
}

static int	check_colectables_access(t_so_long *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->height)
	{
		j = 0;
		while (j < sl->width)
		{
			if (sl->map[i][j] == 'C')
			{
				sl->map[i][j] = 'c';
				if (!is_valid_path(sl, sl->map[i][j], 'P'))
					return (0);
				sl->map[i][j] = 'C';
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_validaty(t_so_long *sl)
{
	if (!check_chars(sl))
	{
		ft_putendl_fd("Invalid map.", 2);
		return (0);
	}
	if (!check_amounts(sl))
	{
		ft_putendl_fd("Invalid Map. Not right number of players or exits.", 2);
		return (0);
	}
	if (!check_walls(sl))
	{
		ft_putendl_fd("Invalid map. Map is not closed.", 2);
		return (0);
	}
	if (!is_valid_path(sl, 'P', 'E') || !check_colectables_access(sl))
	{
		ft_putendl_fd("Invalid map. Path is not valid.", 2);
		return (0);
	}
	if (check_dimensions(sl))
	{
		ft_putendl_fd("Invalid map. Not correct dimensions.", 2);
		return (0);
	}
	return (1);
}
