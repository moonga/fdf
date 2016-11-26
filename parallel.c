/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhabib <moongamingpp@hotmail.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:14:28 by rhabib            #+#    #+#             */
/*   Updated: 2016/11/06 20:14:55 by rhabib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		get_parallelpoint(int x, int y, int z, t_env *e)
{
	t_coord		p;

	x *= e->scale;
	y *= e->scale;
	p.y = (x + e->y_offset) + e->cte1 * -z + e->y_origin;
	p.x = (y + e->x_offset) + e->cte3 * (-z * e->height) + e->x_origin;
	p.z = z;
	return (p);
}

void		parallel(t_env *e)
{
	int			i;
	int			j;
	t_coord		p1;
	t_coord		p2;

	i = -1;
	while (++i < e->width)
	{
		j = e->length;
		while (--j >= 0)
		{
			p1 = get_parallelpoint(i, j, e->array[i][j], e);
			if (i < e->width - 1)
			{
				p2 = get_parallelpoint(i + 1, j, e->array[i + 1][j], e);
				ligne(e, &p1, &p2);
			}
			if (j < e->length - 1)
			{
				p2 = get_parallelpoint(i, j + 1, e->array[i][j + 1], e);
				ligne(e, &p1, &p2);
			}
		}
	}
}

int		findcolor(t_color *color, int z, int z_min, int z_max)
{
	int		t1;
	int		t2;
	int		v;

	if (z <= z_min)
		return (color->color1);
	if (z >= z_max)
		return (color->color2);
	t1 = color->color1 / 256 / 256;
	t2 = color->color2 / 256 / 256;
	v = ((((z - abs(z_min)) * (t2 - t1)) / \
				(z_max - abs(z_min))) + t1) * 256 * 256;
	t1 = color->color1 / 256 % 256;
	t2 = color->color2 / 256 % 256;
	v += ((((z - abs(z_min)) * (t2 - t1)) / (z_max - abs(z_min))) + t1) * 256;
	t1 = color->color1 % 256;
	t2 = color->color2 % 256;
	v += ((((z - abs(z_min)) * (t2 - t1)) / (z_max - abs(z_min))) + t1);
	return (v);
}

int		getlevel(t_env *e, double z)
{
	t_color		color;

	if (z < e->z_min || z > e->z_max)
		return (0);
	if (z <= e->z_mid && z >= e->z_min)
	{
		color.color1 = e->color[e->cnum][0];
		color.color2 = e->color[e->cnum][1];
		return (findcolor(&color, z, e->z_min, e->z_mid));
	}
	else if (z <= e->z_max && z >= e->z_mid)
	{
		color.color1 = e->color[e->cnum][1];
		color.color2 = e->color[e->cnum][2];
		return (findcolor(&color, z, e->z_mid, e->z_max));
	}
	return (0);
}


int		*putcolor(int a, int b, int c)
{
	int		*color;

	color = malloc(sizeof(int) * 3);
	color[0] = a;
	color[1] = b;
	color[2] = c;
	return (color);
}

int		**getcolor(char **av, int ac)
{
	int		**color;

	color = malloc(sizeof(int *) * 5);
	if (ac > 4)
	{
		color[0] = malloc(sizeof(int *) * 3);
		color[0][0] = ft_atoi(av[2]);
		color[0][1] = ft_atoi(av[3]);
		color[0][2] = ft_atoi(av[4]);
	}
	else
		color[0] = putcolor(0x000000, 0x808080, 0xFFFFFF);
	color[1] = putcolor(0x0070e0, 0x42c6ff, 0xf3d85e);
	color[2] = putcolor(0xb9280e, 0x3d231a, 0x27160c);
	color[3] = putcolor(0x124511, 0x1a0f0f, 0x888181);
	color[4] = putcolor(0x0000ff, 0x00ff00, 0xff0000);
	return (color);
}

