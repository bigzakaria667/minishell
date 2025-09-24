/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:49:41 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/24 15:50:57 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_node(t_env **node)
{
	*node = malloc(sizeof(t_env));
	if (!(*node))
		return ;
	(*node)->name = NULL;
	(*node)->value = NULL;
	(*node)->next = NULL;
}

void	init_shell(t_shell **shell)
{
	*shell = malloc(sizeof(t_shell));
	(*shell)->envp = NULL;
}
