/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:56:16 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/30 19:23:12 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	here_doc_put_in(char **av, int *p_fd)
{
	char	*line;

	close(p_fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, p_fd[1]);
		free(line);
	}
}

void	here_doc(char **av)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		error("pipe error\n", 1);
	pid = fork();
	if (pid == -1)
		error("fork error\n", 1);
	if (!pid)
		here_doc_put_in(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

int	open_file(char *file, int in_or_out)
{
	int	fd;

	fd = 0;
	if (in_or_out == 0)
		fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
	{
		error("file invalid\n", 0);
		fd = STDIN_FILENO;
	}
	if (in_or_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd < 0)
		error("file invalid\n", 1);
	return (fd);
}