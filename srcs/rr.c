/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 17:59:54 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/19 18:00:03 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)b;
	if (a->len > 1)
	{
		tmp = a->ptr[0];
		ft_memmove(a->ptr, &a->ptr[1], a->len * sizeof(int));
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
		ft_memmove(b->ptr, &b->ptr[1], b->len * sizeof(int));
		b->ptr[b->len - 1] = tmp;
	}
}

void	rrr(t_nbrs *a, t_nbrs *b)
{
	rra(a, b);
	rrb(a, b);
}
