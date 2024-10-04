/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:27:34 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/28 17:01:18 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief 
 * 
 * It's just a strdup but until \n
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_custom_strdup(char *s1)
{
	char	*dest;
	int		size;
	int		idx;

	dest = NULL;
	size = ft_strlen(s1);
	idx = FALSE;
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!(dest))
		return (NULL);
	while (s1[idx] && s1[idx] != '\n')
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

/**
 * @brief
 * 
 * It's just ft_strlcpy but the end file is \n
 * 
 * @param dst 
 * @param src 
 * @param dst_size 
 * @return int 
 */
int	ft_custom_strlcpy(char *dst, char *src, int dst_size)
{
	int	idx;
	int	len;

	len = ft_strlen(src);
	idx = FALSE;
	if (dst_size == FALSE)
		return (len);
	while (idx < dst_size - TRUE && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		idx++;
	}
	*dst = '\0';
	return (len);
}

/**
 * @brief 
 * 
 * its just a strjoin but by the \n
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_custom_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	dst = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_custom_strdup(s2));
	else if (s2 == NULL)
		return (ft_custom_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!(dst))
		return (NULL);
	ft_custom_strlcpy(dst, s1, s1_len + 1);
	ft_custom_strlcpy((dst + s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (dst);
}

/**
 * @brief 
 * 
 * if the env is NULL we quit and print the error msg
 * we loop in the tab end if we found Display we quit
 * if there is no display we print the error msg
 * 
 * @param env 
 */
void	ft_check_env(char **env)
{
	int	idx;

	if (!*env)
	{
		write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
		write(STDERR_FILENO, NO_ENV_ERROR, ft_strlen(NO_ENV_ERROR));
		exit(EXIT_FAILURE);
	}
	idx = FALSE;
	while (env[idx])
	{
		if (ft_strncmp("DISPLAY", env[idx], ft_strlen("DISPLAY")) == FALSE)
			return ;
		else
			idx++;
	}
	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(STDERR_FILENO, NO_DISP_ERROR, ft_strlen(NO_DISP_ERROR));
	exit(EXIT_FAILURE);
}

/**
 * @brief 
 * 
 * we get the len of the map and the extension
 * 	/path/to/map.ber  and .ber
 * 
 * if we have less than .ber ex .be we found a bad extension
 * so we return SUCCESS			flemme de changer cest linverse....
 * then we get the cursor at * 
 * 				 /path/to/map.ber 
 * 			then we compare with .ber if there is not equal
 * 	we return SUCCESS because we found bad extenstion
 * 	   then inc the pointer of both
 * 
 * @param map_name 
 * @param extension 
 * @return int 
 */
int	ft_check_extension(char *map_name, char *extension)
{
	int	len_map_name;
	int	len_extension;

	len_map_name = ft_strlen(map_name);
	len_extension = ft_strlen(extension);
	if (len_map_name <= len_extension)
		return (EXIT_SUCCESS);
	map_name += len_map_name - len_extension;
	while (*map_name)
	{
		if (*map_name != *extension)
			return (EXIT_SUCCESS);
		map_name++;
		extension++;
	}
	return (EXIT_FAILURE);
}
