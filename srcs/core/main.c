/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:18:26 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/19 22:42:48 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_strc_game(char *argv[], t_game *game)
{
	(void)argv;
	game->mlx = mlx_init();
	game->last_ts = 0;
	game->game_size.x = -1;
	game->game_size.y = -1;
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		exit(EXIT_FAILURE);
	game->player->jump_state = 0;
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	game->player_offset.x = 0;
	game->player_offset.y = 0;
	game->mvts_num = 0;
	game->lst_map = NULL;
	game->enemies = NULL;
}

void	sl_error(t_game *game, int err)
{
	(void)game;
	if (err == INV_ARGS)
		ft_printf_fd(2, "Error: You must indicate only one map path!\n");
	if (err == INV_MAP)
		ft_printf_fd(2, "Error: Unable to open the map!\n");
	if (err == INV_MAP_FORM)
		ft_printf_fd(2, "Error: The map is not in a valid format!\n");
	if (err == INV_SPRITE)
		ft_printf_fd(2, "Error: Unable to open the sprite!\n");
	exit(EXIT_FAILURE);
}

int	open_map(char *relative_path, t_game *game)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (0);
	if (ft_strncmp(&relative_path[path_len - 4], ".ber", 4) != 0)
		return (0);
	game->map_fd = open(relative_path, O_RDONLY);
	if (game->map_fd < 0)
		return (0);
	return (1);
}

int	read_map(t_game *game)
{
	char	*line;
	int		line_size;

	line = "";
	while (line)
	{
		line = get_next_line(game->map_fd);
		if (!line)
		{
			if (game->game_size.x == -1)
				return (0);
			return (1);
		}
		line_size = ft_strlen(line);
		line[line_size - 1] = '\0';
		if (game->game_size.x == -1)
			game->game_size.x = ft_strlen(line);
		if (game->lst_map == NULL)
			game->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&game->lst_map, ft_lstnew(line));
	}
	return (1);
}

int	set_map(t_game *game)
{
	t_list	*lst;
	int		i;

	game->game_size.y = ft_lstsize(game->lst_map);
	if (game->game_size.y < 3)
		return (0);
	game->map = ft_calloc(game->game_size.y + 1, sizeof(char *));
	if (!game->map)
		return (0);
	lst = game->lst_map;
	i = 0;
	while (lst)
	{
		game->map[i] = ft_strdup(lst->content);
		if (!game->map[i])
			return (0);
		i++;
		lst = lst->next;
	}
	game->game_size.x = ft_strlen(game->map[0]);
	if (game->game_size.x < 4)
		return (0);
	return (1);
}

int	check_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i > game->game_size.y)
			return (0);
		if ((int)ft_strlen(game->map[i]) != game->game_size.x)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'M'
				&& game->map[i][j] != '*')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && i < game->game_size.y
			&& j < game->game_size.x)
		{
			if (i == 0 || i + 1 == game->game_size.y)
				if (game->map[i][j] != '1')
					return (0);
			if (j == 0 || j + 1 == game->game_size.x)
				if (game->map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_requisites(t_game *game)
{
	int	i;
	int	j;
	int	elements[3];

	i = 0;
	ft_memset(elements, 0, sizeof(elements));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				elements[0]++;
			else if (game->map[i][j] == 'P')
				elements[1]++;
			else if (game->map[i][j] == 'E')
				elements[2]++;
			j++;
		}
		i++;
	}
	if (elements[0] < 1 || elements[1] != 1 || elements[2] != 1)
		return (0);
	game->c_num = elements[0];
	return (1);
}

int	init_map(int argc, char *argv[], t_game *game)
{
	(void)argc;
	if (!open_map(argv[1], game))
		sl_error(game, 2);
	if (!read_map(game))
		sl_error(game, 3);
	if (!set_map(game))
		sl_error(game, 3);
	if (!check_map(game))
		sl_error(game, 3);
	if (!check_map_chars(game))
		sl_error(game, 3);
	if (!check_map_walls(game))
		sl_error(game, 3);
	if (!check_map_requisites(game))
		sl_error(game, 3);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		sl_error(&game, 1);
	init_strc_game(argv, &game);
	init_map(argc, argv, &game);
	return (0);
}
