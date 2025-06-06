/*
** EPITECH PROJECT, 2024
** my_macro header
** File description:
** header for my macros of dragon 1
*/

#ifndef _MY_DRAGON_1_H_
    #define _MY_DRAGON_1_H_

typedef struct dragon_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect frame_rect;
    sfVector2f position;
    sfVector2f velocity;
    int current_frame;
    int frame_count;
    float animation_speed;
} dragon_t;

dragon_t *initialize_dragon(const char *spritesheet_path, sfVector2f scale);
void move_dragon(dragon_t *dragon, float delta_time, sfVector2u window_size);
void update_dragon(dragon_t *dragon, float delta_time);
//ANIMATION DRAGON 1 FLIGHT
    #define DRAG_1_FLY_SHEET "./content/sprites/Dragon1/flight_spritesheet.png"
//ANIMATION  DRAGON 1 DEATHS
    #define DRAG_1_DEAD_SHEET "./content/sprites/Dragon1/dead_spritesheet.png"
#endif /* _MY_DRAGON_1_H_ */
