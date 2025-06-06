/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** Video game inspired from duck hunter
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
#include <time.h>

sfRenderWindow *create_window(int width, int height, const char *title)
{
    sfVideoMode video_mode;
    sfRenderWindow *window;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode,
    "My_Hunter", sfResize | sfClose, NULL);
    return window;
}

sfSprite *create_background(const char *filepath, sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *background;
    sfVector2u texture_size;
    sfVector2u window_size;
    sfVector2f scale;

    texture = sfTexture_createFromFile(filepath, NULL);
    background = sfSprite_create();
    sfSprite_setTexture(background, texture, sfTrue);
    texture_size = sfTexture_getSize(texture);
    window_size = sfRenderWindow_getSize(window);
    scale.x = (float)window_size.x / texture_size.x;
    scale.y = (float)window_size.y / texture_size.y;
    sfSprite_setScale(background, scale);
    return background;
}

void game_loop(sfRenderWindow *window, sfSprite *background, dragon_t *dragon)
{
    sfClock *clock = sfClock_create();
    sfEvent event;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfTime delta_time;
    float delta_seconds;

    while (sfRenderWindow_isOpen(window)) {
        manage_events(window, dragon);
        delta_time = sfClock_restart(clock);
        delta_seconds = sfTime_asSeconds(delta_time);
        update_dragon(dragon, delta_seconds);
        move_dragon(dragon, delta_seconds, window_size);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawSprite(window, dragon->sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
}

int main(void)
{
    sfRenderWindow *window;
    sfSprite *background;
    dragon_t *dragon;
    sfVector2f dragon_scale;

    srand(time(NULL));
    window = create_window(800, 600, "My Hunter");
    menu_loop(window);
    background = create_background(BCK_GRND_IMG, window);
    dragon_scale.x = 0.3f;
    dragon_scale.y = 0.3f;
    dragon = initialize_dragon(DRAG_1_FLY_SHEET, dragon_scale);
    game_loop(window, background, dragon);
    sfSprite_destroy(dragon->sprite);
    sfTexture_destroy(dragon->texture);
    free(dragon);
    sfSprite_destroy(background);
    sfRenderWindow_destroy(window);
    return 0;
}
