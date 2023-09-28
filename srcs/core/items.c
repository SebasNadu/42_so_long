/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:32:40 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/28 12:15:29 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	item_action(t_game *game)
{
	game->c_num--;
}

static void	item_collision(t_game *game)
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

static int	*get_item_sprite(t_game *game)
{
	static int	position;
	static int	anim_intv;

	if (anim_intv >= ANIM_INTV)
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

static void	draw_item(t_game *game)
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

void	items(t_game *game)
{
	draw_item(game);
	item_collision(game);
}
