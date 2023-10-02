/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:24:07 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/01 21:13:24 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_jump(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((p->ac[0] == 10 || p->ac[1] == 10) && p->jump_state == 0
		&& get_player_g_distance(game) < 15 && p->jump_count < 2)
	{
		if (((p->last_ac[0] == 0 && p->last_ac[1] == 0) || (p->last_ac[0] != 10
					&& p->last_ac[1] == 0)) && p->jump_count < 2)
		{
			p->jump_state = 8;
			p->jump_count++;
		}
	}
	if (p->jump_state > 0 && p->diagonal_dir == 0)
	{
		p->pos.y -= get_player_j_distance(game);
		p->jump_state--;
	}
}

void	player_gravity(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((p->ac[0] != 4) && p->jump_state == 0)
		p->pos.y += get_player_g_distance(game);
	if (get_player_g_distance(game) == 0)
		p->jump_count = 0;
}

void	player_move_x(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == 2)
		p->pos.x += get_player_r_distance(game);
	else if (p->ac[0] == 1)
		p->pos.x -= get_player_l_distance(game);
}

void	player_move_y(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == 3)
		p->pos.y -= get_player_j_distance(game);
	else if (p->ac[0] == 4)
		p->pos.y += get_player_d_distance(game);
}

void	player_move_d(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((((p->ac[0] == 10 && p->ac[1] == 1) || (p->ac[0] == 1 && p->ac[1] == 10)
			) || ((p->ac[0] == 10 && p->ac[1] == 2) || \
		(p->ac[0] == 2 && p->ac[1] == 10))) && get_player_g_distance(game) == 0)
	{
		p->jump_state = 7;
		if (p->ac[1] == 1)
			p->diagonal_dir = 1;
		else if (p->ac[1] == 2)
			p->diagonal_dir = 2;
	}
	if (p->jump_state > 0 && p->diagonal_dir > 0)
	{
		p->pos.y -= get_player_j_distance(game);
		if (p->diagonal_dir == 2)
			p->pos.x += get_player_r_distance(game);
		else if (p->diagonal_dir == 1)
			p->pos.x -= get_player_l_distance(game);
		p->jump_state--;
		if (p->jump_state == 0)
			p->diagonal_dir = 0;
	}
}
