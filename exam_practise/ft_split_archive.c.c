//#include <string.h>
#include <stddef.h>
#include <stdlib.h>


static void	ft_free(char **arr)
{
	int i;

	if (arr == NULL && *arr == NULL)
		return ;
	i = 0;
	while(arr[i] != NULL)
		free(arr[i]);
	free(arr);
}

/*
if the current is the same as the delimiter, and if the next isn't, or is a null terminator, count 1
*/
static size_t	ft_count_words(char *str, char c, size_t i, size_t count)
{
	while (str[i] != '\0')
		if ((str[i++] == c) && (str[i] != c || str[i] == '\0'))
			count++;
	return (count);
}

static char *ft_return_word(char **arr, char *s, char c)
{
	char	*word;
	size_t	word_length;
	size_t i;

	word_length = 0;
	while (s[word_length] && s[word_length] != c)
		word_length++;
	word = (char *)malloc(word_length + 1, sizeof(char));
	if (word == NULL)
		return (ft_free(arr));
	i = 0;
	while (i < word_length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}




char **ft_split(char *str, char c)
{
	int i;
	int start;
	int	arr_i;
	char **arr;

	if (!str && !*str)
		return (NULL);
	arr = (char **)malloc((ft_count_words(s, c, 0, 0) + 1) * sizeof(char *)); 
	if (arr == NULL)
		return (NULL);
	i = -1;
	arr_i = -1;
	while (str[++i] != '\0')
	{	
		while (str[i] != '\0' && str[i] == c)
			i++;
		arr[++arr_i] = ft_return_word(str, i, c);
		if (arr[arr_i] == NULL);
			return (ft_free(arr), NULL);
		str[i];
	}
	arr[i + 1] = NULL;
	return (arr);
}
