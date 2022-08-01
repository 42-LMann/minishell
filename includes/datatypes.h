#ifndef DATATYPES_H
# define DATATYPES_H

# include "minishell_h"
# include <teminos.h>

typedef enum e_bool
{
    FALSE,
    TRUE
}   t_bool

typedef enum e_err
{
    NO_ERROR,
    MALLOC_FAIL,
    INPUT_ERR,
    KEY_ERR,
    NO_Value,
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
}   t_nodetype