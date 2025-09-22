/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:46:55 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/22 17:05:28 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_shell *shell)
{
	t_env	*current;

	current = shell->envp;
	while (current)
	{
		printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
}

int	check_built_in(char *s)
{
	int	i;
	char	*built_in[7];

	i = 0;
	built_in[0] = "echo";
	built_in[1] = "cd";
	built_in[2] = "pwd";
	built_in[3] = "export";
	built_in[4] = "unset";
	built_in[5] = "env";
	built_in[6] = "exit";
	while (i <= 6)
	{
		if (ft_strncmp(s, built_in[i], INT_MAX) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	built_in(char *s, t_shell **shell)
{
	int	error;

	error = check_built_in(s);
	if (error == 0)
		return (printf("echo"));
	if (error == 1)
		return (printf("cd"));
	if (error == 2)
		return (printf("pwd"));
	if (error == 3)
		return (printf("export"));
	if (error == 4)
		return (printf("unset"));
	if (error == 5)
		return (print_list(*shell), 0);	
	if (error == 6)
		return (printf("exit"));
	else
		return (1);
	return (0);
}

void	init_node(t_env **node)
{
	*node = malloc(sizeof(t_env));
	if (!(*node))
		return ;
	(*node)->name = NULL;
	(*node)->value = NULL;
	(*node)->next = NULL;
}

void	insert_node(t_env **node, char *name, char *value)
{
	(*node)->name = ft_strdup(name);
	(*node)->value = ft_strdup(value);
}

void	init_shell(t_shell **shell)
{
	*shell = malloc(sizeof(t_shell));
	(*shell)->envp = NULL;
}

int	envp_into_list(char **envp, t_shell **shell)
{
	int	i;
	char	**split;
	t_env	*last;
	t_env	*current;

	i = 0;
	init_shell(shell);
	while (envp[i])
	{
		init_node(&current);
		split = ft_split(envp[i], '=');
		insert_node(&current, split[0], split[1]);
		if (i == 0)
			(*shell)->envp = current;
		else
			last->next = current;
		last = current;
		current = current->next;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	if (argc <= 1)
		return (1);
	if (envp_into_list(envp, &shell) == 1)
		return (printf("Error") ,1);
	if (built_in(argv[1], &shell) == 1)
		return (printf("Error") ,1);
	return (0);
}
