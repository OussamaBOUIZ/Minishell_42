/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:35:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/18 17:49:03 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_H
# define LEXER_H
# include <string.h>
# include "minishell.h"
# include "exp.h"

typedef struct s_lex
{
	char	c;
	size_t	i;
	char	*string;
	size_t	str_len;
}				t_lex;

typedef enum
{
	_head,
	_chev,
	_ichev,
	_dchev,
	_dichev,
	_pipe,
	_word,
}	e_nat;

typedef struct s_toklist
{
	e_nat				nature;
	char				*lexeme;
	struct s_toklist	*next;
}					t_toklist;

t_lex		*init_lex(char *cmd_line);
void		lex_forward(t_lex *lex);
void		lex_backward(t_lex *lex);
char		*lex_gather_lexeme(t_lex *lex);
t_toklist	*new_token(int	nature, char *lexeme);
t_toklist	*new_io_token(t_lex *lex);
t_toklist	*get_tokens_list(t_lex *lex);
void		lex_skip_blanks(t_lex *lex);
size_t		get_lexeme_size(t_lex *lex);
char		*lex_gather_str(t_lex *lex, char quote);
char		*lex_gather_option(t_lex *lex);
char		*lex_strdup(t_lex *lex, int n);
void		lstadd_tok(t_toklist **lst, t_toklist *new_token);
t_toklist	*lexer(char *cmd_line);
void		print_tokens(t_toklist *tokens);
int			toklist_size(t_toklist *tokens);
int			is_symbol(char c);
#endif