/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:06:48 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 22:27:54 by sebasnadu        ###   ########.fr       */
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
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
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
