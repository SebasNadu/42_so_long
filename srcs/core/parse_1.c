/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:01:37 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/11/06 15:37:33 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_valid_requisites(t_game *game, int elements[3], int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		if (game->map[i][j + 1] != '1' || game->map[i][j - 1] != '1'
			|| game->map[i + 1][j] != '1' || game->map[i - 1][j] != '1')
			elements[0]++;
		else
			elements[0]--;
	}
	else if (game->map[i][j] == 'P')
	{
		if (game->map[i][j + 1] != '1' || game->map[i][j - 1] != '1'
			|| game->map[i + 1][j] != '1' || game->map[i - 1][j] != '1')
			elements[1]++;
		else
			elements[1]--;
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->map[i][j + 1] != '1' || game->map[i][j - 1] != '1'
			|| game->map[i + 1][j] != '1' || game->map[i - 1][j] != '1')
			elements[2]++;
		else
			elements[2]--;
	}
}

t_bool	check_map_requisites(t_game *game)
{
	int	i;
	int	j;
	int	elements[3];

	i = 0;
	ft_memset(elements, 0, sizeof(elements));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			check_valid_requisites(game, elements, i, j);
			j++;
		}
		i++;
	}
	if (elements[0] < 1 || elements[1] != 1 || elements[2] != 1)
		return (0);
	game->c_num = elements[0];
	return (1);
}

t_bool	check_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && i < game->g_len.y
			&& j < game->g_len.x)
		{
			if (i == 0 || i + 1 == game->g_len.y)
				if (game->map[i][j] != '1')
					return (false);
			if (j == 0 || j + 1 == game->g_len.x)
				if (game->map[i][j] != '1')
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'M'
				&& game->map[i][j] != '*')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
