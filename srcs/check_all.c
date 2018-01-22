/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_all.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <ybarraul@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:29:32 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:56:55 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int				check_coord(t_coord *crds, int i, char c, int fd)
{
	if (i % 5 == 4 && c != '\n')
		exit_close(fd);
	if (i % 5 == 4)
		return (0);
	if (c == '#')
	{
		crds->x = i % 5;
		crds->y = i / 5;
		return (1);
	}
	if (c != '.')
		exit_close(fd);
	return (0);
}

t_onetet		check_tet(char *str, int fd)
{
	int			xi;
	int			yi;
	int			i;
	t_onetet	tet;

	yi = 0;
	i = 0;
	while (yi < 4)
	{
		xi = 0;
		while (xi < 5)
		{
			i += check_coord(&(tet.crds[i]), yi * 5 + xi, str[yi * 5 + xi], fd);
			xi++;
		}
		yi++;
	}
	if (i != 4)
		exit_close(fd);
	return (tet);
}

int				check_link(char *str)
{
	int			i;
	int			cpt;

	i = 0;
	cpt = 0;
	while (str[cpt])
	{
		if (str[cpt] == '#')
		{
			if (str[cpt - 5] == '#' && (cpt - 5) >= 0)
				i++;
			if (str[cpt - 1] == '#' && (cpt - 1) >= 0)
				i++;
			if (str[cpt + 1] == '#' && (cpt + 1) < 20)
				i++;
			if (str[cpt + 5] == '#' && (cpt + 5) < 20)
				i++;
		}
		cpt++;
	}
	return (i);
}

void			check_list(t_eachtet *memtet, int fd)
{
	char		buff[21];
	int			len;
	int			lien;

	if ((len = read(fd, buff, 20)) == -1 || memtet->nb_tet >= 26)
		exit_close(fd);
	buff[len] = '\0';
	if (len != 20)
		exit_close(fd);
	lien = check_link(buff);
	if ((lien != 6) && (lien != 8))
		exit_close(fd);
	memtet->list_tet[(int)memtet->nb_tet] = check_tet(buff, fd);
	memtet->nb_tet++;
}

void			check_all(t_eachtet *memtet, int fd)
{
	char		c;
	int			len;

	check_list(memtet, fd);
	if ((len = read(fd, &c, 1)) == -1)
		exit_close(fd);
	while (len)
	{
		if (c != '\n')
			exit_close(fd);
		check_list(memtet, fd);
		if ((len = read(fd, &c, 1)) == -1)
			exit_close(fd);
	}
	if (!check_to_tet(memtet))
		exit_close(fd);
	move_tet(memtet);
	size_tet(memtet);
	end_tet(memtet);
}
