/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_tet.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <ybarraul@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:29:49 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:53:45 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int				ft_size_calc(int nb)
{
	int			res;

	res = 1;
	while (res * res < nb)
		res++;
	return (res - 1);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			print_alpha(t_eachtet *memtet, int x, int y)
{
	int		i;

	i = 0;
	while (i < memtet->nb_tet)
	{
		if (pos_tet(&memtet->list_tet[i], x - memtet->list_tet[i].x,
											y - memtet->list_tet[i].y))
		{
			ft_putchar('A' + i);
			return ;
		}
		i++;
	}
	ft_putchar('.');
}

void			print_tet(t_eachtet *memtet)
{
	int		xi;
	int		yi;

	yi = 0;
	while (yi < memtet->size_each)
	{
		xi = 0;
		while (xi < memtet->size_each)
		{
			print_alpha(memtet, xi, yi);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}
