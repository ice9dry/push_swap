#include "parse_utils2.h"

static int check_overflow(long long res, int sign)
{
	if (sign == 1)
	{
		if (res > 2147483647)
			return (1);
	}
	else
	{
		if (res > 2147483648L)
			return (1);
	}
	return (0);
}

static int get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int is_valid_integer(const char *str)
{
	long long	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	if (!str || ft_strlen(str) == 0)
		return (0);
	sign = get_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + (str[i] - '0');
		if (check_overflow(res, sign))
			return (0);
		i++;
	}
	return (1);
}

