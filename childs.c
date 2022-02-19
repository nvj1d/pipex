/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:27:24 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/17 21:35:01 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.end[1], 1);
	close(pipex.end[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		write(2, "Command not found: ", ft_strlen("Command not found: "));
		write(2, av[2], ft_strlen(av[2]));
		write(2, "\n", 1);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.end[0], 0);
	close(pipex.end[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		write(2, "Command not found: ", ft_strlen("Command not found: "));
		write(2, av[3], ft_strlen(av[3]));
		write(2, "\n", 1);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
