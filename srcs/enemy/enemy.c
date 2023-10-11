/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:13:04 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:41:00 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_enemy(t_game *game)
{
	t_list	*lst;
	t_enemy	*e;

	lst = game->enemies;
	while (lst)
	{
		e = (t_enemy *)lst->content;
		if (e->is_alive == true || e->death_state > 0)
			draw_block(e->pos.x + game->p_offset.x,
				e->pos.y + game->p_offset.y, get_enemy_sprite(e, game), game);
		lst = lst->next;
	}
}

void	enemy_interaction(t_player *p, t_game *game)
{
	t_list		*lst;
	t_enemy		*e;

	lst = game->enemies;
	while (lst)
	{
		e = (t_enemy *)lst->content;
		if ((((p->t_l.x > e->t_l.x && p->t_l.x < e->b_l.x)
					|| (p->b_l.x > e->t_l.x && p->b_l.x < e->b_l.x))
				&& p->t_l.y < e->t_r.y && p->t_r.y > e->t_l.y)
			&& (e->is_alive == true || e->death_state > 0))
		{
			if (e->t_l.x > p->t_l.x)
				e->direction = left;
			else
				e->direction = right;
			enemy_action(e, game);
		}
		else
		{
			e->is_moving = true;
			e->attack_state = 0;
		}
		lst = lst->next;
	}
}

void	enemy_position(t_enemy *e, t_game *game)
{
	int			e_w;
	int			e_h;

	e_w = 100;
	e_h = 100;
	e->t_l.x = e->pos.x + ((200 - e_w) / 2);
	e->t_l.y = e->pos.y + ((200 - e_h) / 2);
	e->t_r.x = e->t_l.x;
	e->t_r.y = e->t_l.y + e_h; 
	e->b_l.x = e->t_l.x + e_w;
	e->b_l.y = e->t_l.y;
	e->b_r.x = e->t_l.x + e_w;
	e->b_r.y = e->t_l.y + e_h; 
	if ((game->map[(e->t_r.y - HPX) / BPX][(e->t_r.x + HPX) / BPX] == '1')
		|| (game->map[(e->b_r.y - HPX) / BPX][(e->b_r.x - HPX) / BPX] == '1'))
	{
		e->pos.y -= 5;
		e->pos.x += 5;
	}
}

void	enemy_move(t_game *game)
{
	t_list	*lst;
	t_enemy	*e;

	lst = game->enemies;
	while (lst)
	{
		e = ((t_enemy *)lst->content);
		enemy_position(e, game);
		if (e->is_moving == true)
			enemy_move_dir(e, game);
		lst = lst->next;
	}
}

void	enemy(t_game *game)
{
	enemy_move(game);
	enemy_interaction(game->player, game);
	draw_enemy(game);
}
