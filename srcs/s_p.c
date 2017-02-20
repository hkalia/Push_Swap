/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 17:55:16 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/19 17:57:25 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
