

static t_bool			executable(t_dirent *file, char *path)
{
	struct stat		s;
	int				(*f)(const char*, struct stat*);

	if (file->d_type != DT_DIR && file->d_type != DT_LNK)
		return (FALSE);
	f = (file->d_type == DT_DIR) ? &stat : &lstat;
	if (f(path, &s))
		return (FALSE);
	return (s.st_mode & S_IXUSR);
}

static char		*foo(char *base, char *filename)
{
	t_dir 		dir;
	t_dirent	*file;
	char		*path;
	int			(*f)(const char*, struct stat*);

	if ((dir = opendir(base)))
		return (NULL);
	while ((file = readdir(dir)))
	{
		if (ft_strcmp(file->d_name, filename))
			continue ;
		if (!(path = join_path(base, filename)))
			break ;
		if (!executable(dir, path))
		{
			free(path);
			path = NULL;
		}
		break ;
	}
	close(dir);
	return (path);
}

static char 	*get_file_path(char *path, char *filename)
{
	if (!(path = resolve_path(path)))
		return (NULL);
	if (!filename)
	{
		if (!(base = get_base_path(path)))
			return (NULL);
		filename = get_filename(path);
	}
	else
		base = path;
	return (foo(base, filename));
}