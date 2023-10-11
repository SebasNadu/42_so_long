/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:35:41 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/11 20:36:36 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// init_0.c
void			init_game(char *argv[], t_game *game);
void			init_map(int argc, char *argv[], t_game *game);
void			init_sprites(t_game *game);
void			init_player(t_game *game);
void			init_camera(t_game *game);
// init_1.c
void			init_enemies(t_game *game);
void			init_hooks(t_game *game);
// error.c
void			sl_error(t_game *game, int err);
void			free_game(t_game *game);
// parse_0.c
t_bool			check_args(int argc, char *argv[]);
t_bool			open_map(char *relative_path, t_game *game);
t_bool			read_map(t_game *game);
t_bool			set_map(t_game *game);
t_bool			check_map_len(t_game *game);
// parse_1.c
t_bool			check_map_chars(t_game *game);
t_bool			check_map_walls(t_game *game);
t_bool			check_map_requisites(t_game *game);
// load.c
void			load_sprite(char *s_name, int s_n, t_sprite_t s_t,
					t_game *game);
// hooks.c
int				keyup_hook(int keycode, t_game *game);
int				keydown_hook(int keycode, t_game *game);
int				close_hook(int keycode, t_game *game);
// actions.c
void			unset_action(int keycode, t_game *game);
void			set_action(int keycode, t_game *game);
int				get_action_keycode(int keycode);
// utils.c
long long		get_millitimestamp(void);
void			fps(t_game *game);
// player.c
void			player_position(t_game *game);
void			player(t_game *game);
// player_move_utils.c
void			player_jump(t_game *game);
void			player_gravity(t_game *game);
void			player_move_x(t_game *game);
void			player_move_y(t_game *game);
void			player_move_d(t_game *game);
// player_distances_utils.c
int				get_pj_dist(t_game *game);
int				get_pg_dist(t_game *game);
int				get_pr_dist(t_game *game);
int				get_pl_dist(t_game *game);
int				get_pd_dist(t_game *game);
// player_sprites_0.c
int				player_jump_sprite(int *last_anim, t_game *game);
int				player_attack_sprite(int *last_anim, t_game *game);
int				player_walk_sprite(int	*last_anim, t_game *game);
int				player_down_sprite(int *last_anim, t_game *game);
int				player_fall_sprite(int *last_anim, t_game *game);
// player_sprites_1.c
int				player_hurt_sprite(int *last_anim, t_game *game);
int				player_stay_sprite(int *last_anim, t_game *game);
int				player_double_jump_sprite(int *last_anim, t_game *game);
int				player_attack_down_sprite(int *last_anim, t_game *game);
// player_sprites_2.c
int				player_jump_attack_sprite(int *last_anim, t_game *game);
int				player_slide_sprite(int *last_anim, t_game *game);
int				player_end_sprite(t_game *game);
// player_draw_utils.c
int				*get_player_sprite(t_game *game);
// structure.c
void			structure(t_game *game);
// background.c
void			background(t_game *g);
// items.c
void			items(t_game *game);
// gate.c
void			gate(t_game *game);
// enemy.c
void			enemy(t_game *game);
// enemy_position.c
void			enemy_move_dir(t_enemy *e, t_game *game);
// enemy_distances.c
void			enemy_distances(t_enemy *enemy, t_game *game);
// enemy_action.c
void			enemy_action(t_enemy *e, t_game *game);
// enemy_draw_utils.c
int				*get_enemy_sprite(t_enemy *e, t_game *game);
// draw.c
void			draw_block(int x, int y, void *sprite, t_game *game);
void			draw_sky(t_game *game);
void			draw_bg(int x, int y, void *sprite, t_game *game);
// show_debug.c
void			show_debug(t_game *game);
// show_hud.c
void			show_hud(t_game *game);
// show_final_screen.c
void			show_final_screen(t_game *game);

#endif
