/*
** EPITECH PROJECT, 2024
** 102architect
** File description:
** 102architect
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "./include/my.h"
#include "./include/my_macro.h"

const struct handle_geometric table[] = {
    {'t', handle_translation},
    {'z', handle_scaling},
    {'r', handle_rotation},
    {'s', handle_reflection},
};

static int handle_translation(double x, double y, double i, double j)
{
    double tr_mat[3][3] = {
        {1, 0, i},
        {0, 1, j},
        {0, 0, 1}
    };
    double new_x;
    double new_y;

    new_x = tr_mat[0][0] * x + tr_mat[0][1] * y + tr_mat[0][2];
    new_y = tr_mat[1][0] * x + tr_mat[1][1] * y + tr_mat[1][2];
    printf("Translation along vector (%.0f, %.0f)\n", i, j);
    printf("%.2f %.2f %.2f\n", tr_mat[0][0], tr_mat[0][1], tr_mat[0][2]);
    printf("%.2f %.2f %.2f\n", tr_mat[1][0], tr_mat[1][1], tr_mat[1][2]);
    printf("%.2f %.2f %.2f\n", tr_mat[2][0], tr_mat[2][1], tr_mat[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, new_x, new_y);
    return 0;
}

static int handle_scaling(double x, double y, double m, double n)
{
    double scale[3][3] = {
        {m, 0, 0},
        {0, n, 0},
        {0, 0, 1}
    };
    double new_x;
    double new_y;

    new_x = scale[0][0] * x + scale[0][1] * y + scale[0][2];
    new_y = scale[1][0] * x + scale[1][1] * y + scale[1][2];
    printf("Scaling by factors %.0f and %.0f\n", m, n);
    printf("%.2f %.2f %.2f\n", scale[0][0], scale[0][1], scale[0][2]);
    printf("%.2f %.2f %.2f\n", scale[1][0], scale[1][1], scale[1][2]);
    printf("%.2f %.2f %.2f\n", scale[2][0], scale[2][1], scale[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, new_x, new_y);
    return 0;
}

static int handle_rotation(double x, double y, double angle, double unused)
{
    double angle_radians = angle * PI / 180.0;
    double rotation[3][3] = {
        {cos(angle_radians), - sin(angle_radians), 0},
        {sin(angle_radians), cos(angle_radians), 0},
        {0, 0, 1}
    };
    double new_x;
    double new_y;

    new_x = rotation[0][0] * x + rotation[0][1] * y + rotation[0][2];
    new_y = rotation[1][0] * x + rotation[1][1] * y + rotation[1][2];
    printf("Rotation by a %0.0f degree angle\n", angle);
    printf("%.2f %.2f %.2f\n", rotation[0][0], rotation[0][1], rotation[0][2]);
    printf("%.2f %.2f %.2f\n", rotation[1][0], rotation[1][1], rotation[1][2]);
    printf("%.2f %.2f %.2f\n", rotation[2][0], rotation[2][1], rotation[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, new_x, new_y);
    return 0;
}

static int handle_reflection(double x, double y, double angle, double unused)
{
    double angle_radians = angle * PI / 180.0;
    double reflect[3][3] = {
        {cos(2 * angle_radians), sin(2 * angle_radians), 0},
        {sin(2 * angle_radians), - cos(2 * angle_radians), 0},
        {0, 0, 1}
    };
    double new_x;
    double new_y;

    new_x = reflect[0][0] * x + reflect[0][1] * y + reflect[0][2];
    new_y = reflect[1][0] * x + reflect[1][1] * y + reflect[1][2];
    printf("Reflection over an axis with an inclination angle of "
    "%.0f degrees\n", angle);
    printf("%.2f %.2f %.2f\n", reflect[0][0], reflect[0][1], reflect[0][2]);
    printf("%.2f %.2f %.2f\n", reflect[1][0], reflect[1][1], reflect[1][2]);
    printf("%.2f %.2f %.2f\n", reflect[2][0], reflect[2][1], reflect[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x, y, new_x, new_y);
    return 0;
}

static int detect_geometric_5_arguments(char **argv)
{
    double x;
    double y;
    double i;
    double j;

    x = atof(argv[1]);
    y = atof(argv[2]);
    i = atof(argv[4]);
    j = atof(argv[5]);
    for (int a = 0; a < NB_OF_FLAGS; a++) {
        if (argv[3][1] == table[a].flags) {
            table[a].function_ptr(x, y, i, j);
            break;
        }
    }
    return 0;
}

static int detect_geometric_4_arguments(char **argv)
{
    double x;
    double y;
    double angle;
    double unused = 0;

    x = atof(argv[1]);
    y = atof(argv[2]);
    angle = atof(argv[4]);
    for (int a = 0; a < NB_OF_FLAGS; a++) {
        if (argv[3][1] == table[a].flags) {
            table[a].function_ptr(x, y, angle, unused);
            break;
        }
    }
    return 0;
}

static int error_handling(void)
{
    fprintf(stderr, "Error: wrong number of arguments\n");
    return 84;
}

int main(int argc, char **argv)
{
    if (argc != 6 && argc != 5) {
        return error_handling();
    }
    if (argc == 6) {
        detect_geometric_5_arguments(argv);
    } else if (argc == 5) {
        detect_geometric_4_arguments(argv);
    }
    return 0;
}
