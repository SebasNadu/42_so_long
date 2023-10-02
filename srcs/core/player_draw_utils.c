/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:05:29 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/02 23:31:49 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_double_jump_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 1 && game->player->jump_state > 1)
			i = 68;
		else if ((i > 67 && i < 75) && game->player->jump_state <= 1)
			i++;
		else if (game->player->jump_state <= 1)
			i = 75;
	}
	else
	{
		if (*last_anim != 1 && game->player->jump_state > 1)
			i = 162;
		else if ((i > 161 && i < 169) && game->player->jump_state <= 1)
			i++;
		else if (game->player->jump_state <= 1)
			i = 169;
	}
	*last_anim = 1;
	return (i);
}

int	player_jump_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 1 && game->player->jump_state > 1)
			i = 46;
		else if ((i > 45 && i < 51) && game->player->jump_state <= 1)
			i++;
		else if (game->player->jump_state <= 1)
			i = 51;
	}
	else
	{
		if (*last_anim != 1 && game->player->jump_state > 1)
			i = 140;
		else if ((i > 139 && i < 145) && game->player->jump_state <= 1)
			i++;
		else if (game->player->jump_state <= 1)
			i = 145;
	}
	*last_anim = 1;
	return (i);
}

int	player_attack_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 2)
			i = 24;
		else if (i > 23 && i < 45)
			i++;
		else
			i = 24;
	}
	else
	{
		if (*last_anim != 2)
			i = 118;
		else if (i > 117 && i < 139)
			i++;
		else
			i = 118;
	}
	*last_anim = 2;
	return (i);
}

int	player_hurt_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 6)
			i = 10;
		else if (i > 9 && i < 11)
			i++;
		else
			i = 10;
	}
	else
	{
		if (*last_anim != 6)
			i = 104;
		else if (i > 103 && i < 105)
			i++;
		else
			i = 104;
	}
	*last_anim = 6;
	return (i);
}

int	player_walk_sprite(int	*last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 3)
			i = 13;
		else if (i > 12 && i < 20)
			i++;
		else
			i = 13;
	}
	else
	{
		if (*last_anim != 3)
			i = 107;
		else if (i > 106 && i < 114)
			i++;
		else
			i = 107;
	}
	*last_anim = 3;
	return (i);
}

int	player_down_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 4)
			i = 76;
		else if (i > 75 && i < 83)
			i++;
		else
			i = 78;
	}
	else
	{
		if (*last_anim != 4)
			i = 170;
		else if (i > 169 && i < 177)
			i++;
		else
			i = 172;
	}
	*last_anim = 4;
	return (i);
}

int	player_fall_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 5)
			i = 52;
		else if (i > 51 && i < 57)
			i++;
		else
			i = 56;
	}
	else
	{
		if (*last_anim != 5)
			i = 146;
		else if (i > 145 && i < 151)
			i++;
		else
			i = 150;
	}
	*last_anim = 5;
	return (i);
}

int	player_stay_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 7)
			i = 0;
		else if (i > -1 && i < 9)
			i++;
		else
			i = 0;
	}
	else
	{
		if (*last_anim != 7)
			i = 94;
		else if (i > 93 && i < 103)
			i++;
		else
			i = 94;
	}
	*last_anim = 7;
	return (i);
}

int	player_sprite_pos(int atk_progress, int hurt_progress,
					int *last_anim, t_game *game)
{
	if (game->player->jump_state != 0 && game->player->jump_count <= 2)
		return (player_double_jump_sprite(last_anim, game));
	else if (game->player->jump_state != 0 && game->player->jump_count <= 1)
		return (player_jump_sprite(last_anim, game));
	else if (atk_progress > 0)
		return (player_attack_sprite(last_anim, game));
	else if (hurt_progress > 0)
		return (player_hurt_sprite(last_anim, game));
	else if (game->player->ac[0] == 2 || game->player->ac[1] == 2 || \
			game->player->ac[0] == 1 || game->player->ac[1] == 1)
		return (player_walk_sprite(last_anim, game));
	else if ((game->player->ac[0] == 4 || game->player->ac[1] == 4) && \
			get_player_g_distance(game) >= 0)
		return (player_down_sprite(last_anim, game));
	else if (game->player->jump_state == 0 && get_player_g_distance(game) > 0)
		return (player_fall_sprite(last_anim, game));
	else
		return (player_stay_sprite(last_anim, game));
}

int	*get_player_sprite(t_game *game)
{
	static int	position;
	static int	anim_intv;
	static int	last_anim;
	static int	atk_progress;
	static int	hurt_progress;

	if (game->player->ac[2] == 5)
		atk_progress = 2;
	if (game->player->life_state == 1)
		hurt_progress = 2;
	if (anim_intv == 2)
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
