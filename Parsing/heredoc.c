/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:10:40 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/09 11:47:41 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	ft_heredoc(char *lim)
{
	t_hdoc	s;

	if (!lim)
		return (-1);
	hdoc_init(lim, &s);
	s.line = readline("> ");
	if (!s.line || ft_strncmp(s.line, lim, s.lim_l) == 0)
	{
		hd_free_close(&s);
		return (s.pip[0]);
	}
	write(s.pip[1], s.line, ft_strlen(s.line));
	free(s.line);
	while (1)
	{
		s.line = readline("> ");
		s.e = ft_hd_short(s.line, lim, s.pip[1]);
		if (s.e == -1)
			break ;
		free(s.line);
	}
	hd_free_close(&s);
	return (s.pip[0]);
}
