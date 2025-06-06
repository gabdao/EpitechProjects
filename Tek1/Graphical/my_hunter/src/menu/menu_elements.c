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

sfText *initialize_menu_title(sfRenderWindow *window)
{
    sfFont *font;
    sfText *title;
    sfVector2u window_size;

    font = sfFont_createFromFile(FONT_TITLE);
    title = sfText_create();
    sfText_setString(title, "My Hunter");
    sfText_setFont(title, font);
    sfText_setCharacterSize(title, 50);
    sfText_setColor(title, sfWhite);
    window_size = sfRenderWindow_getSize(window);
    sfText_setPosition(title, (sfVector2f){
        (window_size.x - sfText_getGlobalBounds(title).width) / 2, 20
    });
    return title;
}

sfSprite *initialize_menu_background(sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *background;
    sfVector2u texture_size;
    sfVector2u window_size;
    sfVector2f scale;

    texture = sfTexture_createFromFile(MENU_BCK_IMG, NULL);
    background = sfSprite_create();
    sfSprite_setTexture(background, texture, sfTrue);
    texture_size = sfTexture_getSize(texture);
    window_size = sfRenderWindow_getSize(window);
    scale.x = (float)window_size.x / texture_size.x;
    scale.y = (float)window_size.y / texture_size.y;
    sfSprite_setScale(background, scale);
    return background;
}

sfSprite *initialize_start_button(sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *button;
    sfFloatRect bounds;
    sfVector2u window_size;
    sfVector2f position;

    texture = sfTexture_createFromFile(START_BUTTON, NULL);
    button = sfSprite_create();
    sfSprite_setTexture(button, texture, sfTrue);
    sfSprite_setScale(button, (sfVector2f){0.5, 0.5});
    bounds = sfSprite_getGlobalBounds(button);
    window_size = sfRenderWindow_getSize(window);
    position.x = (window_size.x - bounds.width) / 2;
    position.y = (window_size.y - bounds.height) / 1.5;
    sfSprite_setPosition(button, position);
    return button;
}

void destroy_menu_resources(menu_resources_t *resources)
{
    if (resources->music)
        sfMusic_destroy(resources->music);
    if (resources->title)
        sfText_destroy(resources->title);
    if (resources->background)
        sfSprite_destroy(resources->background);
    if (resources->button)
        sfSprite_destroy(resources->button);
}
