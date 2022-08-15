
#ifndef "PARSING_H"
# define "PARSING_H"

char    *g_cmdline;

typedef struct	s_parse
{
	char		*builtnb[NB_BUILINS];
}				t_parse;

typedef struct	s_cmd
{
	char		**arg;
	char		**input_arg;
	int			nb_redir;
	int			apply_redir;
	int			redir_ok;
	int			pipe_ret;
	t_parse		parse;
}				t_cmd;

#endif