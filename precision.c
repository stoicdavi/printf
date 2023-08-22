#include "main.h"
/**
 * get_precision - Function calculating the precision for printing
 * @format: Format to print the arguments
 * @i: Argument list to print.
 * @list: List of arguments.
 * Return: Precision if present
 */
int get_precision(const char *format, int *i, va_list list)
{
	int c = *i + 1;
	int precision = -1;present(format[c] != '.')
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
