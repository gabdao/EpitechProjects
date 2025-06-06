/*
** EPITECH PROJECT, 2025
** hash_handling
** File description:
** File that regroups all the function to handle data in hash tables
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/my_macro.h"
#include "../include/my_secured.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = ht->hash(key, ht->len);
    entry_t *new_entry = malloc(sizeof(entry_t));

    if (!new_entry) {
        print_errors_messages("Error: Memory allocation failed\n");
        return ERROR;
    }
    new_entry->key = my_strdup(key);
    new_entry->value = my_strdup(value);
    new_entry->next = ht->table[index];
    ht->table[index] = new_entry;
    return SUCCESS;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int index = ht->hash(key, ht->len);
    entry_t *entry = ht->table[index];

    while (entry) {
        if (my_strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

static void unlink_entry(entry_t **head, entry_t *entry, entry_t *prev)
{
    if (prev) {
        prev->next = entry->next;
    } else {
        *head = entry->next;
    }
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = ht->hash(key, ht->len);
    entry_t *entry = ht->table[index];
    entry_t *prev = NULL;

    while (entry) {
        if (my_strcmp(entry->key, key) == 0) {
            unlink_entry(&ht->table[index], entry, prev);
            free(entry->key);
            free(entry->value);
            free(entry);
            return 0;
        }
        prev = entry;
        entry = entry->next;
    }
    return ERROR;
}

static void print_entries(entry_t *entry)
{
    while (entry) {
        my_printf("  Key: %s, Value: %s\n", entry->key, entry->value);
        entry = entry->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    int i = 0;
    entry_t *entry = ht->table[i];

    for (; i < ht->len; i++) {
        entry = ht->table[i];
        if (entry) {
            my_printf("Index %d:\n", i);
            print_entries(entry);
        }
    }
}

void delete_hashtable(hashtable_t *ht)
{
    entry_t *temp;
    entry_t *entry;

    for (int i = 0; i < ht->len; i++) {
        entry = ht->table[i];
        while (entry) {
            temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}
