/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:47:06 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/01 16:55:16 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;

	tmp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (tmp == NULL)
		return (0);
	ft_strlcpy(tmp, s, ft_strlen(s) + 1);
	return (tmp);
}
