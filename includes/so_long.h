/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:27:59 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/22 14:26:57 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  define OS "linux"
#  include "../minilibx_linux/mlx.h"
# else
#  define OS "macos"
#  include "mlx.h"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include "keys.h"
# include "../libft/includes/libft.h"

# define WIN_TITLE "so_Long"
# define WIN_WIDTH 1366
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
	INV_ARGS = 1,
	INV_MAP = 2,
	INV_MAP_FORM = 3,
	INV_SPRITE = 4,
};

enum e_sprites
{
	LUKE = 0,
	STORM = 1,
	STRUC = 2,
	COIN = 3,
	GATE = 4,
	HEART = 5,
};

typedef enum e_direction
{
	left,
	right
}				t_direction;

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
}				t_player;

typedef struct s_enemy
{
	t_vtr2D	pos;
	t_vtr2D	init_pos;
	t_vtr2D	t_l;
	t_vtr2D	t_r;
	t_vtr2D	b_l;
	t_vtr2D	b_r;
	int		is_alive;
	int		is_moving;
	int		attack_state;
	int		death_state;
	int		direction;
	int		last_anim;
	int		anim_pos;
	int		anim_intv;
	int		mv_intv;
}				t_enemy;

typedef struct s_sprites
{
	void	*luke[188];
	void	*strom[27];
	void	*coin[4];
	void	*gate[3];
	void	*heart[2];
	void	*struc[5];
}				t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_vtr2D		global_size;
	int			map_fd;
	t_list		*lst_map;
	char		**map;
	t_sprites	sprites;
	long long	timestamp;
	int			fps;
	t_vtr2D		player_offset;
	t_vtr2D		global_offset;
	int			c_num;
	int			mvts_num;
	t_player	*player;
	t_list		*enemies;
	int			debug;
}				t_game;

#endif
