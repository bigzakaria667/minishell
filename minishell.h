/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:55:05 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/24 18:12:48 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "functions/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
	struct s_env	*envp;
}			t_shell;

typedef struct s_env
{
	char		*name;
	char		*value;
	struct s_env	*next;
}			t_env;

/*----------------  built_in.c  ---------------*/
int	check_built_in(char *s);
int	built_in(char *s, char **envp, t_shell **shell);
int	envp_into_list(char **envp, t_shell **shell);
int	main(int argc, char **argv, char **envp);
/*----------------  init.c  ---------------*/
void	init_node(t_env **node);
void	init_shell(t_shell **shell);
/*----------------  list.c  ---------------*/
void	insert_node(t_env **node, char *name, char *value);
void	print_list(t_env *list);
/*----------------  ft_env.c  ---------------*/
void	ft_env(char *s, t_env *envp);
/*----------------  ft_pwd.c  ---------------*/
void	ft_pwd(char **envp);
/*----------------  ft_exit.c  ---------------*/
int	count_args(char	**split);
int	check_is_alpha(char *s);
int	check_is_digit(char *s);
void	ft_exit(char *s);

#endif
