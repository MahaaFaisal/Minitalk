/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:46:54 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/26 15:34:29 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	handle_sigusr1(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message Recieved!\n");
}

pid_t	arg_to_pid(char *arg)
{
	pid_t	server_pid;
	int		error;

	error = 0;
	server_pid = str_to_int(arg, &error);
	if (error || server_pid <= 0)
	{
		ft_putstr_fd("Error\nServer pid must be a valid positive integer\n", 2);
		exit(1);
	}
	return (server_pid);
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i--) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(350);
	}
}

void	send_msg(pid_t server_pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		send_char(server_pid, msg[i++]);
	send_char(server_pid, msg[i]);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putstr_fd("Error\n<program> <server_pid> <Message>\n", 2);
		exit(1);
	}
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	server_pid = arg_to_pid(argv[1]);
	send_msg(server_pid, argv[2]);
	usleep(5);
}
