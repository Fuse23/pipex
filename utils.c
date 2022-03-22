/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:23:23 by falarm            #+#    #+#             */
/*   Updated: 2022/03/22 20:35:46 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_fd(int *in, int *out, char **files)
{
	*in = open(files[1], O_RDONLY);
	if (*in == -1)
		error_file(files[1]);
	*out = open(files[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*out == -1)
		error_file(files[4]);
}

char	**find_path(char **envp)
{
	char	**arr;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			arr = ft_split(envp[i] + 5, ':');
			if (!arr)
				error_process();
			return (arr);
		}
		i++;
	}
	return (NULL);
}

char	*get_line(char *cmd, char **arr)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	while (arr[i])
	{
		tmp = ft_strjoin(arr[i], "/");
		line = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(line, F_OK) == 0)
			return (line);
		else
			free(line);
		i++;
	}
	error_cmd(cmd);
	return (NULL);
}
