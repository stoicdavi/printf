#include "main.h"
/**
 * get_precision - function to calculates the precision for printing
 * @format: Format in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: the list of arguments.
 * Return: Precision if exists
 */
int get_precision(const char *format, int *i, va_list list)
{
	int c = *i + 1;
	int precision = -1;

	if (format[c] != '.')
		return (precision);
	precision = 0;

	for (c += 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			precision *= 10;
			precision += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (precision);
}
