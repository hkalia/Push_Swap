/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:59:49 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/09 11:17:43 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "string.h"
void	sa(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)b;
	if (a->len > 1)
	{
		tmp = a->ptr[a->len - 1];
		a->ptr[a->len - 1] = a->ptr[a->len - 2];
		a->ptr[a->len - 2] = tmp;
	}
}

void	sb(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)a;
	if (b->len > 1)
	{
		tmp = b->ptr[b->len - 1];
		b->ptr[b->len - 1] = b->ptr[b->len - 2];
		b->ptr[b->len - 2] = tmp;
	}
}

void	ss(t_nbrs *a, t_nbrs *b)
{
	sa(a, b);
	sb(a, b);
}

void	pa(t_nbrs *a, t_nbrs *b)
{
	if (b->len > 0)
		a->ptr[++a->len - 1] = b->ptr[b->len-- - 1];
}

void	pb(t_nbrs *a, t_nbrs *b)
{
	if (a->len > 0)
		b->ptr[++b->len - 1] = a->ptr[a->len-- - 1];
}

void	ra(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)b;
	if (a->len > 1)
	{
		tmp = a->ptr[a->len - 1];
		memmove(&a->ptr[1], a->ptr, a->len * sizeof(int));
		a->ptr[0] = tmp;
	}
}

void	rb(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)a;
	if (b->len > 1)
	{
		tmp = b->ptr[b->len - 1];
		memmove(&b->ptr[1], b->ptr, b->len * sizeof(int));
		b->ptr[0] = tmp;
	}
}

void	rr(t_nbrs *a, t_nbrs *b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)b;
	if (a->len > 1)
	{
		tmp = a->ptr[0];
		memmove(a->ptr, &a->ptr[1], a->len * sizeof(int));
		a->ptr[a->len - 1] = tmp;
	}
}

void	rrb(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)a;
	if (b->len > 1)
	{
		tmp = b->ptr[0];
		memmove(b->ptr, &b->ptr[1], b->len * sizeof(int));
		b->ptr[b->len - 1] = tmp;
	}
}

void	rrr(t_nbrs *a, t_nbrs *b)
{
	rra(a, b);
	rrb(a, b);
}

static char	g_spec[11][4] = {{"sa"}, {"sb"}, {"ss"}, {"pa"}, {"pb"}, {"ra"}
							, {"rb"}, {"rr"}, {"rra"}, {"rrb"}, {"rrr"}};

static void	(*g_funcs[11]) (t_nbrs *a, t_nbrs *b) = {sa, sb, ss, pa, pb, ra, rb
													, rr, rra, rrb, rrr};

bool	sorted(t_nbrs *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		GRD(a->ptr[i] < a->ptr[i + 1], 0);
		++i;
	}
	return (1);
}

bool	check(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	if (s1[i] == 0 && s2[i] == '\n')
		return (1);
	return (0);
}

int8_t	reader(t_nbrs *a, t_nbrs *b)
{
	char	*line;
	size_t	cap;
	ssize_t	len;
	int		i;

	line = 0;
	cap = 0;
	while ((len = getline(&line, &cap, stdin)) > 0)
	{
		i = 0;
		while (i < 11)
		{
			if (check(g_spec[i], line))
			{
				(*g_funcs[i])(a, b);
				break ;
			}
			++i;
		}
		free(line);
		line = 0;
		cap = 0;
	}
	if (sorted(a))
		printf("OK");
	else
		printf("KO");
	return (0);
}

int8_t	init(int *nbrs, int len)
{
	t_nbrs	a;
	t_nbrs	b;
	int		i;

	GRD((a.ptr = malloc(sizeof(int) * (len + 1))) == 0, -1);
	GRD((b.ptr = malloc(sizeof(int) * (len + 1))) == 0, -1);
	a.len = len;
	b.len = 0;
	i = 0;
	while (i < len)
	{
		a.ptr[i] = nbrs[(len - 1) - i];
		++i;
	}
	GRD2(reader(&a, &b) == -1, free(a.ptr), free(b.ptr), -1);
	return (0);
}

int8_t	check_dup(int *nbrs, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			GRD(nbrs[i] == nbrs[j], -1);
			++j;
		}
		++i;
	}
	return (0);
}

int8_t	handle_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	*endptr;
	int		nbrs[ac - 1];

	i = 1;
	while (i < ac)
	{
		endptr = 0;
		tmp = strtol(av[i], &endptr, 10);
		GRD(*endptr != 0, -1);
		GRD(tmp > 2147483647 || tmp < -2147483648, -1);
		nbrs[i - 1] = (int)tmp;
		++i;
	}
	GRD(check_dup(nbrs, ac - 1) == -1, -1);
	GRD(init(nbrs, ac - 1) == -1, -1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		GRD1(handle_args(ac, av) == -1, fprintf(stderr, "Error\n"), -1);
	return (0);
}
