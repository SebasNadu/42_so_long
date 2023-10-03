/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:20:04 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/03 23:20:09 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	gate_action(t_game *game)
{
	static int	anim_intv;

	if (game->c_num == 0 && anim_intv == 200)
	{
		ft_printf("You win!\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (game->c_num == 0)
	{
		game->won = true;
		show_final_screen(game);
		anim_intv++;
	}
}

int	*get_gate_sprite(t_game *game)
{
	static int	position;
	static int	anim_intv;

	if (anim_intv == 12)
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
