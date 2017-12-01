/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:02:10 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/01 17:04:04 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_prog.h"

void	ft_lstadd_end(t_forme **alst, t_forme *new)
{
	t_forme *tmp;

	printf("%s\n", new->tab[0]);
	printf("%p\n", alst);
	if (alst && new)
	{
		printf("Rentre\n");
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
			printf("%s\n", tmp->tab[0]);
			printf("%s\n", tmp->tab[1]);
			printf("%s\n", tmp->tab[2]);
			printf("%s\n", tmp->tab[3]);
		}
		else
		{
			*alst = (t_forme*)malloc(sizeof(t_forme));
			*alst = new;
		}
	}
}
