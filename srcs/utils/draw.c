/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:47:49 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:42:39 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_bg(int x, int y, void *sprite, t_game *game)
{
	if (x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, sprite,
		x + game->g_offset.x, y + game->g_offset.y);
}

void	draw_sky(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->g_len.x)
	{
		draw_block(j * BPX + game->p_offset.x,
			0 + game->p_offset.y,
			game->sprites.bg[0], game);
		j++;
	}
}

void	draw_block(int x, int y, void *sprite, t_game *game)
{
	if (x < -BPX || y < -BPX
		|| x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, sprite,
		x + game->g_offset.x, y + game->g_offset.y);
}
