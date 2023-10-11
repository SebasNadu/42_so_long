/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:24:07 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:42:03 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_jump(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((p->ac[0] == k_u || p->ac[1] == k_u) && p->jump_state == 0
		&& get_pg_dist(game) < 15 && p->jump_count < 1)
	{
		if (((p->last_ac[0] == k_n && p->last_ac[1] == k_n) || \
		(p->last_ac[0] != k_u && p->last_ac[1] == k_n)) && p->jump_count < 1)
		{
			p->jump_state = 8;
			p->jump_count++;
		}
	}
	if (p->jump_state > 0 && p->diagonal_dir == 0)
	{
		p->pos.y -= get_pj_dist(game);
		p->jump_state--;
	}
}

void	player_gravity(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((p->ac[0] != k_d) && p->jump_state == 0)
		p->pos.y += get_pg_dist(game);
	if (get_pg_dist(game) == 0)
		p->jump_count = 0;
}

void	player_move_x(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == k_r)
		p->pos.x += get_pr_dist(game);
	else if (p->ac[0] == k_l)
		p->pos.x -= get_pl_dist(game);
}

void	player_move_y(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == 10)
		p->pos.y -= get_pj_dist(game);
	else if (p->ac[0] == k_d)
		p->pos.y += get_pd_dist(game);
}

void	player_move_d(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((((p->ac[0] == k_u && p->ac[1] == k_l) || \
		(p->ac[0] == k_l && p->ac[1] == k_u)) || \
		((p->ac[0] == k_u && p->ac[1] == k_r) || \
		(p->ac[0] == k_r && p->ac[1] == k_u))) && get_pg_dist(game) == 0)
	{
		p->jump_state = 7;
		if (p->ac[1] == k_l)
			p->diagonal_dir = 1;
		else if (p->ac[1] == k_r)
			p->diagonal_dir = 2;
	}
	if (p->jump_state > 0 && p->diagonal_dir > 0)
	{
		p->pos.y -= get_pj_dist(game);
		if (p->diagonal_dir == 2)
			p->pos.x += get_pr_dist(game);
		else if (p->diagonal_dir == 1)
			p->pos.x -= get_pl_dist(game);
		p->jump_state--;
		if (p->jump_state == 0)
			p->diagonal_dir = 0;
	}
}
