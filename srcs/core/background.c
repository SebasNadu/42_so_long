/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:36:49 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 23:44:47 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_block_bg(int x, int y, void *sprite, t_game *game)
{
	if (x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, sprite,
		x + game->g_offset.x, y + game->g_offset.y);
}

void	background(t_game *game)
{
	int	i;
	int	j;
	int	x_offset;
	int	y_offset;

	i = -1;
	j = 1;
	y_offset = BPX + game->p_offset.y;
	while (++i < bg_n)
	{
		x_offset = (((j * BPX) - (game->player->pos.x)) / (j * 4));
		draw_block_bg(x_offset - BPX, y_offset, game->sprites.bg[i], game);
		draw_block_bg((8 * BPX) + x_offset, y_offset, game->sprites.bg[i], game);
		j++;
	}
}
