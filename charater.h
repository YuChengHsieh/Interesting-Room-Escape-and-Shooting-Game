#include "global.h"

void character_init();
void charater_process(ALLEGRO_EVENT event);
void charater_update();
void character_draw();
void character_destory();
void character_change_state(int dir);
void character_bathroom_go_down_in_tube();
void character_bathroom_go_up_in_tube();
void character_underground_go_down_in_tube();
void character_underground_go_up_in_tube();


void second_game_character_process(ALLEGRO_EVENT event);
void second_game_character_init();
void second_game_character_update();
void second_game_character_draw();
void second_game_character_destory();
void second_game_generate_enemies();
void second_game_restart();
