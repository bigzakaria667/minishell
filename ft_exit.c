/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:39:56 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/09/24 19:52:09 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	check_is_alpha(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char 	*delete_quote(char *s)
{
	int	i;
	int	len;
	char	*s_no_quote;

	i = 0;
	len = ft_strlen(s);
	if ((s[0] == '"' && s[len - 1] == '"') || (s[0] == '\'' && s[len - 1] == '\''))
	{
		s_no_quote = malloc(sizeof(char) + len - 2 + 1);
		while (i < len - 2)
		{
			s_no_quote[i] = s[i + 1];
			i++;
		}
		return (s_no_quote);
	}
	return (s);
}

void	ft_exit(char *s)
{
	char	**split;
	int	args;

	split = ft_split(s, ' ');
	args = count_args(split);
	if (args == 1)
		exit(0);
	else if (args == 2)
	{
		split[1] = delete_quote(split[1]);
		if (check_is_digit(split[1]) == 1)
			exit(ft_atoi(split[1]));
		else if (check_is_alpha(split[1]) == 1)
			exit(255);
		else
		{
			printf("exit: %s: numeric argument required\n", split[1]);
			exit(2);
		}
	}
	else
		printf("exit: too many arguments\n");
}
