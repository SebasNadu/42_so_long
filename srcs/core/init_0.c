/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:05:21 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/24 21:12:29 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_camera(t_game *game)
{
	game->g_offset.x = 0;
	game->g_offset.y = 0;
	if (game->g_len.x < 15)
		game->g_offset.x = (14 - game->g_len.x) / 2 * BPX + 25;
	if (game->g_len.y < 8)
		game->g_offset.y = (7 - game->g_len.y) / 2 * BPX + 25;
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player->life_state = 50;
	game->player->life_num = LIFE_NUM;
	game->player->direction = right;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player->pos.x = j * BPX;
				game->player->pos.y = i * BPX - 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_sprites(t_game *game)
{
	load_sprite("luke", luke_n, luke_t, game);
	load_sprite("storm", storm_n, storm_t, game);
	load_sprite("coin", coin_n, coin_t, game);
	load_sprite("gate", gate_n, gate_t, game);
	load_sprite("misc", misc_n, misc_t, game);
	load_sprite("bg", bg_n, bg_t, game);
}

void	init_map(int argc, char *argv[], t_game *game)
{
	if (!check_args(argc, argv))
		sl_error(game, inv_args);
	if (!open_map(argv[1], game))
		sl_error(game, inv_map);
	if (!read_map(game))
		sl_error(game, inv_map_form);
	if (!set_map(game))
		sl_error(game, inv_map_form);
	if (!check_map_len(game))
		sl_error(game, inv_map_form);
	if (!check_map_chars(game))
		sl_error(game, inv_map_form);
	if (!check_map_walls(game))
		sl_error(game, inv_map_form);
	if (!check_map_requisites(game))
		sl_error(game, inv_map_form);
}

void	init_game(char *argv[], t_game *game)
{
	game->mlx = mlx_init();
	game->updated_at = 0;
	game->g_len.x = -1;
	game->g_len.y = -1;
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		exit(EXIT_FAILURE);
	game->player->jump_state = 0;
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	game->p_offset.x = 0;
	game->p_offset.y = 0;
	game->mvts_num = 0;
	game->lst_map = NULL;
	game->enemies = NULL;
	game->map = NULL;
	if (argv[2] && ft_strncmp(argv[2], "DEBUG=1", 7) == 0)
		game->debug = true;
	else
		game->debug = false;
}
