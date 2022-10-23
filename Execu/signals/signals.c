/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:25:47 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 09:30:00 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	handler(int signum)
{
	if (signum == SIGQUIT)
		printf("SIGQUIT OCCURED\n");
	else if (signum == SIGINT)
		printf("SIGINT OCCURED\n");
}

void	interrupt_handle()
{
	// printf("WE should give the prompt back\n");
	// rl_replace_line();
	exit(0);
}

void	handle_signals()
{
	signal(SIGINT, interrupt_handle);
	signal(SIGQUIT, SIG_IGN);
}
