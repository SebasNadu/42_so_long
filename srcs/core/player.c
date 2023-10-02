/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:27:56 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/02 23:24:20 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	player_move_x(game);
	player_move_y(game);
	player_move_d(game);
	player_count_mvts(game);
	player_draw(game);
	game->player->last_ac[0] = game->player->ac[0];
	game->player->last_ac[1] = game->player->ac[1];
	game->player->last_ac[2] = game->player->ac[2];
}

void	player_position(t_game *game)
{
	t_player	*p;
	int			p_w;
	int			p_h;

	p_h = 100;
	p_w = 100;
	p = game->player;
	if ((game->map[(p->t_r.y - HPX) / BPX][(p->t_r.x + HPX) / BPX] == '1')
		|| (game->map[(p->b_r.y - HPX) / BPX][(p->b_r.x - HPX) / BPX] == '1'))
	{
		p->pos.y -= 5;
		p->pos.x += 5;
	}
	p->t_l.x = p->pos.x + ((200 - p_w) / 2);
	p->t_l.y = p->pos.y + ((200 - p_h) / 2);
	p->t_r.x = p->t_l.x;
	p->t_r.y = p->t_l.y + p_h;
	p->b_l.x = p->t_l.x + p_w;
	p->b_l.y = p->t_l.y;
	p->b_r.x = p->t_l.x + p_w;
	p->b_r.y = p->t_l.y + p_h;
}
