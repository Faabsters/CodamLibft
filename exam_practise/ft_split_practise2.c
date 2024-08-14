#include <stdlib.h>


/*

1. Check for an empty string
2. malloc the size of count words + 1 and do malloc check
3. while loop to copy each word


*/

static int ft_count_words(char *str, char c, int i, int count)
{
	while (str[i] != '\0')
	{
		if ((str[i++] == c) && str[i] != c || str[i] == '\0')
			count++;
	}
	return (count);
}

char *ft_return_word(char *str, char c, int i, int word_length)
{
	char *word;

	while (str[word_length] != '\0' && str[word_length] != c)
		word_length++;
	word = (char *)malloc((word_length + 1 * sizeof(char)));
	if (word == NULL)
		return (NULL);
	while (i < word_length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split (char *str, char c)
{
	char **arr;
	int y;

	if (!str || !*str)
		return (NULL);
	arr = (char **)malloc((ft_count_words(str, c, 0, 0) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	y = -1;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str == '\0')
			break ;
		arr[++y] = ft_return_word(str, c, 0, 0);
		if (arr[y] == NULL)
			return (NULL); 
		while (*str != '\0' && *str != c)
			str++;
	}	
	arr[y + 1] = NULL;
	return (arr);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	char **arr;
	int i;
	
	if (argc != 3)
		return (1);
	arr = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}