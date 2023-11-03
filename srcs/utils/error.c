/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:06:48 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/11/03 18:05:13 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	destroy_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < luke_n && game->sprites.luke[i])
		mlx_destroy_image(game->mlx, game->sprites.luke[i++]);
	i = 0;
	while (i < storm_n && game->sprites.strom[i])
		mlx_destroy_image(game->mlx, game->sprites.strom[i++]);
	i = 0;
	while (i < coin_n && game->sprites.coin[i])
		mlx_destroy_image(game->mlx, game->sprites.coin[i++]);
	i = 0;
	while (i < gate_n && game->sprites.gate[i])
		mlx_destroy_image(game->mlx, game->sprites.gate[i++]);
	i = 0;
	while (i < misc_n && game->sprites.misc[i])
		mlx_destroy_image(game->mlx, game->sprites.misc[i++]);
	i = 0;
	while (i < bg_n && game->sprites.bg[i])
		mlx_destroy_image(game->mlx, game->sprites.bg[i++]);
}

#ifdef __linux__

void	free_game(t_game *game)
{
	if (game->player)
		free(game->player);
	if (game->lst_map)
		ft_lstclear(&game->lst_map, free);
	if (game->enemies)
		ft_lstclear(&game->enemies, free);
	if (game->map)
		ft_free_matrix(game->map);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

#else

void	free_game(t_game *game)
{
	if (game->player)
		free(game->player);
	if (game->lst_map)
		ft_lstclear(&game->lst_map, free);
	if (game->enemies)
		ft_lstclear(&game->enemies, free);
	if (game->map)
		ft_free_matrix(game->map);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
}

#endif

void	sl_error(t_game *game, int err)
{
	(void)game;
	if (err == inv_args)
		ft_printf_fd(2,
			"\033[0;91mError: You must indicate only one map path!\n\033[0;39m");
	else if (err == inv_map)
		ft_printf_fd(2, "\033[0;91mError: Unable to open the map!\n\033[0;39m");
	else if (err == inv_map_form)
		ft_printf_fd(2,
			"\033[0;91mError: The map is not in a valid format!\n\033[0;39m");
	else if (err == inv_sprite)
		ft_printf_fd(2, "\033[0;91mError: Unable to open the sprite!\n\033[0;39m");
	else if (err == inv_use)
	{
		ft_printf_fd(2, "\033[0;91mError: \033[0;39mUsage:\n");
		ft_printf_fd(2, "\t\033[0;93mNormal Mode: ./so_long [map_path]\n");
		ft_printf_fd(2, "\tDev Mode: ./so_long [map_path] [DEBUG=1]\n\033[0;39m");
	}
	else
		perror("Error");
	free_game(game);
	exit(EXIT_FAILURE);
}
