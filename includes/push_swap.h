/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:57:41 by hkalia            #+#    #+#             */
/*   Updated: 2017/02/19 18:03:35 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
#  define GRD4(a, b, c, d, e, f) do{if(a){b;c;d;e;return(f);}}while(0)
#  define GRD5(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;return(g);}}while(0)
#  define GRD6(a, b, c, d, e, f, g, h) do{if(a){b;c;d;e;f;g;return(h);}}while(0)
# endif

# define BUFF_SIZE 20

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <libarr.h>
# include <libft.h>
# include <libftprintf.h>

typedef struct	s_nbrs
{
	int			*ptr;
	int			len;
}				t_nbrs;

int				gnl(const int fd, char **line);
void			sa(t_nbrs *a, t_nbrs *b);
void			sb(t_nbrs *a, t_nbrs *b);
void			ss(t_nbrs *a, t_nbrs *b);
void			pa(t_nbrs *a, t_nbrs *b);
void			pb(t_nbrs *a, t_nbrs *b);
void			ra(t_nbrs *a, t_nbrs *b);
void			rb(t_nbrs *a, t_nbrs *b);
void			rr(t_nbrs *a, t_nbrs *b);
void			rra(t_nbrs *a, t_nbrs *b);
void			rrb(t_nbrs *a, t_nbrs *b);
void			rrr(t_nbrs *a, t_nbrs *b);
bool			sorted(t_nbrs *a);
void			print_stacks(t_nbrs *a, t_nbrs *b);
int8_t			check_dup(int *nbrs, int len);

#endif
