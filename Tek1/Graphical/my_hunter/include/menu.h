/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_dragon_1.h"

#ifndef MY_H_
    #define MY_H_
    #define START_BUTTON "./content/menu/start_button.png"
    #define FONT_TITLE "./content/fonts/Jaro-Regular-VariableFont_opsz.ttf"

typedef struct {
    sfRenderWindow *window;
    sfSprite *start_button;
    sfMusic *background_music;
} menu_t;

typedef struct {
    sfMusic *music;
    sfText *title;
    sfSprite *background;
    sfSprite *button;
} menu_resources_t;

sfMusic *initialize_background_music(void);
sfText *initialize_menu_title(sfRenderWindow *window);
sfSprite *initialize_menu_background(sfRenderWindow *window);
sfSprite *initialize_start_button(sfRenderWindow *window);
static int handle_menu_events(menu_t *menu);
void destroy_audio(sfMusic *music, sfSound *sound, sfSoundBuffer *buffer);
void destroy_menu_resources(menu_resources_t *resources);
void menu_loop(sfRenderWindow *window);
void manage_events(sfRenderWindow *window, dragon_t *dragon);
#endif /* MY_H_ */
