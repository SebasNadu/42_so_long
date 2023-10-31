/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/10/31 13:16:59 by sebas_nadu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  define OS "linux"
#  include "../minilibx-linux/mlx.h"
# else
#  define OS "macos"
#  include "../minilibx_opengl/mlx.h"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>

# include "../libft/includes/libft.h"
# include "keys.h"
# include "macros.h"
# include "structs.h"
# include "functions.h"

#endif
