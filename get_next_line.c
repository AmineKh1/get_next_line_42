#include "get_next_line.h"
static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!s1 && !s2)
		return NULL;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[l++] = s1[i++];
	i = 0;
	while (s2[i])
		str[l++] = s2[i++];
	str[l] = '\0';
	return (&str[0]);
}

char *read_string(int s, char *st)
{
	char *str;
	int	i;
	i = 0;
	if(ft_strlen(st) < s)
		str = malloc(s + 1);
	else
		str = malloc(ft_strlen(st) + 1);
	while(i < s && st[i])
	{
		str[i] = st[i];
		i++;
	}
	return &str[0];
}
char *read_ft(char *st)
{
	char *str;
	int	i;
	i = 0;
	
	str = malloc(ft_strlen(st) + 1);
	while(st[i] && st[i] != '\n')
	{
		str[i] = st[i];
		i++;
	}
	return &str[0];
}
int	read_ft_int(char *st)
{
	int	i;
	i = 0;
	while(st[i] && st[i] != '\n')
	{
		i++;
	}
	return i;
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	l;
	char			*str;

	i = 0;
	l = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		str = (char *) malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] && i < start)
		i++;
	while (len-- > 0 && s[i])
		str[l++] = s[i++];
	str[l] = '\0';
	return (&str[0]);
}/*
char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE];
	int byte_read;
	char *str;
	int g;
	static int c = 0;
	g = c;
	printf("----\n");
	byte_read = read(fd, buf, BUFFER_SIZE);
	printf("%d\n",byte_read);
	if(byte_read == -1)
		return NULL;
	str = read_string(byte_read, &buf[c]);
	printf("%d\n", c);
	
	c = read_int(byte_read, &buf[c]) + 1;
	printf("%d\n",c);
	g = c;
	
	return read_string(byte_read, &buf[g]);
}*/
char	*get_next_line(int fd)
{
	char *buf;
	buf = malloc(BUFFER_SIZE); 
	int			byte_read;
	char static	*get_next_line = "";
	char		*str;
	char *s;
	int i;
	byte_read = read(fd, buf, BUFFER_SIZE);
	if(byte_read == -1 || byte_read == 0)
		return NULL;
	str = ft_strjoin(get_next_line, buf);

	while(str[i] && str[i] != '\n')
	{
		i++;
	}
	s = ft_substr(str,0,i);
	if(str[i] == '\n')
	{
		get_next_line = &str[i + 1];
	}
	free(buf);
	return s;



}/*
char 	*get_next_line(int fd);
{
	char buf[BUFFER_SIZE];
	int	byte_read;
	char static *gert_next_lline;
	char *str;
	int i;

}*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int i;
	char *str;
	i = open("text",  O_RDONLY);
	while ((str = get_next_line(i)))
	{
		printf("%s\n", str);
	}
}