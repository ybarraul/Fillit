/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <ybarraul@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:08:21 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:59:42 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_eachtet	memtet;
	int			fd;

	if ((ac != 2) || ((fd = open(av[1], O_RDONLY)) < 0))
	{
		write(1, "usage: fillit source_file\n", 27);
		return (0);
	}
	init_memtet(&memtet);
	check_all(&memtet, fd);
	resolve(&memtet);
	print_tet(&memtet);
	close(fd);
	return (0);
}
