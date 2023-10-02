/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:18:26 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/01 20:13:09 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

void	show_hud(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.misc[5],
		HUD_LM + 10, 10);
	show_movements(game);
	show_lifes(game);
}

void	show_fps(t_game *game)
{
	char	*debug_msg;
	char	*fps;

	fps = ft_itoa(game->fps);
	debug_msg = ft_strjoin("FPS: ", fps);
	mlx_string_put(game->mlx, game->win, 20, 30, 11001101, debug_msg);
	free(fps);
	free(debug_msg);
}

char	*get_action(int action)
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

void	show_action(t_game *game)
{
	char		*debug_msg[4];
	t_player	*p;

	p = game->player;
	debug_msg[0] = ft_strjoin("MV ACTION 1: ", get_action(p->ac[0]));
	debug_msg[1] = ft_strjoin("MV ACTION 2: ", get_action(p->ac[1]));
	debug_msg[2] = ft_strjoin("ATK ACTION 1: ", get_action(p->ac[2]));
	mlx_string_put(game->mlx, game->win, 20, 53, 11001101, debug_msg[0]);
	mlx_string_put(game->mlx, game->win, 20, 73, 11001101, debug_msg[1]);
	mlx_string_put(game->mlx, game->win, 20, 93, 11001101, debug_msg[2]);
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

int	render_next_frame(t_game *game)
{
	long long	now;
	long long	diff;

	now = get_millitimestamp();
	diff = now - game->updated_at;
	if (diff > 15)
	{
		// ft_printf("ac[0]: %d\n", game->player->ac[0]);
		// ft_printf("ac[1]: %d\n", game->player->ac[1]);
		// ft_printf("ac[2]: %d\n", game->player->ac[2]);
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
	exit(EXIT_SUCCESS);
	return (0);
}
