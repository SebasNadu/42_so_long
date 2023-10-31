/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_final_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:03:54 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/31 20:35:30 by sebas_nadu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	show_final_screen(t_game *game)
{
	char		*msg;
	char		*count;
	int			bg_position;

	if (game->won == true)
		bg_position = 10;
	else
		bg_position = 9;
	mlx_put_image_to_window(game->mlx, game->win,
		game->sprites.misc[bg_position], 0, 0);
	count = ft_itoa(game->player->kills_count);
	msg = ft_strjoin("kills count: ", count);
	mlx_string_put(game->mlx, game->win, (WIN_WIDTH / 2) - 64,
		WIN_HEIGHT - 165, 0xFFFFFF, msg);
	free(count);
	free(msg);
	count = ft_itoa(game->mvts_num);
	msg = ft_strjoin("movements count: ", count);
	mlx_string_put(game->mlx, game->win, (WIN_WIDTH / 2) - 64,
		WIN_HEIGHT - 140, 0xFFFFFF, msg);
	free(count);
	free(msg);
}
