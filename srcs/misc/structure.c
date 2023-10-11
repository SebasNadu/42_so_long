/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:42:11 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:41:44 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_structure(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (i == 0)
			draw_block(j * BPX + game->p_offset.x, i * BPX + game->p_offset.y,
				game->sprites.misc[3], game);
		else if (i == game->g_len.y - 1)
			draw_block(j * BPX + game->p_offset.x, i * BPX + game->p_offset.y,
				game->sprites.misc[0], game);
		if ((j == game->g_len.x - 1 || j == 0) && i != 0)
			draw_block(j * BPX + game->p_offset.x, i * BPX + game->p_offset.y,
				game->sprites.misc[1], game);
		if (i != 0 && i != game->g_len.y - 1 && j != 0
			&& j != game->g_len.x - 1)
			draw_block(j * BPX + game->p_offset.x, i * BPX + game->p_offset.y,
				game->sprites.misc[1], game);
	}
	else if (i * BPX < WIN_HEIGHT && game->map[i][j] == '*')
		draw_block(j * BPX + game->p_offset.x, i * BPX + game->p_offset.y,
			game->sprites.misc[2], game);
	else if (i * BPX >= WIN_HEIGHT
		&& (game->map[i][j] == '0' || game->map[i][j] == 'M'
			|| game->map[i][j] == 'P' || game->map[i][j] == 'C'))
		draw_block(j * BPX + game->p_offset.x,
			i * BPX + game->p_offset.y, game->sprites.misc[2], game);
}

void	structure(t_game *game)
{
	int	i;
	int	j;

	i = game->g_len.y;
	while (0 <= --i)
	{
		j = game->g_len.x;
		while (0 <= --j)
		{
			draw_structure(game, i, j);
		}
	}
}
