/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:18:26 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/16 19:16:40 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int main()
{
	void *mlx;
	void *win;
	void *img;
	// void *img2;
	// void *img3;
	// void *img4;
	// void *img5;
	// void *img6;
	// void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1250, 720, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "assets/luke/cat_1.xpm", &img_width, &img_height);
	if (!img)
	{
		ft_printf("Error\n");
		exit(0);
	}
	// img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	// img3 = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &img_width, &img_height);
	// img4 = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	// img5 = mlx_xpm_file_to_image(mlx, "./images/chest_open.xpm", &img_width, &img_height);
	// img6 = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	// img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	// mlx_put_image_to_window(mlx, win, img2, 64, 0);
	// mlx_put_image_to_window(mlx, win, img3, 128, 0);
	// mlx_put_image_to_window(mlx, win, img4, 192, 64);
	// mlx_put_image_to_window(mlx, win, img5, 0, 64);
	// mlx_put_image_to_window(mlx, win, img6, 64, 64);
	// mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_image(mlx, img);
	free(mlx);
	exit(0);
	return (0);
}
