/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:07:31 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/14 18:09:04 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/lexer.h"

t_toklist	*new_token(int nature, char *lexeme)
{
	t_toklist	*token;

	token = malloc(sizeof(t_toklist));
	if (!token)
		malloc_fail();
	token->nature = nature;
	token->lexeme = lexeme;
	token->next = NULL;
	return (token);
}

t_toklist	*get_tokens_list(t_lex *lex)
{
	t_toklist	*head;

	head = new_token(_head, NULL);
	while (lex->c)
	{
		if (ft_isblank(lex->c))
			lex_skip_blanks(lex);
		else if (lex->c == '\"' || lex->c == '\'')
			lstadd_tok(&head, new_token(_str, lex_gather_str(lex, lex->c)));
		else if (lex->c == '<' || lex->c == '>')
			lstadd_tok(&head, new_io_token(lex));
		else if (lex->c == '|')
			lstadd_tok(&head, new_token(_pipe, lex_strdup(lex, 1)));
		else
			lstadd_tok(&head, new_token(_str, lex_gather_lexeme(lex)));
		lex_forward(lex);
	}
	return (head);
}





