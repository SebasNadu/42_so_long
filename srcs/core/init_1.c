/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:46:44 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:40:31 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_hooks(t_game *game)
{
	if (ft_strncmp(OS, "linux", 5) == 0)
	{
		mlx_hook(game->win, X_EVENT_DESTROY, 1L << 0, close_hook, game);
		mlx_hook(game->win, X_EVENT_KEYPRESS, 1L << 0, keydown_hook, game);
		mlx_hook(game->win, X_EVENT_KEYRELEASE, 1L << 1, keyup_hook, game);
	}
	else if (ft_strncmp(OS, "macos", 5) == 0)
	{
		mlx_hook(game->win, X_EVENT_DESTROY, 1L << 17, close_hook, game);
		mlx_hook(game->win, X_EVENT_KEYPRESS, 0L, keydown_hook, game);
		mlx_key_hook(game->win, keyup_hook, game);
	}
}

static void	create_enemy(int i, int j, t_game *game)
{
	t_enemy	*enemy;

	enemy = ft_calloc(1, sizeof(t_enemy));
	if (!enemy)
		exit(EXIT_FAILURE);
	enemy->pos.x = j * BPX;
	enemy->pos.y = i * BPX - 1;
	enemy->init_pos.x = enemy->pos.x;
	enemy->init_pos.y = enemy->pos.y;
	enemy->is_alive = true;
	enemy->is_moving = true;
	enemy->direction = left;
	enemy->anim_intv = 0;
	enemy->death_state = 0;
	enemy->life_state = 50;
	if (game->enemies == NULL)
		game->enemies = ft_lstnew(enemy);
	else
		ft_lstadd_back(&game->enemies, ft_lstnew(enemy));
}

void	init_enemies(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->g_len.y)
	{
		j = 0;
		while (j < game->g_len.x)
		{
			if (game->map[i][j] == 'M')
				create_enemy(i, j, game);
			j++;
		}
		i++;
	}
}
