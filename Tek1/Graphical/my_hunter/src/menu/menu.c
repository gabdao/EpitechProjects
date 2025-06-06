/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** Menu functions
*/

#include "menu.h"
#include "image_and_sound.h"
#include "my_dragon_1.h"
#include "my_dragon_2.h"
#include "my_dragon_3.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

static int check_button_clicked(sfRenderWindow *window, sfSprite *start_button)
{
    sfVector2i mouse_pos;
    sfFloatRect button_bounds;

    mouse_pos = sfMouse_getPositionRenderWindow(window);
    button_bounds = sfSprite_getGlobalBounds(start_button);
    return sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y);
}

static int handle_menu_events(menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        if (event.type == sfEvtClosed)
            return 1;
        if (event.type == sfEvtMouseButtonPressed &&
            check_button_clicked(menu->window, menu->start_button)) {
            return 1;
        }
    }
    return 0;
}

static void draw_menu(sfRenderWindow *window, sfSprite *menu_image,
    sfText *title, sfSprite *start_button)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu_image, NULL);
    sfRenderWindow_drawText(window, title, NULL);
    sfRenderWindow_drawSprite(window, start_button, NULL);
    sfRenderWindow_display(window);
}

void menu_loop(sfRenderWindow *window)
{
    sfMusic *background_music = initialize_background_music();
    sfText *title = initialize_menu_title(window);
    sfSprite *menu_image = initialize_menu_background(window);
    sfSprite *start_button = initialize_start_button(window);
    menu_t menu = {window, start_button, background_music};
    menu_resources_t resources = {
        .music = background_music,
        .title = title,
        .background = menu_image,
        .button = start_button
    };

    while (sfRenderWindow_isOpen(window)) {
        if (handle_menu_events(&menu))
            break;
        draw_menu(window, menu_image, title, start_button);
    }
    destroy_menu_resources(&resources);
}
