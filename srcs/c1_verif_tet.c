/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c1_verif_tet.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <ybarraul@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:28:37 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:56:20 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		pos_tet(t_onetet *tet, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((tet->crds[i].x == x) && (tet->crds[i].y == y))
			return (1);
		i++;
	}
	return (0);
}

char		check_tier(t_onetet *tet, int x, int y)
{
	int		cas;

	cas = 0;
	cas = cas + ((pos_tet(tet, x + 1, y)) && (pos_tet(tet, x + 2, y)));
	cas = cas + ((pos_tet(tet, x + 1, y)) && (pos_tet(tet, x + 1, y + 1)));
	cas = cas + ((pos_tet(tet, x + 1, y)) && (pos_tet(tet, x + 1, y - 1)));
	cas = cas + ((pos_tet(tet, x - 1, y)) && (pos_tet(tet, x - 2, y)));
	cas = cas + ((pos_tet(tet, x - 1, y)) && (pos_tet(tet, x - 1, y + 1)));
	cas = cas + ((pos_tet(tet, x - 1, y)) && (pos_tet(tet, x - 1, y - 1)));
	cas = cas + ((pos_tet(tet, x, y + 1)) && (pos_tet(tet, x, y + 2)));
	cas = cas + ((pos_tet(tet, x, y + 1)) && (pos_tet(tet, x + 1, y + 1)));
	cas = cas + ((pos_tet(tet, x, y + 1)) && (pos_tet(tet, x - 1, y + 1)));
	cas = cas + ((pos_tet(tet, x, y - 1)) && (pos_tet(tet, x, y - 2)));
	cas = cas + ((pos_tet(tet, x, y - 1)) && (pos_tet(tet, x + 1, y - 1)));
	cas = cas + ((pos_tet(tet, x, y - 1)) && (pos_tet(tet, x - 1, y - 1)));
	return (cas);
}

char		check_duo(t_onetet *tet)
{
	int		i;
	char	x;
	char	y;
	int		cas;

	i = 0;
	while (i < 4)
	{
		x = tet->crds[i].x;
		y = tet->crds[i].y;
		cas = pos_tet(tet, x + 1, y) + pos_tet(tet, x, y + 1);
		cas = cas + pos_tet(tet, x - 1, y) + pos_tet(tet, x, y - 1);
		if (cas >= 2)
			return (1);
		cas = check_tier(tet, x, y);
		if (!cas)
			return (0);
		i++;
	}
	return (1);
}

char		check_solo(t_onetet *tet)
{
	int		i;
	int		cas;

	i = 0;
	while (i < 4)
	{
		cas = 0;
		cas = cas + pos_tet(tet, tet->crds[i].x + 1, tet->crds[i].y);
		cas = cas + pos_tet(tet, tet->crds[i].x, tet->crds[i].y + 1);
		cas = cas + pos_tet(tet, tet->crds[i].x - 1, tet->crds[i].y);
		cas = cas + pos_tet(tet, tet->crds[i].x, tet->crds[i].y - 1);
		if (!cas)
			return (0);
		i++;
	}
	return (1);
}

char		check_to_tet(t_eachtet *memtet)
{
	int		i;

	i = 0;
	while (i < memtet->nb_tet - 1)
	{
		if (!check_solo(&memtet->list_tet[i]))
			return (0);
		if (!check_duo(&memtet->list_tet[i]))
			return (0);
		i++;
	}
	return (1);
}
