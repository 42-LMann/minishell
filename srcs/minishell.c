#include "minishell.h"

t_msh   msh_init(t_msh  *msh)
{

}

t_msh   env_init(t_msh  *msh, char  **env)
{
    msh->env.pwdpaths = find_path(**env, "PWD");
    msh->env.cmdpaths = find_path(**env, "PATH");
    msh->env.cmd_pathways = ft_split(msh->env.paths, ':');
}

void    minishell(char **env)
{
    t_msh  msh;

    msh_init(&msh);
    env_init(&msh, env);
    while (msh.exit != 0)
    {

    }
}