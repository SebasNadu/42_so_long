/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:06:48 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/31 20:30:26 by sebas_nadu       ###   ########.fr       */
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

void	sl_error(t_game *game, int err)
{
	(void)game;
	if (err == inv_args)
		ft_printf_fd(2, "Error: You must indicate only one map path!\n");
	else if (err == inv_map)
		ft_printf_fd(2, "Error: Unable to open the map!\n");
	else if (err == inv_map_form)
		ft_printf_fd(2, "Error: The map is not in a valid format!\n");
	else if (err == inv_sprite)
		ft_printf_fd(2, "Error: Unable to open the sprite!\n");
	else
		perror("Error");
	free_game(game);
	exit(EXIT_FAILURE);
}
