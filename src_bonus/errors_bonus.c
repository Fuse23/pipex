/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:27:32 by falarm            #+#    #+#             */
/*   Updated: 2022/06/09 21:26:01 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_file(char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	error_cmd(char *cmd)
{
	ft_putstr_fd("Error: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	error_process(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

void	error_args(void)
{
	ft_putstr_fd("Error: Bad arguments!\n", 2);
	ft_putstr_fd("Example: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 2);
	ft_putstr_fd(
		"Example: ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 2);
	exit(EXIT_SUCCESS);
}
