/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:28:31 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:41:22 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_action_keycode(int keycode)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
		return (k_l);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		return (k_r);
	else if (keycode == KEY_W || keycode == KEY_UP)
		return (k_u);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		return (k_d);
	else if (keycode == KEY_SPACE)
		return (k_s);
	return (0);
}

void	set_action(int keycode, t_game *game)
{
	t_player	*p;

	p = game->player;
	if (get_action_keycode(keycode) != 5)
	{
		if (p->ac[0] == k_n || p->ac[0] == get_action_keycode(keycode))
			p->ac[0] = get_action_keycode(keycode);
		else if (p->ac[1] == k_n || p->ac[1] == get_action_keycode(keycode))
			p->ac[1] = get_action_keycode(keycode);
	}
	else
		p->ac[2] = get_action_keycode(keycode);
	if (p->ac[0] == k_l || p->ac[1] == k_l)
		p->direction = left;
	else if (p->ac[0] == k_r || p->ac[1] == k_r)
		p->direction = right;
}

void	unset_action(int keycode, t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == get_action_keycode(keycode))
		p->ac[0] = k_n;
	if (p->ac[1] == get_action_keycode(keycode))
		p->ac[1] = k_n;
	if (p->ac[0] == k_n && p->ac[1] != k_n)
	{
		p->ac[0] = p->ac[1];
		p->ac[1] = k_n;
	}
	if (p->ac[2] == get_action_keycode(keycode))
		p->ac[2] = k_n;
}
