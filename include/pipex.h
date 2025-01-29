/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:24:24 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/29 00:58:20 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <libft.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

//-----------------------   UTILS   -----------------------------------

void	free_tab(char **tab);
void	print_tab(char **tab);

//-----------------------   EXEC    -----------------------------------

char	*get_path(char *name, char **env);
void	exec(char *command, char **env);

//-----------------------   ERROR   -----------------------------------

void	error(char *str, int exit_code);

//-----------------------   PIPE    -----------------------------------

void	my_pipe(char *cmd, char **env);
int		open_file(char *file, int in_or_out);
void	here_doc(char **av);

#endif