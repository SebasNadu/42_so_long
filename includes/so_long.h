/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/25 23:45:39 by sebasnadu        ###   ########.fr       */
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
	storm_n = 27,
	coin_n = 4,
	gate_n = 3,
	misc_n = 12,
	bg_n = 10,
}		t_sprite_n;

typedef enum e_bool
{
	false,
	true
}				t_bool;

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
	t_bool	is_alive;
	t_bool	is_moving;
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
	void	*misc[12];
	void	*bg[10];
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
}				t_game;

// init_0.c
void		init_game(char *argv[], t_game *game);
void		init_map(int argc, char *argv[], t_game *game);
void		init_sprites(t_game *game);
void		init_player(t_game *game);
void		init_camera(t_game *game);
// init_1.c
void		init_enemies(t_game *game);
void		init_hooks(t_game *game);
// error.c
void		sl_error(t_game *game, int err);
void		free_game(t_game *game);
// parse_0.c
t_bool		check_args(int argc, char *argv[]);
t_bool		open_map(char *relative_path, t_game *game);
t_bool		read_map(t_game *game);
t_bool		set_map(t_game *game);
t_bool		check_map_len(t_game *game);
// parse_1.c
t_bool		check_map_chars(t_game *game);
t_bool		check_map_walls(t_game *game);
t_bool		check_map_requisites(t_game *game);
// load.c
void		load_sprite(char *s_name, int s_n, t_sprite_t s_t, t_game *game);
// hooks.c
int			keyup_hook(int keycode, t_game *game);
int			keydown_hook(int keycode, t_game *game);
int			close_hook(int keycode, t_game *game);
// actions.c
void		unset_action(int keycode, t_game *game);
void		set_action(int keycode, t_game *game);
int			get_action_keycode(int keycode);
// utils.c
long long	get_millitimestamp(void);
void		fps(t_game *game);
// player.c
void		player_position(t_game *game);
// structure.c
void		structure(t_game *game);
// draw.c
void		draw_block(int x, int y, void *sprite, t_game *game);
void		background(t_game *game);

#endif
