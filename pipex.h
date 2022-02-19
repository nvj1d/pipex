/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:59:33 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/17 21:51:43 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

# define ERR_MSG "syntax: ./pipex infile 'cmd1''cmd2' outfile\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	close_pipes(t_pipex *pipex);
void	free_parent(t_pipex *pipex);

void	free_child(t_pipex *pipex);
void	first_child(t_pipex pipex, char **av, char **envp);
void	second_child(t_pipex pipex, char **av, char **envp);

int		simp_msg_ret(char *err);
void	msg_err_ex(char *err);

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
