/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:27:59 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/19 22:42:12 by sebasnadu        ###   ########.fr       */
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
# include "keys.h"
# include "../libft/includes/libft.h"

# define WIN_TITLE "so_Long"
# define WIN_WIDTH 1929
# define WIN_HEIGHT 1080

# define BLOCK_PX 100

enum e_so_long_err
{
	INV_ARGS = 1,
	INV_MAP = 2,
	INV_MAP_FORM = 3,
	INV_SPRITE = 4,
};

typedef struct s_vtr2D
{
	int	x;
	int	y;
}				t_vtr2D;

typedef struct s_player
{
	t_vtr2D	pos;
	t_vtr2D	last_pos;
	t_vtr2D	top_l;
	t_vtr2D	top_r;
	t_vtr2D	bottom_l;
	t_vtr2D	bottom_r;
	int		jump_state;
	int		actions[3];
	int		direction;
	int		diagonal_dir;
	int		life_state;
	int		life_num;
}				t_player;

typedef struct s_enemy
{
	t_vtr2D	pos;
	t_vtr2D	init_pos;
	t_vtr2D	top_l;
	t_vtr2D	top_r;
	t_vtr2D	bottom_l;
	t_vtr2D	bottom_r;
	int		is_alive;
	int		is_moving;
	int		direction;
	int		last_anim;
	int		anim_pos;
	int		anim_interv;
	int		move_interv;
}				t_enemy;

typedef struct s_images
{
	void	*luke[94];
}				t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_vtr2D		game_size;
	int			map_fd;
	t_list		*lst_map;
	char		**map;
	long long	last_ts;
	int			fps;
	t_vtr2D		player_offset;
	t_vtr2D		global_offset;
	int			c_num;
	int			mvts_num;
	t_player	*player;
	t_list		*enemies;
}				t_game;

#endif
