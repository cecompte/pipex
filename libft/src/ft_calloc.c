/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:49:50 by cecompte          #+#    #+#             */
/*   Updated: 2025/05/15 14:09:00 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (nmemb > 0)
	{
		if (SIZE_MAX / nmemb < size)
			return (NULL);
	}
	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (0);
	ft_bzero(tmp, size * nmemb);
	return (tmp);
}
