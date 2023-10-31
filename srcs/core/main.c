/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:18:26 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/31 20:00:26 by sebas_nadu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
		items(game);
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
	free_game(&game);
	exit(EXIT_SUCCESS);
	return (0);
}
