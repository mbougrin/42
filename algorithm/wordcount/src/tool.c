#include <main.h>

//concatenate two strings and return result in new line malloc
static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int	i;
	int	j;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

//return a new string malloc
static char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > i)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

//return a new string malloc copy from start a len
char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_strnew(len + 1);
	if (dst == NULL)
		return (NULL);
	while (len > 0)
	{
		dst[i] = s[start];
		start++;
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

//free a string and initialise into NULL
void		ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}

//copy a string s2 into a string s1
static char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

//duplicate a string an return copy a new string malloc
static char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1) + 1;
	dest = (char*)malloc(sizeof(char) * (len));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}

//search a char value into a string
static char	*ft_strchr(const char *s, int c)
{
	unsigned char	charact;

	charact = (unsigned char)c;
	while (*s != '\0')
	{
		if (charact == *s)
			return ((char *)s);
		s++;
	}
	if (charact == *s)
		return ((char *)s);
	return (NULL);
}

//copy a new line return and copy next line into buff
static char	*ft_copy(char **buff_tmp, char **line, int fd)
{
	int	i;
	int	j;
	char	*tmp;

	i = 0;
	while (buff_tmp[fd][i] != '\n')
		i++;
	j = i;
	while (buff_tmp[fd][j] != '\0')
		j++;
	buff_tmp[fd][i] = '\0';
	*line = ft_strdup(buff_tmp[fd]);
	buff_tmp[fd][i] = '\n';
	i++;
	if (buff_tmp[fd][i] != '\0')
	{
		tmp = buff_tmp[fd];
		buff_tmp[fd] = ft_strsub(tmp, i, j);
		ft_strdel(&tmp);
		return (buff_tmp[fd]);
	}
	ft_strdel(&buff_tmp[fd]);
	return (buff_tmp[fd]);
}

//copy old buffer begin a new buffer read
static char	*ft_copy_buff_tmp(char **buff_tmp, char *buff, int fd)
{
	char	*tmp;

	if (buff_tmp[fd] == NULL)
		buff_tmp[fd] = ft_strdup(buff);
	else
	{
		tmp = buff_tmp[fd];
		buff_tmp[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	return (buff_tmp[fd]);
}

//copy a end line and return final line
static void	ft_copy_end(char **line, char **buff_tmp, char *buff, int fd)
{
	if (*line == NULL && buff_tmp[fd] == NULL)
		*line = ft_strdup(buff);
	else if (buff_tmp[fd] != NULL)
		*line = ft_strdup(buff_tmp[fd]);
	ft_strdel(&buff_tmp[fd]);
}

//check buffer is empty or not
int		ft_check_buff(char **buff_tmp, char **line, int fd)
{
	buff_tmp[fd] = ft_copy(buff_tmp, line, fd);
	return (1);
}

//read buffer and return a new line malloc (line per line)
int		get_next_line(int fd, char **line)
{
	static char	*buff_tmp[512];
	char		buff[BUFF_SIZE + 1];
	int		ret;

	if (buff_tmp[fd] != NULL && ft_strchr(buff_tmp[fd], '\n') != NULL)
		return (ft_check_buff(buff_tmp, line, fd));
	if (fd < 0 || fd == 1)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
		{
			buff_tmp[fd] = ft_copy_buff_tmp(buff_tmp, buff, fd);
			buff_tmp[fd] = ft_copy(buff_tmp, line, fd);
			return (1);
		}
		buff_tmp[fd] = ft_copy_buff_tmp(buff_tmp, buff, fd);
	}
	ft_copy_end(line, buff_tmp, buff, fd);
	return (0);
}

//print a char value
void		ft_putchar(char c)
{
	write(1, &c, 1);
}

//print a int value
void			ft_putnbr(unsigned int n)
{
	int		div;

	div = 1;
	while ((n / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((n / div) % 10 + 48);
		div /= 10;
	}
}

//count character into a string
int		ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

//print a string
void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

//print a string and a new line character
void		ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

//compare a two strings
int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[i] == p2[i])
	{
		if (p1[i] == '\0' && p2[i] == '\0')
			return (0);
		i++;
	}
	return (p1[i] - p2[i]);
}

//compare a two strings into len character
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*p1;
	unsigned char		*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p1[i] != p2[i] || (p1[i + 1] == '\0' && p2[i + 1] == '\0'))
			return (p1[i] - p2[i]);
		i++;
	}
	return (p1[i - 1] - p2[i - 1]);
}

//find char into a string and return occurence
int		find_char(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}
