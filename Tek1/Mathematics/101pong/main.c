/*
** EPITECH PROJECT, 2024
** 101pong
** File description:
** Implementation of the 101pong game
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./include/my.h"
#include "./include/my_macro.h"

static int check_arguments(int argc, char *argv[])
{
    if (argc != 8) {
       exit(84);
    }
    if (atoi(argv[7]) < 0) {
        fprintf(stderr, "Error: n must be greater than or equal to zero.\n");
        return 1;
    }
    return 0;
}

static vector3d_t create_vector(double x, double y, double z)
{
    vector3d_t vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}

static vector3d_t vector_diff(vector3d_t v1, vector3d_t v2)
{
    vector3d_t result;

    result.x = v2.x - v1.x;
    result.y = v2.y - v1.y;
    result.z = v2.z - v1.z;
    return result;
}

static vector3d_t calculate_future_position(vector3d_t p1, vector3d_t velocity,
    int n)
{
    vector3d_t future_pos;

    future_pos.x = p1.x + velocity.x * n;
    future_pos.y = p1.y + velocity.y * n;
    future_pos.z = p1.z + velocity.z * n;
    return future_pos;
}

static void print_velocity(vector3d_t velocity)
{
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", velocity.x, velocity.y, velocity.z);
}

static void print_future_position(vector3d_t future_pos, int n)
{
    printf("At time t + %d, ball coordinates will be:\n", n);
    printf("(%.2f, %.2f, %.2f)\n", future_pos.x, future_pos.y, future_pos.z);
}

int main(int argc, char *argv[])
{
    vector3d_t v1;
    vector3d_t v2;
    vector3d_t velocity;
    vector3d_t future_pos;
    int n;

    if (check_arguments(argc, argv) != 0) {
        return 84;
    }
    v1 = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
    v2 = create_vector(atof(argv[4]), atof(argv[5]), atof(argv[6]));
    n = atoi(argv[7]);
    velocity = vector_diff(v1, v2);
    future_pos = calculate_future_position(v2, velocity, n);
    print_velocity(velocity);
    print_future_position(future_pos, n);
    return 0;
}
