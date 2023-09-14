/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:18:26 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/14 17:56:27 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/mlx.h"
// #include <stdlib.h>
//
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
//
// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (1);
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	if (!mlx_win)
// 		return (1);
// 	mlx_loop(mlx);
// 	free(mlx);
// 	exit(0);
// 	return (0);
// }

#include "../../libft/includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../../includes/mlx.h"

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;


	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

int main()
{
		void	*mlx;
		void	*win;
		t_img	img;
		int		count_h;
		int		count_w;


		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "my_mlx");
		img.ptr = mlx_png_file_to_image(mlx, "../../textures/wall_s.png", &img.width, &img.height);
		if (!img.ptr)
		{
			ft_printf("Error\n");
			return (1);
		}
		img.bpp = 0;
		img.size_l = 0;
		img.endian = 0;
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);
		count_h = -1;
		while (++count_h < img.height)
		{
			count_w = -1;
			while (++count_w < img.width / 2)
			{
				if (count_w % 2)
					img.data[count_h * img.width + count_w] = 0xFFFFFF;
				else
					img.data[count_h * img.width + count_w] = 0xFF0000;
			}
		}
		mlx_put_image_to_window(mlx, win, img.ptr, 50, 50);
		mlx_loop(mlx);
		return (0);
}
