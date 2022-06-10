/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:02:27 by falarm            #+#    #+#             */
/*   Updated: 2022/06/09 21:33:52 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft_src/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>

//error_bonus.c
void	error_cmd(char *cmd);
void	error_file(char *file);
void	error_process(void);
void	error_args(void);

//utils_bonus.c
char	**find_path(char **env);
char	*get_line(char *cmd, char **arr);
int		get_next_line(char **line);
void	execute(char *argv, char **env);
int		open_file(char *argv, int i);

//main_bonus.c
void	child_process(char *argv, char **env);
void	here_doc(char *limiter);
void	pipex(int argc, char **argv, char **env);

#endif
