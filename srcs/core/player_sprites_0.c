/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprites_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:04:22 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/03 21:06:33 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
