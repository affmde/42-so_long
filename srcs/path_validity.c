/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:44:30 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/18 10:06:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	**aloc_array(t_so_long *sl)
{
	int	**visited;
	int	i;
	
	visited = (int **)malloc(sizeof(int *) * sl->height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < sl->height)
	{
		visited[i] = (int *)ft_calloc(sl->width, sizeof(int));
		if (!visited[i])
			return (0);
		i++;
	}
	return (visited);
}

static int	is_safe(int i, int j, t_so_long *sl)
{
	if ((i >= 0 && i < sl->height) && (j >= 0 && j < sl->width))
		return (1);
	return (0);
}

static int	check_path(t_so_long *sl, int i, int j, int **visited)
{
	int	up;
	int	down;
	int	left;
	int	right;
	
	if (is_safe(i, j, sl) && sl->map[i][j] != '1' && !visited[i][j])
	{
		visited[i][j] = 1;
		if (sl->map[i][j] == 'E')
			return (1);
		up = check_path(sl, i - 1, j, visited);
		if (up)
			return (1);
		down = check_path(sl, i + 1, j, visited);
		if (down)
			return (1);
		left = check_path(sl, i, j - 1, visited);
		if (left)
			return (1);
		right = check_path(sl, i, j + 1, visited);
		if (right)
			return (1);
	}
	return (0);
}

int	is_valid_path(t_so_long *sl)
{
	int	**visited;
	int	i;
	int	j;
	int	path_found;
	
	visited = aloc_array(sl);
	if (!visited)
		return (0);
	path_found = 0;
	i = 0;
	while (i < sl->height)
	{
		j = 0;
		while (j < sl->width)
		{
			if (sl->map[i][j] == 'P' && !visited[i][j])
			{
				if (check_path(sl, i, j, visited))
				{
					path_found = 1;
					break;
				}
			}
			j++;
		}
		i++;
	}
	free_visited(visited, sl->height);
	return (path_found);
}