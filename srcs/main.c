/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:59:49 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/19 18:06:09 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	g_spec[11][4] = {{"sa"}, {"sb"}, {"ss"}, {"pa"}, {"pb"}, {"ra"}, {"rb"}, {"rr"}, {"rra"}, {"rrb"}, {"rrr"}};
static void	(*g_funcs[11]) (t_nbrs *a, t_nbrs *b) = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

static int8_t	match(char *line, t_nbrs *a, t_nbrs *b)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(g_spec[i], line) == 0)
		{
			(*g_funcs[i])(a, b);
			return (0);
		}
		++i;
	}
	return (-1);
}

static int8_t	reader(t_nbrs *a, t_nbrs *b)
{
	char	*line;
	int		ret;

	while ((ret = gnl(0, &line)) > 0)
	{
		GRD1(match(line, a, b) == -1, free(line), -1);
		print_stacks(a, b);
		free(line);
	}
	GRD(ret == -1, -1);
	if (sorted(a))
		ft_printf("OK");
	else
		ft_printf("KO");
	return (0);
}

static int8_t	init(int *nbrs, int len)
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

static int8_t	handle_args(int ac, char **av)
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

int				main(int ac, char **av)
{
	if (ac > 1)
		GRD1(handle_args(ac, av) == -1, ft_dprintf(STDERR_FILENO, "Error\n")
			, -1);
	return (0);
}
