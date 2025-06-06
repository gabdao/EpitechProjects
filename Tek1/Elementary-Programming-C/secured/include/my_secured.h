/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** header for project secured
*/

#ifndef MY_SECURED_H
    #define MY_SECURED_H
    #define TABLE_SIZE 20000

typedef struct entry_t {
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct hashtable_t {
    entry_t **table;
    int len;
    int (*hash)(char *, int);
} hashtable_t;

int hash(char *key, int len);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
int ht_insert(hashtable_t *ht, char *key, char *value);
char *ht_search(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
int ht_delete(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
int print_errors_messages(const char *message);


#endif
