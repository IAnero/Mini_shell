/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:08:44 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/14 12:15:02 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *dest, const char *src)
{
	char	*result;
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;

	if (!dest && !src)
		return (NULL);
	if (!dest)
		return (ft_strdup(src));
	if (!src)
		return (ft_strdup(dest));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, dest);
	ft_strcat(result, src);
	free(dest);
	return (result);
}
