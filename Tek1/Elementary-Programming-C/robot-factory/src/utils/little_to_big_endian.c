/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-robotfactory-raphael.varichon-dupre
** File description:
** little_to_big_endian
*/

int little_to_big_endian(int little_nb)
{
    int big_nb = 0;

    big_nb =
    ((little_nb & 0x000000FF) << 24) |
    ((little_nb & 0x0000FF00) << 8) |
    ((little_nb & 0x00FF0000) >> 8) |
    ((little_nb & 0xFF000000) >> 24);
    return big_nb;
}
