/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_draw_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:48:30 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:41:10 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	enemy_death_sprite(t_enemy *e)
{
	if (e->last_anim != 3)
		e->anim_pos = 0;
	e->last_anim = 3;
	if (e->anim_pos > 51 && e->anim_pos < 60)
		e->anim_pos++;
	else
		e->anim_pos = 52;
	return (e->anim_pos);
}

int	enemy_attack_sprite(t_enemy *e)
{
	if (e->last_anim != 2)
		e->anim_pos = 0;
	e->last_anim = 2;
	if (e->direction == left)
	{
		if (e->anim_pos > 5 && e->anim_pos < 28)
			e->anim_pos++;
		else
			e->anim_pos = 6;
	}
	else
	{
		if (e->anim_pos > 28 && e->anim_pos < 51)
			e->anim_pos++;
		else
			e->anim_pos = 29;
	}
	return (e->anim_pos);
}

int	enemy_move_sprite(t_enemy *e)
{
	if (e->last_anim != 1)
		e->anim_pos = 0;
	e->last_anim = 1;
	if (e->anim_pos > -1 && e->anim_pos < 5)
		e->anim_pos++;
	else
		e->anim_pos = 0;
	return (e->anim_pos);
}

void	enemy_sprite_pos(t_enemy *e)
{
	if (e->death_state > 0)
		enemy_death_sprite(e);
	else if (e->attack_state > 0)
		enemy_attack_sprite(e);
	else
		enemy_move_sprite(e);
}

int	*get_enemy_sprite(t_enemy *e, t_game *game)
{
	if (e->anim_intv == 2)
	{
		e->anim_intv = 0;
		enemy_sprite_pos(e);
	}
	else
		e->anim_intv++;
	return (game->sprites.strom[e->anim_pos]);
}
