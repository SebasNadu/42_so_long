/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:17:32 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/31 19:59:35 by sebas_nadu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_hook(int keycode, t_game *game)
{
	(void)keycode;
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keydown_hook(int keycode, t_game *game)
{
	if (game->won == false && game->lose == false)
		set_action(keycode, game);
	return (0);
}

int	keyup_hook(int keycode, t_game *game)
{
	if (keycode != KEY_ESC)
		unset_action(keycode, game);
	else
		close_hook(0, game);
	return (0);
}
