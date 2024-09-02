/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:10:27 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 18:54:36 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

static t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**input;

	if (argc == 1)
		input = ft_split(*argv, ' ');
	else
		input = argv;
	if (!argv)
		return (NULL);
	stack = create_stack(arr_len(input), input, 'a');
	if (argc == 1)
		free_arr(input);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = init_stack(argc - 1, argv + 1);
	b = NULL;
	if (!a)
		return (write(2, "Error\n", 6));
	if (!a->next)
		return (free_stack(&a), 0);
	sort_stack(&a, &b);
	free_stack(&a);
}
