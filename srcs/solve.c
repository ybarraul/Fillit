/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/22 16:54:00 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:53:21 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void						ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = 0;
}

static inline void			ver_tet(t_onetet *tet, t_uint16_t *map)
{
	*((t_uint64_t *)(map + tet->y)) ^= (tet->size << tet->x);
}

static inline t_uint64_t	check_map(t_onetet *tet, t_uint16_t *map)
{
	return (!((*(t_uint64_t *)(map + tet->y)) & (tet->size << tet->x)));
}

static inline char			resolve_bis(t_eachtet *memtet,
							t_uint16_t *map, int n)
{
	t_onetet			*tet;

	tet = &(memtet->list_tet[n]);
	tet->y = (tet->last >= 0 ? memtet->list_tet[tet->last].y : 0);
	tet->x = (tet->last >= 0 ? memtet->list_tet[tet->last].x + 1 : 0);
	while (tet->y + tet->height < memtet->size_each)
	{
		while (tet->x + tet->width < memtet->size_each)
		{
			if (check_map(tet, map))
			{
				ver_tet(tet, map);
				if (n + 1 == memtet->nb_tet)
					return (1);
				else if (resolve_bis(memtet, map, n + 1))
					return (1);
				ver_tet(tet, map);
			}
			tet->x++;
		}
		tet->x = 0;
		tet->y++;
	}
	return (0);
}

void						resolve(t_eachtet *memtet)
{
	t_uint16_t			map[16];
	int					nb_tet;

	nb_tet = memtet->nb_tet;
	ft_bzero(map, sizeof(t_uint16_t) * 16);
	memtet->size_each = nb_tet > 1 ? ft_size_calc(4 * nb_tet) : 2;
	while (!resolve_bis(memtet, map, 0) && memtet->size_each < 16)
	{
		ft_bzero(map, sizeof(t_uint16_t) * 16);
		memtet->size_each++;
	}
}
