/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:29:33 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 12:50:39 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

# include "minishell.h"
# include <termios.h>



typedef enum e_bool
{
    FALSE,
    TRUE
}   t_bool;

typedef enum e_err
{
    NO_ERROR,
    MALLOC_FAIL,
    INPUT_ERR,
    KEY_ERR,
    NO_VALUE,
    NO_KEY,
    SYNTAX_ERR,
    EMPTY,
    DEFAULT_ERR
}   t_err;

typedef enum s_nodetype
{
    PIPE,
    NO_PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APP,
    HERE_DOC,
    CMD
}   t_nodetype;

typedef enum s_token_type
{
	TOK_WORD,
	TOK_PIPE,
	TOK_QUOTE,
	TOK_DQUOTE,
	TOK_DOLLAR,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_APPEND,
	TOK_HERE_DOC,
	TOK_SPACE,
	TOK_NO_TOKENS,
	TOK_ERROR
}		t_token_type;

typedef struct s_tree
{
	int				id;
	t_nodetype		type;
	char			**data;
	struct s_tree	*left_node;
	struct s_tree	*right_node;
	struct s_tree	*prev_node;
}		t_tree;

typedef struct s_token_list
{
	int					id;
	t_token_type		type;
	t_bool				is_parsed;
	char				*data;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}		t_token_list;

typedef struct s_token
{
	t_token_list	*lexer;
	t_tree			*tree;
}		t_token;

typedef struct s_envi
{
	struct termios	termios_p;
	int				exitcode;
	t_executor		*exec;
	t_tree			**loc_tree_ptr;
}		t_envi;

#endif