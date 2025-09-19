/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:46:55 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/19 18:52:07 by zel-ghab         ###   ########.fr       */
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
	char	**built_in;

	i = 0;
	built_in = NULL;
	built_in[0] = "echo";
	built_in[1] = "cd";
	built_in[2] = "pwd";
	built_in[3] = "export";
	built_in[4] = "unset";
	built_in[5] = "env";
	built_in[6] = "exit";
	while (built_in[i])
	{
		if (ft_strncmp(s, built_in[i], ft_strlen(built_in[i])), ft_strlen(built_in[i]) == 0)
			return (i);
	}
	return (-1);
}

/*
int	built_in(char *s, char **envp)
{
	if (check_built_in(s) == 0)
		ft_echo();
	if (check_built_in(s) == 1)
		ft_cd();
	if (check_built_in(s) == 2)
		ft_pwd();
	if (check_built_in(s) == 3)
		ft_export();
	if (check_built_in(s) == 4)
		ft_unset();
	if (check_built_in(s) == 5)
		ft_env();
	if (check_built_in(s) == 6)
		ft_exit();
	else
		return (1);
	return (0);
}
*/

int	envp_into_list(char **envp, t_shell **shell)
{
	int	i;
	char	**split;
	t_env	*current;

	i = 0;
	while (envp[i])
	{
		split = ft_split(envp[i], '=');			
		current = malloc(sizeof(t_env));
		if (!current)
			return (1);
		current->name = ft_strdup(split[0]);
		current->value = ft_strdup(split[1]);
		current->next = NULL;
		if (i == 0)
			(*shell)->envp = current; 
		current = current->next;
		i++;
	}
	return (0);
}

void	init_shell(t_shell **shell)
{
	*shell = malloc(sizeof(t_shell));
	(*shell)->envp = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	init_shell(&shell);
	if (envp_into_list(envp, &shell) == 1)
		return (1);
	//if (built_in(argv[1]), envp == 1)
	//	return (1);
	print_list(shell);	
	return (0);
}
