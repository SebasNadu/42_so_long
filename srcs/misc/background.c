/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:36:49 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:39:39 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	background(t_game *g)
{
	int	i;
	int	j;
	int	x_offs;
	int	y_offs;

	i = 0;
	j = 1;
	draw_sky(g);
	if (g->g_len.y * BPX < WIN_HEIGHT)
		return ;
	while (++i < bg_n)
	{
		y_offs = (j + (BPX / 2) + g->p_offset.y);
		if (i == 7 || i == 1)
			draw_bg(g->g_offset.x, y_offs, g->sprites.bg[i], g);
		else if (i == 6)
			draw_bg(g->g_offset.x, y_offs + (BPX / 8), g->sprites.bg[i], g);
		else
		{
			x_offs = (((j * 400) - (g->player->pos.x)) / (j * 4));
			draw_bg(x_offs - 50, y_offs, g->sprites.bg[i], g);
		}
		j++;
	}
}
