/*
** EPITECH PROJECT, 2025
** my_macro header
** File description:
** header for my macros
*/

#ifndef _MY_MACRO_H_
    #define _MY_MACRO_H_
    #define SUCCESS 0
    #define ERROR 84
    #define ERROR_NAME_ENV 1
    #define ERROR_CMD 1
    #define ERROR_DIR 1
    #define ERROR_SETENV 1
    #define SHELL 1
    #define EXIT 2
    #define NOT_A_BUILTIN 3
    #define TTY 4
    #define EXECUTABLE 0
    #define SEGFAULT 139
    #define FOUND 1
    #define NOT_FOUND 0

typedef struct {
    int code;
    char *message;
    int should_exit;
} return_status_t;

static const return_status_t RETURN_VALUES[] = {
    {SUCCESS, "Success", 0},
    {ERROR, "Error", 1},
    {ERROR_CMD, "Command not found", 0},
    {ERROR_DIR, "Not a directory", 0},
    {EXIT, "Exit requested", 1},
    {NOT_A_BUILTIN, "Not a builtin", 0},
    {-1, NULL, 0}
};
#endif /* _MY_MACRO_H_ */
