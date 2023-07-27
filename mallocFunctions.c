#include "monty.h"
/**
 * _calloc - To concatenate two strings specially
 * @nmemb: element number
 * @size: element type
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p = NULL;
	unsigned int a;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < (nmemb * size); a++)
	{
		*((char *)(p) + a) = 0;
	}
	return (p);
}
/**
 * _realloc - To change the size and copy the content
 * @ptr: The malloc pointer to reallocate
 * @old_size: The old number of bytes
 * @new_size: The new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int a;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (a = 0; a < old_size; a++)
			p[a] = *((char *)ptr + a);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (a = 0; a < new_size; a++)
			p[a] = *((char *)ptr + a);
		free(ptr);
	}
	return (p);
}
