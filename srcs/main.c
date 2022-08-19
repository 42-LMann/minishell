/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:46:30 by lmann             #+#    #+#             */
/*   Updated: 2022/08/19 14:56:41 by lmann            ###   ########.fr       */
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

t_err	process_input(char *line, t_curr_input *g_cmdline, t_envi *info)
{
	int						i;
	t_err					err;
	static t_proc_cmd_line	proc_funptr[3] = {
	[0] = lexer,
	[1] = expander,
	[2] = parser
	};

	i = 0;
	while (i < 3)
	{
		err = proc_funptr[i](line, g_cmdline, info);
		if (err != NO_ERROR)
		{
			if (err == SYNTAX_ERR)
				info->exitcode = 258;
			return (err);
		}
		i++;
	}
	clean_lexer(&g_cmdline->lexer);
	return (NO_ERROR);
}

void	default_term(t_envi *envi)
{
	set_term_settings();
	rl_replace_line("", 0);
	g_cmdline = readline(GREEN PROMPT RESET);
	restore_term_settings(&envi->termios_p);
	add_history(g_cmdline);
}

int	loop_mini(t_envi *envi, t_token *token_list)
{
	t_err	rv;

	while (1)
	{
		//init_sigs();
		default_term(envi);
		if (!g_cmdline)
			continue;
		rv = process_input(g_cmdline, token_list, envi);
		free (g_cmdline)
		if (rv != NO_ERROR)
		{
			clean_tree(&token_list->tree)
			clean_lexer(&token_list->lexer)
			if (rv == MALLOC_FAIL)
				exit (-1);
			continue;
		}
		//ignore_sigs();
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