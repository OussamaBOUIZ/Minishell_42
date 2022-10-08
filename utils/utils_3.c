/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:28:46 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/08 17:33:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	vector_len(char **vec)
{
	int i;

	i = 0;
	while (vec[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	int				len;

	len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}


char	*strjoin_s(char *s1, char *s2)
{
	char	*nw_str;
	size_t	total_l;
	int		i;
	int		j;

	total_l = ft_strlen(s1) + ft_strlen(s2) + 1;
	nw_str = malloc(sizeof(char) * (total_l + 1));
	if (!nw_str)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			nw_str[i] = s1[i];
	nw_str[i] = '/';
	j = ft_strlen(s1) + 1;
	i = 0;
	if (s2)
		while (s2[i])
			nw_str[j++] = s2[i++];
	nw_str[j] = 0;
	return (nw_str);
}
