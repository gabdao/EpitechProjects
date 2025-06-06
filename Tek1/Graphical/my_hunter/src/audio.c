/*
** EPITECH PROJECT, 2024
** My_hunter
** File description:
** audio for menu
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

sfSound *initialize_death_sound(void)
{
    sfSoundBuffer *buffer;
    sfSound *death_sound;

    buffer = sfSoundBuffer_createFromFile(SOUND_DEATH);
    death_sound = sfSound_create();
    sfSound_setBuffer(death_sound, buffer);
    return death_sound;
}

sfMusic *initialize_background_music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile(SOUND_MENU_MUSIC);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 20);
    sfMusic_play(music);
    return music;
}

void destroy_audio(sfMusic *music, sfSound *sound, sfSoundBuffer *buffer)
{
    if (music)
        sfMusic_destroy(music);
    if (sound)
        sfSound_destroy(sound);
    if (buffer)
        sfSoundBuffer_destroy(buffer);
}
