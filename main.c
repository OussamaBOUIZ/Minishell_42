/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 13:10:33 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "./Header/minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmdl	*cmd_line;
	int fd;

	fd = dup(0);
	shell.env = set_env(env);
	while (1)
	{
		handle_signals();
		cmd_line = parser(shell.env);
		execute(cmd_line, shell);
		dup2(fd, STDIN_FILENO);
	}
	return (0);
}
