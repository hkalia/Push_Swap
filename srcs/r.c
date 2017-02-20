/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 17:57:43 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/19 17:59:47 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_nbrs *a, t_nbrs *b)
{
	int	tmp;

	(void)b;
	if (a->len > 1)
	{
		tmp = a->ptr[a->len - 1];
		ft_memmove(&a->ptr[1], a->ptr, a->len * sizeof(int));
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
		ft_memmove(&b->ptr[1], b->ptr, b->len * sizeof(int));
		b->ptr[0] = tmp;
	}
}

void	rr(t_nbrs *a, t_nbrs *b)
{
	ra(a, b);
	rb(a, b);
}
