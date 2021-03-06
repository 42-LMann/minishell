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

#endif