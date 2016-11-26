/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhabib <moongamingpp@hotmail.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:57:57 by rhabib            #+#    #+#             */
/*   Updated: 2016/11/22 21:13:27 by rhabib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getbutton(int num, int type)
{
	if (type == 1)
		return(getbuttonx(num));
	if (type == 2)
		return(getbuttony(num));
	if (type == 4)
		return(getbuttonid(num));
}

int	getbuttonid(int num)
{
	if (num == 1)
		return(100);
	if (num == 2)
		return(97);
	if (num == 3)
		return(119);
	if (num == 4)
		return(115);
	if (num == 5)
		return(65451);
	if (num == 6)
		return(65453);
	if (num == 7)
		return(101);
	if (num == 8)
		return(113);
	if (num == 9)
		return(65362);
	if (num == 10)
		return(65364);

}

int	getbuttonx(int num)
{
	if (num == 1)
		return(WIDTH/2 +35);
	if (num == 2)
		return(WIDTH/2 -35);
	if (num == 3 || num == 4)
		return(WIDTH/2);
	if (num == 5 || num == 6 || num == 9 || num == 10)
		return(WIDTH - 60);
	if (num == 7)
		return(WIDTH/2 + 42);
	if (num == 8)
		return(WIDTH/2 - 42);

}

int     getbuttony(int num)
{
	if (num == 1 || num == 2)
		return(HEIGHT - 60);
	if (num == 3)
		return(HEIGHT - 80);
	if (num == 4)
		return(HEIGHT - 40);
	if (num == 5)
		return(20);
	if (num == 6)
		return(60);
	if (num == 9)
		return(120);
	if (num == 10)
		return(160);
	if (num == 7 || num == 8)
		return(HEIGHT - 115);

}


char	*getbuttontext(int num)
{
	if (num == 1)
		return("D");
	if (num == 2)
		return("A");
	if (num == 3)
		return("W");
	if (num == 4)
		return("S");
	if (num == 5 || num == 9)
		return("+");
	if (num == 6 || num == 10)
		return("-");
	if (num == 7)
		return("E");
	if (num == 8)
		return("A");
}

