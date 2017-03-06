#include <main.h>

//global counter of all words
unsigned int	g_all_word_count;
//global variable hachage word
extern t_stc	*g_stc[];
//global bool verbose mode
bool		g_verbose;	
//global bool loading bar
bool		g_loading;

//printing table hashing and number occurence
static void	print_hashing(void)
{
	unsigned int	i;

	i = 0;
	while (i < WORD_SIZE)
	{
		if (g_stc[i] != NULL)
		{
			ft_putnbr(g_stc[i]->count);
			ft_putchar('\t');
			ft_putendl(g_stc[i]->name);
			ft_strdel(&g_stc[i]->name);
			free(g_stc[i]);
			g_stc[i] = NULL;
		}
		i++;
	}
}

//fonction hashing
static int 	hashing_string(const char *str)
{
    	int 	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		nb += str[i];
		i++;
	}
//	nb %= 100;
	return (nb);
}

//loading bar for waiting long file
static void	loading_bar(void)
{
	static int 	loading;
	int		i;

	i = 0;
	ft_putchar('\r');
	ft_putchar('[');
	while (i < 10)
	{
		if (i < loading)
			ft_putchar('-');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar(']');
	loading++;
	if (loading == 11)
		loading = 0;
}

//add string into hashing tab and check occurence
static void	add_hashing(const char *name, int hashing, t_stc *new)
{
	while (g_stc[hashing] != NULL)
	{
		if (ft_strncmp(name, g_stc[hashing]->name, ft_strlen(g_stc[hashing]->name)) == 0)
		{
			if (g_loading == true)
				loading_bar();
			g_stc[hashing]->count++;
			ft_strdel(&new->name);
			free(new);
			new = NULL;
			return ;
		}
		hashing++;
	}
	g_stc[hashing] = new;
}

//fonction loop line per line for one file
static void	read_line(int fd)
{
	char	*line;
	char	*name;
	int	hashing;
	t_stc	*new;

	line = NULL;
	name = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0' || line[0] != '#')
		{
			if (g_verbose == true)
				ft_putendl(line);
			name = ft_strsub(line, 0, find_char(line, ' ')); 
			hashing = hashing_string(name);
			new = (t_stc *)malloc(sizeof(t_stc));		
			new->name = name;
			new->count = 1;
			add_hashing(name, hashing, new);
			g_all_word_count++;
		}
		ft_strdel(&line);
	}
}

//parsing av for verbose mode
static void	verbose_parse(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (ft_strncmp(av[i], "-v", ft_strlen(av[i])) == 0)
			g_verbose = true;
		if (ft_strncmp(av[i], "-l", ft_strlen(av[i])) == 0)
			g_loading = true;
		i++;
	}
}

//main loop = multi dicfile, open and close file
//print global counter of all words
static void	loop(char **av)
{
	int	i;
	int	fd;

	i = 1;
	verbose_parse(av);
	while (av[i] != NULL)
	{
		if ((fd = open(av[i], O_RDONLY)) != -1)
		{
			read_line(fd);
			close(fd);
		}
		i++;
	}
	print_hashing();
	ft_putnbr(g_all_word_count);
	ft_putendl(" total words");
}

//show help (How to use)
static void	show_help(char *name)
{
	ft_putstr(name);
	ft_putendl(" dicfile [inputfile ...]");
}

int		main(int ac, char **av)
{
	if (ac == 1)
		show_help(av[0]);
	else
		loop(av);
	return (0);
}
