/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprites_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:07:05 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/03 21:08:48 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_attack_down_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 9)
			i = 84;
		else if ((i > 83 && i < 93))
			i++;
		else
			i = 84;
	}
	else
	{
		if (*last_anim != 9)
			i = 176;
		else if ((i > 175 && i < 183))
			i++;
		else
			i = 176;
	}
	*last_anim = 9;
	return (i);
}

int	player_double_jump_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 8)
			i = 68;
		else if ((i > 67 && i < 75))
			i++;
		else
			i = 68;
	}
	else
	{
		if (*last_anim != 8)
			i = 162;
		else if ((i > 161 && i < 169))
			i++;
		else
			i = 162;
	}
	*last_anim = 8;
	return (i);
}

static int	player_stay_sprite_helper(int i, long long *now, int start, int end)
{
	if (i == end && get_millitimestamp() - *now > 1000)
		i = start;
	else if (i > start - 1 && i < end && get_millitimestamp() - *now > 2000)
	{
		i++;
		if (i == end)
			*now = get_millitimestamp();
	}
	return (i);
}

int	player_stay_sprite(int *last_anim, t_game *game)
{
	static int			i;
	static long long	now;

	if (game->player->direction == right)
	{
		if (*last_anim != 7)
		{
			i = 0;
			now = get_millitimestamp();
		}
		else
			i = player_stay_sprite_helper(i, &now, 0, 9);
	}
	else
	{
		if (*last_anim != 7)
		{
			i = 94;
			now = get_millitimestamp();
		}
		else
			i = player_stay_sprite_helper(i, &now, 94, 103);
	}
	*last_anim = 7;
	return (i);
}

int	player_hurt_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 6)
			i = 10;
		else if (i > 9 && i < 11)
			i++;
		else
			i = 10;
	}
	else
	{
		if (*last_anim != 6)
			i = 104;
		else if (i > 103 && i < 105)
			i++;
		else
			i = 104;
	}
	*last_anim = 6;
	return (i);
}
