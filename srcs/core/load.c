/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:06:09 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/24 19:56:14 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*sprite_path(char *s_name, int n)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(n);
	str1 = ft_strjoin("./assets/", s_name);
	str2 = ft_strjoin(str1, "/");
	free(str1);
	str1 = ft_strjoin(str2, s_name);
	free(str2);
	str2 = ft_strjoin(str1, "_");
	free(str1);
	str1 = ft_strjoin(str2, nbr);
	free(str2);
	str2 = ft_strjoin(str1, ".xpm");
	free(str1);
	free(nbr);
	return (str2);
}

static void	load_sprite_type(int i, char *path, t_sprite_t s_t, t_game *game)
{
	int		d;

	if (s_t == luke_t)
		game->sprites.luke[i] = mlx_xpm_file_to_image(game->mlx, path, &d, &d);
	else if (s_t == storm_t)
		game->sprites.strom[i] = mlx_xpm_file_to_image(game->mlx, path, &d, &d);
	else if (s_t == coin_t)
		game->sprites.coin[i] = mlx_xpm_file_to_image(game->mlx, path, &d, &d);
	else if (s_t == gate_t)
		game->sprites.gate[i] = mlx_xpm_file_to_image(game->mlx, path, &d, &d);
	else if (s_t == misc_t)
		game->sprites.heart[i] = mlx_xpm_file_to_image(game->mlx, path, &d, &d);
	else if (s_t == bg_t)
		game->sprites.bg[i] = mlx_xpm_file_to_image(game->mlx, path, &d, &d);
}

void	load_sprite(char *s_name, int s_n, t_sprite_t s_t, t_game *game)
{
	int		i;
	int		fd;
	char	*path;

	i = -1;
	while (++i < s_n)
	{
		path = sprite_path(s_name, i);
		fd = open(path, O_RDONLY);
		if (fd < 0)
			sl_error(game, 4);
		close(fd);
		load_sprite_type(i, path, s_t, game);
		free(path);
	}
}
