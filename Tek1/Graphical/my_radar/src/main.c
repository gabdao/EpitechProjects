/*
** EPITECH PROJECT, 2024
** My_radar
** File description:
** my_radar
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "macro.h"
#include "my_lib.h"
#include "handling_script_files.h"

sfRenderWindow *create_window(int width, int height, const char *title)
{
    sfVideoMode video_mode;
    sfRenderWindow *window;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, title,
    sfResize | sfClose, NULL);
    return window;
}

static void handle_window_resize(sfRenderWindow *window, sfEvent event)
{
    sfView *view;

    view = sfView_create();
    sfView_setSize(view, (sfVector2f){event.size.width, event.size.height});
    sfView_setCenter(view, (sfVector2f){event.size.width / 2.0f,
    event.size.height / 2.0f});
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}

static void handle_close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

static void handle_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtResized) {
        handle_window_resize(window, event);
    } else {
        handle_close_event(window, event);
    }
}

int main(int argc, char **argv)
{
    sfRenderWindow *window;
    sfEvent event;

    if (handling_script_files(argc, argv) == ERROR) {
        return ERROR;
    }
    window = create_window(1920, 1080, "My Radar");
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_events(window, event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return SUCCESS;
}
