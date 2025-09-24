/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:52:21 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/24 16:00:27 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_node(t_env **node, char *name, char *value)
{
	(*node)->name = ft_strdup(name);
	(*node)->value = ft_strdup(value);
}

void	print_list(t_env *list)
{
	t_env	*current;

	current = list;
	while (current)
	{
		printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
}
