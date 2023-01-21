#include "global.h"
#include "charater.h"
#include "object.h"

void menu_init();
void menu_process(ALLEGRO_EVENT event);
void menu_draw();
void menu_audio();
void menu_stop_audio();
void menu_destroy();

void first_game_scene_init();
void first_game_scene_draw();
void first_game_scene_audio();
void first_game_scene_stop_audio();
void first_game_scene_sound();
void first_game_scene_process(ALLEGRO_EVENT event);
void first_game_scene_destroy();

void second_game_scene_init();
void second_game_scene_process(ALLEGRO_EVENT event);
void second_game_scene_draw();
void second_game_scene_audio();
void second_game_scene_stop_audio();
void second_game_scene_destroy();

//--resized bitmap
ALLEGRO_BITMAP *load_bitmap_resized(const char *filename, int w, int h);

