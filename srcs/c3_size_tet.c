/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c3_size_tet.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <ybarraul@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:29:00 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:43:04 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char			swap(char a, char b)
{
	return (a < b ? b : a);
}

t_uint64_t		the_size(t_onetet *tet)
{
	t_uint64_t		size;
	t_uint16_t		*to;

	size = 0;
	to = (t_uint16_t *)(&size);
	to[(int)tet->crds[0].y] |= 1 << tet->crds[0].x;
	to[(int)tet->crds[1].y] |= 1 << tet->crds[1].x;
	to[(int)tet->crds[2].y] |= 1 << tet->crds[2].x;
	to[(int)tet->crds[3].y] |= 1 << tet->crds[3].x;
	return (size);
}

void			measure_tet(t_onetet *tet)
{
	tet->width = swap(tet->crds[0].x, tet->crds[1].x);
	tet->width = swap(tet->width, tet->crds[2].x);
	tet->width = swap(tet->width, tet->crds[3].x);
	tet->height = swap(tet->crds[0].y, tet->crds[1].y);
	tet->height = swap(tet->height, tet->crds[2].y);
	tet->height = swap(tet->height, tet->crds[3].y);
	tet->size = the_size(tet);
}

void			size_tet(t_eachtet *memtet)
{
	int			i;

	i = 0;
	while (i < memtet->nb_tet)
	{
		measure_tet(&(memtet->list_tet[i]));
		i++;
	}
}
