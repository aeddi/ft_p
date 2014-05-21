/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 23:15:36 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/18 23:31:35 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define SIZE_BUF	1024

void	launch_prompt(int sock);
void	exit_error(char *error);
void	local_cd(char *entry);
void	local_ls(char *entry);
void	local_pwd(char *entry);
void	send_get_request(char *entry, int sock);
void	send_put_request(char *entry, int sock);
void	send_command(char *entry, int sock);
void	clean_exit(char *entry, int sock);
int		send_entry(char *entry, int sock);
char	*receive_ret(int sock);
char	**split_entry_l(char *entry);

#endif
