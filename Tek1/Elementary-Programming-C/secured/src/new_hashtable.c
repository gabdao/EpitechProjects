/*
** EPITECH PROJECT, 2025
** hash_table
** File description:
** function to handle new hastable
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/my_secured.h"


hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = NULL;

    if (len <= 0 || !hash) {
        return NULL;
    }
    ht = malloc(sizeof(hashtable_t));
    if (!ht) {
        return NULL;
    }
    ht->table = malloc(sizeof(entry_t *) * len);
    if (!ht->table) {
        free(ht);
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        ht->table[i] = NULL;
    }
    ht->len = len;
    ht->hash = hash;
    return ht;
}
