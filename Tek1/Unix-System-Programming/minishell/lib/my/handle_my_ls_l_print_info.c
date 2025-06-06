/*
** EPITECH PROJECT, 2024
** handle my_ls_l
** File description:
** Function to handle my_ls_l print info
*/

#include "../../include/my.h"
#include "../../include/my_macro.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>


int print_rights(mode_t data_rights)
{
    my_printf((S_ISDIR(data_rights)) ? "d" : "-");
    my_printf((data_rights & S_IRUSR) ? "r" : "-");
    my_printf((data_rights & S_IWUSR) ? "w" : "-");
    my_printf((data_rights & S_IXUSR) ? "x" : "-");
    my_printf((data_rights & S_IRGRP) ? "r" : "-");
    my_printf((data_rights & S_IWGRP) ? "w" : "-");
    my_printf((data_rights & S_IXGRP) ? "x" : "-");
    my_printf((data_rights & S_IROTH) ? "r" : "-");
    my_printf((data_rights & S_IWOTH) ? "w" : "-");
    my_printf((data_rights & S_IXOTH) ? "x" : "-");
    return 0;
}

int print_owners(uid_t owner, gid_t group, nlink_t nb_links)
{
    struct passwd *pw = getpwuid(owner);
    struct group *gr = getgrgid(group);

    my_printf("%ld ", nb_links);
    my_printf("%s ", pw->pw_name);
    my_printf("%s ", gr->gr_name);
    return 0;
}

int print_data_size(off_t size)
{
    my_printf("%ld", size);
    return 0;
}

int print_last_modification_date(time_t last_modification)
{
    char *date_before_format;
    int i;

    date_before_format = ctime(&last_modification);
    for (int i = DAY_TO_SUPPR_IN_DATE; i < SECS_TO_SUPPR_IN_DATE; i++) {
        my_putchar(date_before_format[i]);
    }
    return 0;
}

int print_files_names(const char *filename)
{
    my_printf("%s\n", filename);
    return 0;
}
