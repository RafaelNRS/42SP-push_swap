/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:58:01 by ranascim          #+#    #+#             */
/*   Updated: 2023/03/02 12:16:34 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*create_new_stack(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void	add_at_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
	{
		return ;
	}
	if (!*stack)
	{
		(*stack) = new;
		return ;
	}
	last = get_last(*stack);
	last->next = new;
}

t_stack	*initialize_stack(char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		add_at_bottom(&stack_a, create_new_stack(ft_atoi(argv[i])));
		i++;
	}
	return (stack_a);
}

int	get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack && stack->next != NULL)
	{
		i++;
		stack = stack->next;
	}
	if (i > 0 && stack->next == NULL)
		i++;
	if (i == 0 && stack != NULL)
		i++;
	return (i);
}

void	fill_indexes(t_stack **stack)
{
	t_stack	*s1;
	t_stack	*s2;

	s1 = (*stack);
	while (s1)
	{
		s1->index = 1;
		s2 = (*stack);
		while (s2)
		{
			if (s1->value > s2->value)
				s1->index++;
			s2 = s2->next;
		}
		s1 = s1->next;
	}
}
