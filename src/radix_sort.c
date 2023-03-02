/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:55:25 by ranascim          #+#    #+#             */
/*   Updated: 2023/03/02 13:17:34 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_stack **stack)
{
	t_stack	*stack_tmp;

	stack_tmp = *stack;
	while (stack_tmp->next != NULL)
	{
		if (stack_tmp->value > stack_tmp->next->value)
			return (0);
		stack_tmp = stack_tmp->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
{
	int		max_index;
	t_stack	*stack_tmp;

	stack_tmp = *stack;
	max_index = stack_tmp->index;
	if (is_sorted(stack))
		return ;
	while (stack_tmp)
	{
		if (stack_tmp->index > max_index)
			max_index = stack_tmp->index;
		stack_tmp = stack_tmp->next;
	}
	if ((*stack)->index == max_index)
		ra(stack);
	else if ((*stack)->next->index == max_index)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_four_five(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(*stack_a) > 3 && !(is_sorted(stack_a)))
	{
		if ((*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else if ((*stack_a)->index == 2 && get_stack_size(*stack_b) == 1)
			pb(stack_a, stack_b);
		else if ((*stack_a)->next->index == 1 || \
			((*stack_a)->next->index == 2 && get_stack_size(*stack_b) == 1))
			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_three(stack_a);
	while (get_stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size_b;
	int	max_num;
	int	i;
	int	j;

	max_num = get_stack_size(*stack_a);
	i = 0;
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j++ < max_num)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		i++;
		size_b = get_stack_size(*stack_b);
		while (size_b > 0)
		{
			pa(stack_a, stack_b);
			size_b--;
		}
	}
}
