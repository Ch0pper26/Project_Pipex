/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:39:30 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/31 16:32:36 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_execute(t_pipex *p, char **argv, char **envp)
{
	while (++p->i < p->nb_cmds)
		ft_child(p, argv, envp);
	ft_close_ends(p);
	waitpid(-1, NULL, 0);
	ft_free_parent_process(p);
}

void	ft_child(t_pipex *p, char **argv, char **envp)
{
	p->pid = fork();
	if (p->pid == 0)
	{
		ft_dup_process(p);
		ft_close_ends(p);
		p->cmd_arg = ft_split(argv[2 + p->i], ' ');
		p->cmd = ft_recovery_cmd(p, p->cmd_arg[0]);
		if (!p->cmd)
		{
			ft_print_error("Command not found ...\n");
			ft_free_child(p);
			exit(1);
		}
		execve(p->cmd, p->cmd_arg, envp);
	}
}

void	ft_dup_process(t_pipex *p)
{
	if (p->i == 0)
	{
		dup2(p->fd1, 0);
		dup2(p->end[1], STDOUT_FILENO);
	}
	else if (p->i == p->nb_cmds - 1)
	{
		dup2(p->end[2 * p->i - 2], STDIN_FILENO);
		dup2(p->fd2, STDOUT_FILENO);
	}
	else
	{
		dup2(p->end[2 * p->i - 2], STDIN_FILENO);
		dup2(p->end[2 * p->i + 1], STDOUT_FILENO);
	}
}

void	ft_close_ends(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->nb_pipes)
		close(p->end[i++]);
}

char	*ft_recovery_cmd(t_pipex *p, char *arg)
{
	char	*tmp_p;
	char	*tmp_c;
	int		i;

	i = 0;
	while (p->cmd_path[i])
	{
		tmp_p = ft_strjoin(p->cmd_path[i], "/");
		tmp_c = ft_strjoin(tmp_p, arg);
		if (access(tmp_c, 0) == 0)
			return (tmp_c);
		free(tmp_p);
		free(tmp_c);
		i++;
	}
	return (NULL);
}
