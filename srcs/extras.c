/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:01:59 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/19 18:03:00 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	print_stacks(t_nbrs *a, t_nbrs *b)
{
	int	i;

	ft_printf("a :");
	i = 0;
	while (i < a->len)
		ft_printf(" %d", a->ptr[i++]);
	ft_printf("\n");
	ft_printf("b :");
	i = 0;
	while (i < b->len)
		ft_printf(" %d", b->ptr[i++]);
	ft_printf("\n");
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
