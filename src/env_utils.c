/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:49:42 by schennal          #+#    #+#             */
/*   Updated: 2024/03/13 16:39:42 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_shell_lv(t_minishell *m)
{
	char	*tmp;
	int		lv;
	char	*lv_tmp;

	lv = ft_atoi(getenv("SHLVL")) + 1;
	lv_tmp = ft_itoa(lv);
	tmp = ft_strjoin("SHLVL=", lv_tmp);
	if (!tmp)
	{
		perror("minishell: cd");
		exit(1);
	}
	free(lv_tmp);
	m_export(m, tmp, NULL);
	ft_lstlast(m->mem_env)->next = ft_lstnew(tmp);
}

void	start_env(t_minishell *m)
{
	char	*tmp;

	m_unset(m, "OLDPWD");
	b_pwd(m, 0);
	tmp = ft_strjoin("PWD=", m->path);
	if (!tmp)
	{
		perror("minishell: cd");
		exit(1);
	}
	m_export(m, tmp, NULL);
	ft_lstlast(m->mem_env)->next = ft_lstnew(tmp);
	handle_shell_lv(m);
}

static void	put_arr(char **str, long long n, int idx)
{
	if (n == LLONG_MIN)
	{
		ft_strlcpy(*str, "-9223372036854775808", 21);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		(*str)[0] = '-';
	}
	if (n >= 10)
	{
		put_arr(str, n / 10, idx - 1);
	}
	(*str)[idx] = '0' + (n % 10);
}

static int	get_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	if (digits == 0)
		digits++;
	return (digits);
}

char	*ft_ltoa(long long n)
{
	long long	digits;
	char		*ans;

	digits = get_digits(n);
	ans = malloc(digits + 1);
	if (!ans)
		return (0);
	ans[digits] = 0;
	put_arr(&ans, n, digits - 1);
	return (ans);
}

void	get_rid_of_sig(t_minishell *m)
{
	struct termios	termios;

	ft_memset(&m->term_orig, 0, sizeof(m->term_orig));
	tcgetattr(STDIN_FILENO, &m->term_orig);
	termios = m->term_orig;
	termios.c_lflag &= ~ECHOCTL;
	termios.c_lflag |= (ECHO | ICANON | ISIG);
	tcsetattr(STDIN_FILENO, TCSANOW, &termios);
}
