/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 23:17:58 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/18 23:18:00 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <client.h>
#include <stdio.h>

static char	*read_entry(void)
{
	int			ret;
	char		*buf;
	char		*save;
	char		*entry;

	ret = get_next_line(0, &buf);
	if (ret == -1)
		exit_error("read stdin");
	else if (ret == 0)
		return (NULL);
	save = buf;
	while (ft_isspace(*buf))
		buf++;
	entry = ft_strdup(buf);
	free(save);
	return (entry);
}

void		launch_prompt(int sock)
{
	char	*entry;

	while (42)
	{
		ft_putstr("ftp> ");
		entry = read_entry();
		if (!entry || !ft_strcmp(entry, "quit"))
			clean_exit(entry, sock);
		else if (!ft_strncmp(entry, "ls", 2) || !ft_strncmp(entry, "cd", 2)
					|| !ft_strncmp(entry, "pwd", 3))
			send_command(entry, sock);
		else if (!ft_strncmp(entry, "get", 3))
			send_get_request(entry, sock);
		else if (!ft_strncmp(entry, "put", 3))
			send_put_request(entry, sock);
		else if (!ft_strncmp(entry, "lcd", 3))
			local_cd(entry);
		else if (!ft_strncmp(entry, "lls", 3))
			local_ls(entry);
		else if (!ft_strncmp(entry, "lpwd", 4))
			local_pwd(entry);
		else
			printf("Command not found: %s\n", entry);
		free(entry);
	}
}
