/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:17:58 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 11:19:13 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

long long	get_millitimestamp(void)
{
	struct timeval	time_val;

	gettimeofday(&time_val, NULL);
	return (time_val.tv_sec * 1000LL + time_val.tv_usec / 1000);
}

void	fps(t_game *game)
{
	long long	now;

	now = get_millitimestamp();
	if (now - game->updated_at > 15)
	{
		game->fps = 960 / (now - game->updated_at);
		game->updated_at = now;
	}
}
