/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:54:08 by mporras-          #+#    #+#             */
/*   Updated: 2022/01/29 23:54:11 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

char	*ft_substr_gnl(char *s, int start, int len, int *nl_len)
{
	char	*rst;

	if (!s)
		return (NULL);
	if (len > (nl_len[1] - start))
		len = nl_len[1] - start;
	if (start > nl_len[1])
		len = 0;
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (rst == NULL)
		return (NULL);
	rst[len] = '\0';
	ft_memcpy(rst, &s[start], len);
	return (rst);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int bytes, int *nl_len)
{
	char	*rst;

	if (!s1 || !s2)
		return (NULL);
	rst = (char *)malloc(sizeof(char) * (nl_len[1] + 1));
	if (rst == NULL)
		return (NULL);
	rst[nl_len[1]] = '\0';
	ft_memcpy(rst, s1, nl_len[1] - bytes);
	ft_memcpy(&rst[nl_len[1] - bytes], s2, bytes);
	free(s1);
	return (rst);
}
