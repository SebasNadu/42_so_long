/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:59:51 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:42:24 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	show_fps(t_game *game)
{
	char	*debug_msg;
	char	*fps;

	fps = ft_itoa(game->fps);
	debug_msg = ft_strjoin("FPS: ", fps);
	mlx_string_put(game->mlx, game->win, 20, 30, 0XA7DD0D, debug_msg);
	free(fps);
	free(debug_msg);
}

static char	*get_action(int action)
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

static void	show_action(t_game *game)
{
	char		*debug_msg[4];
	t_player	*p;

	p = game->player;
	debug_msg[0] = ft_strjoin("MV ACTION 1: ", get_action(p->ac[0]));
	debug_msg[1] = ft_strjoin("MV ACTION 2: ", get_action(p->ac[1]));
	debug_msg[2] = ft_strjoin("ATK ACTION 1: ", get_action(p->ac[2]));
	mlx_string_put(game->mlx, game->win, 20, 53, 0XA7DD0D, debug_msg[0]);
	mlx_string_put(game->mlx, game->win, 20, 73, 0XA7DD0D, debug_msg[1]);
	mlx_string_put(game->mlx, game->win, 20, 93, 0XA7DD0D, debug_msg[2]);
	free(debug_msg[0]);
	free(debug_msg[1]);
	free(debug_msg[2]);
}

void	show_debug(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[4],
		10, 10);
	show_fps(game);
	show_action(game);
}
