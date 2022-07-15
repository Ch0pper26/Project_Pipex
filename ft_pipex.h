/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:03:54 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/31 15:26:24 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/ashes.h"

/* h_d Precise si heredoc ou non */
/* nb_pipes Donne le nombre de "pipes" */
/* (entre sortie = 2 donc pour 1 pipe nb_pipes = 2) */
typedef struct s_pipex
{
	int		fd1;
	int		fd2;
	char	*env_p;
	char	**cmd_path;
	char	*cmd;
	char	**cmd_arg;
	int		h_d;
	pid_t	pid;
	int		nb_cmds;
	int		nb_pipes;
	int		*end;
	int		i;
}	t_pipex;

/* ft_check */
int		ft_check(int argc, char **argv);
/* ft_init_struct */
void	ft_init_struct(t_pipex *p, int argc, char **argv, char **envp);
void	ft_get_fd(t_pipex *p, int argc, char **argv);
void	ft_get_path(t_pipex *p, char **envp);
void	ft_init_pipes(t_pipex *p);
/* ft_utils */
void	ft_perror(char *str);
void	ft_free_pipe(t_pipex *p);
void	ft_free_parent_process(t_pipex *p);
void	ft_free_child(t_pipex *p);
/* ft_exec */
void	ft_execute(t_pipex *p, char **argv, char **envp);
void	ft_child(t_pipex *p, char **argv, char **envp);
void	ft_dup_process(t_pipex *p);
void	ft_close_ends(t_pipex *p);
char	*ft_recovery_cmd(t_pipex *p, char *arg);
#endif
