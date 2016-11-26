/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhabib <moongamingpp@hotmail.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:01:07 by rhabib            #+#    #+#             */
/*   Updated: 2016/11/26 16:49:29 by rhabib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_button(t_env *e, int num, int check);

void	mlx_fill_image(t_env *e)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			pixel_put(e, x, y, 0x121111);
		}
	}
}

void    draw_button(t_env *e, int num, int check)
{
	int x;
	int y;
	int keycode;
	char *text;
	int             xx;
	int             yy;

	x = getbutton(num, 1);
	y = getbutton(num, 2);
	keycode = getbutton(num, 4);
	text = getbuttontext(num);
	xx = -1;
	while (++xx < 30)
	{
		yy = -1;
		while (++yy < 30)
		{
			if (yy == 0 || xx == 0 || yy == 30 -1 || xx == 30 -1)
				pixel_put(e, x+xx, y+yy, 0xCCCCCC);
			else
				pixel_put(e, x+xx, y+yy, 0x999999);
		}
	}
	mlx_string_put(e->mlx, e->win, x+xx/2, y+yy/1.5, 0xFFFFFF,text);

	if (check && e->mouse_x > x && e->mouse_x <x+xx && e->mouse_y > y && e->mouse_y < y+yy)
	{
		key_hook(keycode, e);
	}


}

void    display_menu(t_env *e)
{
	int i;

	i = 1;
	while (i != 11)
	{
		draw_button(e, i, 0);
		i++;
	}
	mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF,
			"Bienvenue sur le meilleur fdf de la terre.");
	mlx_string_put(e->mlx, e->win, WIDTH - 90, 60, 0xFFFFFF,"ZOOM");
	mlx_string_put(e->mlx, e->win, WIDTH -100, 60+100, 0xFFFFFF,"RELIEF");
}	    

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_fill_image(e);
	if (e->tpro == 0 && e->wire == 0)
	  isometric(e);
	  else if (e->tpro == 0 && e->wire == 1)
	  isometricf(e);
	  else if (e->tpro == 1)
	  parallel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	display_menu(e);
	display_param(e);
	return (0);
}

int     gere_souris(int x, int x2, int y, t_env *e)
{
	int i;

	e->mouse_x = x2;
	e->mouse_y = y;
	i = 1;
	while (i != 11)
	{
		draw_button(e, i, 1);
		i++;
	}
	expose_hook(*&e);
	return (0);
}



int             key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(1);
	else
		eventkey(e, keycode);
	expose_hook(*&e);
	return (0);
}


void	display_tab(int **array, int length, int width, int **color)
{
	t_env	e;

	e = initenv(length, width, array, color);
	mlx_mouse_hook(e.win, gere_souris, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
