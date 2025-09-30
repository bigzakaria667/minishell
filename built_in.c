/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:46:55 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/30 18:13:19 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (ft_strncmp(s, built_in[i], ft_strlen(built_in[i])) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	built_in(char *s, char**envp, t_shell **shell)
{
	int	error;

	error = check_built_in(s);
	if (error == 0)
		printf("echo\n");
	if (error == 1)
		printf("cd\n");
	if (error == 2)
		ft_pwd(envp);
	if (error == 3)
		ft_export(&(*shell)->envp);
	if (error == 4)
		printf("unset\n");
	if (error == 5)
		ft_env(s, (*shell)->envp);
	if (error == 6)
		ft_exit(s);
	return (0);
}

int	envp_into_list(char **envp, t_shell **shell)
{
	int	i;
	char	**split;
	t_env	*last;
	t_env	*current;

	i = 0;
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
	char	*input;

	(void)argc;
	(void)argv;
	init_shell(&shell);
	if (!shell)
		return (1);
	if (envp_into_list(envp, &shell) == 1)
		return (printf("Error\n") ,1);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break;
		if (built_in(input, envp, &shell) == 1)
			return (printf("Error\n") ,1);
		free(input);
	}
	return (0);
}
