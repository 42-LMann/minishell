#ifndef INPUT_H
# define INPUT_H

typedef t_err(*t_proc_input_ptr)(char*, t_curr_input*, t_envi*);

t_err	process_input(char *line, t_curr_input *input, t_envi *info);
t_err	get_input(t_envi *envi, char **input_ptr);

#endif