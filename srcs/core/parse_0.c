/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:52:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/23 16:34:26 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	check_map_len(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i > game->g_len.y)
			return (false);
		if ((int)ft_strlen(game->map[i]) != game->g_len.x)
			return (false);
		i++;
	}
	return (true);
}

t_bool	set_map(t_game *game)
{
	t_list	*lst;
	int		i;

	game->g_len.y = ft_lstsize(game->lst_map);
	if (game->g_len.y < 3)
		return (false);
	game->map = ft_calloc(game->g_len.y + 1, sizeof(char *));
	if (!game->map)
		return (false);
	lst = game->lst_map;
	i = 0;
	while (lst)
	{
		game->map[i] = ft_strdup(lst->content);
		if (!game->map[i])
			return (false);
		i++;
		lst = lst->next;
	}
	game->g_len.x = ft_strlen(game->map[0]);
	if (game->g_len.x < 4)
		return (false);
	return (true);
}

t_bool	read_map(t_game *game)
{
	char	*line;
	int		line_size;

	line = "";
	while (line)
	{
		line = get_next_line(game->map_fd);
		if (!line)
		{
			if (game->g_len.x == -1)
				return (false);
			return (true);
		}
		line_size = ft_strlen(line);
		line[line_size - 1] = '\0';
		if (game->g_len.x == -1)
			game->g_len.x = ft_strlen(line);
		if (game->lst_map == NULL)
			game->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&game->lst_map, ft_lstnew(line));
	}
	return (true);
}

t_bool	open_map(char *relative_path, t_game *game)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (false);
	if (ft_strncmp(&relative_path[path_len - 4], ".ber", 5) != 0)
		return (false);
	game->map_fd = open(relative_path, O_RDONLY);
	if (game->map_fd < 0)
		return (false);
	return (true);
}

t_bool	check_args(int argc, char *argv[])
{
	if (argc == 3 && argv[2] && ft_strncmp(argv[2], "DEBUG=1", 8) == 0)
		return (true);
	else if (argc == 3 && argv[2] && ft_strncmp(argv[2], "DEBUG=0", 8) == 0)
		return (true);
	else if (argc != 2)
		return (false);
	return (true);
}
