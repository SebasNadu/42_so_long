/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:27:56 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/27 22:46:26 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_position(t_game *game)
{
	t_player	*player;
	int			player_w;
	int			player_h;

	player_w = 55;
	player_h = 110;
	player = game->player;
	player->t_l.x = player->pos.x + (200 - player_w) / 2;
	player->t_l.y = player->pos.y + (200 - player_h) / 2;
	player->t_r.x = player->t_l.x;
	player->t_r.y = player->t_l.y + player_h;
	player->b_l.x = player->t_l.x + player_w;
	player->b_l.y = player->t_l.y;
	player->b_r.x = player->t_l.x + player_w;
	player->b_r.y = player->t_l.y + player_h;
}
