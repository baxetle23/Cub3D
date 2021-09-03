#include "libft.h"

static int	ft_word_count(char *st, char symb);
static int	ft_count(char **mas, char *st, char symb, int i);

char	**ft_split(const char *src, char ch)
{
	int		i;
	int		number;
	char	**split;

	if (!src)
		return (0);
	number = ft_word_count((char *)src, ch);
	split = malloc(sizeof(char *) * (number + 1));
	if (!split)
		return (NULL);
	split[number] = NULL;
	i = 0;
	while (i < number)
	{
		src += ft_count(&split[i], (char *)src, ch, 0);
		if ((int)src == -1)
			return (NULL);
		i++;
	}
	return (split);
}

int	ft_word_count(char *st, char symb)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (st[i] != '\0')
	{
		if (st[i] != symb)
		{
			while (st[i] != symb && st[i + 1] != 0)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_count(char **mas, char *st, char symb, int i)
{
	int	count;

	count = 0;
	while (st[i] != '\0')
	{
		if (st[i] != symb)
		{
			while (st[i] != symb && st[i] != '\0')
			{
				i++;
				count ++;
			}
			break ;
		}
		i++;
	}
	*mas = (char *)malloc(count + 1);
	if (!*mas)
		return (-1);
	ft_strlcpy(*mas, st + (i - count), count + 1);
	return (i);
}
