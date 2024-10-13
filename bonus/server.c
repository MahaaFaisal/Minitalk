/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:46:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/26 15:34:41 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	static int	sender_pid;

	sender_pid = info->si_pid;
	if (sig == SIGUSR1)
		c = (c << 1) + 1;
	else if (sig == SIGUSR2)
		c = (c << 1) + 0;
	i++;
	if (i == 8)
	{
		if (c == '\0' && sender_pid > 0)
		{
			kill(sender_pid, SIGUSR1);
			usleep(350);
			sender_pid = 0;
		}
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}
