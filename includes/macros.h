/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:22:03 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/04 23:28:34 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define WIN_TITLE "so_Long"
# define WIN_WIDTH 1360
# define WIN_HEIGHT 768
# define HUD_LM 920
# define LIFE_NUM 7

# define BPX 100
# define MPX 8
# define GPX 14
# define DPX 20
# define JPX 40
# define HPX 15
# define EHPX 25

enum e_so_long_err
{
	inv_args,
	inv_map,
	inv_map_form,
	inv_sprite,
};

enum e_direction
{
	left,
	right
};

enum e_k_action
{
	k_n,
	k_l,
	k_r,
	k_u,
	k_d,
	k_s,
};

typedef enum e_sprite_t
{
	luke_t,
	storm_t,
	coin_t,
	gate_t,
	misc_t,
	bg_t,
}			t_sprite_t;

typedef enum e_sprite_n
{
	luke_n = 188,
	storm_n = 62,
	coin_n = 4,
	gate_n = 3,
	misc_n = 12,
	bg_n = 8,
}		t_sprite_n;

typedef enum e_bool
{
	false,
	true
}				t_bool;

#endif
