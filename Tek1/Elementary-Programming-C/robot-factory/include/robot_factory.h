/*
** EPITECH PROJECT, 2025
** my_robot factory header
** File description:
** header for robot factory
*/

#ifndef _ROBOT_H_
    #define _ROBOT_H_
    #include <stdio.h>
    #include "op.h"
    #include <stdint.h>

typedef struct body_s {
    char *label;
    char *opcode;
    char *parameters[4];
    struct body_s *next;
} body_t;

typedef struct {
    char *opcode;
    uint8_t value;
} opcode_t;

//Parsing functions
int send_each_line_file(char *file);

//Parsing body
int handling_body(char **instruction, body_t **body_list);
void handling_labels(char *label, body_t *body);
void handling_opcode(char *opcode, body_t *body);
void handling_parameters(char *parameter, body_t *body, int i);

//Linked list functions
body_t *create_body_node(void);
void add_body_node(body_t **head, body_t *new_node);
void free_body_list(body_t *head);

//Utils functions
int print_error_message(char *str);
int little_to_big_endian(int little_nb);
int get_prog_size(body_t **body);


//Utils condition handling functions
int check_conditions_body(char **instruction, body_t *body);

// Writing
FILE *header_writing(header_t header, body_t *body);
void body_writing_handling(body_t *body, FILE *fd);

//Header errors functions
int ignore_comment(char *line);
int check_name_errors(char **header_data);
int check_comment_errors(char **header_data);

//Print body data
void print_parameters(body_t *current);
void print_linked_list_body_data(body_t *body_list);

//Writing opcode
void handle_opcode(body_t *body_list, FILE *fd);
void handle_params(body_t *current, FILE *fd);

#endif /* _ROBOT_H_ */
