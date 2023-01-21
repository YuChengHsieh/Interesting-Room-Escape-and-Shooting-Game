#include "scene.h"

//--Scene bitmap
//--background
ALLEGRO_BITMAP *menu_bg;
ALLEGRO_BITMAP *first_game_intro_bg;
ALLEGRO_BITMAP *first_game_livingroom_bg;
ALLEGRO_BITMAP *first_game_kitchen_bg;
ALLEGRO_BITMAP *first_game_bathroom_bg;
ALLEGRO_BITMAP *first_game_password_bg;
ALLEGRO_BITMAP *first_game_underground_bg;
ALLEGRO_BITMAP *first_game_treasure_map_bg;

//--paste
ALLEGRO_BITMAP *first_game_intro_paste;
ALLEGRO_BITMAP *first_game_livingroom_paste;
ALLEGRO_BITMAP *first_game_kitchen_paste;
ALLEGRO_BITMAP *first_game_bathroom_paste;
ALLEGRO_BITMAP *first_game_underground_paste;

//--all scene
ALLEGRO_BITMAP *first_game_get_UFO_bitmap;
ALLEGRO_BITMAP *first_game_not_enough_UFO_bitmap;
ALLEGRO_BITMAP *first_game_get_paste_bitmap;

//--livingroom
ALLEGRO_BITMAP *first_game_UFO_1;
ALLEGRO_BITMAP *first_game_UFO_2;
ALLEGRO_BITMAP *first_game_UFO_open;
ALLEGRO_BITMAP *first_game_UFO_out;
ALLEGRO_BITMAP *first_game_UFO_ref;
ALLEGRO_BITMAP *first_game_password_1;
ALLEGRO_BITMAP *first_game_password_2;
ALLEGRO_BITMAP *first_game_password_ref;
ALLEGRO_BITMAP *first_game_dog_1;
ALLEGRO_BITMAP *first_game_dog_2;
ALLEGRO_BITMAP *first_game_dog_ref;
ALLEGRO_BITMAP *first_game_dog_smile;

//--bathroom
ALLEGRO_BITMAP *first_game_toilet_1;
ALLEGRO_BITMAP *first_game_toilet_2;
ALLEGRO_BITMAP *first_game_toilet_ref;
ALLEGRO_BITMAP *first_game_treasure_map_1;
ALLEGRO_BITMAP *first_game_treasure_map_2;
ALLEGRO_BITMAP *first_game_treasure_map_ref;


//--kitchen
ALLEGRO_BITMAP *first_game_chicken_1;
ALLEGRO_BITMAP *first_game_chicken_2;
ALLEGRO_BITMAP *first_game_chicken_ref;


//--password
ALLEGRO_BITMAP *first_game_password_start_bitmap;

//--underground
ALLEGRO_BITMAP *first_game_treasure_1;
ALLEGRO_BITMAP *first_game_treasure_2;
ALLEGRO_BITMAP *first_game_treasure[IMAGE_TREASURE];

//--Scene sample
//--BGM
ALLEGRO_SAMPLE *menu_bgm = NULL;
ALLEGRO_SAMPLE_ID menu_bgm_ID;

ALLEGRO_SAMPLE *first_game_intro_bgm = NULL;
ALLEGRO_SAMPLE_ID first_game_intro_bgm_ID;

ALLEGRO_SAMPLE *first_game_livingroom_bgm = NULL;
ALLEGRO_SAMPLE_ID first_game_livingroom_bgm_ID;

ALLEGRO_SAMPLE *first_game_kitchen_bgm = NULL;
ALLEGRO_SAMPLE_ID first_game_kitchen_bgm_ID;

ALLEGRO_SAMPLE *first_game_bathroom_bgm = NULL;
ALLEGRO_SAMPLE_ID first_game_bathroom_bgm_ID;

ALLEGRO_SAMPLE *first_game_underground_bgm = NULL;
ALLEGRO_SAMPLE_ID first_game_underground_bgm_ID;

//--INTRO
ALLEGRO_SAMPLE *first_game_fall_sound = NULL;
ALLEGRO_SAMPLE_ID first_game_fall_sound_ID;


//--GET UFO SOUND
ALLEGRO_SAMPLE *first_game_get_UFO_sound = NULL;
ALLEGRO_SAMPLE_ID first_game_get_UFO_sound_ID;

//--PASSWORD
ALLEGRO_SAMPLE *first_game_password_insert_sound = NULL;
ALLEGRO_SAMPLE_ID first_game_password_insert_sound_ID;

ALLEGRO_SAMPLE *first_game_password_unlocked_sound = NULL;
ALLEGRO_SAMPLE_ID first_game_password_unlocked_sound_ID;

ALLEGRO_SAMPLE *first_game_password_error_sound = NULL;
ALLEGRO_SAMPLE_ID first_game_password_error_sound_ID;

//--BATHROOM AND UNDERGROUND
ALLEGRO_SAMPLE *first_game_in_tube_sound = NULL;
ALLEGRO_SAMPLE_ID first_game_in_tube_sound_ID;

//--LIVINGROOM and LAUNCH
ALLEGRO_SAMPLE *first_game_launch_sound = NULL;
ALLEGRO_SAMPLE_ID first_game_launch_sound_ID;


//---------second  game---------//
ALLEGRO_BITMAP* start_img_background;
ALLEGRO_BITMAP* start_img_background_2;
ALLEGRO_BITMAP* gameover_img_background;
ALLEGRO_BITMAP* boss_img_background;
ALLEGRO_BITMAP* boss_img_background_2;
ALLEGRO_BITMAP* victory_img_background;

ALLEGRO_SAMPLE* start_bgm;
ALLEGRO_SAMPLE_ID start_bgm_id;
ALLEGRO_SAMPLE* gameover_bgm;
ALLEGRO_SAMPLE_ID gameover_bgm_id;
ALLEGRO_SAMPLE* boss_bgm_1;
ALLEGRO_SAMPLE_ID boss_bgm_id_1;
ALLEGRO_SAMPLE* boss_bgm_2;
ALLEGRO_SAMPLE_ID boss_bgm_id_2;
ALLEGRO_SAMPLE* victory_bgm;
ALLEGRO_SAMPLE_ID victory_bgm_id;

//--scene start sound
//--sound
ALLEGRO_SAMPLE* shoot_sound;
ALLEGRO_SAMPLE_ID shoot_sound_id;
ALLEGRO_SAMPLE* fire_sound;
ALLEGRO_SAMPLE_ID fire_sound_id;
ALLEGRO_SAMPLE* laser_sound;
ALLEGRO_SAMPLE_ID laser_sound_id;
ALLEGRO_SAMPLE* shield_sound;
ALLEGRO_SAMPLE_ID shield_sound_id;


// function of menu
void menu_init(){
    font_12 = al_load_ttf_font("./font/pirulen.ttf",12,0);
    if(!font_12)
        game_abort("failed to load font: pirulen.ttf with size 12");

    font_18 = al_load_ttf_font("./font/pirulen.ttf",18,0);
    if(!font_18)
        game_abort("failed to load font: pirulen.ttf with size 18");

    font_36 = al_load_ttf_font("./font/pirulen.ttf",36,0);
    if(!font_36)
        game_abort("failed to load font: pirulen.ttf with size 36");

    font_60 = al_load_ttf_font("./font/pirulen.ttf",60,0);
    if(!font_60)
        game_abort("failed to load font: pirulen.ttf with size 60");

    menu_bg = load_bitmap_resized("./image/menu-bg.jpg",WIDTH,HEIGHT);

    menu_bgm = al_load_sample("./sound/Ys VIII -Lacrimosa of DANA- OST - Lacrimosa of DANA.ogg");
    if(!menu_bgm)
        game_abort("failed to load sample: Ys VIII -Lacrimosa of DANA- OST - Lacrimosa of DANA.ogg");

    menu_audio();
}

void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_UP )
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER )
            judge_next_window = true;
}

void menu_draw(){
    al_draw_bitmap(menu_bg, 0, 0, 0);
    al_draw_text(font_36, al_map_rgb(0,0,0), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    //al_draw_rectangle(WIDTH/2-150, 510, WIDTH/2+150, 550, al_map_rgb(255, 255, 255), 0);
}

void menu_audio(){
    if (!al_play_sample(menu_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &menu_bgm_ID)){
        game_abort("failed to play menu bgm");
    }
}

void menu_stop_audio(){
    al_stop_sample(&menu_bgm_ID);
    game_log("stop menu_bgm");
}

void menu_destroy(){
    al_destroy_font(font_12);
    al_destroy_bitmap(menu_bg);
    al_destroy_sample(menu_bgm);
}


// function of first_game_scene
void first_game_scene_init(){
    character_init();
    object_init();
    //--background
    first_game_intro_bg = load_bitmap_resized("./image/intro_new.png",WIDTH,HEIGHT);
    first_game_bg_ptr[SCENE_FIRST_GAME_INTRO] = first_game_intro_bg;

    first_game_livingroom_bg = load_bitmap_resized("./image/livingroom_background1.png",WIDTH,HEIGHT);
    first_game_bg_ptr[SCENE_FIRST_GAME_LIVINGROOM] = first_game_livingroom_bg;

    first_game_kitchen_bg = load_bitmap_resized("./image/kitchen_bg.png",WIDTH,HEIGHT);
    first_game_bg_ptr[SCENE_FIRST_GAME_KITCHEN] = first_game_kitchen_bg;

    first_game_bathroom_bg = load_bitmap_resized("./image/bathroom_background.png",WIDTH,HEIGHT);
    first_game_bg_ptr[SCENE_FIRST_GAME_BATHROOM] = first_game_bathroom_bg;

    first_game_password_bg = load_bitmap_resized("./image/password_keyboard.png",WIDTH,HEIGHT);
    first_game_bg_ptr[SCENE_FIRST_GAME_PASSWORD] = first_game_password_bg;

    first_game_underground_bg = load_bitmap_resized("./image/underground_bg.png",WIDTH,HEIGHT);
    first_game_bg_ptr[SCENE_FIRST_GAME_UNDERGROUND] = first_game_underground_bg;

    first_game_treasure_map_bg = load_bitmap_resized("./image/big_treasure_map.png",WIDTH,HEIGHT);
    first_game_bg_ptr[SCENE_FIRST_GAME_TREASURE_MAP] = first_game_treasure_map_bg;

    //--記下background的width 和 height
    for(i=SCENE_FIRST_GAME_INTRO ; i<SCENE_SECOND_GAME_START ; i++){
        first_game_bg[i].w = al_get_bitmap_width(first_game_bg_ptr[i]);
        first_game_bg[i].h = al_get_bitmap_height(first_game_bg_ptr[i]);
        printf("%d %d %d\n",i,first_game_bg[i].w,first_game_bg[i].h);
    }

    //--paste
    first_game_intro_paste = load_bitmap_resized("./image/intro_paste.png",WIDTH,HEIGHT);
    first_game_livingroom_paste = load_bitmap_resized("./image/livingroom_paste.png",WIDTH,HEIGHT);
    first_game_bathroom_paste = load_bitmap_resized("./image/bathroom_paste.png",WIDTH,HEIGHT);
    first_game_kitchen_paste = load_bitmap_resized("./image/kitchen_paste.png",WIDTH,HEIGHT);
    first_game_underground_paste = load_bitmap_resized("./image/underground_paste.png",WIDTH,HEIGHT);


    //--all scene
    first_game_get_UFO_bitmap = al_load_bitmap("./image/get_UFO_notice.png");
    if (!first_game_get_UFO_bitmap)
		game_abort("failed to load image: first_game_get_UFO_bitmap");

    first_game_not_enough_UFO_bitmap = al_load_bitmap("./image/not_enough_UFO.png");
    if (!first_game_not_enough_UFO_bitmap)
		game_abort("failed to load image: first_game_not_enough_UFO_bitmap");

    first_game_get_paste_bitmap = al_load_bitmap("./image/get_char_paste.png");
    if (!first_game_get_paste_bitmap)
		game_abort("failed to load image: get_char_paste_bitmap");

    //--livingroom
    first_game_UFO_1 = load_bitmap_resized("./image/UFO_repair_1.png",WIDTH,HEIGHT);
    first_game_UFO_2 = load_bitmap_resized("./image/UFO_repair_2.png",WIDTH,HEIGHT);
    first_game_UFO_open = load_bitmap_resized("./image/UFO_open.png",WIDTH,HEIGHT);
    first_game_UFO_out = load_bitmap_resized("./image/UFO_out.png",WIDTH,HEIGHT);
    first_game_UFO_ref = al_load_bitmap("./image/UFO_repair_ref.png");
    if (!first_game_UFO_ref)
		game_abort("failed to load image: first_game_UFO_ref");

    first_game_password_1 = load_bitmap_resized("./image/password_1.png",WIDTH,HEIGHT);
    first_game_password_2 = load_bitmap_resized("./image/password_2.png",WIDTH,HEIGHT);
    first_game_password_ref = al_load_bitmap("./image/password_ref.png");
    if (!first_game_password_ref)
		game_abort("failed to load image: first_game_password_ref");

    first_game_dog_1 = load_bitmap_resized("./image/dog_1.png",WIDTH,HEIGHT);
    first_game_dog_2 = load_bitmap_resized("./image/dog_2.png",WIDTH,HEIGHT);
    first_game_dog_smile = load_bitmap_resized("./image/dog_smile.png",WIDTH,HEIGHT);
    first_game_dog_ref = al_load_bitmap("./image/dog_ref.png");
    if (!first_game_dog_ref)
		game_abort("failed to load image: first_game_dog_ref");

    //--kitchen
    first_game_chicken_1 = load_bitmap_resized("./image/chicken_1.png",WIDTH,HEIGHT);
    first_game_chicken_2 = load_bitmap_resized("./image/chicken_2.png",WIDTH,HEIGHT);
    first_game_chicken_ref = al_load_bitmap("./image/chicken_ref.png");

    first_game_treasure_map_1 = load_bitmap_resized("./image/treasure_map1.png",WIDTH,HEIGHT);
    first_game_treasure_map_2 = load_bitmap_resized("./image/treasure_map2.png",WIDTH,HEIGHT);
    first_game_treasure_map_ref = al_load_bitmap("./image/treasure_map_ref.png");

    //--bathroom
    first_game_toilet_1 = load_bitmap_resized("./image/toilet_1.png",WIDTH,HEIGHT);
    first_game_toilet_2 = load_bitmap_resized("./image/toilet_2.png",WIDTH,HEIGHT);
    first_game_toilet_ref = al_load_bitmap("./image/toilet_ref.png");
    if (!first_game_toilet_ref)
		game_abort("failed to load image: first_game_toliet_ref");


    //--password
    first_game_password_start_bitmap = al_load_bitmap("./image/star.png");
    if (!first_game_password_start_bitmap)
		game_abort("failed to load image: first_game_password_start_bitmap");

    //--underground
    first_game_treasure_1 = al_load_bitmap("./image/Box close.PNG");
    if (!first_game_treasure_1)
		game_abort("failed to load image: first_game_treasure_1");
    first_game_treasure_2 = al_load_bitmap("./image/Box open.PNG");
    if (!first_game_treasure_2)
		game_abort("failed to load image: first_game_treasure_2");

    for(int i = 1 ; i <= IMAGE_TREASURE ; i++){
        char temp[50];
        sprintf( temp, "./image/Box close_cut_%d.png", i );
        first_game_treasure[i-1] = al_load_bitmap(temp);
        if (!first_game_treasure[i-1])
            game_abort("failed to load image: first_game_treasure.png");
    }


    //--BGM
    first_game_intro_bgm = al_load_sample("./sound/Ys IX -Monstrum NOX- OST - Only the Corpse Goes Out.ogg");
    if(!first_game_intro_bgm)
        game_abort("failed to load sample: first_game_intro_bgm");

    first_game_livingroom_bgm = al_load_sample("./sound/Ys IX -Monstrum NOX- OST - Tranquil Silence.ogg");
    if(!first_game_livingroom_bgm)
        game_abort("failed to load sample: first_game_bgm");

    first_game_kitchen_bgm = al_load_sample("./sound/Ys IX -Monstrum NOX- OST - Ambiguous Territory.ogg");
    if(!first_game_kitchen_bgm)
        game_abort("failed to load sample: first_game_bgm_2");

    first_game_bathroom_bgm = al_load_sample("./sound/Ys IX -Monstrum NOX- OST - Il Était une Fois.ogg");
    if(!first_game_bathroom_bgm)
        game_abort("failed to load sample: first_game_bgm_3");

    first_game_underground_bgm = al_load_sample("./sound/Ys IX -Monstrum NOX- OST - Prison of Balduq  -Live the Future-.ogg");
    if(!first_game_underground_bgm)
        game_abort("failed to load sample: first_game_underground_bgm");

    //--INTRO
    first_game_fall_sound = al_load_sample("./sound/fall_sound.ogg");
    if(!first_game_fall_sound)
        game_abort("failed to load sample: first_game_fall_sound");

    //--PASSWORD
    first_game_password_insert_sound = al_load_sample("./sound/insert_sound.ogg");
    if(!first_game_password_insert_sound)
        game_abort("failed to load sample: first_game_password_insert_sound");

    first_game_password_unlocked_sound = al_load_sample("./sound/unlocked.ogg");
    if(!first_game_password_unlocked_sound)
        game_abort("failed to load sample: first_game_password_unlocked");

    first_game_password_error_sound = al_load_sample("./sound/wrong_answer.ogg");
    if(!first_game_password_error_sound)
        game_abort("failed to load sample: first_game_password_error");

    //--BATHROOM
    first_game_in_tube_sound = al_load_sample("./sound/go_in_tube.ogg");
    if(!first_game_in_tube_sound)
        game_abort("failed to load sample: first_game_in_tube_sound");

    //--get UFO sound initialize
    first_game_get_UFO_sound = al_load_sample("./sound/Ys IX -Monstrum NOX- OST - Treasure Box -Ys IX-.ogg");
    if (!first_game_get_UFO_sound)
		game_abort("failed to load audio: first_game_get_UFO_sound");

    //--LIVINGROOM
    first_game_launch_sound = al_load_sample("./sound/rocket.ogg");
    if (!first_game_launch_sound)
		game_abort("failed to load audio: first_game_launch_sound");

    first_game_scene_audio();
}


void first_game_scene_process(ALLEGRO_EVENT event){//--judge other places

    //--use keyboard and mouse
    if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        //printf("%d\n",event.keyboard.keycode);
        //game_log("key event down");
        main_chara.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        //game_log("key event up");
        key_state[event.keyboard.keycode] = false;
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        // Event for mouse key down.
        game_log("Mouse button %d down at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
        mouse_state[event.mouse.button] = true;
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        // Event for mouse key up.
        //game_log("Mouse button %d up at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_state[event.mouse.button] = false;
    }

    //--all scene process
    //--停掉動畫
    now = al_get_time();

    if( UFO_get_animation_and_sound && now - last_get_animation_time >= GET_ANIMATION_LASTTIME ){
        UFO_get_animation_and_sound = false;
        first_game_scene_audio();
    }

    if( paste_get_animation_and_sound && now - last_get_animation_time >= GET_ANIMATION_LASTTIME ){
        paste_get_animation_and_sound = false;
        first_game_scene_audio();
    }

    if( UFO_get_animation_and_sound || paste_get_animation_and_sound ){
        first_game_scene_stop_audio();
    }
    //--關閉飛碟不足提醒
    if(open_UFO_attempt && now - last_open_UFO_attempt_time >= NOT_ENOUGH_UFO_ANIMATION_LASTTIME) open_UFO_attempt = false;

    if(window == SCENE_FIRST_GAME_INTRO){


        if(key_state[ALLEGRO_KEY_ENTER] && hide_char){
            hide_char = false;
            start_ani = true;
            first_game_scene_stop_audio();
            first_game_scene_sound();
            start_animation_time = al_get_time();
        }
        //--可操縱腳色
        if(now -start_animation_time >= START_ANIMATION_LASTTIME && !hide_char && start_ani){
            sit_count = false;
            start_ani = false;
            first_game_scene_audio();
        }

        //--拿到paste
        if(!get_intro_paste && pnt_in_rect(mouse_x,mouse_y,1143,857,20,80)){
            get_intro_paste = true;
            paste_get();
            first_game_scene_sound();
        }

        if(main_chara.y > HEIGHT - main_chara.h-200 && main_chara.x < 1200 && main_chara.x > 1000
           && (key_state[ALLEGRO_KEY_UP] || key_state[ALLEGRO_KEY_W])){
            judge_next_window = true;
        }

    }
    else if(window == SCENE_FIRST_GAME_LIVINGROOM){
        now = al_get_time();
        //--special case for go out screen
        if( ((main_chara.x <=100 || main_chara.x + main_chara.w >=WIDTH - 100) && main_chara.y > 300 && main_chara.y < 500)
           || (( main_chara.y + main_chara.h >= HEIGHT-100 ) && main_chara.x >500 && main_chara.x <1000 ))
        {
            special_case = true;
        }
        else{
            special_case = false;
        }

        //--do something when calling object
        if(in_UFO && key_state[ALLEGRO_KEY_SPACE] && !open_UFO){
            if(UFO_count < 3){
                open_UFO_attempt = true;
                last_open_UFO_attempt_time = now;
            }
            else{
                open_UFO = true;
                last_push_space_time = now;
            }
        }
        else if(in_password && key_state[ALLEGRO_KEY_SPACE] && !password_done){
            judge_next_window = true;
            livingroom_scene = 4;
        }
        else if(in_dog && key_state[ALLEGRO_KEY_SPACE] && take_chicken){
            dog_smile = true;
            take_chicken = false;
            UFO_get();
            first_game_scene_sound();
        }

        //--當UFO門打開
        //UFO_count = 3;
        //printf("%d %d %d %lf\n",open_UFO,key_state[ALLEGRO_KEY_SPACE],!sec_start_ani,now - last_push_space_time);
        if(open_UFO && key_state[ALLEGRO_KEY_SPACE] && !sec_start_ani_down && now - last_push_space_time >= BETWEEN_TWO_SPACE_COOLDOWN
           && pnt_in_rect(672,146,main_chara.x,main_chara.y,main_chara.w,main_chara.h)){
            printf("in first game end");
            first_game_done = true;
            if(UFO_count == 3 && paste_count == 5) first_game_bonus = true;
            sec_start_ani_down = true;
            first_game_scene_stop_audio();
            sec_start_down_animation_time = al_get_time();
        }
        //--從down變up
        if(sec_start_ani_down && now - sec_start_down_animation_time >= SECOND_START_DOWN_ANIMATION_LASTTIME){
            sec_start_ani_down = false;
            sec_start_ani_up = true;
            sec_start_up_animation_time = al_get_time();
            first_game_scene_sound();
        }

        //--當動畫播完
        if(sec_start_ani_up && now - sec_start_up_animation_time >= SECOND_START_UP_ANIMATION_LASTTIME){
            judge_next_window = true;
        }

        //--拿到paste
        if(!get_livingroom_paste && pnt_in_rect(mouse_x,mouse_y,273,20,60,40)){
            get_livingroom_paste = true;
            paste_get();
            first_game_scene_sound();
        }

        //--back to intro
        if(main_chara.y > HEIGHT+200 && main_chara.x >500 && main_chara.x <1000){
            judge_next_window = true;
            livingroom_scene = 3;
        }
        //-- to kitchen
        else if(main_chara.y > 300 && main_chara.y <500 && main_chara.x <-150){
            judge_next_window = true;
            livingroom_scene = 1;
        }
        //-- to bathroom
        else if(main_chara.y > 300 && main_chara.y <500 && main_chara.x > WIDTH+150){
            judge_next_window = true;
            livingroom_scene = 2;
        }

    }
    else if(window == SCENE_FIRST_GAME_PASSWORD){
        now = al_get_time();
        //--滑鼠左鍵
        if( mouse_state[1] && now - last_password_insert_time >=  PASSWORD_INSERT_COOLDOWN){
            //printf("*");
            last_password_insert_time = now;
            //-按下退出
            if(pnt_in_rect(event.mouse.x,event.mouse.y,50,50,100,100)){
                judge_next_window = true;
            }
            //--按下0
            if(pnt_in_rect(event.mouse.x,event.mouse.y,password_loc_x[1],710,password_W,password_H)){
                password_insert[0] = true;
                printf("0 down\n");
            }
            else{
                password_insert[0] = false;
            }
            //--按下1~9
            for(int i=0 ; i<3 ; i++){
                for(int j=0 ; j<3 ; j++){
                    if(pnt_in_rect(event.mouse.x,event.mouse.y,password_loc_x[j],password_loc_y[i],password_W,password_H)){
                        password_insert[i*3+j+1] = true;
                        printf("%d down\n",i*3+j+1);
                    }
                    else{
                        password_insert[i*3+j+1] = false;
                    }
                }
            }
            //--按下delete
            if(pnt_in_rect(event.mouse.x,event.mouse.y,password_loc_x[2],710,password_W,password_H)){
                password_insert[10] = true;
                printf("delete down\n");

            }
            else{
                password_insert[10] = false;
            }
            //--按下ok
            if(pnt_in_rect(event.mouse.x,event.mouse.y,password_loc_x[0],710,password_W,password_H)){
                password_insert[11] = true;
                printf("ok down\n");
            }
            else{
                password_insert[11] = false;
            }
            password_validation();
            //--不想讓按退出觸發到音效
            if(!judge_next_window) first_game_scene_sound();
        }
    }
    else if(window == SCENE_FIRST_GAME_KITCHEN){

        if( main_chara.x + main_chara.w >= WIDTH-100 && main_chara.y > 300 && main_chara.y <500){
            special_case = true;
        }
        else{
            special_case = false;
        }

        if(!take_chicken && in_chicken && key_state[ALLEGRO_KEY_SPACE]){
            take_chicken = true;
        }
        if(take_chicken && in_chicken && key_state[ALLEGRO_KEY_LCTRL]){
            take_chicken = false;
        }

        //--換去map場景
        if(in_treasure_map && key_state[ALLEGRO_KEY_SPACE]){
            read_treasure_map = true;
            judge_next_window = true;
        }

        //--拿到paste
        if(!get_kitchen_paste && pnt_in_rect(mouse_x,mouse_y,652,229,40,20)){
            get_kitchen_paste = true;
            paste_get();
            first_game_scene_sound();
        }

        if(main_chara.y > 300 && main_chara.y <500 && main_chara.x > WIDTH+150){
            judge_next_window = true;
        }
    }
    else if(window == SCENE_FIRST_GAME_TREASURE_MAP){
        if(pnt_in_rect(event.mouse.x,event.mouse.y,50,50,100,100) && mouse_state[1]){
            judge_next_window = true;
        }
    }
    else if(window == SCENE_FIRST_GAME_BATHROOM){

        //go_out_tube = false;
        if( main_chara.x <= 100 && main_chara.y > 300 && main_chara.y <500){
            special_case = true;
        }
        else{
            special_case = false;
        }

        //--去underground
        if(in_toilet && key_state[ALLEGRO_KEY_SPACE] ){
            //--go to underground
            first_game_scene_sound();
            go_into_tube = true;
        }
        /*
        if(!go_into_tube && in_tube){
            printf("to underground\n");
            bathroom_scene = 2;
            judge_next_window = true;

        }
        */
        //--進水管動畫跑完
        if(in_tube){
            printf("to underground\n");
            bathroom_scene = 2;
            judge_next_window = true;
        }


        //--拿到paste
        if(!get_bathroom_paste && pnt_in_rect(mouse_x,mouse_y,1205,200,10,50)){
            get_bathroom_paste = true;
            paste_get();
            first_game_scene_sound();
        }


        //--回到living room
        if(main_chara.y > 300 && main_chara.y <500 && main_chara.x <-150){
            bathroom_scene = 1;
            judge_next_window = true;
        }

    }
    else if(window == SCENE_FIRST_GAME_UNDERGROUND){

        //in_tube = false;
        //go_into_tube = true;
        //--get UFO

        if(read_treasure_map && rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h,WIDTH-300,HEIGHT-300
            ,al_get_bitmap_width(first_game_treasure_2)+100,al_get_bitmap_height(first_game_treasure_2)+100) && key_state[ALLEGRO_KEY_SPACE])
        {
            treasure_appear = true;
            last_treasure_appear_time = al_get_time();
        }


        if(treasure_ani_done && rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h,WIDTH-300,HEIGHT-300
            ,al_get_bitmap_width(first_game_treasure_2)+100,al_get_bitmap_height(first_game_treasure_2)+100) && key_state[ALLEGRO_KEY_SPACE])
        {
            if(!treasure_get){
                UFO_get();
                first_game_scene_sound();
            }
            treasure_get = true;
        }

        //--回到bathroom
        if(main_chara.y <= 300 && main_chara.x <= WIDTH/2
           && main_chara.x >= WIDTH/2-200 && key_state[ALLEGRO_KEY_SPACE]){
            first_game_scene_sound();
            go_out_tube = true;

        }

        if(!in_tube){
            printf("to bathroom\n");
            judge_next_window = true;
        }


        //--拿到paste
        if(!get_underground_paste && pnt_in_rect(mouse_x,mouse_y,790,90,10,80)){
            get_underground_paste = true;
            paste_get();
            first_game_scene_sound();
        }

    }
}

void first_game_scene_draw(){

    if(window == SCENE_FIRST_GAME_INTRO){
        al_draw_bitmap(first_game_intro_bg, 0, 0, 0);
        if(!get_intro_paste) al_draw_bitmap(first_game_intro_paste,0,0,0);
    }
    else if(window == SCENE_FIRST_GAME_LIVINGROOM){
        al_draw_bitmap(first_game_livingroom_bg,0,0,0);

        if(sec_start_ani_down || sec_start_ani_up) al_draw_bitmap(first_game_UFO_out,0,0,0);
        else if(open_UFO) al_draw_bitmap(first_game_UFO_open,0,0,0);
        else if(rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h
            ,600,105,al_get_bitmap_width(first_game_UFO_ref),al_get_bitmap_height(first_game_UFO_ref)))
        {
            al_draw_bitmap(first_game_UFO_2,0,0,0);
            in_UFO = true;
        }
        else{
            al_draw_bitmap(first_game_UFO_1,0,0,0);
            in_UFO = false;
        }

        if(rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h
            ,955,130,al_get_bitmap_width(first_game_password_ref),al_get_bitmap_height(first_game_password_ref)) || password_done)
        {
            al_draw_bitmap(first_game_password_2,0,0,0);
            in_password = true;
        }
        else{
            al_draw_bitmap(first_game_password_1,0,0,0);
            in_password = false;
        }

        if(dog_smile) al_draw_bitmap(first_game_dog_smile,0,0,0);
        else if(rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h
            ,245,200,al_get_bitmap_width(first_game_dog_ref),al_get_bitmap_height(first_game_dog_ref)))
        {
            al_draw_bitmap(first_game_dog_2,0,0,0);
            in_dog = true;
        }
        else{
            al_draw_bitmap(first_game_dog_1,0,0,0);
            in_dog = false;
        }
        //--draw paste
        if(!get_livingroom_paste) al_draw_bitmap(first_game_livingroom_paste,0,0,0);
    }
    else if(window == SCENE_FIRST_GAME_PASSWORD){
        al_draw_bitmap(first_game_password_bg,0,0,0);
        for(int i=0 ; i<password_cursor ; i++){
            al_draw_bitmap(first_game_password_start_bitmap,star_position[i]-75,162-75,0);
        }
    }
    else if(window == SCENE_FIRST_GAME_KITCHEN){
        //game_log("draw");
        al_draw_bitmap(first_game_kitchen_bg, 0, 0, 0);

        if(take_chicken || dog_smile);
        else if(rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h
            ,438,550,al_get_bitmap_width(first_game_chicken_ref),al_get_bitmap_height(first_game_chicken_ref)))
        {

            al_draw_bitmap(first_game_chicken_2,0,0,0);
            in_chicken = true;
        }
        else{
            al_draw_bitmap(first_game_chicken_1,0,0,0);
            in_chicken = false;
        }

        if(rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h
            ,830,700,al_get_bitmap_width(first_game_treasure_map_ref),al_get_bitmap_height(first_game_treasure_map_ref)))
        {
            in_treasure_map = true;
            al_draw_bitmap(first_game_treasure_map_2,0,0,0);
        }
        else{
            in_treasure_map = false;
            al_draw_bitmap(first_game_treasure_map_1,0,0,0);
        }

        //--draw paste
        if(!get_kitchen_paste) al_draw_bitmap(first_game_kitchen_paste,0,0,0);
    }
    else if(window == SCENE_FIRST_GAME_TREASURE_MAP){
        al_draw_bitmap(first_game_treasure_map_bg,0,0,0);
    }
    else if(window == SCENE_FIRST_GAME_BATHROOM){

        al_draw_bitmap(first_game_bathroom_bg, 0, 0, 0);

        if(rect_in_rect(main_chara.x,main_chara.y,main_chara.w,main_chara.h
            ,440,100,al_get_bitmap_width(first_game_toilet_ref),al_get_bitmap_height(first_game_toilet_ref))
           && !take_chicken)
        {
            al_draw_bitmap(first_game_toilet_2,0,0,0);
            in_toilet = true;
        }
        else{
            al_draw_bitmap(first_game_toilet_1,0,0,0);
            in_toilet = false;
        }

        //--draw paste
        if(!get_bathroom_paste) al_draw_bitmap(first_game_bathroom_paste,0,0,0);

    }
    else if(window == SCENE_FIRST_GAME_UNDERGROUND){
        //al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(first_game_underground_bg,0,HEIGHT/2-al_get_bitmap_height(first_game_underground_bg)/2,0);


        if(treasure_get){
            al_draw_bitmap(first_game_treasure_2,WIDTH-300-al_get_bitmap_width(first_game_treasure_1)/2
                           ,HEIGHT-300+al_get_bitmap_height(first_game_treasure_1)/2-(al_get_bitmap_height(first_game_treasure_2)-al_get_bitmap_height(first_game_treasure_1)),0);
        }
        else{
            if(treasure_appear){
                //printf("in treasure appear\n");
                if(!treasure_ani_done){
                    printf("in !treasure ani done\n");
                    now = al_get_time();
                    if(now - last_treasure_appear_time >= TREASURE_APPEAR_INTERVAL){
                        last_treasure_appear_time  = now;
                        img_treasure_count--;
                        printf("%d ",img_treasure_count);
                    }
                    al_draw_bitmap(first_game_treasure[img_treasure_count],WIDTH-300-al_get_bitmap_width(first_game_treasure_1)/2
                                   ,HEIGHT-300+7*img_treasure_count+al_get_bitmap_height(first_game_treasure_1)/2,0);
                    if(img_treasure_count == 0){
                        //img_bathroom_tube_count++;
                        treasure_ani_done = true;
                    }
                }
                if(treasure_ani_done)al_draw_bitmap(first_game_treasure_1,WIDTH-300-al_get_bitmap_width(first_game_treasure_1)/2
                               ,HEIGHT-300+al_get_bitmap_height(first_game_treasure_1)/2,0);
            }
        }

        //--draw paste
        if(!get_underground_paste) al_draw_bitmap(first_game_underground_paste,0,0,0);
    }
    //--密碼場景不需要顯示
    if(window != SCENE_FIRST_GAME_PASSWORD && window != SCENE_FIRST_GAME_TREASURE_MAP && !hide_char){
        character_draw();
        //--一開始不要顯示UFO count
        if(!start_ani){
            object_draw();
            UFO_count_draw();
            if(get_first_paste)
                paste_count_draw();
        }
    }

    //--all scene draw
    if(UFO_get_animation_and_sound){
        //printf("animation draw\n");
        al_draw_bitmap(first_game_get_UFO_bitmap, 450, 0, 0);
    }

    if(paste_get_animation_and_sound){
        al_draw_bitmap(first_game_get_paste_bitmap, 450, 0, 0);
    }

    if(open_UFO_attempt){
        al_draw_bitmap(first_game_not_enough_UFO_bitmap, 450, 0, 0);
    }
}

void first_game_scene_audio(){
    //game_log("first_game_scene_audio : %d",window);

    if(window == SCENE_FIRST_GAME_INTRO){
        if (!al_play_sample(first_game_intro_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &first_game_intro_bgm_ID)){
            game_abort("failed to play first game intro bgm");
        }
    }
    else if(window == SCENE_FIRST_GAME_LIVINGROOM){
        if (!al_play_sample(first_game_livingroom_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &first_game_livingroom_bgm_ID)){
            game_abort("failed to play first game bgm");
        }
    }
    else if(window == SCENE_FIRST_GAME_KITCHEN){
        if (!al_play_sample(first_game_kitchen_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &first_game_kitchen_bgm_ID)){
            game_abort("failed to play first game bgm 2");
        }
    }
    else if(window == SCENE_FIRST_GAME_BATHROOM){
        if (!al_play_sample(first_game_bathroom_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &first_game_bathroom_bgm_ID)){
            game_abort("failed to play first game bgm 2");
        }
    }
    else if(window == SCENE_FIRST_GAME_UNDERGROUND){
        if (!al_play_sample(first_game_underground_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &first_game_underground_bgm_ID)){
            game_abort("failed to play first game bgm 2");
        }
    }
}

void first_game_scene_stop_audio(){

    if(window == SCENE_FIRST_GAME_INTRO){
        al_stop_sample(&first_game_intro_bgm_ID);
        game_log("stop first game intro bgm");
    }
    else if(window == SCENE_FIRST_GAME_LIVINGROOM){
        al_stop_sample(&first_game_livingroom_bgm_ID);
        game_log("stop first scene bgm");
    }
    else if(window == SCENE_FIRST_GAME_KITCHEN){
        al_stop_sample(&first_game_kitchen_bgm_ID);
        game_log("stop first scene bgm 2");
    }
    else if(window == SCENE_FIRST_GAME_BATHROOM){
        al_stop_sample(&first_game_bathroom_bgm_ID);
        game_log("stop first scene bgm 3");
    }
    else if(window == SCENE_FIRST_GAME_UNDERGROUND){
        al_stop_sample(&first_game_underground_bgm_ID);
        game_log("stop first scene bgm 3");
    }
}

//--音效
void first_game_scene_sound(){

    //al_stop_samples();
    //first_game_scene_audio();

    if(window == SCENE_FIRST_GAME_INTRO){
        if(start_ani){
            if (!al_play_sample(first_game_fall_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_fall_sound_ID)){
                game_abort("failed to play first_game_fall_sound");
            }
        }

    }
    else if(window == SCENE_FIRST_GAME_LIVINGROOM){//--發射飛碟
        if(sec_start_ani_up){
            if (!al_play_sample(first_game_launch_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_launch_sound_ID)){
                game_abort("failed to play first_game_launch_sound");
            }
        }
    }
    else if(window == SCENE_FIRST_GAME_PASSWORD){
        for(int i=0 ; i<=10 ; i++){
            if(password_insert[i]){
                if (!al_play_sample(first_game_password_insert_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_password_insert_sound_ID)){
                    game_abort("failed to play first_game_password_insert_sound");
                }
            }
        }
        //--OK
        if(password_insert[11]){
            if(password_done){
                if (!al_play_sample(first_game_password_unlocked_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_password_unlocked_sound_ID)){
                    game_abort("failed to play first_game_password_unlocked");
                }
            }
            else{
                if (!al_play_sample(first_game_password_error_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_password_error_sound_ID)){
                    game_abort("failed to play first_game_password_error");
                }
            }
        }
    }
    else if(window == SCENE_FIRST_GAME_BATHROOM){
        if(!go_into_tube){
            if (!al_play_sample(first_game_in_tube_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_in_tube_sound_ID)){
                game_abort("failed to play first_game_password_unlocked");
            }
        }
    }
    else if(window == SCENE_FIRST_GAME_UNDERGROUND){
        if((go_into_tube || !go_out_tube) && !UFO_get_animation_and_sound && !paste_get_animation_and_sound ){
            if (!al_play_sample(first_game_in_tube_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_in_tube_sound_ID)){
                game_abort("failed to play first_game_password_unlocked");
            }
        }
    }
    now = al_get_time();
    if((UFO_get_animation_and_sound || paste_get_animation_and_sound)){
        if(now - last_get_sound_time <= GET_UFO_LASTTIME) al_stop_sample(&first_game_get_UFO_sound_ID);
        last_get_sound_time = now;
        if (!al_play_sample(first_game_get_UFO_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &first_game_get_UFO_sound_ID)){
                game_abort("failed to play first_game_get_UFO_sound");
            }
    }

}

void first_game_scene_destroy(){
    al_destroy_bitmap(first_game_intro_bg);
    al_destroy_bitmap(first_game_livingroom_bg);
    al_destroy_bitmap(first_game_kitchen_bg);
    al_destroy_bitmap(first_game_password_bg);

    al_destroy_bitmap(first_game_UFO_1);
    al_destroy_bitmap(first_game_UFO_2);
    al_destroy_bitmap(first_game_password_1);
    al_destroy_bitmap(first_game_password_2);
    al_destroy_bitmap(first_game_dog_1);
    al_destroy_bitmap(first_game_dog_2);

    //character_destory();
    al_destroy_sample(first_game_intro_bgm);
    al_destroy_sample(first_game_livingroom_bgm);
    al_destroy_sample(first_game_kitchen_bgm);
}



//---------second  game---------//



void second_game_scene_init(){

    //--start
    start_img_background = load_bitmap_resized("./image/start-bg.jpg", WIDTH, HEIGHT);
    start_img_background_2 = load_bitmap_resized("./image/start_bg_2.jpg", WIDTH, HEIGHT);

    start_bgm = al_load_sample("./sound/Ys VIII -Lacrimosa of DANA- OST - You'll See Out the End of the Tales.ogg");
    if (!start_bgm)
        game_abort("failed to load audio: start bgm");



    //--boss
    //boss_img_background = load_bitmap_resized("./image/Dark-Background_1.jpg", WIDTH, HEIGHT);
    //boss_img_background_2 = load_bitmap_resized("./image/Dark-Background_2.jpg", WIDTH, HEIGHT);
    boss_img_background = load_bitmap_resized("./image/boss_bg.png", WIDTH, HEIGHT);
    boss_img_background_2 = load_bitmap_resized("./image/boss_bg_2.png", WIDTH, HEIGHT);

    boss_bgm_1 = al_load_sample("./sound/Ys IX -Monstrum NOX- OST - Urban Terror.ogg");
    if (!boss_bgm_1)
        game_abort("failed to load audio : boss bgm 1");

    boss_bgm_2 = al_load_sample("./sound/Ys VIII -Lacrimosa of DANA- OST - Volitional Decision.ogg");
    if (!boss_bgm_2)
        game_abort("failed to load audio : Ys VIII -Lacrimosa of DANA- OST - Volitional Decision.ogg");



    //--gameover
    gameover_img_background = load_bitmap_resized("./image/gameover.jpg", WIDTH, HEIGHT);

    gameover_bgm = al_load_sample("./sound/Ys VIII -Lacrimosa of DANA- OST - Dana.ogg");
    if (!gameover_bgm)
        game_abort("failed to load audio: Ys VIII -Lacrimosa of DANA- OST - Dana.ogg");

    //--victory
    victory_img_background = load_bitmap_resized("./image/victory_bg.jpg", WIDTH, HEIGHT);

    victory_bgm = al_load_sample("./sound/Final Fantasy XV OST - 09. Day's End Fanfare.ogg");
    if (!victory_bgm)
        game_abort("failed to load audio : Ys VIII -Lacrimosa of DANA- OST - Final Fantasy XV OST - 09. Day's End Fanfare.ogg");

    //--character init
    second_game_character_init();
    printf("end character init\n");

    //--start and boss sound
    shoot_sound = al_load_sample("./sound/shoot.ogg");
	if (!shoot_sound)
		game_abort("failed to load audio:shoot.ogg");

	fire_sound = al_load_sample("./sound/fire.ogg");
	if (!fire_sound)
		game_abort("failed to load audio:fire.ogg");

    laser_sound = al_load_sample("./sound/starburst.ogg");
	if (!laser_sound)
		game_abort("failed to load audio:starburst.ogg");

    shield_sound = al_load_sample("./sound/the_wall.ogg");
	if (!shield_sound)
		game_abort("failed to load audio:shield_sound");


}



void second_game_scene_process(ALLEGRO_EVENT event){
    double now = al_get_time();
    int i,j;
    //--use keyboard and mouse
    if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        //printf("%d\n",event.keyboard.keycode);
        //game_log("key event down");
        main_chara.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        //game_log("key event up");
        key_state[event.keyboard.keycode] = false;
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        // Event for mouse key down.
        game_log("Mouse button %d down at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_state[event.mouse.button] = true;
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        // Event for mouse key up.
        //game_log("Mouse button %d up at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_state[event.mouse.button] = false;
    }

    //--場景轉換
    if(first_change_to_second && now-first_change_to_second_time >= CHANGE_TIME_COOLDOWN){
        start_time = al_get_time();
        first_change_to_second = false;
    }

    //--共有
    if( window == SCENE_SECOND_GAME_START || window == SCENE_SECOND_GAME_BOSS ){
        now = al_get_time();

        //--open small plane
        if(first_game_bonus && key_state[ALLEGRO_KEY_C]){
            printf("in open small plane\n");
            for(i=0 ; i<MAX_SMALL_PLANE ; i++){
                small_plane[i].hidden = false;
            }
            small_plane_appear = true;
        }
        //--close small plane
        if(small_plane_appear && key_state[ALLEGRO_KEY_V]){
            printf("in close small plane\n");
            for(i=0 ; i<2 ; i++){
                small_plane[i].hidden = true;
            }
            small_plane_appear = false;
        }

        //--plane shoot bullet
        if ((key_state[ALLEGRO_KEY_LCTRL] || mouse_state[1] ) && now - last_plane_shoot_timestamp >= MAX_COOLDOWN && !laser_appearance) {//--if tab ctrl, bullets gain x,y coordinate ,shoot
            for ( i=0 ; i<MAX_BULLET ;i++ ) {
                if (bullets[i].hidden){//---recycle the bullet
                al_stop_sample(&shoot_sound_id);
                last_plane_shoot_timestamp = now;
                bullets[i].hidden = false;
                bullets[i].x = plane.x;
                bullets[i].y = plane.y - (plane.h)/2; //- bullets[i].h/2;
                //game_log("bullet %d is at (%f,%f) with velocity (%f,%f) and plane (%f,%f)",i,bullets[i].x,bullets[i].y,bullets[i].vx,bullets[i].vy,plane.x,plane.y);

                //--play shoot,fire sound
                if (!al_play_sample(shoot_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &shoot_sound_id)){
                    game_abort("failed to play shoot sound");
                }
                break;
                }
            }
        }

        now = al_get_time();

        //--plane shoot laser
        if ((key_state[ALLEGRO_KEY_LCTRL] || mouse_state[1] )
            && laser_appearance && laser.hidden && now - last_plane_shoot_laser_timestamp >= LASER_LAST_TIME){
            last_plane_shoot_laser_timestamp = now;
            al_stop_sample(&fire_sound_id);
            laser.hidden = false;
            laser.x = plane.x-laser.w/2;
            laser.y = plane.y-plane.h/2-laser.h;
            //plane.ULT -= 50;

            if (!al_play_sample(fire_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &fire_sound_id)){
                game_abort("failed to play shoot sound");
            }
        }

        //--small plane shoot bullet
        now = al_get_time();
        if( now - last_small_plane_shoot_timestamp >= SMALL_BULLET_MAX_COOLDOWN){
            for( i=0 ; i<MAX_SMALL_PLANE ; i++){
                for( j=0 ; j<MAX_BULLET ; j++){
                    if(!small_plane[i].hidden && small_bullets[i][j].hidden){
                        last_small_plane_shoot_timestamp = now;
                        //game_log("enemy bullet [%d] is shoot",i);
                        //--control different enemies shooting interval
                        small_bullets[i][j].hidden = false;
                        small_bullets[i][j].x = small_plane[i].x;
                        small_bullets[i][j].y = small_plane[i].y-small_plane[i].h/2;
                        break;
                    }
                }
            }
        }

        //--plane's ultimate trigger
        now = al_get_time();
        if( plane.ULT >= plane.MAX_ULT && (key_state[ALLEGRO_KEY_X] || key_state[ALLEGRO_KEY_Z] || mouse_state[2]) && plane_code != 1 && !ultimate){
            ultimate_trigger_time = al_get_time();
            ultimate = true;
            //plane.ULT -= 1;
            key_state[ALLEGRO_KEY_LSHIFT] = false;
            //--play ultimate sound
            //--laser
            if( plane_code == 3 && key_state[ALLEGRO_KEY_X]){
                laser_appearance = true;
                if (!al_play_sample(laser_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &laser_sound_id)){
                    game_abort("failed to play laser_sound");
                }

            }
            //--shield
            else if(plane_code == 3 && key_state[ALLEGRO_KEY_Z]){
                shield_appearance = true;
                if (!al_play_sample(shield_sound, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &laser_sound_id)){
                    game_abort("failed to play shield_sound");
                }
            }
        }

        //--plane's ultimate
         if( ultimate ){

            plane.ULT -= plane.MAX_ULT/(FPS*ULTIMATE_LAST_TIME);
            //printf("%f ",plane.ULT);
            //--end ultimate mode
            if( /*now - ultimate_trigger_time >= ULTIMATE_LAST_TIME ||*/ plane.ULT < 0 ){
                ultimate = false;
                plane.ULT = 0;
                if( plane_code == 3 ){
                    laser_appearance = false;
                    shield_appearance = false;
                    laser.hidden = true;
                }

            }
        }

        //--if get HP drink
        if( pnt_in_rect( HP_drink.x, HP_drink.y, plane.x, plane.y, plane.w, plane.h ) && !HP_drink.hidden ){
            plane.HP += HP_drink.HP;
            if( plane.HP > plane.MAX_HP ) plane.HP = plane.MAX_HP;
            HP_drink.hidden = true;
        }

        //--if get ULT drink
        if( pnt_in_rect( ULT_drink.x, ULT_drink.y, plane.x, plane.y, plane.w, plane.h ) && !ULT_drink.hidden ){
            plane.ULT = plane.MAX_ULT;
            ULT_drink.hidden = true;
        }

        //--plane invincible process
        now = al_get_time();
        if(invincible && now - last_invincible_plane_draw_time >= INVINCIBLE_PLANE_DRAW_COOLDOWN){
            last_invincible_plane_draw_time = now;
            if(plane_draw_key) plane_draw_key = false;
            else plane_draw_key = true;
        }

        //--plane invincible end
        now = al_get_time();
        if( invincible && now - last_invincible_time >= INVINCIBLE_COOLDOWN ){
            invincible = false;
        }




    }

    if(window == SCENE_SECOND_GAME_START){
        //--loss
        if(plane.HP <=0){
            judge_next_window = true;
            dead = true;
        }
        //--win start
        if( now - last_text_time >= GAME_DRAW_TEXT_LAST_TIME && draw_count ){
            start_to_boss = true;
            //judge_next_window = true;
        }
        //--change to boss
        if(plane.y <= -100 && start_to_boss){
            plane.y = HEIGHT+200;
            judge_next_window = true;
            first_in_boss_scene_time = al_get_time();
        }

        //--first enemy shoot bullet
        now = al_get_time();
        if( now - last_first_enemy_shoot_timestamp >= ENEMY_MAX_COOLDOWN){
            for( i=0 ; i<FIRST_ENEMY ; i++){
                for( j=0 ; j<MAX_FIRST_ENEMY_BULLET ; j++){
                    if( first_enemies_bullets[i][j].hidden && !first_enemies[i].hidden  ){
                        //game_log("enemy bullet [%d] is shoot",i);
                        //--control different enemies shooting interval
                        last_first_enemy_shoot_timestamp = now;
                        first_enemies_bullets[i][j].hidden = false;
                        first_enemies_bullets[i][j].x = first_enemies[i].x;
                        first_enemies_bullets[i][j].y = first_enemies[i].y+first_enemies[i].h/2;
                        break;
                    }
                }
            }
        }

        //--second enemy shoot bullet
        now = al_get_time();
        if( now - last_second_enemy_shoot_timestamp >= ENEMY_MAX_COOLDOWN){
            //printf("in second\n");
            for( i=0 ; i<SECOND_ENEMY ; i++){
                for( j=0 ; j<MAX_SECOND_ENEMY_BULLET/4 ; j++){
                    int can = 1;//--可以一起發射
                    //--四發子彈為一組
                    for( k=0 ; k<4 ; k++){
                        if( second_enemies_bullets[i][j*4+k].hidden && !second_enemies[i].hidden );
                        else {
                            //printf("i = %d j = %d k = %d hidden = %d\n",i,j,k,second_enemies_bullets[i][j*4+k].hidden);
                            can = 0;
                            break;
                        }
                    }

                    if(can){
                        //printf("can\n");
                        last_second_enemy_shoot_timestamp = now+1;
                        for( k=0 ; k<4 ; k++){
                            second_enemies_bullets[i][j*4+k].hidden = false;
                            if(k==0){
                                second_enemies_bullets[i][j*4+k].x = second_enemies[i].x;
                                second_enemies_bullets[i][j*4+k].y = second_enemies[i].y+second_enemies[i].h/2;
                            }
                            else if(k==1){
                                second_enemies_bullets[i][j*4+k].x = second_enemies[i].x-second_enemies[i].w/2;
                                second_enemies_bullets[i][j*4+k].y = second_enemies[i].y;
                            }
                            else if(k==2){
                                second_enemies_bullets[i][j*4+k].x = second_enemies[i].x;
                                second_enemies_bullets[i][j*4+k].y = second_enemies[i].y-second_enemies[i].h/2;
                            }
                            else if(k==3){
                                second_enemies_bullets[i][j*4+k].x = second_enemies[i].x+second_enemies[i].w/2;
                                second_enemies_bullets[i][j*4+k].y = second_enemies[i].y;
                            }
                        }

                    }
                }
            }
        }

        //--first enemy bullet hit plane
        now = al_get_time();
        if( now -last_bullet_hit_plane_timestamp >= BULLET_HIT_PLANE_INTERVAL){
            for( i=0 ; i<FIRST_ENEMY ;i++ ){
                for( j=0 ; j<MAX_FIRST_ENEMY_BULLET ; j++){
                    if(pnt_in_rect(first_enemies_bullets[i][j].x,first_enemies_bullets[i][j].y,plane.x,plane.y,plane.w,plane.h)
                       && !first_enemies[i].hidden && !first_enemies_bullets[i][j].hidden ){//--enemy death, can not shoot bullet
                        last_bullet_hit_plane_timestamp = now;
                        first_enemies_bullets[i][j].hidden = true;
                        if(invincible) plane.HP -= 1;
                        else if(shield_appearance) plane.HP-=first_enemies_bullets[i][j].HP/2;
                        else plane.HP-=first_enemies_bullets[i][j].HP;

                        if(!invincible){
                            invincible = true;
                            last_invincible_time = al_get_time();
                        }
                    }
                }
            }
        }

        //--second enemy bullet hit plane
        now = al_get_time();
        if( now -last_bullet_hit_plane_timestamp >= BULLET_HIT_PLANE_INTERVAL){
            for( i=0 ; i<SECOND_ENEMY ;i++ ){
                for( j=0 ; j<MAX_SECOND_ENEMY_BULLET ; j++){
                    if(pnt_in_rect(second_enemies_bullets[i][j].x,second_enemies_bullets[i][j].y,plane.x,plane.y,plane.w,plane.h)
                       && !second_enemies[i].hidden && !second_enemies_bullets[i][j].hidden ){//--enemy death, can not shoot bullet
                        last_bullet_hit_plane_timestamp = now;
                        second_enemies_bullets[i][j].hidden = true;

                        if(invincible) plane.HP -= 1;
                        else if(shield_appearance) plane.HP -= second_enemies_bullets[i][j].HP/2;
                        else plane.HP -= second_enemies_bullets[i][j].HP;

                        if(!invincible){
                            invincible = true;
                            last_invincible_time = al_get_time();
                        }
                    }
                }
            }
        }

        //--plane bullet hit first enemy
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && !laser_appearance ){
            for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                for ( j=0 ; j<FIRST_ENEMY ;j++ ){
                    if(pnt_in_rect(bullets[i].x,bullets[i].y,first_enemies[j].x,first_enemies[j].y,first_enemies[j].w,first_enemies[j].h) && !first_enemies[j].hidden && !bullets[i].hidden){
                        last_bullet_hit_enemy_timestamp = now;
                        //bullets[i].hidden = true;
                        bullets[i].x = -10000;//--recycle the bullet
                        first_enemies[j].HP -= bullets[i].HP;

                        //---if enemy dead
                        if( first_enemies[j].HP <= 0 ){
                            printf("%d hidden :%d \n",j,first_enemies[j].hidden);
                            first_enemies[j].hidden = true;
                            first_explode[j].hidden = false;
                            if(!ultimate) score += 400;
                            else score += 800;//--use ultimate kill enemy have higher score
                            //-- not in ultimate mode
                            if(!ultimate){
                                if( plane.ULT < plane.MAX_ULT ) plane.ULT += 50;
                                if( plane.ULT > plane.MAX_ULT) plane.ULT = plane.MAX_ULT;
                            }
                        }
                    }
                }
            }
        }


        //--plane bullet hit second enemy
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && !laser_appearance ){
            for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                for ( j=0 ; j<SECOND_ENEMY ;j++ ){
                    if(pnt_in_rect(bullets[i].x,bullets[i].y,second_enemies[j].x,second_enemies[j].y,second_enemies[j].w,second_enemies[j].h) && !second_enemies[j].hidden && !bullets[i].hidden){
                        last_bullet_hit_enemy_timestamp = now;
                        //bullets[i].hidden = true;
                        bullets[i].x = -10000;//--recycle the bullet
                        second_enemies[j].HP -= bullets[i].HP;

                        //---if enemy dead
                        if( second_enemies[j].HP <= 0 ){
                            printf("%d hidden :%d \n",j,second_enemies[j].hidden);
                            second_enemies[j].hidden = true;
                            second_explode[j].hidden = false;
                            if(!ultimate) score += 400;
                            else score += 800;//--use ultimate kill enemy have higher score
                            //-- not in ultimate mode
                            if(!ultimate){
                                if( plane.ULT < plane.MAX_ULT ) plane.ULT += 50;
                                if( plane.ULT > plane.MAX_ULT) plane.ULT = plane.MAX_ULT;
                            }
                        }
                    }
                }
            }
        }


        //--plane laser hit first enemy
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && laser_appearance){
            //printf("%d %d %d %d\n",determine_laser_hit_enemy( laser.x,laser.w,enemies[i].x,enemies[i].w )
                       //,!enemies[i].hidden,!laser.hidden,img_laser_count);
            for ( i=0 ; i<FIRST_ENEMY ;i++ ){
                if( determine_laser_hit_enemy( laser.x,laser.w,first_enemies[i].x,first_enemies[i].w ) && !first_enemies[i].hidden
                   && !laser.hidden && (img_laser_count == 2 || img_laser_count == 3 || img_laser_count == 4 )){
                    last_bullet_hit_enemy_timestamp = now;
                    first_enemies[i].HP -= laser.HP;
                    //game_log("**");

                    //---if enemy dead
                        if( first_enemies[i].HP <= 0){
                            first_enemies[i].hidden = true;
                            first_explode[i].hidden = false;
                            score+=800;
                        }

                }
            }
        }

        //--plane laser hit second enemy
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && laser_appearance){
            //printf("%d %d %d %d\n",determine_laser_hit_enemy( laser.x,laser.w,enemies[i].x,enemies[i].w )
                       //,!enemies[i].hidden,!laser.hidden,img_laser_count);
            for ( i=0 ; i<SECOND_ENEMY ;i++ ){
                if( determine_laser_hit_enemy( laser.x,laser.w,second_enemies[i].x,second_enemies[i].w ) && !second_enemies[i].hidden
                   && !laser.hidden && (img_laser_count == 2 || img_laser_count == 3 || img_laser_count == 4 )){
                    last_bullet_hit_enemy_timestamp = now;
                    second_enemies[i].HP -= laser.HP;
                    //game_log("**");

                    //---if enemy dead
                        if( second_enemies[i].HP <= 0){
                            second_enemies[i].hidden = true;
                            second_explode[i].hidden = false;
                            score+=800;
                        }

                }
            }
        }

        //--small plane bullet hit first enemy
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL){
            for(k=0 ; k<MAX_SMALL_PLANE ; k++){
                for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                    for ( j=0 ; j<FIRST_ENEMY ;j++ ){
                        if(pnt_in_rect(small_bullets[k][i].x,small_bullets[k][i].y,first_enemies[j].x,first_enemies[j].y,first_enemies[j].w,first_enemies[j].h)
                           && !first_enemies[j].hidden && !small_bullets[k][i].hidden){
                            last_bullet_hit_enemy_timestamp = now;
                            //bullets[i].hidden = true;
                            small_bullets[k][i].x = -10000;//--recycle the bullet
                            first_enemies[j].HP -= small_bullets[k][i].HP;

                            //---if enemy dead
                            if( first_enemies[j].HP <= 0 ){
                                printf("%d hidden :%d \n",j,first_enemies[j].hidden);
                                first_enemies[j].hidden = true;
                                first_explode[j].hidden = false;
                                if(!ultimate) score += 400;
                                else score += 800;//--use ultimate kill enemy have higher score
                                //-- not in ultimate mode
                                if(!ultimate){
                                    if( plane.ULT < plane.MAX_ULT ) plane.ULT += 50;
                                    if( plane.ULT > plane.MAX_ULT) plane.ULT = plane.MAX_ULT;
                                }
                            }
                        }
                    }
                }
            }
        }


        //--small plane bullet hit second enemy
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL){
            for(k=0 ; k<MAX_SMALL_PLANE ; k++){
                for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                    for ( j=0 ; j<SECOND_ENEMY ;j++ ){
                        if(pnt_in_rect(small_bullets[k][i].x,small_bullets[k][i].y,second_enemies[j].x,second_enemies[j].y,second_enemies[j].w,second_enemies[j].h)
                           && !second_enemies[j].hidden && !small_bullets[k][i].hidden){
                            last_bullet_hit_enemy_timestamp = now;
                            //bullets[i].hidden = true;
                            small_bullets[k][i].x = -10000;//--recycle the bullet
                            second_enemies[j].HP -= small_bullets[k][i].HP;

                            //---if enemy dead
                            if( second_enemies[j].HP <= 0 ){
                                printf("%d hidden :%d \n",j,second_enemies[j].hidden);
                                second_enemies[j].hidden = true;
                                second_explode[j].hidden = false;
                                if(!ultimate) score += 400;
                                else score += 800;//--use ultimate kill enemy have higher score
                                //-- not in ultimate mode
                                if(!ultimate){
                                    if( plane.ULT < plane.MAX_ULT ) plane.ULT += 50;
                                    if( plane.ULT > plane.MAX_ULT) plane.ULT = plane.MAX_ULT;
                                }
                            }
                        }
                    }
                }
            }
        }


        //--if first enemy hit plane
        now = al_get_time();
        if( now - last_enemy_clash_plane_timestamp >= ENEMY_CLASH_PLANE_INTERVAL ){
           for( i=0 ; i<FIRST_ENEMY ;i++ ){
                if(rect_in_rect(plane.x,plane.y,plane.w,plane.h,first_enemies[i].x,first_enemies[i].y,first_enemies[i].w,first_enemies[i].h) && !first_enemies[i].hidden){
                    last_enemy_clash_plane_timestamp = now;

                    if(invincible) plane.HP -= 1;
                    else if(shield_appearance) plane.HP-=100;
                    else plane.HP-=200;


                    if(!invincible){
                        invincible = true;
                        last_invincible_time = al_get_time();
                    }
                }
           }
        }

        //--if second enemy hit plane
        now = al_get_time();
        if( now - last_enemy_clash_plane_timestamp >= ENEMY_CLASH_PLANE_INTERVAL ){
           for( i=0 ; i<SECOND_ENEMY ;i++ ){
                if(rect_in_rect(plane.x,plane.y,plane.w,plane.h,second_enemies[i].x,second_enemies[i].y,second_enemies[i].w,second_enemies[i].h) && !second_enemies[i].hidden){
                    last_enemy_clash_plane_timestamp = now;

                    if(invincible) plane.HP -= 1;
                    else if(shield_appearance) plane.HP-=100;
                    else plane.HP-=200;


                    if(!invincible){
                        //printf("second enemy crash\n");
                        invincible = true;
                        last_invincible_time = al_get_time();
                    }
                }
           }
        }

        //-- if all enemies are destroyed
        //printf("%d\n",enemy_clear);

        if( enemy_clear ){
            //judge_next_window = true;
            if( plane.HP < 0 ) plane.HP = 1;
            enemy_hidden = true;
            if(!draw_count){
                last_text_time = al_get_time();
                draw_count = true;
            }
        }
    }
    else if( window == SCENE_SECOND_GAME_BOSS ){

        //--
        if(start_to_boss && plane.y <= HEIGHT-200){
            start_to_boss = false;
        }
        //--change music when boss hp < maxhp/2 && HP restore
        if( boss1.HP < boss1.MAX_HP/2 && !chg_music ){
            chg_music = true;
            //--換bgm
            judge_next_window = true;
            //--give HP drink
            HP_drink.hidden = false;
            HP_drink.x = WIDTH/2-100;
            HP_drink.y = HEIGHT-100;
        }
        else if(plane.HP <=0){
            judge_next_window = true;
        }
        else if(boss1.HP <=0){
            //printf("boss1 dead");
            judge_next_window = true;
        }
        now = al_get_time();
        if(now - first_in_boss_scene_time >= BOSS_COOLDOWN){
            //--boss 1 shooting bullet
            now = al_get_time();
            if( now - last_boss1_shoot_bullet_timestamp >= BOSS1_BULLET_INTERVAL && !boss1.hidden
               && now - last_boss1_shoot_time >= BOSS1_BULLET_MAX_COOLDOWN ){
                last_boss1_shoot_bullet_timestamp = now;
                boss1_bullets[boss_bullet_count].y = boss1.y + boss1.h/2;

                //--bullet mode
                if(boss_bullet_mode == 0)
                    boss1_bullets[boss_bullet_count].x = boss1.x + boss1.w/2 -(boss1.w)*(float(boss_bullet_count)/(MAX_BOSS_ENEMY_BULLET-1));
                else if(boss_bullet_mode == 1)
                    boss1_bullets[boss_bullet_count].x = boss1.x - boss1.w/2 +(boss1.w)*(float(boss_bullet_count)/(MAX_BOSS_ENEMY_BULLET-1));
                else if(boss_bullet_mode == 2){
                    boss1_bullets[boss_bullet_count].x = boss1.x + sign*(boss1.w/2)*((float(boss_bullet_count/2))/(MAX_BOSS_ENEMY_BULLET/2));
                    sign *= -1;
                }

                boss1_bullets[boss_bullet_count].hidden = false;
                //printf("%d %f %f\n",boss_bullet_count,boss1_bullets[boss_bullet_count].x,boss1_bullets[boss_bullet_count].y);
                boss_bullet_count++;
                if(boss_bullet_count == MAX_BOSS_ENEMY_BULLET){
                    boss_bullet_count = 0;
                    last_boss1_shoot_time = now;
                    boss_bullet_mode = rand()%3;
                }
            }


            //--boss 1 //--boss 1 change from cooldown to warning
            now = al_get_time();
            if(now - last_boss1_mine_time >= BOSS1_MINE_COOLDOWN && warning_cooldown == 0){
                last_boss1_mine_time = now;
                last_boss1_warning_time = now;
                warning_cooldown = 1;
                //--reset
                hit_by_mine = false;
                if(chg_music){
                    for(i=0 ; i<MAX_MINE/2 ; i++){
                        mine_pos_y[i] = 100+i*150;
                    }
                    //--設定警告(地雷)位置
                    for(i=0 ; i<MAX_MINE ; i++){
                        //--暫時先隨機設
                        if(i < MAX_MINE/2)
                            boss1_mine[i].x = plane.x;
                        else
                            boss1_mine[i].x = WIDTH-plane.x;

                        boss1_mine[i].y = mine_pos_y[i%(MAX_MINE/2)];
                        boss1_mine[i].hidden = false;
                    }
                }
                else{
                    for(i=0 ; i<MAX_MINE/2 ; i++){
                        if(i == 0){
                            boss1_mine[i].x = plane.x;
                            boss1_mine[i].y = plane.y;
                        }
                        else{
                            boss1_mine[i].x = rand()%WIDTH;
                            boss1_mine[i].y = rand()%HEIGHT;
                        }
                        boss1_mine[i].hidden = false;
                    }
                }
            }

            //--boss 1 change from warning to mine
            now = al_get_time();
            if( now - last_boss1_warning_time >= BOSS1_WARNING_COOLDOWN && warning_cooldown == 1){
                //--undraw warning
                for(i=0 ; i<MAX_MINE ; i++){
                    boss1_mine[i].hidden = true;
                }
                //printf("/-------------/\n");
                warning_cooldown = 2;
            }

            //--plane encounter mine explode
            now = al_get_time();
            if(warning_cooldown == 2){
                //printf("%f %f %f %f\n",boss1_mine[0].x+boss1_mine[0].w/2,boss1_mine[0].y+boss1_mine[0].h/2,plane.x+plane.w/2,plane.y+plane.h/2);
                for(i=0 ; i<MAX_MINE ; i++){
                    if(pnt_in_rect(plane.x+plane.w/2,plane.y+plane.h/2,
                        boss1_mine[i].x+boss1_mine[i].w/2,boss1_mine[i].y+boss1_mine[i].h/2,boss1_mine[i].w,boss1_mine[i].h) && !hit_by_mine){
                        printf("got hit by mine : %d\n",i);

                        if(invincible) plane.HP -= 1;
                        else if(shield_appearance) plane.HP-=boss1_mine[i].HP/2;
                        else plane.HP-=boss1_mine[i].HP;

                        hit_by_mine = true;

                       if(!invincible){
                            invincible = true;
                            last_invincible_time = al_get_time();
                        }
                    }
                }
            }


            //-- boss 2 1 shooting laser
            now = al_get_time();
            if( now - last_boss2_shoot_laser_timestamp >= BOSS2_LASER_MAX_COOLDOWN ){
                if( !boss2[0].hidden &&  boss2[0].y >= HEIGHT/2+50){
                    //game_log("%d\n",boss_2[0].hidden);
                    last_boss2_shoot_laser_timestamp = now;
                    boss_2_1_stop = true;
                    if(chg_music){
                        for(i=0 ; i<MAX_BOSS_LASER ; i++){
                            int LASER_HEIGHT_CTRL = 20;
                            boss_laser[i].hidden = false;
                            boss_laser[i].y = boss2[0].y-boss2[0].h/2+LASER_HEIGHT_CTRL+(boss2[0].h-LASER_HEIGHT_CTRL*2)*i/2;
                            boss_laser[i].x = boss2[0].x + boss_laser[0].w/2;
                        }
                    }
                    else{
                        boss_laser[0].hidden = false;
                        boss_laser[0].y = boss2[0].y;
                        boss_laser[0].x = boss2[0].x + boss_laser[0].w/2;
                    }

                }
            }
            //-- laser lasting time
            now = al_get_time();
            if( now - last_boss2_shoot_laser_timestamp >= 1){
                for(i=0 ; i<MAX_BOSS_LASER ; i++){
                    boss_laser[i].hidden = true;
                }

                boss_2_1_stop = false;
            }

            //--boss 2 2 shooting bullet
            now = al_get_time();
            if( now - last_boss2_shoot_bullet_timestamp >= BOSS2_BULLET_MAX_COOLDOWN){
                if( !boss2[1].hidden &&  boss2[1].y >= HEIGHT/2+150){
                    for( i=0 ; i<MAX_FIRST_ENEMY_BULLET ; i++ ){
                        last_boss2_shoot_bullet_timestamp = now;
                        boss_2_2_stop = true;
                        boss2_bullets[i].hidden = false;
                        boss2_bullets[i].y = boss2[1].y;
                        boss2_bullets[i].x = boss2[1].x - boss2[1].w/2;
                        //break;
                    }
                }
            }

            //--boss 1 bullet hit plane
            now = al_get_time();
            if( now - last_boss1_bullet_hit_plane_timestamp >= BOSS_BULLET_HIT_PLANE_INTERVAL ){
                for ( i=0 ; i<MAX_BOSS_ENEMY_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                    if(pnt_in_rect(boss1_bullets[i].x,boss1_bullets[i].y,plane.x,plane.y,plane.w,plane.h) ){
                            last_boss1_bullet_hit_plane_timestamp = now;
                            //bullets[i].hidden = true;
                            boss1_bullets[i].x = -10000;//--bullet out of screen (recycle the bullet)

                            if(invincible) plane.HP -= 1;
                            else if(shield_appearance) plane.HP-=boss1_bullets[i].HP/2;
                            else plane.HP-=boss1_bullets[i].HP;

                            if(!invincible){
                                invincible = true;
                                last_invincible_time = al_get_time();
                            }
                    }
                }
            }

            //--boss 2 1 laser hit plane
            now = al_get_time();
            for(i=0 ; i<MAX_BOSS_LASER ; i++){
                if( now - last_laser_hit_plane_timestamp >= BOSSLASER_HIT_PLANE_INTERVAL && !boss_laser[i].hidden){
                    //game_log("*");for ( i=0 ; i<MAX_ENEMY ;i++ ){
                    if( determine_laser_hit_enemy( plane.y,plane.h ,boss_laser[i].y ,boss_laser[i].h) ){
                        last_laser_hit_plane_timestamp = now;

                        if(invincible) plane.HP -= 1;
                        else if(shield_appearance) plane.HP-=boss_laser[i].HP/2;
                        else plane.HP-=boss_laser[i].HP;

                        if(!invincible){
                            invincible = true;
                            last_invincible_time = al_get_time();
                        }
                    }
                }
            }

            //--boss 2 2 bullet hit plane
            now = al_get_time();
            if( now - last_boss2_bullet_hit_plane_timestamp >= BOSS_BULLET_HIT_PLANE_INTERVAL ){
                for ( i=0 ; i<MAX_FIRST_ENEMY_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                    if( pnt_in_rect(boss2_bullets[i].x,boss2_bullets[i].y,plane.x,plane.y,plane.w,plane.h) ){
                            last_boss2_bullet_hit_plane_timestamp = now;
                            //bullets[i].hidden = true;
                            boss2_bullets[i].x = -100;//--bullet out of screen (recycle the bullet)

                            if(invincible) plane.HP -= 1;
                            else if(shield_appearance) plane.HP -= boss2_bullets[i].HP/2;
                            else plane.HP-=boss2_bullets[i].HP;

                            if(!invincible){
                                invincible = true;
                                last_invincible_time = al_get_time();
                            }
                    }
                }
            }
        }

        //--plane bullets hit boss 1
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && !laser_appearance ){
            for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                if(pnt_in_rect(bullets[i].x , bullets[i].y , boss1.x , boss1.y , boss1.w , boss1.h ) &&  !boss1.hidden){
                    //--two boss2 still alive
                    printf("in bullet\n");
                    last_bullet_hit_enemy_timestamp = now;
                    if(!boss2[0].hidden || !boss2[1].hidden ){
                        //bullets[i].hidden = true;
                        bullets[i].x = -100;//--recycle the bullet
                        boss1.HP -= 1;

                    }
                    else{//--2 boss2 are dead
                        bullets[i].x = -100;//--recycle the bullet
                        if(laser_appearance){
                            boss1.HP -= 2*laser.HP;
                        }
                        else{
                            boss1.HP -= 2*bullets[0].HP;
                        }
                    }
                        //---if enemy dead
                        if( boss1.HP <= 0){
                            boss1.hidden = true;
                            //explode[2].hidden = false;
                            if(!ultimate) score += 2000;
                            else score += 4000;//--use ultimate kill enemy have higher score
                        }
                }
            }
        }

        //--plane bullets hit boss 2
        now = al_get_time();
        //int j;
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && !laser_appearance ){
            for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                for( j=0 ; j<MAX_BOSS_2 ; j++ ){
                    if(pnt_in_rect(bullets[i].x,bullets[i].y,boss2[j].x,boss2[j].y,boss2[j].w,boss2[j].h) && !boss2[j].hidden){
                        last_bullet_hit_enemy_timestamp = now;
                        //bullets[i].hidden = true;
                        bullets[i].x = -100;//--recycle the bullet
                        boss2[j].HP -= bullets[i].HP;

                        //---if enemy dead
                        if( boss2[j].HP <= 0){
                            boss2[j].hidden = true;
                            printf("in boss2 dead\n");
                            boss_explode[j].hidden = false;
                            if(!ultimate) score += 1000;
                            else score += 2000;//--use ultimate kill enemy have higher score

                            if(!ultimate){
                                if( plane.ULT < plane.MAX_ULT ) plane.ULT =plane.MAX_ULT;
                            }
                        }
                    }
                }
            }
        }

        //--plane laser hit boss 1

        if( determine_laser_hit_enemy( laser.x,laser.w,boss1.x,boss1.w ) && !boss1.hidden
               && !laser.hidden && (img_laser_count == 2 || img_laser_count == 3 || img_laser_count == 4 )){
            now = al_get_time();
            if( now - last_bullet_hit_enemy_timestamp >= 0.3f && laser_appearance){
                last_bullet_hit_enemy_timestamp = now;
                printf("in laser\n");
                if(!boss2[0].hidden || !boss2[1].hidden ){
                    boss1.HP -= 1;
                }
                else{
                    boss1.HP -= 2*laser.HP;
                }
                    //game_log("**");

                //---if enemy dead
                if( boss1.HP <= 0){
                    boss1.hidden = true;
                    //explode[2].hidden = false;
                    score+=4000;
                }
            }
        }

        //--plane laser hit boss 2
        //printf("%d %d %d %d\n",determine_laser_hit_enemy( laser.x,laser.w,boss2[0].x,boss2[0].w ),!boss2[0].hidden,!laser.hidden,img_laser_count);
        for ( i=0 ; i<MAX_BOSS_2 ; i++){
            if( determine_laser_hit_enemy( laser.x,laser.w,boss2[i].x,boss2[i].w ) && !boss2[i].hidden
                && !laser.hidden && (img_laser_count == 2 || img_laser_count == 3 || img_laser_count == 4 )){
                now = al_get_time();
                //printf("in %lf %d\n",now - last_bullet_hit_enemy_timestamp,laser_appearance);
                if(now - last_bullet_hit_enemy_timestamp >= 0.25f && laser_appearance){
                    last_bullet_hit_enemy_timestamp = now;
                    //printf("*");
                    boss2[i].HP -= laser.HP;
                    //game_log("**");

                    //---if enemy dead
                    if( boss2[i].HP <= 0){
                        boss2[i].hidden = true;
                        printf("in boss2 dead\n");
                        boss_explode[i].hidden = false;
                        score+=2000;
                    }
                }
            }
        }

        //--small plane bullet hit boss 1
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && !laser_appearance ){
            for(j=0 ; j<MAX_SMALL_PLANE ; j++){
                for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                    if(pnt_in_rect(small_bullets[j][i].x , small_bullets[j][i].y , boss1.x , boss1.y , boss1.w , boss1.h ) &&  !boss1.hidden){
                        //--two boss2 still alive
                        //printf("in bullet\n");
                        last_bullet_hit_enemy_timestamp = now;
                        if(!boss2[0].hidden || !boss2[1].hidden ){
                            //bullets[i].hidden = true;
                            small_bullets[j][i].x = -100;//--recycle the bullet
                            boss1.HP -= 1;

                        }
                        else{//--2 boss2 are dead
                            small_bullets[j][i].x = -100;//--recycle the bullet
                            if(laser_appearance){
                                boss1.HP -= 2*laser.HP;
                            }
                            else{
                                boss1.HP -= 2*bullets[0].HP;
                            }
                        }
                            //---if enemy dead
                            if( boss1.HP <= 0){
                                boss1.hidden = true;
                                //explode[2].hidden = false;
                                if(!ultimate) score += 2000;
                                else score += 4000;//--use ultimate kill enemy have higher score
                            }
                    }
                }
            }
        }

        //--small plane bullet hit boss 2
        now = al_get_time();
        if( now - last_bullet_hit_enemy_timestamp >= BULLET_HIT_ENEMY_INTERVAL && !laser_appearance ){
            for(k=0 ; k<MAX_SMALL_PLANE ; k++){
                for ( i=0 ; i<MAX_BULLET ;i++ ) {//--if bullets hit enemies, enemies hidden = true
                    for( j=0 ; j<MAX_BOSS_2 ; j++ ){
                        if(pnt_in_rect(small_bullets[k][i].x,small_bullets[k][i].y,boss2[j].x,boss2[j].y,boss2[j].w,boss2[j].h) && !boss2[j].hidden){
                            last_bullet_hit_enemy_timestamp = now;
                            //bullets[i].hidden = true;
                            small_bullets[k][i].x = -100;//--recycle the bullet
                            boss2[j].HP -= small_bullets[k][i].HP;

                            //---if enemy dead
                            if( boss2[j].HP <= 0){
                                boss2[j].hidden = true;
                                printf("in boss2 dead\n");
                                boss_explode[j].hidden = false;
                                if(!ultimate) score += 1000;
                                else score += 2000;//--use ultimate kill enemy have higher score

                                if(!ultimate){
                                    if( plane.ULT < plane.MAX_ULT ) plane.ULT =plane.MAX_ULT;
                                }
                            }
                        }
                    }
                }
            }
        }

        //--boss2 clash plane
        now = al_get_time();
        if( now - last_boss2_clash_plane_timestamp >= ENEMY_CLASH_PLANE_INTERVAL ){
           for( i=0 ; i<MAX_BOSS_2 ;i++ ){
                if(rect_in_rect(plane.x,plane.y,plane.w,plane.h,boss2[i].x,boss2[i].y,boss2[i].w,boss2[i].h) && !boss2[i].hidden){
                    last_boss2_clash_plane_timestamp = now;

                    if(invincible) plane.HP -= 1;
                    else if(shield_appearance) plane.HP -= 100;
                    else plane.HP -= 200;

                    if(!invincible){
                        invincible = true;
                        last_invincible_time = al_get_time();
                    }
                }
           }
        }

        //--boss1 hit plane
        now = al_get_time();
        if( now - last_boss1_clash_plane_timestamp >= ENEMY_CLASH_PLANE_INTERVAL ){
            if(rect_in_rect(plane.x,plane.y,plane.w,plane.h,boss1.x,boss1.y,boss1.w,boss1.h) && !boss1.hidden){
                last_boss1_clash_plane_timestamp = now;

                if(invincible) plane.HP -= 1;
                else if(shield_appearance) plane.HP-=250;
                else plane.HP-=500;

                if(!invincible){
                    invincible = true;
                    last_invincible_time = al_get_time();
                }
            }
        }

        //--boss2 alive
        static int buf = 3;
        if(boss1.HP <= buf*boss1.MAX_HP/4){
            for( i=0 ; i<MAX_BOSS_2 ; i++ ){
                if( i == 0 ) boss2[i].x = 100;//--left
                else if(i == 1) boss2[i].x = WIDTH - 100;//--right
                boss2[i].y = HEIGHT/2-200;
                boss2[i].hidden = false;
                boss2[i].HP = boss2[i].MAX_HP;
            }
            buf--;
        }

        //--boss 1 launch ultimate
        now = al_get_time();
        if( now - last_boss1_launch_ultimate_timestamp >= BOSS1_LAUNCH_ULTIMATE_INTERVAL ){
            if(!boss1.hidden && chg_music){
                //game_log("%d\n",boss_2[0].hidden);
                printf("in boss1 launch\n");
                last_boss1_launch_ultimate_timestamp = now;

                boss1_ultimate.hidden = false;
                boss1_ultimate.y = boss1.y+boss1.h/2;
                boss1_ultimate.x = boss1.x;
                boss1_ultimate.vx = 0;//--重設
                boss1_ultimate.vy = 0;
            }
        }

        //--boss 1 集氣發射
        now = al_get_time();
        if(!boss1_ultimate.hidden && now - last_boss1_launch_ultimate_timestamp >= 2.0f){
            int CTRL_ULTIMATE_TIME = 100.f;
            boss1_ultimate.vx = (plane.x-boss1.x)/CTRL_ULTIMATE_TIME;
            boss1_ultimate.vy = (plane.y-boss1.y)/CTRL_ULTIMATE_TIME;
            //printf("%f %f\n",boss1_ultimate.vx,boss1_ultimate.vy);
        }

        //--boss 1  ultimate hit plane
        now = al_get_time();
        if( now - last_boss2_bullet_hit_plane_timestamp >= BOSS_BULLET_HIT_PLANE_INTERVAL ){
            if( rect_in_rect(plane.x,plane.y,plane.w,plane.h,boss1_ultimate.x,boss1_ultimate.y,boss1_ultimate.w,boss1_ultimate.h) ){
                    last_boss2_bullet_hit_plane_timestamp = now;
                    boss1_ultimate.x = -100;//--bullet out of screen (recycle the bullet)

                    if(invincible) plane.HP -= 1;
                    //else if(shield_appearance) plane.HP-=boss1_ultimate.HP/2;
                    else plane.HP-=boss1_ultimate.HP;

                    if(!invincible){
                        invincible = true;
                        last_invincible_time = al_get_time();
                    }
            }

        }

    }
    else if(window == SCENE_SECOND_GAME_RESTART){
        //printf("in restart\n");
        if (mouse_state[1]) {
            //printf("%d %d\n",mouse_x,mouse_y);
            if (pnt_in_rect(mouse_x, mouse_y, WIDTH/2,HEIGHT/2+175,100,50)){
                printf("true %d %d\n",mouse_x,mouse_y);
                judge_next_window = true;
                restart = true;
            } else if(pnt_in_rect( mouse_x, mouse_y, WIDTH/2, HEIGHT/ 2+250,100,50)){
                printf("false %d %d\n",mouse_x,mouse_y);
                judge_next_window = true;
                restart = false;
            }

        }
    }
}

void second_game_scene_draw(){
    if(window == SCENE_SECOND_GAME_START){
        //move background
        al_draw_bitmap(start_img_background  , 0, background_position, 0);
        al_draw_bitmap(start_img_background_2, 0, background_position - HEIGHT, 0);
        al_draw_bitmap(start_img_background  , 0, background_position -2*HEIGHT, 0);
        background_position += background_velocity;

        if( background_position >= 2*HEIGHT ) {
          background_position = 0;
        }
        second_game_character_draw();

        if(enemy_clear){
            al_draw_text( font_60, al_map_rgb(0, 255, 0) , WIDTH/2 ,HEIGHT/2 ,ALLEGRO_ALIGN_CENTER,"C L E A R");
        }
    }
    else if(window == SCENE_SECOND_GAME_BOSS){
        al_draw_bitmap(boss_img_background  , 0, background_position, 0);
        al_draw_bitmap(boss_img_background_2, 0, background_position - HEIGHT, 0);
        al_draw_bitmap(boss_img_background  , 0, background_position -2*HEIGHT, 0);
        background_position += background_velocity;

        if( background_position >= 2*HEIGHT ) {
          background_position = 0;
        }
        second_game_character_draw();
    }
    else if(window == SCENE_SECOND_GAME_GAMEOVER){
        al_draw_bitmap(gameover_img_background, 0, 0, 0);
        al_flip_display();
        al_rest(2);
        judge_next_window = true;
    }
    else if(window == SCENE_SECOND_GAME_RESTART){
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(font_36,al_map_rgb(255, 255, 255),WIDTH / 2,HEIGHT / 2-100,ALLEGRO_ALIGN_CENTER,"Your final score is :");
        al_draw_textf(font_36,al_map_rgb(255, 255, 255),WIDTH/2,HEIGHT / 2,ALLEGRO_ALIGN_CENTER,"%d",score);
        al_draw_text(font_36,al_map_rgb(255, 255, 255),WIDTH / 2,HEIGHT / 2+100,ALLEGRO_ALIGN_CENTER,"Do you want to restart");
        al_draw_text(font_36,al_map_rgb(255, 255, 255),WIDTH / 2,HEIGHT / 2+175,ALLEGRO_ALIGN_CENTER,"YES");
        al_draw_text(font_36,al_map_rgb(255, 255, 255),WIDTH / 2,HEIGHT / 2+250,ALLEGRO_ALIGN_CENTER,"NO");
    }
    else if(window == SCENE_SECOND_GAME_VICTORY){
        al_draw_bitmap(victory_img_background, 0, 0, 0);
        //al_flip_display();
        //al_rest(6);
    }
}


void second_game_scene_audio(){

    if(window == SCENE_SECOND_GAME_START){
        if (!al_play_sample(start_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &start_bgm_id)){
            game_abort("failed to play second game start bgm");
        }
    }
    else if(window == SCENE_SECOND_GAME_BOSS && !chg_music){
        if (!al_play_sample(boss_bgm_1, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &boss_bgm_id_1)){
            game_abort("failed to play second game boss bgm 1");
        }
    }
    else if(window == SCENE_SECOND_GAME_BOSS && chg_music){
        if (!al_play_sample(boss_bgm_2, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &boss_bgm_id_2)){
            game_abort("failed to play second game boss bgm 2");
        }
    }
    else if(window == SCENE_SECOND_GAME_GAMEOVER){
        if (!al_play_sample(gameover_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &gameover_bgm_id)){
            game_abort("failed to play second game gameover bgm");
        }
    }
    else if(window == SCENE_SECOND_GAME_VICTORY){
        if (!al_play_sample(victory_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &victory_bgm_id)){
            game_abort("failed to play second game victory bgm");
        }
    }
}

void second_game_scene_stop_audio(){

    if(window == SCENE_SECOND_GAME_START){
        al_stop_sample(&start_bgm_id);
        game_log("stop second game start bgm");
    }
    else if(window == SCENE_SECOND_GAME_BOSS){
        al_stop_samples();
    }
    else if(window == SCENE_SECOND_GAME_RESTART){
        al_stop_sample(&gameover_bgm_id);
        game_log("stop second game gameover bgm");
    }
    else if(window == SCENE_SECOND_GAME_VICTORY){
        al_stop_sample(&victory_bgm_id);
        game_log("stop second game victory bgm");
    }
}

void second_game_scene_destroy(){
    al_destroy_bitmap(start_img_background);
	al_destroy_bitmap(start_img_background_2);
	al_destroy_bitmap(gameover_img_background);
    al_destroy_bitmap(boss_img_background);
	al_destroy_bitmap(boss_img_background_2);
    al_destroy_bitmap(victory_img_background);

	al_destroy_sample(start_bgm);
	al_destroy_sample(gameover_bgm);
	al_destroy_sample(boss_bgm_1);
    al_destroy_sample(boss_bgm_2);
    al_destroy_sample(victory_bgm);
}

//--load bitmap resize
ALLEGRO_BITMAP *load_bitmap_resized(const char *filename, int w, int h) {
	ALLEGRO_BITMAP* loaded_bmp = al_load_bitmap(filename);
	if (!loaded_bmp)
		game_abort("failed to load image: %s", filename);
	ALLEGRO_BITMAP *resized_bmp = al_create_bitmap(w, h);
	ALLEGRO_BITMAP *prev_target = al_get_target_bitmap();

	if (!resized_bmp)
		game_abort("failed to create bitmap when creating resized image: %s", filename);
	al_set_target_bitmap(resized_bmp);
	al_draw_scaled_bitmap(loaded_bmp, 0, 0,
		al_get_bitmap_width(loaded_bmp),
		al_get_bitmap_height(loaded_bmp),
		0, 0, w, h, 0);
	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp);

	game_log("resized image: %s", filename);
	return resized_bmp;
}

