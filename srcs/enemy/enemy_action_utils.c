/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_action_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:22:04 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/11/03 18:13:19 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	enemy_player_action(t_enemy *e, t_game *game)
{
	if (game->player->t_l.x > e->t_l.x)
		game->player->direction = left;
	else
		game->player->direction = right;
	if (e->life_state > 0)
		e->life_state--;
	else if (e->is_alive == true)
	{
		game->player->life_state = 50;
		e->death_state = 12;
		e->is_alive = false;
		game->player->kills_count++;
	}
}

void	lose_action(t_game *game)
{
	static int	anim_intv;

	if (game->player->life_num < 1 && anim_intv == 50)
	{
		ft_printf("\033[0;91mYou lose.\n\033[0;39m");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (game->player->life_num < 1)
	{
		game->lose = true;
		show_final_screen(game);
		anim_intv++;
	}
}

void	enemy_action(t_enemy *e, t_game *game)
{
	e->is_moving = false;
	game->player->life_state--;
	if (e->attack_state == 0)
		e->attack_state = 50;
	if (e->attack_state > 0)
		e->attack_state--;
	if (e->death_state > 0)
		e->death_state--;
	if (game->player->life_num < 1)
		lose_action(game);
	if (game->player->life_state < 1)
	{
		ft_printf("\033[0;93mYou loose 1 life!\n\033[0;39m");
		game->player->life_state = 50;
		game->player->life_num--;
		e->attack_state = 50;
	}
	else if (game->player->ac[2] == 5)
		enemy_player_action(e, game);
}
