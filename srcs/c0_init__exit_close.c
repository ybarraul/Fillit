/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c0_init__exit_close.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <ybarraul@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:27:58 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:38:07 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	init_memtet(t_eachtet *memtet)
{
	int		i;

	i = 0;
	memtet->size_each = 2;
	memtet->nb_tet = 0;
	while (i < 26)
	{
		memtet->list_tet[i].crds[0].x = 0;
		memtet->list_tet[i].crds[0].y = 0;
		memtet->list_tet[i].crds[1].x = 0;
		memtet->list_tet[i].crds[1].y = 0;
		memtet->list_tet[i].crds[2].x = 0;
		memtet->list_tet[i].crds[2].y = 0;
		memtet->list_tet[i].crds[3].x = 0;
		memtet->list_tet[i].crds[3].y = 0;
		memtet->list_tet[i].x = 0;
		memtet->list_tet[i].y = 0;
		memtet->list_tet[i].width = 0;
		memtet->list_tet[i].height = 0;
		memtet->list_tet[i].last = 0;
		i++;
	}
}

void	exit_close(int fd)
{
	write(1, "error\n", 6);
	close(fd);
	exit(2);
}
