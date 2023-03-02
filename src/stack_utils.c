/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:59:24 by ranascim          #+#    #+#             */
/*   Updated: 2023/03/02 12:15:33 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*get_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_last_but_one(t_stack *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	print_stack(t_stack **stack)
{
	t_stack	*stack_tmp;

	stack_tmp = *stack;
	while (stack_tmp && stack_tmp->next != NULL)
	{
		ft_printf("Value: %d - Index: %d\n", stack_tmp->value, stack_tmp->index);
		stack_tmp = stack_tmp->next;
	}
	if (stack_tmp)
		ft_printf("Value: %d - Index: %d\n", stack_tmp->value, stack_tmp->index);
}
