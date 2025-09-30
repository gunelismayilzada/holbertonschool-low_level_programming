#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * _create_and_insert_node - Creates a new node and inserts it in the hash table.
 * @ht: The hash table.
 * @key: The key string (non-NULL, non-empty).
 * @value: The value string (non-NULL).
 * @index: The index to insert into.
 *
 * Return: 1 on success, 0 on failure.
 */
int _create_and_insert_node(hash_table_t *ht, const char *key,
			    const char *value, unsigned long int index)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));
	char *value_copy = strdup(value);

	if (!node || !value_copy)
	{
		free(node);
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
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @hash_t: Pointer to the hash table
 * @key: The key (cannot be empty)
 * @value: Value associated with key (will be duplicated)
 *
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *hash_t, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *tmp;
	char *value_copy;

	if (!hash_t || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, hash_t->size);
	for (tmp = hash_t->array[index]; tmp; tmp = tmp->next)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			value_copy = strdup(value);
			if (!value_copy)
				return (0);
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
	}

	return (_create_and_insert_node(hash_t, key, value, index));
}
