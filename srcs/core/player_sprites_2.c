/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprites_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:09:12 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/03 21:10:15 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_end_sprite(t_game *game)
{
	if (game->player->direction == right)
	{
		if (game->won == true)
			return (2);
		else
			return (12);
	}
	else
	{
		if (game->won == true)
			return (96);
		else
			return (106);
	}
}

int	player_slide_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 11)
			i = 21;
		else if ((i > 12 && i < 23))
			i++;
		else
			i = 13;
	}
	else 
	{
		if (*last_anim != 11)
			i = 115;
		else if ((i > 106 && i < 117))
			i++;
		else
			i = 107;
	}
	*last_anim = 11;
	return (i);
}

int	player_jump_attack_sprite(int *last_anim, t_game *game)
{
	static int	i;

	if (game->player->direction == right)
	{
		if (*last_anim != 10)
			i = 58; 
		else if ((i > 57 && i < 67))
			i++;
		else 
			i = 58; 
	}
	else
	{
		if (*last_anim != 10)
			i = 152; 
		else if ((i > 151 && i < 161))
			i++;
		else
			i = 152; 
	}
	*last_anim = 10;
	return (i);
}
