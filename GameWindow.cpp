#include "GameWindow.h"
#include "scene.h"

bool draw = false;


const char *title = "Final Project 107011217";

// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;
ALLEGRO_TIMER* game_update_timer;

int Game_establish() {
    int msg = 0;

    game_init();
    game_begin();

    while ( msg != GAME_TERMINATE ) {
        msg = game_run();
        if ( msg == GAME_TERMINATE )
            printf( "Game Over\n" );
    }

    game_destroy();
    return 0;
}

void game_init() {
    printf( "Game Initializing...\n" );
    al_init();
    // init audio
    al_install_audio();
    al_init_acodec_addon();
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    // create event queue
    event_queue = al_create_event_queue();
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    //--mouse
    const unsigned m_buttons = al_get_mouse_num_buttons();
	game_log("There are total %u supported mouse buttons", m_buttons);
	// mouse_state[0] will not be used.
	mouse_state = (bool*)malloc((m_buttons + 1) * sizeof(bool));
	memset(mouse_state, false, (m_buttons + 1) * sizeof(bool));

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source( display ));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    fps  = al_create_timer( 1.0f / FPS );
    al_register_event_source(event_queue, al_get_timer_event_source( fps )) ;

    // initialize the icon on the display
    ALLEGRO_BITMAP *icon = al_load_bitmap("./image/icon.jpg");
    al_set_display_icon(display, icon);

}

void game_begin() {
    al_reserve_samples(20);
    al_start_timer(fps);
    // initialize the menu before entering the loop
    all_init();
}

void all_init(){
    menu_init();
    first_game_scene_init();
    second_game_scene_init();
}

void game_update(){
    if( code == 0 ){
        charater_update();
        //UFO_get();
    }

    //---------second  game---------//
    else if( code == 1 ){
        //printf("in second update\n");
        second_game_character_update();
    }
    //game_log("main character is at (%d,%d)\n",main_chara.x,main_chara.y);

}


void game_change_window(){
    if( judge_next_window ){
        if( window == SCENE_MENU ){

            code = 0;
            window = SCENE_FIRST_GAME_INTRO;
            menu_stop_audio();

            judge_next_window = false;
            first_game_scene_audio();

            //--test for second game
            /*
            menu_stop_audio();
            code = 1;
            window = SCENE_SECOND_GAME_START;

            judge_next_window = false;
            second_game_scene_audio();
            */

        }
        else if(window == SCENE_FIRST_GAME_INTRO){
            first_game_scene_stop_audio();
            window = SCENE_FIRST_GAME_LIVINGROOM;
            first_game_scene_audio();
            character_change_state(2);//--middle

            for(int i=0 ; i<FPS ; i++){
                first_game_scene_draw();
                al_flip_display();
            }

            judge_next_window = false;
        }
        //--first game scene middle
        else if(window == SCENE_FIRST_GAME_LIVINGROOM){
            //--back to intro
            judge_next_window = false;
            first_game_scene_stop_audio();

            if(first_game_done){
                window = SCENE_SECOND_GAME_START;
                code = 1;
                second_game_scene_audio();
                first_change_to_second_time = al_get_time();
                first_change_to_second = true;
                start_time = al_get_time();
            }
            else if(livingroom_scene == 3){//--左邊
                window = SCENE_FIRST_GAME_INTRO;
                //--更新character位置
                for(int i=0 ; i<FPS ; i++){
                    first_game_scene_draw();
                    al_flip_display();
                }
                character_change_state(3);//--down
            }
            //--to kitchen
            else if(livingroom_scene == 1){//--左邊
                window = SCENE_FIRST_GAME_KITCHEN;
                //--更新character位置
                for(int i=0 ; i<FPS ; i++){
                    first_game_scene_draw();
                    al_flip_display();
                }
                character_change_state(0);//--left
            }
            //--to bathroom
            else if(livingroom_scene == 2){//--右邊
                window = SCENE_FIRST_GAME_BATHROOM;
                //--更新character位置
                for(int i=0 ; i<FPS ; i++){
                    first_game_scene_draw();
                    al_flip_display();
                }
                character_change_state(1);//--left
            }
            //--to password
            else if(livingroom_scene == 4){
                window = SCENE_FIRST_GAME_PASSWORD;
            }
            first_game_scene_audio();
        }
        else if(window == SCENE_FIRST_GAME_PASSWORD){//--輸入密碼
            judge_next_window = false;
            first_game_scene_stop_audio();
            window = SCENE_FIRST_GAME_LIVINGROOM;
            for(int i=0 ; i<FPS ; i++){
                first_game_scene_draw();
                al_flip_display();
            }
            first_game_scene_audio();
        }
        else if(window == SCENE_FIRST_GAME_KITCHEN){//--左邊
            judge_next_window = false;
            if(in_treasure_map){
                window = SCENE_FIRST_GAME_TREASURE_MAP;
            }
            else{
                first_game_scene_stop_audio();
                window = SCENE_FIRST_GAME_LIVINGROOM;
                for(int i=0 ; i<FPS ; i++){
                    first_game_scene_draw();
                    al_flip_display();
                }
                character_change_state(1);
                first_game_scene_audio();
            }


        }
        else if(window == SCENE_FIRST_GAME_TREASURE_MAP){
            judge_next_window = false;
            //first_game_scene_stop_audio();
            window = SCENE_FIRST_GAME_KITCHEN;
            for(int i=0 ; i<FPS ; i++){
                first_game_scene_draw();
                al_flip_display();
            }
            //first_game_scene_audio();
        }
        else if(window == SCENE_FIRST_GAME_BATHROOM){//--右邊
            judge_next_window = false;
            first_game_scene_stop_audio();

            if(bathroom_scene == 1){
                window = SCENE_FIRST_GAME_LIVINGROOM;
                for(int i=0 ; i<FPS ; i++){
                    first_game_scene_draw();
                    al_flip_display();
                }
                character_change_state(0);
            }
            else if(bathroom_scene == 2){
                printf("in underground\n");
                window = SCENE_FIRST_GAME_UNDERGROUND;
                character_change_state(4);
                first_game_scene_sound();
            }

            first_game_scene_audio();

        }
        else if(window == SCENE_FIRST_GAME_UNDERGROUND){
            judge_next_window = false;
            first_game_scene_stop_audio();
            window = SCENE_FIRST_GAME_BATHROOM;
            first_game_scene_sound();

            character_change_state(5);
            first_game_scene_audio();

        }
        else if(window == SCENE_SECOND_GAME_START){
            judge_next_window = false;
            //--loss
            if(dead){
                second_game_scene_stop_audio();
                window = SCENE_SECOND_GAME_GAMEOVER;
                second_game_scene_audio();
            }
            //--win
            else{
                second_game_scene_stop_audio();
                window = SCENE_SECOND_GAME_BOSS;
                second_game_scene_audio();
            }

        }
        else if(window == SCENE_SECOND_GAME_BOSS){
            judge_next_window = false;
            //--boss血量低於50%，要換bgm
            if(plane.HP <= 0){
                second_game_scene_stop_audio();
                window = SCENE_SECOND_GAME_GAMEOVER;
                second_game_scene_audio();
            }
            else if(boss1.HP <= 0){
                //printf("in next window\n");
                second_game_scene_stop_audio();
                window = SCENE_SECOND_GAME_VICTORY;
                second_game_scene_audio();
            }
            else if(chg_music){
                second_game_scene_stop_audio();
                second_game_scene_audio();
            }
        }
        else if(window == SCENE_SECOND_GAME_GAMEOVER){
            judge_next_window = false;
            //second_game_scene_stop_audio();
            window = SCENE_SECOND_GAME_RESTART;
            //second_game_scene_audio();
        }
        else if(window == SCENE_SECOND_GAME_RESTART){
            judge_next_window = false;
            second_game_scene_stop_audio();

            if(restart) {
                second_game_restart();
                window = SCENE_SECOND_GAME_START;
                second_game_scene_audio();
            }
            else{
                window = SCENE_MENU;
                menu_audio();
            }
        }
    }
}

int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // process the event of other component
    if( window == SCENE_MENU ){
        menu_process(event);
    }else if( code == 0 ){
        //game_log("process window = %d",window);
        charater_process(event);
        first_game_scene_process(event);
    }else if( code == 1 ){
        second_game_character_process(event);
        second_game_scene_process(event);
    }


    //---------second  game---------//

    // Shutdown our program
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;
    else if(event.type == ALLEGRO_EVENT_TIMER)
        if(event.timer.source == fps)
            draw = true;
    //game_update();
    game_change_window();
    //game_sound();
    return 0;
}

void game_draw(){
    if( window == SCENE_MENU ){
        menu_draw();
    }else if( code == 0 ){
        //game_log("window = %d",window);
        first_game_scene_draw();
    }else if( code == 1 ){
        second_game_scene_draw();
    }
    al_flip_display();
}

void game_sound(){
    if(code == 0){
        first_game_scene_sound();
    }
}

int game_run() {
    int error = 0;
    if( draw ){
        //--先update再draw
        game_update();
        game_draw();
        draw = false;
    }
    if ( !al_is_event_queue_empty(event_queue) ) {
        error = process_event();
    }
    return error;
}

void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    first_game_scene_destroy();
    character_destory();
    object_destroy();
}
