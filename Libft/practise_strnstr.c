#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	while (*big && len > 0 && len >= ft_strlen(little))
	{
		if (ft_strncmp(big, little, ft_strlen(little)))
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
