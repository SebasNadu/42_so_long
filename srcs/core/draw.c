/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:47:49 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 11:48:00 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_block(int x, int y, void *sprite, t_game *game)
{
	if (x < -BPX || y < -BPX
		|| x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, sprite,
		x + game->g_offset.x, y + game->g_offset.y);
}
