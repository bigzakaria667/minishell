/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:46:55 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/17 16:18:45 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_built_in(char *s)
{
	int	i;
	char	**built_in;

	i = 0;
	built_in = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	while (built_in[i])
	{
		if (ft_strncmp(s, built_in[i]), ft_strlen(built_in[i]) == 0)
			return (i);
	}
	return (-1);
}

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

int	main(int argc, char **argv, char **envp)
{
	if (built_in(argv[1], envp == 1)
		return (1);
	return (0);
}
