/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:27:56 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 17:24:08 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_position(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->t_l.x = player->pos.x;
	player->t_l.y = player->pos.y;
	player->t_r.x = player->t_l.x;
	player->t_r.y = player->t_l.y + BPX;
	player->b_l.x = player->t_l.x + BPX;
	player->b_l.y = player->t_l.y;
	player->b_r.x = player->t_l.x + BPX;
	player->b_r.y = player->t_l.y + BPX;
}
