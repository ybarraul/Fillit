/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c2_move_tet.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 19:55:28 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:41:00 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		corners(t_onetet *tet)
{
	while (tet->crds[0].x && tet->crds[1].x &&
			tet->crds[2].x && tet->crds[3].x)
	{
		tet->crds[0].x--;
		tet->crds[1].x--;
		tet->crds[2].x--;
		tet->crds[3].x--;
	}
	while (tet->crds[0].y && tet->crds[1].y &&
			tet->crds[2].y && tet->crds[3].y)
	{
		tet->crds[0].y--;
		tet->crds[1].y--;
		tet->crds[2].y--;
		tet->crds[3].y--;
	}
}

void		move_tet(t_eachtet *tet)
{
	int		i;

	i = 0;
	while (i < tet->nb_tet)
	{
		corners(&(tet->list_tet[i]));
		i++;
	}
}
