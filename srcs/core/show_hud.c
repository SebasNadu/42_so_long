/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:04:15 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/03 22:50:29 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_lifes(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->player->life_num)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[7],
			HUD_LM + 167 + (i * 35), 10);
		i++;
	}
	while (i < LIFE_NUM)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[8],
			HUD_LM + 167 + (i * 35), 10);
		i++;
	}
}

void	show_movements(t_game *game)
{
	char	*num_movements;

	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[6],
		HUD_LM + 20, 17);
	num_movements = ft_itoa(game->mvts_num);
	mlx_string_put(game->mlx, game->win, HUD_LM + 60, 35, 0xFFFFFF,
		num_movements);
	free(num_movements);
}

void	show_kills(t_game *game)
{
	char	*num_kills;

	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[11],
		HUD_LM + 100, 17);
	num_kills = ft_itoa(game->player->kills_count);
	mlx_string_put(game->mlx, game->win, HUD_LM + 140, 35, 0xFFFFFF,
		num_kills);
	free(num_kills);
}

void	show_hud(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[5],
		HUD_LM + 10, 10);
	show_movements(game);
	show_lifes(game);
	show_kills(game);
}
