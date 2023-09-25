/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:36:49 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 20:23:25 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_block_bg(int x, int y, void *sprite, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite,
		x + game->g_offset.x, y + game->g_offset.y);
}

void	background(t_game *game)
{
	int	i;

	i = -1;
	while (++i < bg_n)
	{
		draw_block_bg((3 * BPX) - (BPX + game->player->pos.x), BPX + game->p_offset.y, game->sprites.bg[i], game);
		draw_block_bg((16 * BPX) - (BPX + game->player->pos.x), BPX + game->p_offset.y, game->sprites.bg[i], game);
	}
}
