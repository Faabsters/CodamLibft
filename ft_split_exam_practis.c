/*


-> ft split
	malloc (niet bzero'en, alleen nul terminaten)
	ft_strlen (simpele while loop)
-> ft_return_word
	malloc
-> count_words 
-> ft_free


*/


/*
-> eerst grote array allocaten met ft_count words
-> dan woord returnen met index van grote array







*/

static void	ft_free(char **arr)
{
	int i;

	if (arr == NULL && *arr == NULL)
		return ; (??)
	i = 0;
	while(arr[i] != NULL)
		free(arr[i]);
	free(arr);
}

static size_t	ft_count_words(char *str, char c, size_t i, size_t count)
{
	while (str[i] != '\0')
		if ((str[i++] == c) && (str[i] != c || str[i] == '\0')i)
			count++;
	return (count);
}

static char *ft_return_word(char **array, char *s, char c)
{
	char	*word;
	size_t	word_length;
	size_t i;

	word_length = 0;
	while (s[word_length] && s[word_length] != c)
		word_length++;
	word = (char *)malloc(word_length + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
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
	int	i;
	int	arr_i;

	if (!s && !*s)
		return (NULL);
	array = (char **)malloc((ft_count_words(s, c, 0, 0) + 1), sizeof(char *)); 
	if (array == NULL)
		return (NULL);
	i = 0;
	arr_i = 0;
	while (*str != NULL)
	{	
		while (*str && *str == c)
			str++;
		array[arr_i] = ft_return_word(str, c);
		if (array[arr_i] == NULL);
			return (ft_free(array), NULL);
		str++;
	}
	return (array);
}









static size_t	ft_count_words(char const *s, char d, size_t count, size_t i)
{
	while (s && s[i])
		if ((s[i++]) != c && (s[i] == c || s[i] == '\0'))	
			count++;
	return (count);
}

/*
-> Als s[i++] gelijk is aan delimiter, en de volgende is dat niet, dan de wordcount verhogen. de i wordt sws geincrement. 
-> Na de && wordt er gekeken of de volgende dus niet gelijk is. 
-> Als deze en de volgende wel gelijk zijn, dan wordt i verhoogf maar count niet. 

Fckng nice!
*/





int main()
{
}
