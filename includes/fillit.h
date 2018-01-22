/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <ybarraul@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 11:31:00 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:56:13 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef unsigned short int		t_uint16_t;
typedef unsigned long long int	t_uint64_t;
typedef unsigned long int		t_size_t;

typedef struct					s_coord
{
	int			x;
	int			y;
}								t_coord;

typedef struct					s_onetet
{
	t_coord						crds[4];
	t_uint64_t					size;
	int							x;
	int							y;
	int							width;
	int							height;
	int							last;
}								t_onetet;

typedef struct					s_eachtet
{
	t_onetet					list_tet[26];
	int							nb_tet;
	int							size_each;
}								t_eachtet;

void							init_memtet(t_eachtet *memtet);
void							exit_close(int fd);
void							check_all(t_eachtet *memtet, int fd);
int								check_link(char *str);
int								ft_size_calc(int nb);
void							check_list(t_eachtet *memtet, int fd);
t_onetet						check_tet(char *str, int fd);
int								check_coord(t_coord *crds, int i,
								char c, int fd);
char							check_to_tet(t_eachtet *memtet);
char							check_solo(t_onetet *tet);
char							check_duo(t_onetet *tet);
char							check_tier(t_onetet *tet, int x, int y);
char							pos_tet(t_onetet *tet, int x, int y);
void							move_tet(t_eachtet *tet);
void							corners(t_onetet *tet);
void							size_tet(t_eachtet *memtet);
void							measure_tet(t_onetet *tet);
t_uint64_t						the_size(t_onetet *tet);
char							swap(char a, char b);
void							end_tet(t_eachtet *memtet);
void							the_last(t_eachtet *memtet, int n);
char							idm_tet(t_onetet tet1, t_onetet tet2);
void							resolve(t_eachtet *memtet);
static inline char				resolve_bis(t_eachtet *memtet,
								t_uint16_t *map, int n);
static inline t_uint64_t		check_map(t_onetet *tet, t_uint16_t *map);
static inline void				ver_tet(t_onetet *tet, t_uint16_t *map);
void							ft_bzero(void *s, size_t n);
void							print_tet(t_eachtet *memtet);
void							print_alpha(t_eachtet *memtet, int x, int y);
void							ft_putchar(char c);

#endif
