/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:27:59 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/16 18:59:36 by sebasnadu        ###   ########.fr       */
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
# include "keys.h"
# include "../libft/includes/libft.h"

# define WIN_TITLE "So_Long"
# define WIN_WIDTH 1250
# define WIN_HEIGHT 720

#endif
