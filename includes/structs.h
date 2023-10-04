/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:31:16 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/04 23:32:38 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vtr2D
{
	int	x;
	int	y;
}				t_vtr2D;

typedef struct s_player
{
	t_vtr2D	pos;
	t_vtr2D	last_pos;
	t_vtr2D	t_l;
	t_vtr2D	t_r;
	t_vtr2D	b_l;
	t_vtr2D	b_r;
	int		jump_state;
	int		ac[3];
	int		diagonal_dir;
	int		direction;
	int		life_state;
	int		life_num;
	int		jump_count;
	int		last_ac[3];
	int		kills_count;
}				t_player;

typedef struct s_enemy
{
	t_vtr2D	pos;
	t_vtr2D	init_pos;
	t_vtr2D	t_l;
	t_vtr2D	t_r;
	t_vtr2D	b_l;
	t_vtr2D	b_r;
	t_bool	is_alive;
	t_bool	is_moving;
	int		attack_state;
	int		death_state;
	int		life_state;
	int		direction;
	int		last_anim;
	int		anim_pos;
	int		anim_intv;
	int		mv_intv;
}				t_enemy;

typedef struct s_sprites
{
	void	*luke[188];
	void	*strom[62];
	void	*coin[4];
	void	*gate[3];
	void	*misc[12];
	void	*bg[8];
}				t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_vtr2D		g_len;
	int			map_fd;
	t_list		*lst_map;
	char		**map;
	t_sprites	sprites;
	long long	updated_at;
	int			fps;
	t_vtr2D		p_offset;
	t_vtr2D		g_offset;
	int			c_num;
	int			mvts_num;
	t_player	*player;
	t_list		*enemies;
	t_bool		debug;
	t_bool		won;
	t_bool		lose;
}				t_game;

#endif
