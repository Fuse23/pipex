/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:50:19 by falarm            #+#    #+#             */
/*   Updated: 2022/06/09 21:33:16 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process(char *argv, char **env)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
		error_process();
	pid = fork();
	if (pid == -1)
		error_process();
	if (pid == 0)
	{
		close(p[0]);
		dup2(p[1], 1);
		execute(argv, env);
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		p[2];
	char	*line;

	if (pipe(p) == -1)
		error_process();
	pid = fork();
	if (pid == -1)
		error_process();
	if (pid == 0)
	{
		close(p[0]);
		while (get_next_line(&line))
		{
			if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
				exit(EXIT_SUCCESS);
			write(p[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		wait(NULL);
	}
}

void	pipex(int argc, char **argv, char **env)
{
	int	i;
	int	in;
	int	out;

	if (!ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")))
	{
		i = 3;
		out = open_file(argv[argc - 1], 0);
		if (argc < 6)
			error_args();
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		out = open_file(argv[argc - 1], 1);
		in = open_file(argv[1], 2);
		dup2(in, 0);
	}
	while (i < argc - 2)
		child_process(argv[i++], env);
	dup2(out, 1);
	execute(argv[argc - 2], env);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
		error_args();
	pipex(argc, argv, env);
	return (0);
}
