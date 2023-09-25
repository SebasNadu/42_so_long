/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:42:11 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 17:37:32 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	structure(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->g_len.y)
	{
		j = 0;
		while (j < game->g_len.x)
		{
			if (game->map[i][j] == '1')
			{
				draw_block(j * BPX + game->p_offset.x,
					i * BPX + game->p_offset.y,
					game->sprites.misc[1], game);
			}
			// else if (game->map[i][j] == '0' || game->map[i][j] == 'M'
			// 	|| game->map[i][j] == 'P' || game->map[i][j] == 'C')
			// 	draw_block(j * BPX + game->p_offset.x,
			// 		i * BPX + game->p_offset.y,
			// 		game->sprites.misc[6], game);
			else if (game->map[i][j] == '*')
				draw_block(j * BPX + game->p_offset.x,
					i * BPX + game->p_offset.y,
					game->sprites.misc[6], game);
			j++;
		}
		i++;
	}
}
