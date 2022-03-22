/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:03:48 by falarm            #+#    #+#             */
/*   Updated: 2022/03/22 21:26:34 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(int *p, char **argv, char **envp, int in)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(in, 0);
	dup2(p[1], 1);
	cmd = ft_split(argv[2], ' ');
	path = find_path(envp);
	line = get_line(cmd[0], path);
	close(in);
	close(p[0]);
	close(p[1]);
	execve(line, cmd, envp);
}

static void	child2_process(int *p, char **argv, char **envp, int out)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(p[0], 0);
	dup2(out, 1);
	cmd = ft_split(argv[3], ' ');
	path = find_path(envp);
	line = get_line(cmd[0], path);
	close(out);
	close(p[1]);
	close(p[0]);
	execve(line, cmd, envp);
}

static void	pipex(char **argv, char **envp)
{
	pid_t	pid;
	int		p[2];
	int		in;
	int		out;

	check_fd(&in, &out, argv);
	if (pipe(p) == -1)
		error_process();
	pid = fork();
	if (pid == -1)
		error_process();
	if (pid == 0)
		child1_process(p, argv, envp, in);
	pid = fork();
	if (pid == -1)
		error_process();
	if (pid == 0)
		child2_process(p, argv, envp, in);
	close(in);
	close(out);
	close(p[0]);
	close(p[1]);
	wait(0);
	wait(0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments.\n", 2);
		ft_putstr_fd("Example: ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
		exit(EXIT_SUCCESS);
	}
	pipex(argv, envp);
	return (0);
}
