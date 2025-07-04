/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_to_binary_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:43:25 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/04 11:23:11 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*dst;

	ptr = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	dst = ptr;
	while (*s)
		*dst++ = *s++;
	*dst = '\0';
	return (ptr);
}

char *ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return NULL;
}

char *decimal_to_binary_str(int	n)
{
	int	bits;
	char	*bin_str;
	int	i;
	char	*first;
	char	*result;

	bits = sizeof(int) * 8;
	bin_str = malloc (bits + 1);
	if (!bin_str)
		return (NULL);
	bin_str[bits] = '\0';
	i = bits - 1;
	while (i >= 0)
	{
		if(n & 1)
			bin_str[i] = '1';
		else
			bin_str[i] = '0';
		n >>= 1;
		i--;
	}
	first = ft_strchr(bin_str, '1');
	if (!first)
	{
		free (bin_str);
		return (ft_strdup("0"));
	}
	result = ft_strdup(first);
	free (bin_str);
	return (result);	
}			

/*unsigned char	reverse_bits(unsigned char octet)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (result);
}

void	print_bits(unsigned char octet)
{
	int	i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
		i--;
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	return (octet << 4 | octet >> 4);
} 

int	is_power_of_2(int n)
{
	if (n > 0 && (n & (n - 1)) == 0)
		return (1);
	return (0);
}*/	







	
