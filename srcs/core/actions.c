/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:28:31 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/24 21:28:52 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_action_keycode(int keycode)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
		return (1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		return (2);
	else if (keycode == KEY_W || keycode == KEY_UP)
		return (3);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		return (4);
	else if (keycode == KEY_SPACE)
		return (5);
	return (0);
}

void	set_action(int keycode, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (get_action_keycode(keycode) != 5)
	{
		if (player->ac[0] == 0 || player->ac[0]
			== get_action_keycode(keycode))
			player->ac[0] = get_action_keycode(keycode);
		else if (player->ac[1] == 0 || player->ac[1]
			== get_action_keycode(keycode))
			player->ac[1] = get_action_keycode(keycode);
	}
	else
		player->ac[2] = get_action_keycode(keycode);
	if (player->ac[0] == 1 || player->ac[1] == 1)
		player->direction = left;
	else if (player->ac[0] == 2 || player->ac[1] == 2)
		player->direction = right;
}

void	unset_action(int keycode, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (player->ac[0] == get_action_keycode(keycode))
		player->ac[0] = 0;
	if (player->ac[1] == get_action_keycode(keycode))
		player->ac[1] = 0;
	if (player->ac[0] == 0 && player->ac[1] != 0)
	{
		player->ac[0] = player->ac[1];
		player->ac[1] = 0;
	}
	if (player->ac[2] == get_action_keycode(keycode))
		player->ac[2] = 0;
}
