/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** File to handle events
*/

#include "menu.h"
#include "image_and_sound.h"
#include "my_dragon_1.h"
#include "my_dragon_2.h"
#include "my_dragon_3.h"
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

int handle_dragon_click(dragon_t *dragon, sfRenderWindow *window)
{
    sfVector2i mouse_pos;
    sfFloatRect dragon_bounds;
    sfSound *death_sound;

    mouse_pos = sfMouse_getPositionRenderWindow(window);
    dragon_bounds = sfSprite_getGlobalBounds(dragon->sprite);
    death_sound = initialize_death_sound();
    if (sfFloatRect_contains(&dragon_bounds, mouse_pos.x, mouse_pos.y)) {
    sfSound_play(death_sound);
    dragon->position.x = -dragon->frame_rect.width;
    dragon->position.y = rand() % (int)(sfRenderWindow_getSize(window).y -
                                            dragon->frame_rect.height);
    sfSprite_setPosition(dragon->sprite, dragon->position);
    return 1;
    }
    return 0;
}

void manage_events(sfRenderWindow *window, dragon_t *dragon)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed &&
                event.mouseButton.button == sfMouseLeft) {
            handle_dragon_click(dragon, window);
        }
    }
}
