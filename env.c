/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhabib <moongamingpp@hotmail.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:02:21 by rhabib            #+#    #+#             */
/*   Updated: 2016/11/17 21:46:21 by rhabib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FDF@42");
	e->img.img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.img = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, \
			&e->img.sl, &e->img.endian);
}

t_env	getminmax(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	e->z_min = e->array[0][0];
	e->z_max = e->z_min;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (e->array[i][j] > e->z_max)
				e->z_max = e->array[i][j];
			if (e->array[i][j] < e->z_min)
				e->z_min = e->array[i][j];
		}
	}
	return (*e);
}

t_env	absarray(t_env *e)
{
	int		i;
	int		j;

	if (e->z_min >= 0)
		return (*e);
	i = -1;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
			e->array[i][j] += -e->z_min;
	}
	e->z_max += -e->z_min;
	e->z_min = 0;
	return (*e);
}

t_env	initenv(int length, int width, int **array, int **color)
{
	t_env e;

	e.mouse_x = 0;
	e.mouse_y = 0;
	e.x_offset = 0;
	e.y_offset = 0;
	e.x_origin = 0;
	e.y_origin = 0;
	e.array = array;
	e.length = length;
	e.width = width;
	e.height = 1;
	e.tpro = 1;
	e.wire = 0;
	e = getminmax(&e);
	e = absarray(&e);
	e.color = color;
	e.cnum = 0;
	e.z_mid = (e.z_min + e.z_max) / 2.0;
	e.scale = ((double)(WIDTH + HEIGHT) / 2.0) / \
		  ((double)(e.width + e.length) / 2.0);
	e.cte1 = 0.75;
	e.cte2 = 0.75;
	e.cte3 = e.cte1 / 2.0;
	e.cte4 = e.cte2 / 2.0;
	init_img(&e);
	return (e);
}
