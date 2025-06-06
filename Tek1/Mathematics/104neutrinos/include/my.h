/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#ifndef MY_H
    #define MY_H

typedef struct {
    int n;
    double a_mean;
    double harmonic_mean;
    double sd;
} stats_t;


int disp_nb_values(int *n);
int disp_arithmetic_mean(double *a_mean, int value_given, int n);
int disp_harmonic_mean(int value_given, int *n, double *harmonic_mean);
int disp_stand_deviation(
    int value_given,
    int n, double *a_mean,
    double *sd);
double calculate_rms(
    int value_given,
    double *arithmetic_mean,
    double *sd,
    int n);
#endif
