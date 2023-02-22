/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:51:09 by ranascim          #+#    #+#             */
/*   Updated: 2023/02/23 00:31:08 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;
	//t_stack *dst_next;

	if ((*src) == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dst);
	(*dst) = (*src);
	//dst_next = (*dst)->next;
	//dst_next->prev = (*dst);
	(*src) = tmp;
	//(*src)->prev = NULL;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}