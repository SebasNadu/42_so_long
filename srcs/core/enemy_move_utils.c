/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:14:03 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/02 18:11:59 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	is_collision(char c, int type)
{
	if (type == 1)
	{
		if (c == '1')
			return (true);
		else
			return (false);
	}
	else
	{
		if (c == '0')
			return (true);
		else if (c == '*')
			return (true);
		else if (c == 'C')
			return (true);
		else if (c == 'M')
			return (true);
		else if (c == 'E')
			return (true);
		else
			return (false);
	}
}

int	get_enemy_r_distance(t_enemy *enemy, t_game *game)
{
	int		dist_collision;
	t_enemy	*e;

	e = enemy;
	if (is_collision(game->map[e->b_l.y / BPX][(e->b_l.x / BPX) + 1], 1))
	{
		if (is_collision(game->map[e->b_l.y / BPX][e->b_l.x / BPX], 1))
			return (0);
		dist_collision = BPX + ((BPX * (e->b_l.x / BPX)) - e->b_l.x) - 1;
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	else if (is_collision(game->map[(e->b_l.y / BPX) + 1][(e->b_r.x / BPX) + 1],
		0))
	{
		if (is_collision(game->map[(e->b_l.y / BPX) + 1][e->b_r.x / BPX], 0))
			return (0);
		dist_collision = BPX + ((BPX * (e->b_l.x / BPX) - e->b_l.x)) - 1;
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	return (MPX);
}

int	get_enemy_l_distance(t_enemy *enemy, t_game *game)
{
	int		dist_collision;
	t_enemy	*e;

	e = enemy;
	if (is_collision(game->map[e->t_l.y / BPX][(e->t_l.x / BPX) - 1], 1))
	{
		dist_collision = e->t_l.x - (BPX * (e->t_l.x / BPX));
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	else if (is_collision(game->map[(e->t_l.y / BPX) + 1][(e->t_l.x / BPX) - 1],
		0))
	{
		dist_collision = e->t_l.x - (BPX * (e->t_l.x / BPX));
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	return (MPX);
}

void	enemy_move_dir(t_enemy *e, t_game *game)
{
	int	dist;

	if (e->mv_intv > 4)
	{
		e->mv_intv = 0;
		if (e->direction == left)
		{
			dist = get_enemy_l_distance(e, game);
			e->pos.x = e->pos.x - dist;
			if (e->pos.x < e->init_pos.x - (BPX * 2) || dist == 0)
				e->direction = right;
		}
		else
		{
			dist = get_enemy_r_distance(e, game);
			e->pos.x = e->pos.x + dist;
			if (e->pos.x > e->init_pos.x + (BPX * 2) || dist == 0)
				e->direction = left;
		}
	}
	e->mv_intv++;
}
