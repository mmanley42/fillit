/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/23 18:20:29 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"
#include "ft_prog.h"

int			check_tetri(char *str, int start)
{
	int		adj;

	adj = 0;
	while (str[start])
	{
		if (str[start] && str[start] == '#')
		{
			if (str[start + 1] == '#')
				adj++;
			if (str[start - 1] == '#')
				adj++;
			if (str[start + 5] == '#')
				adj++;
			if (str[start - 5] == '#')
				adj++;
			start++;
		}
		else
			start++;
	}
	if (adj == 6 || adj == 8)
		return (1);
	else
		return (0);
}

t_forme		*tetri_compos(int a, t_forme *p)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	a = 0;
	while (p->tab[y])
	{
		while (p->tab[y][x] && p->tab[y][x] != p->myl)
			x++;
		if (p->tab[y][x] && p->tab[y][x] == p->myl && i == 0)
		{
			i++;
			x++;
		}
		if (p->tab[y][x] && p->tab[y][x] == p->myl && i == 1)
		{
			p->cmps->y1 = y - (int)p->yaxis;
			p->cmps->x1 = x - (int)p->xaxis;
			i++;
			x++;
		}
		if (p->tab[y][x] && p->tab[y][x] == p->myl && i == 2)
		{
			p->cmps->y2 = y - (int)p->yaxis;
			p->cmps->x2 = x - (int)p->xaxis;
			i++;
			x++;
		}
		if (p->tab[y][x] && p->tab[y][x] == p->myl && i == 3)
		{
			p->cmps->y3 = y - (int)p->yaxis;
			p->cmps->x3 = x - (int)p->xaxis;
			i++;
			x++;
		}
		x = 0;
		y++;
	}
	return (p);
}

void		pos_tetriminos(t_forme *pt, char **newt, int pos, int size)
{
	t_coor	co;
	int		i;

	co.y2 = 0;
	co.x2 = 0;
	co.y1 = pos / size;
	co.x1 = pos % size;
	i = 0;
	while (pt->tab[co.y2])
	{
		while (pt->tab[co.y2][co.x2] && pt->tab[co.y2][co.x2] != pt->myl)
			co.x2++;
		while (pt->tab[co.y2][co.x2] && pt->tab[co.y2][co.x2] == pt->myl)
		{
			co.x1 += (int)(co.x2 - (int)pt->xaxis);
			newt[co.y1][co.x1] = pt->tab[co.y2][co.x2];
			if (co.x1 != pos % size)
				co.x1 = pos % size;
			co.x2++;
			i++;
		}
		if (i != 0)
			co.y1++;
		co.x2 = 0;
		i = 0;
		co.y2++;
	}
}