#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

static int check_args(int argc, char **argv)
{
    if (argc == 1) {
        printf("No args given\n");
        return 84;
    }
    return 0;
}

static int remove_spe_characters(char **argv, int i, int y)
{
    if (argv[i][y] == '\\' && argv[i][y + 1] == 't') {
        printf("Found special character %c\n", argv[i][y]);
        y++;
    }

    return y;
}

static char **handling_characters(int argc, char **argv)
{
    printf("In handling characters\n");

    char **new_table_str = NULL;
    int i = 1;
    int y = 0;

    for (; i < argc; i++) {
        for (y = 0; argv[i][y] != '\0'; y++) {
            printf("Character is: %c\n", argv[i][y]);
            y = remove_spe_characters(argv, i, y);
        }
    }

    return new_table_str;
}

static int countwords(int argc, char **argv)
{
    printf("In countwords\n");

    return 0;
}

int main(int argc, char **argv)
{
    if (check_args(argc, argv) == 84)
        return 84;

    char **processed_words = handling_characters(argc, argv);

    if (processed_words == NULL) {
        printf("Error handling characters\n");
        return 84;
    }
    if (countwords(argc, argv) == 84)
        return 84;

    return 0;
}
