/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:29:02 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/31 10:29:05 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_init_struct(t_pipex *p, int argc, char **argv, char **envp)
{
	ft_get_fd(p, argc, argv);
	p->nb_cmds = argc - 3;
	p->nb_pipes = (p->nb_cmds - 1) * 2;
	p->end = (int *)calloc(sizeof(int), p->nb_pipes);
	if (!p->end)
	{
		free(p);
		ft_perror("Allocation");
	}
	ft_get_path(p, envp);
	p->cmd_path = ft_split(p->env_p, ':');
	if (!p->cmd_path)
	{
		ft_free_pipe(p);
		ft_perror("Allocation");
	}
	ft_init_pipes(p);
	p->i = -1;
}

void	ft_get_fd(t_pipex *p, int argc, char **argv)
{
	p->fd1 = open(argv[1], O_RDONLY);
	if (p->fd1 == -1)
	{
		free(p);
		ft_perror("Infile");
	}
	p->fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0744);
	if (p->fd2 == -1)
	{
		free(p);
		ft_perror("Outfile");
	}
}

void	ft_get_path(t_pipex *p, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			p->env_p = ft_substr(envp[i], 5, (ft_strlen(envp[i]) - 5));
			break ;
		}
		i++;
	}
}

void	ft_init_pipes(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->nb_cmds - 1)
	{
		if (pipe(p->end + 2 * i) < 0)
		{
			ft_free_parent_process(p);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
