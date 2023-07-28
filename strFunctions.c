#include "monty.h"
/**
 * _strcmp - A function that compares two strings.
 * @s1: a type str compared
 * @s2: a type str compared
 * Return: 0 if s1 and s2 are equals.
 *         another value if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a]; a++)
		;
	if (s1[a] > s2[a])
		return (1);
	if (s1[a] < s2[a])
		return (-1);
	return (0);
}

/**
 * _sch - To search if a char is inside a string
 * @s: a string to review
 * @c: a char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - a function that cut a string into tokens depending of the delimit
 * @s: a string to cut in parts
 * @d: a delimiters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int a = 0, k = 0;

	if (!s)
		s = ultimo;
	while (s[a] != '\0')
	{
		if (_sch(d, s[a]) == 0 && s[a + 1] == '\0')
		{
			ultimo = s + a + 1;
			*ultimo = '\0';
			s = s + k;
			return (s);
		}
		else if (_sch(d, s[a]) == 0 && _sch(d, s[a + 1]) == 0)
			a++;
		else if (_sch(d, s[a]) == 0 && _sch(d, s[a + 1]) == 1)
		{
			ultimo = s + a + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + k;
			return (s);
		}
		else if (_sch(d, s[a]) == 1)
		{
			k++;
			a++;
		}
	}
	return (NULL);
}
