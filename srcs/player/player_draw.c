/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:05:29 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:42:00 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	player_sprite_pos2(int atk_p, int hurt_p, int *last_anim, t_game *game)
{
	(void)hurt_p; 
	if (((game->player->ac[0] == k_r && game->player->ac[1] == k_d) 
			|| (game->player->ac[0] == k_l && game->player->ac[1] == k_d))
		&& get_pg_dist(game) == 0) 
		return (player_slide_sprite(last_anim, game));
	else if ((game->player->ac[0] == k_r || game->player->ac[1] == k_r
			|| game->player->ac[0] == k_l || game->player->ac[1] == k_l)
		&& get_pg_dist(game) == 0)
		return (player_walk_sprite(last_anim, game));
	else if ((game->player->ac[0] == k_d || game->player->ac[1] == k_d)
		&& get_pg_dist(game) >= 0 && atk_p > 0)
		return (player_attack_down_sprite(last_anim, game));
	else if ((game->player->ac[0] == k_d || game->player->ac[1] == k_d)
		&& get_pg_dist(game) >= 0)
		return (player_down_sprite(last_anim, game));
	else if (game->player->jump_state == 0 && get_pg_dist(game) > 0)
		return (player_fall_sprite(last_anim, game));
	else
		return (player_stay_sprite(last_anim, game));
}

int	player_sprite_pos(int atk_p, int hurt_p, int *last_anim, t_game *game)
{
	if (game->lose == true || game->won == true)
		return (player_end_sprite(game));
	else if (get_pg_dist(game) > 0 && game->player->jump_count == 1
		&& atk_p == 0)
		return (player_double_jump_sprite(last_anim, game));
	else if (game->player->jump_state != 0 && game->player->jump_count == 0)
		return (player_jump_sprite(last_anim, game));
	else if (atk_p > 0 && game->player->ac[0] != k_d && get_pg_dist(game) > 0)
		return (player_jump_attack_sprite(last_anim, game));
	else if (atk_p > 0 && game->player->ac[0] != k_d) 
		return (player_attack_sprite(last_anim, game));
	else if (hurt_p > 0)
		return (player_hurt_sprite(last_anim, game));
	else
		return (player_sprite_pos2(atk_p, hurt_p, last_anim, game));
}

int	*get_player_sprite(t_game *game)
{
	static int	position;
	static int	anim_intv;
	static int	last_anim;
	static int	atk_progress;
	static int	hurt_progress;

	if (game->player->ac[2] == 5)
		atk_progress = 5;
	if (game->player->life_state == 1)
		hurt_progress = 5;
	if (anim_intv == 3)
	{
		anim_intv = 0;
		if (atk_progress > 0)
			atk_progress--;
		if (hurt_progress > 0)
			hurt_progress--;
		position = player_sprite_pos(atk_progress, hurt_progress,
				&last_anim, game);
	}
	else
		anim_intv++;
	return (game->sprites.luke[position]);
}
