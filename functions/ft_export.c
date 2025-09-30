/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:52:50 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/30 18:39:40 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(t_env *envp)
{
	while (envp)
	{
		printf("declare -x %s=%s\n", envp->name, envp->value);
		envp = envp->next;
	}
}

void	add_with_value(t_envp **envp)
{
	while (*envp)
		*envp = *envp->next;
}

void	add_without_value(t_envp **envp)
{
	while (*envp)
		*envp = *envp->next;
}

void	ft_export(t_env **envp)
{
	// EXPORT
	if (argc == 1)
		print_export(*envp);
	// EXPORT VAR=value
		// SPLIT LE DEUXIEME ARG
	// EXPORT VAR
		
	// EXPORT VAR1=val1 VAR2=val2
}
