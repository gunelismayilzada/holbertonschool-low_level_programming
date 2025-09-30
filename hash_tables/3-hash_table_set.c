#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds or updates an element in a hash table
 * @hash_t: pointer to the hash table
 * @key: the key (cannot be empty)
 * @value: value associated with key (will be duplicated)
 *
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *hash_t, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *tmp;
	char *value_copy;

	if (!hash_t || !key || !*key || !value)
		return (0);

	value_copy = strdup(value);
	if (!value_copy)
		return (0);

	index = key_index((const unsigned char *)key, hash_t->size);
	for (tmp = hash_t->array[index]; tmp; tmp = tmp->next)
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}

	node = malloc(sizeof(hash_node_t));
	if (!node)
	{
		free(value_copy);
		return (0);
	}

	node->key = strdup(key);
	if (!node->key)
	{
		free(value_copy);
		free(node);
		return (0);
	}

	node->value = value_copy;
	node->next = hash_t->array[index];
	hash_t->array[index] = node;
	return (1);
}