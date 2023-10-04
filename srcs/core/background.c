/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:36:49 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/04 14:36:27 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_background(int x, int y, void *sprite, t_game *game)
{
	if (x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, sprite,
		x + game->g_offset.x, y + game->g_offset.y);
}

static void	draw_sky(t_game *game)
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

void	background(t_game *game)
{
	int	i;
	int	j;
	int	x_offs;
	int	y_offs;

	i = 0;
	j = 1;
	draw_sky(game);
	if (game->g_len.y * BPX < WIN_HEIGHT)
		return ;
	while (++i < bg_n)
	{
		y_offs = (j + (BPX / 2) + game->p_offset.y);
		if (i == 7 || i == 1)
			draw_background(game->g_offset.x, y_offs, game->sprites.bg[i],
				game);
		else if (i == 6)
			draw_background(game->g_offset.x, y_offs + (BPX / 8),
				game->sprites.bg[i], game);
		else
		{
			x_offs = (((j * 400) - (game->player->pos.x)) / (j * 4));
			draw_background(x_offs - 50, y_offs, game->sprites.bg[i], game);
		}
		j++;
	}
}
