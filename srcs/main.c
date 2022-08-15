/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:46:30 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 16:54:09 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "term_colours.h"
#include "data_types.h"

void	print_text_prompt(void)
{
	printf("%s@%s:%s$",
		find_path(g_envs, "USER="), find_path(g_envs, "LOGNAME="), find_path(g_envs, "PWD="));
	write(1, GREEN, 7);
	printf("Minishell > ");
	write(1, RESET, 7);
}

t_err	process_input(char *line, t_curr_input *input, t_envi *info)
{
	int						i;
	t_err					err;
	static t_proc_input_ptr	proc_funptr[3] = {
	[0] = lexer,
	[1] = expander,
	[2] = parser
	};

	i = 0;
	while (i < 3)
	{
		err = proc_funptr[i](line, input, info);
		if (err != NO_ERROR)
		{
			if (err == SYNTAX_ERR)
				info->exitcode = 258;
			return (err);
		}
		i++;
	}
	clean_lexer(&input->lexer);
	return (NO_ERROR);
}

t_err	get_input(t_envi *envi, char **input_ptr)
{
	char	*temp;

	set_term_settings();
	rl_replace_line("", 0);
	*input_ptr = readline(YEL PROMPT RESET);
	restore_term_settings(&envi->termios_p);
	if (*input_ptr && (*input_ptr)[0])
	{
		temp = *input_ptr;
		*input_ptr = ft_strtrim_white(*input_ptr);
		free(temp);
		if (!*input_ptr)
			return (MALLOC_FAIL);
		add_history(*input_ptr);
	}
	//else if (!*input_ptr)
		//ft_exit_sig(envi);
	return (NO_ERROR);
}

int	loop_mini(t_envi *envi, t_token *token_list)
{
	char	*input;
	int		status = 0;
	t_err	rv;

	g_cmdline = readline(">>> ");
	while (status == 0 || g_cmdline != NULL)
	{
		init_sigs();
		if (get_input(envi, g_cmdline) == MALLOC_FAIL)
			return (-1);
		if (!input)
			continue;
		rv = process_input(input, token_list, envi);
		free (input)
		if (rv != NO_ERROR)
		{
			clean_tree(&token_list->tree)
			clean_lexer(&token_list->lexer)
			if (rv == MALLOC_FAIL)
				exit (-1);
			continue;
		}
		ignore_sigs();
		ft_start_tree(envi, &token_list->tree);
	}
}

int	minishell(char **env)
{
	t_envi	envi;
	t_token	token_list;

	g_envs = env_init(&g_envs, env);
	save_term_settings(&envi->termios_p);
	if (loop_mini(&envi, &token_list) != 0)
	{
		free(g_cmdline);
		ft_lstclear(&g_envs, free);
	}
	return (0);
}

int	main(int argc, char *argv[argc], char **env)
{
	(void)argc;
	(void)argv;
	minishell(env);
	return(0);
}