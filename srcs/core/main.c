/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:18:26 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 17:39:28 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	item_action(t_game *game)
{
	game->c_num--;
}

void	item_collision(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (game->map[(p->t_l.y + HPX) / BPX][(p->t_l.x + HPX) / BPX] == 'C')
	{
		game->map[(p->t_l.y + HPX) / BPX][(p->t_l.x + HPX) / BPX] = '0';
		item_action(game);
	}
	else if (game->map[(p->t_r.y - HPX) / BPX][(p->t_r.x + HPX) / BPX] == 'C')
	{
		game->map[(p->t_r.y + HPX) / BPX][(p->t_r.x + HPX) / BPX] = '0';
		item_action(game);
	}
	else if (game->map[(p->t_l.y + HPX) / BPX][(p->b_l.x - HPX) / BPX] == 'C')
	{
		game->map[(p->t_l.y + HPX) / BPX][(p->b_l.x - HPX) / BPX] = '0';
		item_action(game);
	}
	else if (game->map[(p->b_r.y - HPX) / BPX][(p->b_l.x - HPX) / BPX] == 'C')
	{
		game->map[(p->b_r.y - HPX) / BPX][(p->b_r.x - HPX) / BPX] = '0';
		item_action(game);
	}
}

int	*get_item_sprite(t_game *game)
{
	static int	position;
	static int	anim_intv;

	if (anim_intv >= game->c_num * 5)
	{
		anim_intv = 0;
		if (position < 3)
			position++;
		else
			position = 0;
	}
	else
		anim_intv++;
	return (game->sprites.coin[position]);
}

void	draw_item(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->g_len.y)
	{
		j = 0;
		while (j < game->g_len.x)
		{
			if (game->map[i][j] == 'C')
				draw_block(j * BPX + game->p_offset.x,
					i * BPX + game->p_offset.y,
					get_item_sprite(game), game);
			j++;
		}
		i++;
	}
}

void	item(t_game *game)
{
	draw_item(game);
	item_collision(game);
}

void	gate_action(t_game *game)
{
	if (game->c_num == 0)
	{
		ft_printf("You win!\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
}

int	*get_gate_sprite(t_game *game)
{
	static int	position;
	static int	anim_intv;

	if (anim_intv == 7)
	{
		anim_intv = 0;
		if (position < 2 && game->c_num == 0)
			position++;
	}
	else
		anim_intv++;
	return (game->sprites.gate[position]);
}

void	draw_gate(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->g_len.y)
	{
		j = 0;
		while (j < game->g_len.x)
		{
			if (game->map[i][j] == 'E')
				draw_block(j * BPX + game->p_offset.x,
					i * BPX + game->p_offset.y, get_gate_sprite(game),
					game);
			j++;
		}
		i++;
	}
}

void	gate_collision(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (game->map[(p->t_l.y + HPX) / BPX][(p->t_l.x + HPX) / BPX] == 'E')
		gate_action(game);
	else if (game->map[(p->t_r.y - HPX) / BPX][(p->t_r.x + HPX) / BPX] == 'E')
		gate_action(game);
	else if (game->map[(p->t_l.y + HPX) / BPX][(p->b_l.x - HPX) / BPX] == 'E')
		gate_action(game);
	else if (game->map[(p->b_r.y - HPX) / BPX][(p->b_l.x - HPX) / BPX] == 'E')
		gate_action(game);
}

void	gate(t_game *game)
{
	draw_gate(game);
	gate_collision(game);
}

int	enemy_death_sprite(t_enemy *e)
{
	if (e->last_anim != 3)
		e->anim_pos = 0;
	e->last_anim = 3;
	if (e->anim_pos > 23 && e->anim_pos < 27)
		e->anim_pos++;
	else
		e->anim_pos = 24;
	return (e->anim_pos);
}

int	enemy_attack_sprite(t_enemy *e)
{
	if (e->last_anim != 2)
		e->anim_pos = 0;
	e->last_anim = 2;
	if (e->direction == left)
	{
		if (e->anim_pos > 4 && e->anim_pos < 7)
			e->anim_pos++;
		else
			e->anim_pos = 5;
	}
	else
	{
		if (e->anim_pos > 16 && e->anim_pos < 19)
			e->anim_pos++;
		else
			e->anim_pos = 17;
	}
	return (e->anim_pos);
}

int	enemy_move_sprite(t_enemy *e)
{
	if (e->last_anim != 1)
		e->anim_pos = 0;
	e->last_anim = 1;
	if (e->direction == left)
	{
		if (e->anim_pos > 0 && e->anim_pos < 4)
			e->anim_pos++;
		else
			e->anim_pos = 1;
	}
	else
	{
		if (e->anim_pos > 12 && e->anim_pos < 16)
			e->anim_pos++;
		else
			e->anim_pos = 13;
	}
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
	if (e->anim_intv == 4)
	{
		e->anim_intv = 0;
		enemy_sprite_pos(e);
	}
	else
		e->anim_intv++;
	return (game->sprites.strom[e->anim_pos]);
}

void	draw_enemy(t_game *game)
{
	t_list	*lst;
	t_enemy	*e;

	lst = game->enemies;
	while (lst)
	{
		e = (t_enemy *)lst->content;
		if (e->is_alive == 1 || e->death_state > 0)
			draw_block(e->pos.x + game->p_offset.x,
				e->pos.y + game->p_offset.y, get_enemy_sprite(e, game),
				game);
		lst = lst->next;
	}
}

int	is_collision(char c, int type)
{
	if (type == 1)
	{
		if (c == '1')
			return (1);
		else
			return (0);
	}
	else
	{
		if (c == '0')
			return (1);
		else if (c == '*')
			return (1);
		else if (c == 'C')
			return (1);
		else if (c == 'M')
			return (1);
		else if (c == 'E')
			return (1);
		else
			return (0);
	}
}

int	get_enemy_r_distance(t_enemy *enemy, t_game *game)
{
	int		dist_collision;
	t_enemy	*e;

	e = enemy;
	if (is_collision(game->map[e->b_l.y / BPX][e->b_l.x / BPX + 1], 1))
	{
		if (is_collision(game->map[e->b_l.y / BPX][e->b_l.x / BPX], 1))
			return (0);
		dist_collision = BPX + (BPX * (e->b_l.x / BPX) - e->b_l.x) - 1;
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	else if (is_collision(game->map[e->b_l.y / BPX + 1][e->b_l.x / BPX + 1], 0))
	{
		if (is_collision(game->map[e->b_l.y / BPX + 1][e->b_l.x / BPX], 0))
			return (0);
		dist_collision = BPX + (BPX * (e->b_l.x / BPX) - e->b_l.x) - 1;
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
	if (is_collision(game->map[(e->t_l.y) / BPX][(e->t_l.x) / BPX - 1], 1))
	{
		dist_collision = e->t_l.x - (BPX * ((e->t_l.x) / BPX));
		if (dist_collision > MPX)
			return (MPX);
		return (dist_collision);
	}
	else if (is_collision(game->map[(e->t_l.y) / BPX + 1][(e->t_l.x) / BPX - 1],
		0))
	{
		dist_collision = e->t_l.x - (BPX * ((e->t_l.x) / BPX));
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
			if (e->pos.x > e->init_pos.x - (BPX * 2) || dist == 0)
				e->direction = right;
		}
		else
		{
			dist = get_enemy_r_distance(e, game);
			e->pos.x = e->pos.x + dist;
			if (e->pos.x < e->init_pos.x + (BPX * 2) || dist == 0)
				e->direction = left;
		}
	}
	e->mv_intv++;
}

void	enemy_position(t_enemy *e)
{
	e->t_l.x = e->pos.x;
	e->t_l.y = e->pos.y;
	e->t_r.x = e->pos.x;
	e->t_r.y = e->pos.y + BPX;
	e->b_l.x = e->pos.x + BPX;
	e->b_l.y = e->pos.y;
	e->b_r.x = e->pos.x + BPX;
	e->b_r.y = e->pos.y + BPX;
}

void	enemy_move(t_game *game)
{
	t_list	*lst;
	t_enemy	*e;

	lst = game->enemies;
	while (lst)
	{
		e = ((t_enemy *)lst->content);
		enemy_position(e);
		if (e->is_moving == 1)
			enemy_move_dir(e, game);
		lst = lst->next;
	}
}

void	monster_player_action(t_enemy *e, t_game *game)
{
	if (game->player->t_l.x > e->t_l.x)
		game->player->direction = left;
	else
		game->player->direction = right;
	game->player->life_state = 50;
	e->death_state = 15;
	e->is_alive = 0;
}

void	monster_action(t_enemy *e, t_game *game)
{
	e->is_moving = 0;
	game->player->life_state--;
	if (e->attack_state > 0)
		e->attack_state--;
	if (e->death_state > 0)
		e->death_state--;
	if (game->player->life_num < 1)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_printf("You loose the game!\n");
		exit(EXIT_SUCCESS);
	}
	if (game->player->life_state < 1)
	{
		ft_printf("You loose 1 life!\n");
		game->player->life_state = 50;
		game->player->life_num--;
		e->attack_state = 20;
	}
	else if (game->player->ac[2] == 5)
		monster_player_action(e, game);
}

void	enemy_interaction(t_game *game)
{
	t_list		*lst;
	t_enemy		*e;
	t_player	*p;

	lst = game->enemies;
	while (lst)
	{
		e = (t_enemy *)lst->content;
		p = game->player;
		if ((((p->t_l.x > e->t_l.x && p->t_l.x < e->b_l.x)
					|| (p->b_l.x > e->t_l.x && p->b_l.x < e->b_l.x))
				&& p->t_l.y < e->t_r.y && p->t_r.y > e->t_l.y)
			&& (e->is_alive == 1 || e->death_state > 0))
		{
			if (e->t_l.x > p->t_l.x)
				e->direction = left;
			else
				e->direction = right;
			monster_action(e, game);
		}
		else
			e->is_moving = 1;
		lst = lst->next;
	}
}

void	enemy(t_game *game)
{
	enemy_move(game);
	enemy_interaction(game);
	draw_enemy(game);
}

int	get_player_g_distance(t_game *game)
{
	int			dist_collision;
	t_player	*p;

	p = game->player;
	if (game->map[p->t_r.y / BPX + 1][(p->t_r.x + HPX) / BPX] == '1'
	|| game->map[game->player->b_r.y / BPX + 1][(p->b_r.x - HPX) / BPX] == '1')
	{
		dist_collision = (BPX * (p->t_r.y / BPX + 1)) - p->t_r.y - 1;
		if (dist_collision > GPX)
			return (GPX);
		return (dist_collision);
	}
	return (GPX);
}

int	get_player_j_distance(t_game *game)
{
	int			dist_collision;
	t_player	*p;

	p = game->player;
	if (game->map[(p->t_l.y + 1) / BPX - 1][(p->t_l.x + HPX) / BPX] == '1'
		|| game->map[(p->b_l.y + 1) / BPX -1][(p->b_l.x - HPX) / BPX] == '1')
	{
		dist_collision = p->t_r.y - (BPX * ((p->t_r.y + 1) / BPX)) - 1 + 2;
		if (dist_collision > JPX)
			return (JPX);
		return (dist_collision);
	}
	if (game->map[p->t_l.y / BPX][(p->t_l.x + HPX) / BPX] == '1'
		|| game->map[p->b_l.y / BPX][(p->b_l.x - HPX) / BPX] == '1')
		return (-(HPX));
	return (JPX);
}

void	player_jump(t_game *game)
{
	t_player	*p;

	p = game->player;
	if ((p->ac[0] == 10 || p->ac[1] == 10) && p->jump_state == 0
		&& get_player_g_distance(game) == 0)
		p->jump_state = 10;
	else if (p->jump_state > 0 && p->diagonal_dir == 0)
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
}

int	get_player_r_distance(t_game *game)
{
	int			dist_collision;
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (m[(p->b_l.y + HPX + EHPX) / BPX][p->b_l.x / BPX + 1] == '1'
		|| m[p->b_r.y / BPX][p->b_r.x / BPX + 1] == '1')
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

int	get_player_l_distance(t_game *game)
{
	int			dist_collision;
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (m[(p->t_l.y + HPX + EHPX) / BPX][p->t_l.x / BPX - 1] == '1'
		|| m[p->t_r.y / BPX][p->t_r.x / BPX -1] == '1')
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

void	player_move_y(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == 2)
		p->pos.x += get_player_r_distance(game);
	else if (p->ac[0] == 1)
		p->pos.x -= get_player_l_distance(game);
}

int	get_player_d_distance(t_game *game)
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

void	player_move_z(t_game *game)
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
		p->jump_state = 10;
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

void	player_count_mvts(t_game *game)
{
	if (game->player->last_pos.x != game->player->pos.x)
	{
		game->mvts_num++;
		return ;
	}
	if (game->player->last_pos.y != game->player->pos.y)
	{
		game->mvts_num++;
		return ;
	}
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
	if (game->player->jump_state != 0)
		return (player_jump_sprite(last_anim, game));
	else if (atk_progress > 0)
		return (player_attack_sprite(last_anim, game));
	else if (hurt_progress > 0)
		return (player_hurt_sprite(last_anim, game));
	else if (game->player->ac[0] == 2 || game->player->ac[1] == 2 || \
			game->player->ac[0] == 1 || game->player->ac[1] == 1)
		return (player_walk_sprite(last_anim, game));
	else if ((game->player->ac[0] == 4 || game->player->ac[1] == 4) && \
			get_player_g_distance(game) > 0)
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
		atk_progress = 5;
	if (game->player->life_state == 1)
		hurt_progress = 5;
	if (anim_intv == 5)
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

void	player_draw(t_game *game)
{
	int			screen_pp[2];
	t_player	*p;

	p = game->player;
	screen_pp[1] = p->pos.y + game->p_offset.y;
	screen_pp[0] = p->pos.x + game->p_offset.x;
	if (p->pos.y < (64 * 2))
		game->p_offset.y = 0;
	else if (screen_pp[1] > (512 + 48))
		game->p_offset.y = -p->pos.y + (64 * 8) + 48;
	else if (screen_pp[1] < 128)
		game->p_offset.y = -p->pos.y + (64 * 2);
	if (p->pos.x < (64 * 2))
		game->p_offset.x = 0;
	else if (screen_pp[0] > (1088 + 76))
		game->p_offset.x = -p->pos.x + (64 * 17) + 76;
	else if (screen_pp[0] < 128)
		game->p_offset.x = -p->pos.x + (64 * 2);
	mlx_put_image_to_window(game->mlx, game->win, get_player_sprite(game),
		p->pos.x + game->p_offset.x + game->g_offset.x,
		p->pos.y + game->p_offset.y + game->g_offset.y);
}

void	player(t_game *game)
{
	game->player->last_pos.x = game->player->pos.x;
	game->player->last_pos.y = game->player->pos.y;
	player_jump(game);
	player_gravity(game);
	player_move_y(game);
	player_move_z(game);
	player_move_d(game);
	player_count_mvts(game);
	player_draw(game);
}

void	show_lifes(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->player->life_num)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[9],
			HUD_LM + 167 + (i * 35), 10);
		i++;
	}
	while (i < LIFE_NUM)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[10],
			HUD_LM + 167 + (i * 35), 10);
		i++;
	}
}

void	show_movements(t_game *game)
{
	char	*num_movements;

	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[8],
		HUD_LM + 20, 17);
	num_movements = ft_itoa(game->mvts_num);
	mlx_string_put(game->mlx, game->win, HUD_LM + 60, 35, 0xFFFFFF,
		num_movements);
	free(num_movements);
}

void	show_hud(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[7],
		HUD_LM + 10, 10);
	show_movements(game);
	show_lifes(game);
}

void	show_fps(t_game *game)
{
	char	*debug_msg;
	char	*fps;

	fps = ft_itoa(game->fps);
	debug_msg = ft_strjoin("FPS: ", fps);
	mlx_string_put(game->mlx, game->win, 20, 30, 11001101, debug_msg);
	free(fps);
	free(debug_msg);
}

char	*get_action(int action)
{
	if (action == 1)
		return ("LEFT");
	else if (action == 2)
		return ("RIGHT");
	else if (action == 3)
		return ("UP");
	else if (action == 4)
		return ("DOWN");
	else if (action == 5)
		return ("ATTACK");
	else if (action == 10)
		return ("JUMP");
	else
		return ("NONE");
}

void	show_action(t_game *game)
{
	char		*debug_msg[4];
	t_player	*p;

	p = game->player;
	debug_msg[0] = ft_strjoin("MV ACTION 1: ", get_action(p->ac[0]));
	debug_msg[1] = ft_strjoin("MV ACTION 2: ", get_action(p->ac[1]));
	debug_msg[2] = ft_strjoin("ATK ACTION 1: ", get_action(p->ac[2]));
	mlx_string_put(game->mlx, game->win, 20, 53, 11001101, debug_msg[0]);
	mlx_string_put(game->mlx, game->win, 20, 73, 11001101, debug_msg[1]);
	mlx_string_put(game->mlx, game->win, 20, 93, 11001101, debug_msg[2]);
	free(debug_msg[0]);
	free(debug_msg[1]);
	free(debug_msg[2]);
}

void	show_debug(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[6],
		10, 10);
	show_fps(game);
	show_action(game);
}

int	render_next_frame(t_game *game)
{
	long long	now;
	long long	diff;

	now = get_millitimestamp();
	diff = now - game->updated_at;
	if (diff > 15)
	{
		fps(game);
		mlx_clear_window(game->mlx, game->win);
		player_position(game);
		background(game);
		structure(game);
		item(game);
		gate(game);
		enemy(game);
		player(game);
		if (game->debug)
			show_debug(game);
		show_hud(game);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 3)
		sl_error(&game, inv_args);
	init_game(argv, &game);
	init_map(argc, argv, &game);
	init_sprites(&game);
	init_player(&game);
	init_camera(&game);
	init_enemies(&game);
	init_hooks(&game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
