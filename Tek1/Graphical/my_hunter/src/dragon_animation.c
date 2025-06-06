/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** File to handle dragon animation
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

static void initialize_sprite(dragon_t *dragon,
    const char *spritesheet_path, sfVector2f scale)
{
    dragon->texture = sfTexture_createFromFile(spritesheet_path, NULL);
    dragon->sprite = sfSprite_create();
    sfSprite_setTexture(dragon->sprite, dragon->texture, sfTrue);
    sfSprite_setScale(dragon->sprite, scale);
}

static void initialize_position_and_frames(dragon_t *dragon)
{
    dragon->frame_rect.left = 0;
    dragon->frame_rect.top = 0;
    dragon->frame_rect.width = 1205;
    dragon->frame_rect.height = 1666;
    sfSprite_setTextureRect(dragon->sprite, dragon->frame_rect);
    dragon->position.x = 100;
    dragon->position.y = 100;
    sfSprite_setPosition(dragon->sprite, dragon->position);
}

dragon_t *initialize_dragon(const char *spritesheet_path, sfVector2f scale)
{
    dragon_t *dragon;

    dragon = malloc(sizeof(dragon_t));
    initialize_sprite(dragon, spritesheet_path, scale);
    initialize_position_and_frames(dragon);
    dragon->velocity.x = 200.0f;
    dragon->velocity.y = 0.0f;
    dragon->current_frame = 0;
    dragon->frame_count = 13;
    dragon->animation_speed = 0.1f;
    return dragon;
}

void move_dragon(dragon_t *dragon, float delta_time, sfVector2u window_size)
{
    sfVector2f scale;
    int max_height;

    dragon->position.x += dragon->velocity.x * delta_time;
    if (dragon->position.x > window_size.x) {
        dragon->position.x = -dragon->frame_rect.width;
        scale = sfSprite_getScale(dragon->sprite);
        max_height = window_size.y - (dragon->frame_rect.height * scale.y);
        if (max_height < 0) {
            max_height = 0;
        }
        dragon->position.y = rand() % (max_height + 1);
    }
    sfSprite_setPosition(dragon->sprite, dragon->position);
}

void update_dragon(dragon_t *dragon, float delta_time)
{
    static float elapsed_time = 0;

    elapsed_time += delta_time;
    if (elapsed_time >= dragon->animation_speed) {
        elapsed_time = 0;
        dragon->current_frame =
            (dragon->current_frame + 1) % dragon->frame_count;
        dragon->frame_rect.left =
            dragon->current_frame * dragon->frame_rect.width;
        sfSprite_setTextureRect(dragon->sprite, dragon->frame_rect);
    }
}
