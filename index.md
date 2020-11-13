Extra Functions:
	ft_isspace.c:
		int	ft_isspace(int c);
		Description:
			works the same as isspace function.
	ft_free.c:
		void	ft_free(int cnt, ...);
		Description:
			Frees cnt pointers.
			Warning: easy to misuse.
	ft_numlen_base.c:
		int	ft_numlen_base(long long nbr, int base);
		Description:
			Returns number of digits in base-version of signed integer 'nbr'.
			max value: long long.
	ft_unumlen_base.c:
		int	ft_unumlen_base(unsigned long long nbr, int base);
		Description:
			Returns number of digits in base-version of unsigned integer 'nbr'
			max value: unsigned long long
	ft_putnofc.c:
		ssize_t	ft_putnofc(size_t n, unsigned char c);
		Description:
			Writes 'c' n times to stdout.
	ft_putllu.c:
		int	ft_putllu(unsigned long long nbr, int precision);
		Description:
			Outputs any value that fits inside unsigned long long.
			Prints a minimum of precision chars.
			Precedes printed nbr with leading zeros if precision flag is given.