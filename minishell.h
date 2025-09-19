/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:55:05 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/19 18:41:03 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "functions/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

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

#endif
