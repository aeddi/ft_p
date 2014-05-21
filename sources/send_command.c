/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 23:18:08 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/18 23:27:38 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <client.h>
#include <libft.h>
#include <sys/socket.h>

int			send_entry(char *entry, int sock)
{
	long	ret;
	long	size;

	ret = 0;
	size = ft_strlen(entry);
	send(sock, (const char *)&size, sizeof(long), 0);
	while ((ret += send(sock, entry + ret, size, 0)) != size)
	{
		if (ret == -1)
		{
			printf("\033[31mError: sending impossible\033[0m\n");
			return (1);
		}
	}
	return (0);
}

char		*receive_ret(int sock)
{
	char	*ret_mes;
	long	size;

	recv(sock, &size, sizeof(long), 0);
	ret_mes = ft_strnew(size);
	recv(sock, ret_mes, size, 0);
	return (ret_mes);
}

void		send_command(char *entry, int sock)
{
	char	*ret;

	if (!send_entry(entry, sock))
	{
		ret = receive_ret(sock);
		printf("%s\n", ret);
		free(ret);
	}
}
