/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distances.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:00:20 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/04 18:27:33 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_pd_dist(t_game *game)
{
	int			dist_collision;
	t_player	*p;

	p = game->player;
	if (game->map[p->t_r.y / BPX + 1][(p->t_r.x + HPX) / BPX] == '1'
		|| game->map[p->b_r.y / BPX + 1][(p->b_r.x - MPX) / BPX] == '1')
	{
		dist_collision = (BPX * (p->t_r.y / BPX + 1)) - p->t_r.y - 1;
		if (dist_collision > DPX)
			return (DPX);
		return (dist_collision);
	}
	return (DPX);
}

int	get_pl_dist(t_game *game)
{
	int			dist_collision;
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (m[(p->t_l.y + HPX + EHPX) / BPX][(p->t_l.x / BPX) - 1] == '1'
		|| m[p->t_r.y / BPX][(p->t_r.x / BPX) - 1] == '1')
	{
		if (m[(p->t_l.y + HPX) / BPX][(p->t_l.x + HPX) / BPX] == '1'
			|| m[p->t_r.y / BPX][(p->t_r.x + HPX) / BPX] == '1')
			return (-(HPX + 10));
		dist_collision = p->t_l.x - (BPX * (p->t_l.x / BPX));
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	if (m[(p->t_l.y + HPX + EHPX) / BPX][(p->t_l.x + HPX + EHPX) / BPX] == '1'
		|| m[p->t_r.y / BPX][(p->t_r.x + HPX + EHPX) / BPX] == '1')
		return (-(HPX + EHPX + 5));
	return (MPX);
}

int	get_pr_dist(t_game *game)
{
	int			dist_collision;
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (m[(p->b_l.y + HPX + EHPX) / BPX][(p->b_l.x / BPX) + 1] == '1'
		|| m[p->b_r.y / BPX][(p->b_r.x / BPX) + 1] == '1')
	{
		if (m[(p->b_l.y + HPX) / BPX][(p->b_l.x - HPX) / BPX] == '1'
			|| m[p->b_r.y / BPX][(p->b_r.x - HPX) / BPX] == '1')
			return (-(HPX + 10));
		dist_collision = BPX + (BPX * (p->b_l.x / BPX) - p->b_l.x) - 1;
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	if (m[(p->b_l.y + HPX + EHPX) / BPX][(p->b_l.x - HPX + EHPX) / BPX] == '1'
		|| m[p->b_r.y / BPX][(p->b_r.x - HPX + EHPX) / BPX] == '1')
		return (-(HPX + EHPX + 5));
	return (MPX);
}

int	get_pg_dist(t_game *game)
{
	int			dist_collision;
	t_player	*p;

	p = game->player; 
	if (game->map[(p->t_r.y / BPX) + 1][(p->t_r.x + (HPX + EHPX)) / BPX] == '1'
	|| game->map[(p->b_r.y / BPX) + 1][(p->b_r.x - (HPX + EHPX)) / BPX] == '1')
	{
		dist_collision = (BPX * (p->t_r.y / BPX + 1)) - p->t_r.y - 1;
		if (dist_collision > GPX)
			return (GPX);
		return (dist_collision);
	}
	return (GPX);
}

int	get_pj_dist(t_game *game)
{
	int			dist_collision;
	t_player	*p;

	p = game->player;
	if (game->map[((p->t_l.y + 1) / BPX) - 1][(p->t_l.x + HPX) / BPX] == '1'
		|| game->map[((p->b_l.y + 1) / BPX) - 1][(p->b_l.x - HPX) / BPX] == '1')
	{
		dist_collision = p->t_r.y - (BPX * ((p->t_r.y + 1) / BPX)) - 1 + 2;
		if (dist_collision > JPX)
			return (JPX);
		return (dist_collision);
	}
	if (game->map[p->t_l.y / BPX][(p->t_l.x + HPX) / BPX] == '1'
		|| game->map[p->b_l.y / BPX][(p->b_l.x - HPX) / BPX] == '1')
		return (-HPX);
	return (JPX);
}
