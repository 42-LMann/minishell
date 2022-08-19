/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:09:06 by lmann             #+#    #+#             */
/*   Updated: 2022/08/19 11:09:08 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef t_err(*t_proc_input_ptr)(char*, t_curr_input*, t_envi*);

t_err	process_input(char *line, t_curr_input *input, t_envi *info);
t_err	get_input(t_envi *envi, char **input_ptr);

#endif