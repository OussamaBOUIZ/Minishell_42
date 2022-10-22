/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/22 10:39:26 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./Header/minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmdl	*cmd_line;

	shell.env = set_env(env);
	while (1)
	{
		cmd_line = parser(shell.env);
		// add_history(cmd_line);
		print_parsing_lst(cmd_line);
		//execute(cmd_line, shell);
		// handle_signals();
	}
	return (0);
}
