#include "charater.h"

ALLEGRO_BITMAP* img_bathroom_tube[IMAGE_BATHROOM_TUBE];
ALLEGRO_BITMAP* img_underground_tube[IMAGE_UNDERGROUND_TUBE];

//---------second  game---------//
ALLEGRO_BITMAP* start_img_plane_1;
ALLEGRO_BITMAP* start_img_plane_2;
ALLEGRO_BITMAP* start_img_plane_3;
ALLEGRO_BITMAP* start_img_plane_3_ult;
ALLEGRO_BITMAP* start_img_plane_small;
ALLEGRO_BITMAP* start_img_plane_small_ult;

ALLEGRO_BITMAP* start_img_enemy_1;
ALLEGRO_BITMAP* start_img_enemy_2;
ALLEGRO_BITMAP* start_img_enemy_3;

ALLEGRO_BITMAP* img_boss_1;
ALLEGRO_BITMAP* img_boss_2;


//--all scene
ALLEGRO_BITMAP* img_explode[IMAGE_EXPLODE];
ALLEGRO_BITMAP* img_warning;
ALLEGRO_BITMAP* img_mine[IMAGE_MINE];
ALLEGRO_BITMAP* img_ultimate_1;
ALLEGRO_BITMAP* img_ultimate_2;
ALLEGRO_BITMAP* img_fire_push[IMAGE_FIRE_PUSH];
ALLEGRO_BITMAP* img_laser[IMAGE_LASER];
ALLEGRO_BITMAP* img_electric[IMAGE_ELECTRIC];
ALLEGRO_BITMAP* img_shield[IMAGE_SHIELD];
ALLEGRO_BITMAP* img_track_bullet;
ALLEGRO_BITMAP* img_HP_drink;
ALLEGRO_BITMAP* img_ULT_drink;
ALLEGRO_BITMAP* img_bullet_1;

ALLEGRO_BITMAP* img_bullet_2;
ALLEGRO_BITMAP* img_bullet_3;

ALLEGRO_BITMAP* img_HP_ULT;

ALGIF_ANIMATION* gif_shield;

//--start scene
ALLEGRO_BITMAP* img_first_enemy_bullet;
ALLEGRO_BITMAP* img_second_enemy_bullet;


//--boss scene
ALLEGRO_BITMAP* img_boss2_laser;
ALLEGRO_BITMAP* img_enemy_bullet_2;
ALLEGRO_BITMAP* img_boss1_bullet;
ALLEGRO_BITMAP* img_boss1_ultimate[IMAGE_BOSS1_ULTIMATE];

void character_init(){

    // load main character images
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/main_char_move%d.png", i );
        main_chara.img_move[i-1] = al_load_bitmap(temp);
        if (!main_chara.img_move[i-1])
            game_abort("failed to load image: main_char_move.png");

    }
    for(int i = 1 ; i <= 1 ; i++){
        char temp[50];
        sprintf( temp, "./image/main_char1.png");
        main_chara.img_dir[i-1] = al_load_bitmap(temp);
        if (!main_chara.img_dir[i-1])
            game_abort("failed to load image: main_char_dir.png");
    }
    //--sit
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/main_char_sit%d.png",i);
        main_chara.img_sit[i-1] = al_load_bitmap(temp);
        if (!main_chara.img_sit[i-1])
            game_abort("failed to load image: main_char_sit.png");
    }
    //--in tube out tube
    for(int i = 1 ; i <= IMAGE_BATHROOM_TUBE ; i++){
        char temp[50];
        sprintf( temp, "./image/main_char1_%d.png", i );
        img_bathroom_tube[i-1] = al_load_bitmap(temp);
        if (!img_bathroom_tube[i-1])
            game_abort("failed to load image: img_bathroom_tube.png");
    }

    for(int i = 1 ; i <= IMAGE_UNDERGROUND_TUBE ; i++){
        char temp[50];
        sprintf( temp, "./image/main_char_rev%d.png", i );
        img_underground_tube[i-1] = al_load_bitmap(temp);
        if (!img_underground_tube[i-1])
            game_abort("failed to load image: img_underground_tube.png");
    }

    //--set take chicken bitmap
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/main_char_take_chicken_move%d.png", i );
        main_chara.img_take_chicken_move[i-1] = al_load_bitmap(temp);
        if (!main_chara.img_take_chicken_move[i-1])
            game_abort("failed to load image: main_char_take_chicken_move.png");

    }
    for(int i = 1 ; i <= 1 ; i++){
        char temp[50];
        sprintf( temp, "./image/main_char_take_chicken_dir.png");
        main_chara.img_take_chicken_dir[i-1] = al_load_bitmap(temp);
        if (!main_chara.img_take_chicken_dir[i-1])
            game_abort("failed to load image: main_char_take_chicken_dir.png");
    }

    //--set main char get UFO back bitmap
    main_chara.img_UFO = al_load_bitmap("./image/plane_model.png");

    //--set guard bitmap
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/guard_atk%d.png", i );
        guard.img_atk[i-1] = al_load_bitmap(temp);
        if (!guard.img_atk[i-1])
            game_abort("failed to load image: guard.img_atk.png");

    }
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/guard_move%d.png",i);
        guard.img_move[i-1] = al_load_bitmap(temp);
        if (!guard.img_move[i-1])
            game_abort("failed to load image: guard_move.png");
    }

    // initial the geometric information of character
    main_chara.w = al_get_bitmap_width(main_chara.img_move[0]);
    main_chara.h = al_get_bitmap_height(main_chara.img_move[0]);
    main_chara.x = 0;
    //main_chara.y = HEIGHT-main_chara.h;
    main_chara.y = -750;
    main_chara.dir = true;

    // initial the animation component
    main_chara.state = STOP;
    main_chara.anime = 0;
    main_chara.anime_time = 30;

    guard.x = -300;
    guard.y = HEIGHT/2;

}

void charater_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            main_chara.anime++;
            main_chara.anime %= main_chara.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        //game_log("key event down");
        main_chara.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        //game_log("key event up");
        key_state[event.keyboard.keycode] = false;
    //--process the mouse event
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        // Event for mouse key down.
        game_log("Mouse button %d down at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_state[event.mouse.button] = true;
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        // Event for mouse key up.
        //game_log("Mouse button %d up at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_state[event.mouse.button] = false;
    }

}

void charater_update(){
    // use the idea of finite state machine to deal with different state
    if(hide_char);
    else if(start_ani){
        if(main_chara.y + main_chara.h < HEIGHT){
            main_chara.y += 5;
            main_chara.state = STOP;
            //--一直更新
            last_change_head_time = now;
        }
        else{
            //printf("in sit count\n");
            sit_count = true;
        }
    }
    else if(sec_start_ani_down){
        main_chara.y += 3;
        main_chara.state = STOP;
    }
    else if(sec_start_ani_up){
        main_chara.y -= 5;
        main_chara.state = STOP;
    }
    //--進出水管
    else if( go_into_tube || go_out_tube);//--如果進出水管就不動
    else if( key_state[ALLEGRO_KEY_UP] || key_state[ALLEGRO_KEY_W]){
        if( main_chara.y >= HEIGHT/2 - first_game_bg[window].h/2 || special_case ){
            main_chara.y -= 5;
            main_chara.state = MOVE;
        }
        else{
            main_chara.state = STOP;
        }
    }else if( key_state[ALLEGRO_KEY_LEFT] || key_state[ALLEGRO_KEY_A] ){
        //game_log("key state left");
        if(main_chara.x >= WIDTH/2 - first_game_bg[window].w/2 || special_case){
            main_chara.dir = false;
            main_chara.x -= 5;
            main_chara.state = MOVE;
        }
        else{
            main_chara.state = STOP;
        }
    }else if( key_state[ALLEGRO_KEY_DOWN] || key_state[ALLEGRO_KEY_S] ){
        if(main_chara.y + main_chara.h <= HEIGHT/2 + first_game_bg[window].h/2 || special_case){
            main_chara.y += 5;
            main_chara.state = MOVE;
        }
        else{
            main_chara.state = STOP;
        }
    }else if( key_state[ALLEGRO_KEY_RIGHT] || key_state[ALLEGRO_KEY_D] ){
        if(main_chara.x + main_chara.w <= WIDTH/2 + first_game_bg[window].w/2 || special_case){
            main_chara.dir = true;
            main_chara.x += 5;
            main_chara.state = MOVE;
        }
        else{
            main_chara.state = STOP;
        }
    }else if( main_chara.anime == main_chara.anime_time-1 ){
        main_chara.anime = 0;
        main_chara.state = STOP;
    }else if ( main_chara.anime == 0 ){
        main_chara.state = STOP;
    }

    if(window == SCENE_FIRST_GAME_UNDERGROUND){
        //printf("in atk1 %d in atk2 %d\n",in_atk_1,in_atk_2);
        now = al_get_time();
        if(now - last_guard_atk_time_1 >= GUARD_ATK_COOLDOWN && !in_atk_1 && !in_atk_2){
            in_atk_1 = true;
            last_guard_atk_time_2 = now;
        }
        else if(now - last_guard_atk_time_2 >= GUARD_ATK_CONT_COOLDOWN && in_atk_1 && !in_atk_2){
            in_atk_1 = false;
            in_atk_2 = true;
            last_guard_stop_time = now;
        }
        else if(now - last_guard_stop_time >= GUARD_ATK_CONT_COOLDOWN && !in_atk_1 && in_atk_2){
            in_atk_2 = false;
            last_guard_atk_time_1 = now;
        }
    }

}

void character_draw(){
    // with the state, draw corresponding image
    //--下水管
    //--main chara
    if(sit_count){
        now = al_get_time();
        if( now - last_change_head_time >= CHANGE_HEAD_COOLDOWN){
            change_head = (!change_head);
            last_change_head_time = now;
        }
        if(change_head) al_draw_bitmap(main_chara.img_sit[1], main_chara.x, main_chara.y,0);
        else al_draw_bitmap(main_chara.img_sit[0], main_chara.x, main_chara.y,0);
    }
    else if(sec_start_ani_down || sec_start_ani_up ){
        al_draw_bitmap(main_chara.img_UFO, main_chara.x-85, main_chara.y,0);
    }
    else if(go_into_tube){
        //printf("in go into tube\n");
        if(window == SCENE_FIRST_GAME_BATHROOM) character_bathroom_go_down_in_tube();
        else if(window == SCENE_FIRST_GAME_UNDERGROUND) character_underground_go_down_in_tube();
    }

    else if(go_out_tube){
        if(window == SCENE_FIRST_GAME_BATHROOM) character_bathroom_go_up_in_tube();
        else if(window == SCENE_FIRST_GAME_UNDERGROUND) character_underground_go_up_in_tube();
    }

    else if( main_chara.state == STOP ){
        if( main_chara.dir ){
            if(take_chicken) al_draw_bitmap(main_chara.img_take_chicken_dir[0], main_chara.x, main_chara.y,0);
            else al_draw_bitmap(main_chara.img_dir[0], main_chara.x, main_chara.y, 0);
        }
        else{
            if(take_chicken) al_draw_bitmap(main_chara.img_take_chicken_dir[0], main_chara.x, main_chara.y,ALLEGRO_FLIP_HORIZONTAL);
            else al_draw_bitmap(main_chara.img_dir[0], main_chara.x, main_chara.y, ALLEGRO_FLIP_HORIZONTAL);
        }
    }else if( main_chara.state == MOVE ){
        now = al_get_time();
        if( now - last_change_foot_time >= WALK_CHANGE_FOOT_COOLDOWN){
            change_step = (!change_step);
            last_change_foot_time = now;
        }

        if( main_chara.dir ){
            if(change_step){
                if(take_chicken) al_draw_bitmap(main_chara.img_take_chicken_move[0], main_chara.x, main_chara.y, 0);
                else al_draw_bitmap(main_chara.img_move[0], main_chara.x, main_chara.y, 0);
            }
            else{
                if(take_chicken) al_draw_bitmap(main_chara.img_take_chicken_move[1], main_chara.x, main_chara.y, 0);
                else al_draw_bitmap(main_chara.img_move[1], main_chara.x, main_chara.y, 0);
            }
        }else{
            if(change_step){
                if(take_chicken) al_draw_bitmap(main_chara.img_take_chicken_move[0], main_chara.x, main_chara.y, ALLEGRO_FLIP_HORIZONTAL);
                else al_draw_bitmap(main_chara.img_move[0], main_chara.x, main_chara.y, ALLEGRO_FLIP_HORIZONTAL);
            }
            else{
                if(take_chicken) al_draw_bitmap(main_chara.img_take_chicken_move[1], main_chara.x, main_chara.y, ALLEGRO_FLIP_HORIZONTAL);
                else al_draw_bitmap(main_chara.img_move[1], main_chara.x, main_chara.y, ALLEGRO_FLIP_HORIZONTAL);
            }
        }
    }

    //--guard
    if(window == SCENE_FIRST_GAME_UNDERGROUND){
        if(in_atk_2){
            //printf("in guard atk2\n");
            al_draw_bitmap(guard.img_atk[1],guard.x,guard.y,0);
        }
        else if(in_atk_1){
            //printf("in guard atk1\n");
            al_draw_bitmap(guard.img_atk[0],guard.x,guard.y,0);
        }
        else {
            //printf("in guard else\n");
            al_draw_bitmap(guard.img_move[0],guard.x,guard.y,0);
        }

    }

}

void character_change_state(int dir){
    if(dir == 0){//--left-->right
        main_chara.x = WIDTH+100;
        //main_chara.y = HEIGHT-300;
    }
    else if(dir == 1){//--right-->left
        main_chara.x = -100;
        //main_chara.y = HEIGHT-300;
    }
    else if(dir == 2){//--intro -> first game scene
        main_chara.x = WIDTH/2;
        main_chara.y = HEIGHT+200;
    }
    else if(dir == 3){//--first game scene --> intro
        main_chara.x = 1100;
        main_chara.y = HEIGHT - main_chara.h-100;
    }
    else if(dir == 4){//--bathroom --> underground
        main_chara.x = WIDTH/2-100;
        main_chara.y = 160;
    }
    else if(dir == 5){//-- underground --> bathroom
        main_chara.x = 385;
        main_chara.y = 65;
    }
}

void character_destory(){
    al_destroy_bitmap(main_chara.img_dir[0]);
    al_destroy_bitmap(main_chara.img_dir[1]);
    al_destroy_bitmap(main_chara.img_move[0]);
    al_destroy_bitmap(main_chara.img_move[1]);
}


void character_bathroom_go_down_in_tube(){
    now = al_get_time();
    if(!main_chara.dir){
        down_flag = ALLEGRO_FLIP_HORIZONTAL;
    }
    else{
        down_flag = 0;
    }
    if(now - img_in_tube_last_time >= 0.1f){
        img_in_tube_last_time  = now;
        img_bathroom_tube_count++;
        printf("%d ",img_bathroom_tube_count);
    }
    al_draw_bitmap(img_bathroom_tube[img_bathroom_tube_count],385,65+img_bathroom_tube_count*7,down_flag);

    if(img_bathroom_tube_count == IMAGE_BATHROOM_TUBE-1){
        img_bathroom_tube_count++;
        //go_into_tube = false;
        in_tube = true;
    }

}

void character_bathroom_go_up_in_tube(){
    if(!main_chara.dir){
        down_flag = ALLEGRO_FLIP_HORIZONTAL;
    }
    else{
        down_flag = 0;
    }
    if(img_bathroom_tube_count == -1 || img_bathroom_tube_count == IMAGE_BATHROOM_TUBE){
        img_bathroom_tube_count = IMAGE_BATHROOM_TUBE-1;
    }
    now = al_get_time();
    if(now - img_in_tube_last_time >= 0.1f){
        img_in_tube_last_time  = now;
        img_bathroom_tube_count--;
        printf("%d ",img_bathroom_tube_count);
    }

    al_draw_bitmap(img_bathroom_tube[img_bathroom_tube_count],385,65+img_bathroom_tube_count*7,down_flag);

    if(img_bathroom_tube_count == 0){
        img_bathroom_tube_count--;
        go_out_tube = false;
    }
    //printf("up end\n");

}

void character_underground_go_down_in_tube(){
    if(!main_chara.dir){
        down_flag = ALLEGRO_FLIP_HORIZONTAL;
    }
    else{
        down_flag = 0;
    }
    if(img_underground_tube_count == -1 || img_underground_tube_count == IMAGE_UNDERGROUND_TUBE){
        img_underground_tube_count = IMAGE_UNDERGROUND_TUBE-1;
    }
    now = al_get_time();
    if(now - img_in_tube_last_time >= 0.1f){
        img_in_tube_last_time  = now;
        img_underground_tube_count--;
        printf("%d ",img_underground_tube_count);
    }

    al_draw_bitmap(img_underground_tube[img_underground_tube_count],WIDTH/2-100,200,down_flag);

    if(img_underground_tube_count == 0){
        img_underground_tube_count--;
        //go_out_tube = false;
        //in_tube = false;
        go_into_tube = false;
    }
    //printf("up end\n");

}

void character_underground_go_up_in_tube(){
    now = al_get_time();
    if(!main_chara.dir){
        down_flag = ALLEGRO_FLIP_HORIZONTAL;
    }
    else{
        down_flag = 0;
    }
    if(now - img_in_tube_last_time >= 0.1f){
        img_in_tube_last_time  = now;
        img_underground_tube_count++;
        printf("%d ",img_underground_tube_count);
    }
    al_draw_bitmap(img_underground_tube[img_underground_tube_count],WIDTH/2-100,200,down_flag);

    if(img_underground_tube_count == IMAGE_UNDERGROUND_TUBE-1){
        img_underground_tube_count++;
        in_tube = false;
    }

}


//---------second  game---------//


void second_game_character_process(ALLEGRO_EVENT event){
    // process the animation
    if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        //game_log("key event down");
        main_chara.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        //game_log("key event up");
        key_state[event.keyboard.keycode] = false;
    // process the mouse event
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        // Event for mouse key down.
        game_log("Mouse button %d down at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_state[event.mouse.button] = true;
    }else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        // Event for mouse key up.
        //game_log("Mouse button %d up at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
        mouse_state[event.mouse.button] = false;
    }


}


void second_game_character_init(){

    start_img_plane_1 = al_load_bitmap("./image/plane_1.png");
	if (!start_img_plane_1)
		game_abort("failed to load image: plane_1.png");

    start_img_plane_2 = al_load_bitmap("./image/plane_2.png");
	if (!start_img_plane_2)
		game_abort("failed to load image: plane_2.png");

    start_img_plane_3 = al_load_bitmap("./image/plane.png");
	if (!start_img_plane_3)
		game_abort("failed to load image: plane.png");

    start_img_plane_3_ult = al_load_bitmap("./image/plane_ult.png");
	if (!start_img_plane_3_ult)
		game_abort("failed to load image: plane_ult.png");

    start_img_plane_small =  al_load_bitmap("./image/small_plane.png");
	if (!start_img_plane_small)
		game_abort("failed to load image: plane_small.png");

    start_img_plane_small_ult =  al_load_bitmap("./image/small_plane_ult.png");
	if (!start_img_plane_small_ult)
		game_abort("failed to load image: plane_small_ult.png");

    start_img_enemy_1 = al_load_bitmap("./image/monster1.png");
	if (!start_img_enemy_1)
		game_abort("failed to load image: enemy_1.png");

	start_img_enemy_2 = al_load_bitmap("./image/monster2.png");
	if (!start_img_enemy_2)
		game_abort("failed to load image: enemy_2.png");

	start_img_enemy_3 = al_load_bitmap("./image/enemy_3.png");
	if (!start_img_enemy_3)
		game_abort("failed to load image: enemy_3.png");


    //--weapon initialize
    img_bullet_1 = al_load_bitmap("./image/bullet-1.png");
	if (!img_bullet_1)
		game_abort("failed to load image: bullet-1.png");

	img_bullet_3 = al_load_bitmap("./image/bullet-6.png");
	if (!img_bullet_3)
		game_abort("failed to load image: bullet-6.png");

    img_track_bullet = al_load_bitmap("./image/bullet-3.png");
	if (!img_track_bullet)
		game_abort("failed to load image: img_track_bullet.png");


    for(int i = 1 ; i <= IMAGE_EXPLODE ; i++){
        char temp[50];
        sprintf( temp, "./image/explosion-d%d.png", i );
        img_explode[i-1] = al_load_bitmap(temp);
        if (!img_explode[i-1])
            game_abort("failed to load image: img_explode.png");
    }

    //--warning
    img_warning = al_load_bitmap("./image/point-red.png");
    if (!img_warning)
            game_abort("failed to load image: img_warning.png");
    //--mine
    for(int i = 1 ; i <= IMAGE_MINE ; i++){
        char temp[50];
        sprintf( temp, "./image/explosion-b%d.png", i );
        img_mine[i-1] = al_load_bitmap(temp);
        if (!img_mine[i-1])
            game_abort("failed to load image: img_mine.png");
    }

    for(int i = 1 ; i <= IMAGE_FIRE_PUSH ; i++){
        char temp[50];
        sprintf( temp, "./image/FX023_%d.png", i );
        img_fire_push[i-1] = al_load_bitmap(temp);
        if (!img_fire_push[i-1])
            game_abort("failed to load image: img_fire_push.png");
    }

    for(int i = 1 ; i <= IMAGE_ELECTRIC ; i++){
        char temp[50];
        sprintf( temp, "./image/electric_%d.png", i );
        img_electric[i-1] = al_load_bitmap(temp);
        if (!img_electric[i-1])
            game_abort("failed to load image: img_electric.png");
    }

    for(int i = 1 ; i <= IMAGE_SHIELD ; i++){
        char temp[50];
        sprintf( temp, "./image/blue_shield-%d.png", i );
        img_shield[i-1] = al_load_bitmap(temp);
        if (!img_shield[i-1])
            game_abort("failed to load image: img_shield.png");
    }

    for(int i = 1 ; i <= IMAGE_LASER ; i++){
        char temp[50];
        sprintf( temp, "./image/FX030_%d.png", i );
        img_laser[i-1] = al_load_bitmap(temp);
        if (!img_laser[i-1])
            game_abort("failed to load image: img_laser.png");
    }

    gif_shield = algif_load_animation("./image/purple_shield.gif");

    img_first_enemy_bullet = al_load_bitmap("./image/bullet-11.png");
    if (!img_first_enemy_bullet)
		game_abort("failed to load image: first enemy bullet.png");

    img_second_enemy_bullet = al_load_bitmap("./image/bullet-10.png");
    if (!img_second_enemy_bullet)
		game_abort("failed to load image: second enemy bullet.png");

    img_HP_drink = al_load_bitmap("./image/HP_restore.png");
    if (!img_HP_drink)
		game_abort("failed to load image: HP_restore.png");

    img_ULT_drink = al_load_bitmap("./image/ULT_restore.png");
    if (!img_ULT_drink)
		game_abort("failed to load image: ULT_restore.png");


    //--boss
    img_boss_1 = al_load_bitmap("./image/boss_1 (2).png");
	if (!img_boss_1)
		game_abort("failed to load image: boss_1.png");

    img_boss_2 = al_load_bitmap("./image/boss_2.png");
	if (!img_boss_2)
		game_abort("failed to load image: boss_2.png");


    //--weapon
    img_boss2_laser = al_load_bitmap("./image/boss_laser.png");
    if (!img_boss2_laser)
		game_abort("failed to load image: boss_laser.png");

    img_enemy_bullet_2 = al_load_bitmap("./image/bullet-9.png");
    if (!img_enemy_bullet_2)
		game_abort("failed to load image: bullet-9.png");

    img_boss1_bullet = al_load_bitmap("./image/bullet-4.png");
    if (!img_boss1_bullet)
		game_abort("failed to load image: bullet-4.png");

    for(int i = 1 ; i <= IMAGE_BOSS1_ULTIMATE ; i++){
        char temp[50];
        sprintf( temp, "./image/explosion-e%d.png", i );
        img_boss1_ultimate[i-1] = al_load_bitmap(temp);
        if (!img_boss1_ultimate[i-1])
            game_abort("failed to load image: img_boss1_ultimate.png");
    }


    img_HP_ULT = al_load_bitmap("./image/HP_ULT.png");
    if (!img_HP_ULT)
		game_abort("failed to load image: img_HP_ULT");

    //----------------initialize--------------------//
    //--共同

    //--設定敵人數量
    FIRST_ENEMY = 6;
    SECOND_ENEMY = 0;

    int i,j;
    score = 0;
    plane_code = 3;//--第三台飛機
    //--setting plane
    if( plane_code == 1) plane.img = start_img_plane_1;//--choose plane
    else if( plane_code == 2) plane.img = start_img_plane_2;
    else if( plane_code == 3) plane.img = start_img_plane_3;
    plane.img_ult = start_img_plane_3_ult;
    plane.x = WIDTH/2;
    plane.y = HEIGHT+200;
    plane.w = al_get_bitmap_width(plane.img);
    plane.h = al_get_bitmap_height(plane.img);
    //printf("%f %f\n",plane.w,plane.h);
    plane.HP = 2000;
    plane.MAX_HP = 2000;
    plane.ULT = 400;
    plane.MAX_ULT = 400;
    //printf("%d ",plane.HP);

    //--setting small plane
    for(i = 0 ; i<MAX_SMALL_PLANE ; i++){
        small_plane[i].img = start_img_plane_small;
        small_plane[i].img_ult = start_img_plane_small_ult;
        small_plane[0].x = plane.x-plane.w;
        small_plane[1].x = plane.x+plane.w;
        small_plane[i].y = plane.y;
        small_plane[i].w = al_get_bitmap_width(small_plane[0].img);
        small_plane[i].h = al_get_bitmap_height(small_plane[0].img);
        small_plane[i].HP = 1000;
        small_plane[i].MAX_HP = 1000;
        small_plane[i].hidden = true;
    }

    //--setting plane_1 bullet
    if( plane_code == 1 ){
        for (i = 0; i < MAX_BULLET; i++) {
            bullets[i].w = al_get_bitmap_width(img_bullet_1);
            bullets[i].h = al_get_bitmap_height(img_bullet_1);
            bullets[i].img = img_bullet_1;
            bullets[i].vx = 0;
            bullets[i].vy = -3;
            bullets[i].hidden = true;
            bullets[i].HP = 50;
            //game_log("bullet %d is at (%f,%f) with velocity (%f,%f) and plane (%f,%f)",i,bullets[i].x,bullets[i].y,bullets[i].vx,bullets[i].vy,plane.x,plane.y);
        }
    }

    //--setting plane_2 bullet
    if( plane_code == 2 ){
        for (i = 0; i < MAX_BULLET; i++) {
            bullets[i].w = al_get_bitmap_width(img_bullet_1);
            bullets[i].h = al_get_bitmap_height(img_bullet_1);
            bullets[i].img = img_bullet_1;
            bullets[i].vx = 0;
            bullets[i].vy = -3;
            bullets[i].hidden = true;
            bullets[i].HP = 50;
            //game_log("bullet %d is at (%f,%f) with velocity (%f,%f) and plane (%f,%f)",i,bullets[i].x,bullets[i].y,bullets[i].vx,bullets[i].vy,plane.x,plane.y);
        }
    }

    //--setting plane_3 bullet
    if( plane_code == 3 ){
        for (i = 0; i < MAX_BULLET; i++) {
            bullets[i].w = al_get_bitmap_width(img_bullet_3);
            bullets[i].h = al_get_bitmap_height(img_bullet_3);
            bullets[i].img = img_bullet_3;
            bullets[i].vx = 0;
            bullets[i].vy = -5;
            bullets[i].hidden = true;
            //bullets[i].HP = 200;
            bullets[i].HP = 200;
            //game_log("bullet %d is at (%f,%f) with velocity (%f,%f) and plane (%f,%f)",i,bullets[i].x,bullets[i].y,bullets[i].vx,bullets[i].vy,plane.x,plane.y);
        }
    }

    //--setting small plane bullet
    for( i = 0 ; i< MAX_SMALL_PLANE ; i++){
        for (j = 0; j < MAX_BULLET; j++) {
            small_bullets[i][j].w = al_get_bitmap_width(img_bullet_1);
            small_bullets[i][j].h = al_get_bitmap_height(img_bullet_1);
            small_bullets[i][j].img = img_bullet_1;
            small_bullets[i][j].vx = 0;
            small_bullets[i][j].vy = -3;
            small_bullets[i][j].hidden = true;
            small_bullets[i][j].HP = 100;
            //game_log("bullet %d is at (%f,%f) with velocity (%f,%f) and plane (%f,%f)",i,bullets[i].x,bullets[i].y,bullets[i].vx,bullets[i].vy,plane.x,plane.y);
        }
    }

    //--setting laser(animation)
    laser.w = al_get_bitmap_width(img_laser[0]);
    laser.h = al_get_bitmap_height(img_laser[0]);
    laser.hidden = true;
    laser.HP = 400;

    //--setting HP drink
    HP_drink.w = al_get_bitmap_width(img_HP_drink);
    HP_drink.h = al_get_bitmap_height(img_HP_drink);
    HP_drink.img = img_HP_drink;
    HP_drink.vx = (((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
    HP_drink.vy = (((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
    HP_drink.hidden = true;
    HP_drink.HP = 500;

    //--setting ULT drink
    ULT_drink.w = al_get_bitmap_width(img_ULT_drink);
    ULT_drink.h = al_get_bitmap_height(img_ULT_drink);
    ULT_drink.img = img_ULT_drink;
    ULT_drink.vx = (((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
    ULT_drink.vy = (((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
    ULT_drink.hidden = true;

    //--initial explode
    for(i=0 ; i<MAX_ENEMY ; i++){
        first_img_explode_count[i] = -1;
    }

    //--start scene
    //--setting first enemy
    for (i = 0; i < MAX_ENEMY; i++) {
        first_enemies[i].img = start_img_enemy_1;
        first_enemies[i].w = al_get_bitmap_width(start_img_enemy_1);
        first_enemies[i].h = al_get_bitmap_height(start_img_enemy_1);

        if( i < FIRST_ENEMY ) first_enemies[i].hidden = false;
        else first_enemies[i].hidden = true;

        first_enemies[i].vx = 3*(((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
        first_enemies[i].vy = 3*(((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
        first_enemies[i].HP = 1000;
        first_enemies[i].MAX_HP = 1000;

        for(j=0 ; j<IMAGE_EXPLODE ; j++){
            first_explode[i].img[j] = img_explode[j];
        }

        first_explode[i].hidden = true;
        enemy_code = 1;

        //printf("%d\n",explode[i].hidden);
        start_time = al_get_time();
    }

    for(i=0 ; i<ENEMY_Y ; i++){
        for(j=0 ; j<ENEMY_X ; j++){
            first_enemies[ENEMY_X*i+j].x = first_enemy_x[j];
            first_enemies[ENEMY_X*i+j].y = first_enemy_y[i];
            first_enemies[ENEMY_X*i+j].init_vx = init_first_enemy_vx[j];
            first_enemies[ENEMY_X*i+j].init_vy = init_first_enemy_vy[i];
            //printf("%d %d\n",enemy_x[i],enemy_y[i]);
        }
    }


    //--setting second enemy
    for (i = 0; i < MAX_ENEMY; i++) {
        second_enemies[i].img = start_img_enemy_2;
        second_enemies[i].w = al_get_bitmap_width(start_img_enemy_2);
        second_enemies[i].h = al_get_bitmap_height(start_img_enemy_2);

        if( i < SECOND_ENEMY ){
            printf("in\n");
            second_enemies[i].hidden = false;
        }
        else second_enemies[i].hidden = true;

        second_enemies[i].vx = 3*(((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
        second_enemies[i].vy = 3*(((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
        second_enemies[i].HP = 1500;
        second_enemies[i].MAX_HP = 1500;

        for(j=0 ; j<IMAGE_EXPLODE ; j++){
            second_explode[i].img[j] = img_explode[j];
        }

        second_explode[i].hidden = true;
        //enemy_code = 1;

        //printf("%d\n",explode[i].hidden);
        //start_time = al_get_time();
    }

    for(i=0 ; i<ENEMY_Y ; i++){
        for(j=0 ; j<ENEMY_X ; j++){
            second_enemies[ENEMY_X*i+j].x = second_enemy_x[j];
            second_enemies[ENEMY_X*i+j].y = second_enemy_y[i];
            second_enemies[ENEMY_X*i+j].init_vx = 0;
            second_enemies[ENEMY_X*i+j].init_vy = init_second_enemy_vy[i];
            //printf("%d %d\n",enemy_x[i],enemy_y[i]);
        }
    }

    //--setting first enemy bullet
    for( i=0 ; i<MAX_ENEMY ; i++ ){
        for( j=0 ; j<MAX_FIRST_ENEMY_BULLET ; j++ ){
            first_enemies_bullets[i][j].w = al_get_bitmap_width(img_first_enemy_bullet);
            first_enemies_bullets[i][j].h = al_get_bitmap_height(img_first_enemy_bullet);
            first_enemies_bullets[i][j].img = img_first_enemy_bullet;
            first_enemies_bullets[i][j].vx = (((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
            first_enemies_bullets[i][j].vy = 2;
            first_enemies_bullets[i][j].hidden = true;
            //enemies_bullets[i][j].x = enemies[i].x;
            //enemies_bullets[i][j].y = enemies[i].y;
            first_enemies_bullets[i][j].HP = 100;
        }
    }

    //--setting second enemy bullet
    for( i=0 ; i<MAX_ENEMY ; i++ ){
        for( j=0 ; j<MAX_SECOND_ENEMY_BULLET/4 ; j++ ){
            for(k=0 ; k<4 ; k++){
                second_enemies_bullets[i][j*4+k].w = al_get_bitmap_width(img_first_enemy_bullet);
                second_enemies_bullets[i][j*4+k].h = al_get_bitmap_height(img_first_enemy_bullet);
                second_enemies_bullets[i][j*4+k].img = img_second_enemy_bullet;
                float SECOND_ENEMY_BULLET_VELOCITY = 3;
                if(k == 0){//--往四個方向射
                    second_enemies_bullets[i][j*4+k].vx = 0;
                    second_enemies_bullets[i][j*4+k].vy = SECOND_ENEMY_BULLET_VELOCITY;
                }
                else if(k == 1){
                    second_enemies_bullets[i][j*4+k].vx = -SECOND_ENEMY_BULLET_VELOCITY;
                    second_enemies_bullets[i][j*4+k].vy = 0;
                }
                else if(k == 2){
                    second_enemies_bullets[i][j*4+k].vx = 0;
                    second_enemies_bullets[i][j*4+k].vy = -SECOND_ENEMY_BULLET_VELOCITY;
                }
                else if(k == 3){
                    second_enemies_bullets[i][j*4+k].vx = SECOND_ENEMY_BULLET_VELOCITY;
                    second_enemies_bullets[i][j*4+k].vy = 0;
                }
                second_enemies_bullets[i][j*4+k].hidden = true;
                //printf("j = %d k = %d hidden = %d\n",j,k,second_enemies_bullets[i][j*4+k].hidden);
                second_enemies_bullets[i][j*4+k].HP = 150;
            }
        }
    }
    //--boss scene
    //--setting boss_1
    boss1.x = WIDTH/2;
    boss1.y = HEIGHT/2-175;
    boss1.w = al_get_bitmap_width(img_boss_1);
    boss1.h = al_get_bitmap_height(img_boss_1);
    boss1.img = img_boss_1;
    boss1.vx = 0;
    boss1.vy = 0;
    boss1.HP = 30000;
    boss1.MAX_HP = 30000;
    boss1.ULT = 0;
    boss1.MAX_ULT = 200;
    boss1.hidden = false;
    //explode[2].img = img_explode;
    first_explode[2].hidden = true;

    //--setting boss_2 boss_3
    for(i=0 ; i<MAX_BOSS_2 ; i++){
        if( i == 0 ) boss2[i].x = 100;//--left
        else if(i == 1) boss2[i].x = WIDTH - 100;//--right

        boss2[i].y = HEIGHT/2-200;
        boss2[i].w = al_get_bitmap_width(img_boss_2);
        boss2[i].h = al_get_bitmap_height(img_boss_2);
        boss2[i].img = img_boss_2;
        boss2[i].hidden = false;
        boss2[i].vx = 0;

        if( i == 0 ) boss2[i].vy = 1;
        else if( i == 1 ) boss2[i].vy = 2;
        boss2[i].HP = 2000;
        boss2[i].MAX_HP = 2000;

        //--setting boss explode
        for(j=0 ; j<IMAGE_EXPLODE ; j++){
            boss_explode[i].img[j] = img_explode[j];
        }
        boss_explode[i].hidden = true;
    }

    //--setting boss1 bullet
    for( i=0 ; i<MAX_BOSS_ENEMY_BULLET ; i++ ){
        boss1_bullets[i].w = al_get_bitmap_width(img_boss1_bullet);
        boss1_bullets[i].h = al_get_bitmap_height(img_boss1_bullet);
        boss1_bullets[i].img = img_boss1_bullet;
        boss1_bullets[i].vx = 0;
        boss1_bullets[i].vy = 2;
        boss1_bullets[i].hidden = true;
        boss1_bullets[i].HP = 200;
        //printf("%d ",i);
    }

    //--setting boss1 mine(warning)
    for( i=0 ; i<MAX_MINE ; i++ ){
        boss1_mine[i].w = al_get_bitmap_width(img_warning);
        boss1_mine[i].h = al_get_bitmap_height(img_warning);
        boss1_mine[i].img = img_warning;
        boss1_mine[i].hidden = true;
        boss1_mine[i].HP = 400;
    }

    //--setting boss2 laser
    for( i=0 ; i<MAX_BOSS_LASER ; i++){
        boss_laser[i].w = al_get_bitmap_width(img_boss2_laser);
        boss_laser[i].h = al_get_bitmap_height(img_boss2_laser);
        boss_laser[i].img = img_boss2_laser;
        boss_laser[i].vx = 0;
        boss_laser[i].vy = 0;
        boss_laser[i].hidden = true;
        boss_laser[i].HP = 200;
    }


    //--setting boss2 bullets
    for( i=0 ; i<MAX_FIRST_ENEMY_BULLET ; i++ ){
        boss2_bullets[i].w = al_get_bitmap_width(img_enemy_bullet_2);
        boss2_bullets[i].h = al_get_bitmap_height(img_enemy_bullet_2);
        boss2_bullets[i].img = img_enemy_bullet_2;
        boss2_bullets[i].vx = -2;
        boss2_bullets[i].vy = 2*(((float)rand() / RAND_MAX)-((float)rand() / RAND_MAX));
        boss2_bullets[i].hidden = true;
            //enemies_bullets[i][j].x = enemies[i].x;
            //enemies_bullets[i][j].y = enemies[i].y;
        boss2_bullets[i].HP = 100;
    }

    //--setting boss1 ultimate
    boss1_ultimate.w = al_get_bitmap_width(img_boss1_ultimate[0]);
    boss1_ultimate.h = al_get_bitmap_height(img_boss1_ultimate[0]);
    boss1_ultimate.img = img_boss1_ultimate[0];
    for(i=0 ; i<IMAGE_BOSS1_ULTIMATE ; i++){
        boss1_ultimate_ani.img[i] = img_boss1_ultimate[i];
    }

    boss1_ultimate.hidden = true;
    boss1_ultimate.HP = 500;

    //--shield
    img_shield_w = al_get_bitmap_width(img_shield[0]);
    img_shield_h = al_get_bitmap_height(img_shield[0]);

}


void second_game_character_update(){

    int i;
    double now = al_get_time();
    //--共同
    if(window == SCENE_SECOND_GAME_START || window == SCENE_SECOND_GAME_BOSS){
        //--plane move
        if(first_change_to_second || start_to_boss){
            plane.vy = -1;
            plane.vx = 0;
        }
        else{
            plane.vx = plane.vy = 0;
            if (key_state[ALLEGRO_KEY_UP] || key_state[ALLEGRO_KEY_W])
                plane.vy -= 1;
            if (key_state[ALLEGRO_KEY_DOWN] || key_state[ALLEGRO_KEY_S])
                plane.vy += 1;
            if (key_state[ALLEGRO_KEY_LEFT] || key_state[ALLEGRO_KEY_A])
                plane.vx -= 1;
            if (key_state[ALLEGRO_KEY_RIGHT] || key_state[ALLEGRO_KEY_D])
                plane.vx += 1;
        }

        //--plane can not exceed screen
        if(!start_to_boss){
            if(!small_plane[0].hidden){
                if(small_plane[0].x -small_plane[0].w/2 <= 0){
                    small_plane[0].x = small_plane[0].w/2;
                    plane.x = small_plane[0].x + plane.w;
                    small_plane[1].x = small_plane[0].x + 2*plane.w;
                }
                else if(small_plane[1].x +small_plane[1].w/2 >= WIDTH){
                    small_plane[1].x = WIDTH - small_plane[1].w/2;
                    plane.x = small_plane[1].x - plane.w;
                    small_plane[0].x = small_plane[1].x - 2*plane.w;
                }
                if (plane.y-plane.h/2 < 0){
                    plane.y = plane.h/2;
                    small_plane[0].y = plane.y;
                    small_plane[1].y = plane.y;
                }
                else if (plane.y+plane.h/2 > HEIGHT){
                    plane.y = HEIGHT-plane.h/2;
                    small_plane[0].y = plane.y;
                    small_plane[1].y = plane.y;
                }

            }
            else{

                if (plane.x-plane.w/2 < 0)
                    plane.x = plane.w/2;
                else if (plane.x+plane.w/2 > WIDTH)
                    plane.x = WIDTH -plane.w/2;
                if (plane.y-plane.h/2 < 0)
                    plane.y = plane.h/2;
                else if (plane.y+plane.h/2 > HEIGHT)
                    plane.y = HEIGHT-plane.h/2;

            }
        }



        //--plane move
        // 0.71 is (1/sqrt(2))
        plane.y += plane.vy * 4 * (plane.vx ? 0.71f : 1);
        plane.x += plane.vx * 4 * (plane.vy ? 0.71f : 1);


        //--small plane move
        for(i=0 ; i<MAX_SMALL_PLANE ; i++){
            small_plane[i].x += plane.vx * 4 * (plane.vy ? 0.71f : 1);
            small_plane[i].y += plane.vy * 4 * (plane.vx ? 0.71f : 1);

            /*
            if(small_plane[0].x -small_plane[0].w/2 <= 0){
                small_plane[0].x = small_plane[0].w/2;
            }
            */

        }

        //--small plane bullet move
        for( i=0 ; i<MAX_SMALL_PLANE ; i++){
            for( j=0 ; j<MAX_BULLET ; j++ ){

                if (!small_bullets[i][j].hidden){
                    small_bullets[i][j].x += small_bullets[i][j].vx;
                    small_bullets[i][j].y += small_bullets[i][j].vy;
                }

            //--enemy bullet exceed screen
                if ( small_bullets[i][j].x < 0 ||
                      small_bullets[i][j].y < 0 ||
                      small_bullets[i][j].x > WIDTH ||
                      small_bullets[i][j].y > HEIGHT ){

                    small_bullets[i][j].hidden = true;
                }
            }
        }

        //--plane bullet coordinate
        for  ( i=0 ; i<MAX_BULLET ; i++ ) {

            if (!bullets[i].hidden){
                bullets[i].x += bullets[i].vx;
                bullets[i].y += bullets[i].vy;
            }

            //--plane bullet exceed screen
            if ( bullets[i].x < 0 ||
                  bullets[i].y < 0 ||
                  bullets[i].x > WIDTH ||
                  bullets[i].y > HEIGHT ){

                bullets[i].hidden = true;
            }

        }

        //--HP drink position
        HP_drink.x += HP_drink.vx;
        HP_drink.y += HP_drink.vy;

        //--ULT drink position
        ULT_drink.x += ULT_drink.vx;
        ULT_drink.y += ULT_drink.vy;

        //--plane_ultimate_recover
        if(plane.ULT < plane.MAX_ULT) plane.ULT += 0.5;

        //--small plane appear

        if(small_plane_appear){
            small_plane[0].x = plane.x-plane.w;
            small_plane[1].x = plane.x+plane.w;
            small_plane[0].y = plane.y;
            small_plane[1].y = plane.y;
        }

        //printf("%f %f %f\n",small_plane[0].x,small_plane[1].x,small_plane[0].y);
    }

    //--start
    if(window == SCENE_SECOND_GAME_START){

        //--enemy move
        float vx_temp;
        float vy_temp;
        for(i=0 ; i< FIRST_ENEMY ; i++){
            //game_log("%dth enemy position (%f,%f)",i,enemies[i].x,enemies[i].y);

            //--first enemy can not exceed the screen
            now = al_get_time();
            if( now - start_time >= ENEMY_APPEAR_COOLDOWN){//--一開始不要判斷

                if(!first_enemies[i].hidden){
                    first_enemies[i].x += first_enemies[i].vx;
                    first_enemies[i].y += first_enemies[i].vy;
                }

                if (first_enemies[i].x - first_enemies[i].w/2 < 0){
                    first_enemies[i].x = first_enemies[i].w/2;
                    vx_temp = first_enemies[i].vx;
                    first_enemies[i].vx = -vx_temp;
                    //gamelog("")
                    }
                else if (first_enemies[i].x + first_enemies[i].w/2 > WIDTH){
                    first_enemies[i].x =WIDTH - first_enemies[i].w/2;
                    vx_temp = first_enemies[i].vx;
                    first_enemies[i].vx = -vx_temp;
                }
                if (first_enemies[i].y - first_enemies[i].h/2 < 0){
                    first_enemies[i].y = first_enemies[i].h/2;
                    vy_temp = first_enemies[i].vy;
                    first_enemies[i].vy = -vy_temp;
                }
                else if (first_enemies[i].y + first_enemies[i].h/2 > HEIGHT){
                    first_enemies[i].y =HEIGHT - first_enemies[i].h/2;
                    vy_temp = first_enemies[i].vy;
                    first_enemies[i].vy = -vy_temp;
                }
            }
            else{
                first_enemies[i].x += first_enemies[i].init_vx;
                first_enemies[i].y += first_enemies[i].init_vy;
                //printf("%lf %lf\n",enemies[i].x,enemies[i].y);
            }
        }


        //--second enemy can not exceed the screen
        for(i=0 ; i< SECOND_ENEMY ; i++){
            now = al_get_time();
            if( now - start_time >= ENEMY_APPEAR_COOLDOWN){//--一開始不要判斷

                if(!second_enemies[i].hidden){
                    second_enemies[i].x += second_enemies[i].vx;
                    second_enemies[i].y += second_enemies[i].vy;
                }

                if (second_enemies[i].x - second_enemies[i].w/2 < 0){
                    second_enemies[i].x = second_enemies[i].w/2;
                    vx_temp = second_enemies[i].vx;
                    second_enemies[i].vx = -vx_temp;
                    //gamelog("")
                    }
                else if (second_enemies[i].x + second_enemies[i].w/2 > WIDTH){
                    second_enemies[i].x =WIDTH - second_enemies[i].w/2;
                    vx_temp = second_enemies[i].vx;
                    second_enemies[i].vx = -vx_temp;
                }
                if (second_enemies[i].y - second_enemies[i].h/2 < 0){
                    second_enemies[i].y = second_enemies[i].h/2;
                    vy_temp = second_enemies[i].vy;
                    second_enemies[i].vy = -vy_temp;
                }
                else if (second_enemies[i].y + second_enemies[i].h/2 > HEIGHT){
                    second_enemies[i].y =HEIGHT - second_enemies[i].h/2;
                    vy_temp = second_enemies[i].vy;
                    second_enemies[i].vy = -vy_temp;
                }
            }
            else{
                second_enemies[i].x += second_enemies[i].init_vx;
                second_enemies[i].y += second_enemies[i].init_vy;
                //printf("%lf %lf\n",enemies[i].x,enemies[i].y);
            }
        }



        //--first enemy bullet coordinate
        for( i=0 ; i<FIRST_ENEMY ; i++){
            for( j=0 ; j<MAX_FIRST_ENEMY_BULLET ; j++ ){

                if (!first_enemies_bullets[i][j].hidden){
                    first_enemies_bullets[i][j].x += first_enemies_bullets[i][j].vx;
                    first_enemies_bullets[i][j].y += first_enemies_bullets[i][j].vy;
                }

            //--enemy bullet exceed screen
                if ( first_enemies_bullets[i][j].x < 0 ||
                      first_enemies_bullets[i][j].y < 0 ||
                      first_enemies_bullets[i][j].x > WIDTH ||
                      first_enemies_bullets[i][j].y > HEIGHT ){

                    first_enemies_bullets[i][j].hidden = true;
                }
            }
        }

        //--second enemy bullet coordinate
        for( i=0 ; i<SECOND_ENEMY ; i++){
            for( j=0 ; j<MAX_SECOND_ENEMY_BULLET ; j++ ){

                if (!second_enemies_bullets[i][j].hidden){
                    second_enemies_bullets[i][j].x += second_enemies_bullets[i][j].vx;
                    second_enemies_bullets[i][j].y += second_enemies_bullets[i][j].vy;
                    //printf("in bullet update\n");
                }

            //--enemy bullet exceed screen
                if ( second_enemies_bullets[i][j].x < 0 ||
                      second_enemies_bullets[i][j].y < 0 ||
                      second_enemies_bullets[i][j].x > WIDTH ||
                      second_enemies_bullets[i][j].y > HEIGHT ){
                    //printf("in bullet exceed screen\n");
                    second_enemies_bullets[i][j].hidden = true;
                }
            }
        }


        //--generate enemy
        now = al_get_time();
        if( generate_enemies && !enemy_hidden && now - all_eneimes_defeated_time >= 2.0f){
            //game_log("%d" ,ENEMY);
            //double generate_eneimes_time = al_get_time();

            second_game_generate_enemies();

            generate_enemies = false;
            start_time = al_get_time();
        }

        //--generate enemy(trigger)
        if( !generate_enemies ){
            for( i=0 ;i<FIRST_ENEMY ;i++){
                //printf("%d %d\n",i,first_enemies[i].hidden);
                if(!first_enemies[i].hidden ) break;//--if some enemy undefeated, break the loop
                if( i == FIRST_ENEMY -1 ){
                    if(SECOND_ENEMY == 0){
                        all_eneimes_defeated_time = al_get_time();
                        generate_enemies = true;
                        //--give HP and ULT drink
                        HP_drink.hidden = false;
                        HP_drink.x = WIDTH/2-100;
                        HP_drink.y = HEIGHT-100;

                        ULT_drink.hidden = false;
                        ULT_drink.x = WIDTH/2+100;
                        ULT_drink.y = HEIGHT-100;

                    }
                    else{
                        for(j=0 ; j<SECOND_ENEMY ; j++){
                            printf("in second\n");
                            if(!second_enemies[j].hidden ) break;
                            if( j == SECOND_ENEMY-1 ){
                                all_eneimes_defeated_time = al_get_time();
                                generate_enemies = true;
                                //--give HP and ULT drink
                                HP_drink.hidden = false;
                                HP_drink.x = WIDTH/2-100;
                                HP_drink.y = HEIGHT-100;

                                ULT_drink.hidden = false;
                                ULT_drink.x = WIDTH/2+100;
                                ULT_drink.y = HEIGHT-100;

                            }
                        }
                    }
                }
            }
        }
    }
    //--boss scene
    else if(window == SCENE_SECOND_GAME_BOSS){
        //--boss1 bullet coordinate
        for ( i=0 ; i<MAX_BOSS_ENEMY_BULLET ; i++ ) {
            if (!boss1_bullets[i].hidden){
            boss1_bullets[i].x += boss1_bullets[i].vx;
            boss1_bullets[i].y += boss1_bullets[i].vy;
            }

            //--boss bullet exceed screen
            if ( boss1_bullets[i].x < 0 ||
                  boss1_bullets[i].y < 0 ||
                  boss1_bullets[i].x > WIDTH ||
                  boss1_bullets[i].y > HEIGHT ){

                    boss1_bullets[i].hidden = true;
                  }

        }

        //--boss2 bullet coordinate
        for  ( i=0 ; i<MAX_FIRST_ENEMY_BULLET ; i++ ) {
            if (!boss2_bullets[i].hidden){
            boss2_bullets[i].x += boss2_bullets[i].vx;
            boss2_bullets[i].y += boss2_bullets[i].vy;
            }

            //--boss bullet exceed screen
            if ( boss2_bullets[i].x < 0 ||
                  boss2_bullets[i].y < 0 ||
                  boss2_bullets[i].x > WIDTH ||
                  boss2_bullets[i].y > HEIGHT ){

                    boss2_bullets[i].hidden = true;
                  }

        }

        //--boss_2 position (move)
        if(! boss_2_1_stop) boss2[0].y +=  boss2[0].vy;
        boss2[1].y +=  boss2[1].vy;
        //--boss_2 can not exceed screen
        for( i=0 ; i<MAX_BOSS_2 ; i++ ){
            if( boss2[i].y + boss2[i].w/2 > HEIGHT || boss2[i].y - boss2[i].w/2 < 0 ){
                int tmp = boss2[i].vy;
                boss2[i].vy = -tmp;
            }
        }

        //--boss1 ultimate img change
        now = al_get_time();
        if(!boss1_ultimate.hidden){
            if(now - img_boss1_ultimate_last_time >= IMAGE_BOSS1_ULTIMATE_COOLDOWN){
                img_boss1_ultimate_last_time = now;
                img_boss1_ultimate_count++;
                printf("%d\n",img_boss1_ultimate_count);
                if(img_boss1_ultimate_count == IMAGE_BOSS1_ULTIMATE)
                    img_boss1_ultimate_count = 0;
            }
            boss1_ultimate.img = img_boss1_ultimate[img_boss1_ultimate_count];
        }


        //--ultimate move
        if (!boss1_ultimate.hidden){
            boss1_ultimate.x += boss1_ultimate.vx;
            boss1_ultimate.y += boss1_ultimate.vy;
            }

        //--ultimate can not exceed screen
        if ( boss1_ultimate.x < 0 ||
            boss1_ultimate.y < 0 ||
            boss1_ultimate.x > WIDTH ||
            boss1_ultimate.y > HEIGHT ){

            boss1_ultimate.hidden = true;
        }

        //-- HP drink appearance
        now = al_get_time();
        if(now - last_HP_drink_appearance_timestamp >= HP_DRINK_APPEARANCE_INTERVAL ){
            last_HP_drink_appearance_timestamp = now;
            HP_drink.x = WIDTH*(float)rand()/RAND_MAX;
            HP_drink.y = HEIGHT/2+200;
            HP_drink.hidden = false;
        }

    }


}

void second_game_character_draw(){

    //--動畫的一些校正
    int CORRECTION = 10;

    //--共同
    if(window == SCENE_SECOND_GAME_START || window == SCENE_SECOND_GAME_BOSS){
        //--plane hp ult score
        al_draw_textf( font_36, al_map_rgb(0, 0, 0) , 10 ,40 ,0,"%05d ",score );
        al_draw_text( font_36, al_map_rgb(0, 0, 0) , 0 ,HEIGHT-85 ,0,"HP  :");
        al_draw_text( font_36, al_map_rgb(0, 0, 0) , 0 ,HEIGHT-55 ,0,"ULT :");

        //--plane HP
        if( plane.HP > 0) al_draw_filled_rectangle( 130, HEIGHT-80, 130+250*plane.HP/plane.MAX_HP, HEIGHT-50, al_map_rgb(0,255,0) );
        if( plane.ULT > 0 ) al_draw_filled_rectangle( 130, HEIGHT-45, 130+250*plane.ULT/plane.MAX_ULT, HEIGHT-15, al_map_rgb(255,0,0) );
        al_draw_rectangle(130, HEIGHT-80, 130+250, HEIGHT-50, al_map_rgb(0,0,0),3);
        al_draw_rectangle( 130, HEIGHT-45, 130+250, HEIGHT-15, al_map_rgb(0,0,0),3 );
        //al_draw_bitmap(img_HP_ULT,25,HEIGHT-200,0);
        //if( plane.HP > 0) al_draw_filled_rectangle( 165+198*plane.HP/plane.MAX_HP , 756, 363, 781, al_map_rgb(255,255,255) );
        //if( plane.ULT > 0 ) al_draw_filled_rectangle( 165+198*plane.ULT/plane.MAX_ULT, 790, 363, 815, al_map_rgb(255,255,255) );


        //--draw plane bullet
        for ( i=0 ; i<MAX_BULLET ; i++){
            draw_movable_object(bullets[i]);
        }

        //--draw small plane bullet
        for(i=0 ; i<MAX_SMALL_PLANE ; i++){
            for(j=0 ; j<MAX_BULLET ; j++){
                //printf("draw small bullet\n");
                draw_movable_object(small_bullets[i][j]);
            }
        }

        //--draw plane laser
        now = al_get_time();
        if(!laser.hidden){
            if(now - img_laser_last_time >= IMAGE_LASER_COOLDOWN){
                img_laser_last_time  = now;
                img_laser_count++;
                printf("%d ",img_laser_count);
            }
            al_draw_bitmap(img_laser[img_laser_count],plane.x-laser.w/2,plane.y-plane.h/2-laser.h,0);

            if(img_laser_count == IMAGE_LASER-1){
                img_laser_count = -1;
                laser.hidden = true;
            }

        }

        //--draw shield
        now = al_get_time();
        if(shield_appearance){
            if(now - img_shield_last_time >= IMAGE_SHIELD_COOLDOWN){
                img_shield_last_time = now;
                img_shield_count++;
                printf("%d\n",img_shield_count);
                if(img_shield_count == IMAGE_SHIELD)
                    img_shield_count = 0;
            }
            al_draw_bitmap(img_shield[img_shield_count],plane.x-plane.w/2-35,plane.y-plane.h/2-30,0);
        }

        /*
        if(shield_appearance)
        al_draw_bitmap(algif_get_bitmap(gif_shield, al_get_time()),plane.x-plane.w/2-40,plane.y-plane.h/2-35,0);
        */
        //--draw plane
        if(invincible){
            if(plane_draw_key){
                plane_draw_movable_object(plane);
            }
        }
        else plane_draw_movable_object(plane);

        //--draw small plane
        for(i=0 ; i<MAX_SMALL_PLANE ; i++){
            //printf("%d %d\n",small_plane[0].hidden,small_plane[1].hidden);
            plane_draw_movable_object(small_plane[i]);
        }

        //--draw HP.ULT drink
        draw_movable_object(HP_drink);
        draw_movable_object(ULT_drink);

        /*
        if(ultimate){
            al_draw_bitmap(img_ultimate_2,(rand()%2)*10+(plane.x-plane.w/2-50),(rand()%2)*10+(plane.y-plane.h/2-50),0);
            ultimate = true;
        }
        */

        //-- draw fire push
        now = al_get_time();
        if(now - img_fire_push_last_time >= IMAGE_FIRE_PUSH_COOLDOWN){
            img_fire_push_last_time = now;
            img_fire_push_count++;
            if(img_fire_push_count == IMAGE_FIRE_PUSH)
                img_fire_push_count = 0;
        }
        al_draw_bitmap(img_fire_push[img_fire_push_count],plane.x-plane.w/2+CORRECTION,plane.y+plane.h/2,0);

        //--draw electric
        if(laser_appearance){
            now = al_get_time();
            if(now - img_electric_last_time >= IMAGE_ELECTRIC_COOLDOWN){
                img_electric_last_time = now;
                img_electric_count++;
                printf("%d\n",img_electric_count);
                if(img_electric_count == IMAGE_ELECTRIC)
                    img_electric_count = 0;
            }
            al_draw_bitmap(img_electric[img_electric_count],plane.x-plane.w/2-50,plane.y-plane.h/2-50,0);
        }

    }

    if(window == SCENE_SECOND_GAME_START){
        //--draw enemy
        for (i = 0; i < FIRST_ENEMY; i++){
             draw_movable_object(first_enemies[i]);
        }
        for (i = 0; i < SECOND_ENEMY; i++){
             draw_movable_object(second_enemies[i]);
        }
        //--draw enemy bullet
        for (i = 0; i < FIRST_ENEMY; i++){
            for (j = 0; j < MAX_FIRST_ENEMY_BULLET; j++){
                 draw_movable_object(first_enemies_bullets[i][j]);
            }
        }
        for (i = 0; i < SECOND_ENEMY ; i++){
            for (j = 0; j < MAX_SECOND_ENEMY_BULLET; j++){
                 draw_movable_object(second_enemies_bullets[i][j]);
            }
        }

        //--draw first enemy HP
        for (i = 0; i < FIRST_ENEMY; i++){
             if ( first_enemies[i].HP > 0 && !first_enemies[i].hidden ){
                al_draw_filled_rectangle( first_enemies[i].x-first_enemies[i].w/2, first_enemies[i].y+first_enemies[i].h/2+10,
                                        first_enemies[i].x-first_enemies[i].w/2+first_enemies[i].w*first_enemies[i].HP/first_enemies[i].MAX_HP
                                        , first_enemies[i].y+first_enemies[i].h/2, al_map_rgb(255,0,0) );
             }

             if( first_enemies[i].HP > 0 && !first_enemies[i].hidden ){
                al_draw_rectangle( first_enemies[i].x-first_enemies[i].w/2, first_enemies[i].y+first_enemies[i].h/2+10,
                                   first_enemies[i].x-first_enemies[i].w/2+first_enemies[i].w, first_enemies[i].y+first_enemies[i].h/2,
                                   al_map_rgb(255,255,255) , 3);
             }

        }

        //--draw second enemy HP
        for (i = 0; i < SECOND_ENEMY ; i++){
             if ( second_enemies[i].HP > 0 && !second_enemies[i].hidden ){
                al_draw_filled_rectangle( second_enemies[i].x-second_enemies[i].w/2, second_enemies[i].y+second_enemies[i].h/2+10,
                                        second_enemies[i].x-second_enemies[i].w/2+second_enemies[i].w*second_enemies[i].HP/second_enemies[i].MAX_HP
                                        , second_enemies[i].y+second_enemies[i].h/2, al_map_rgb(255,0,0) );
             }

             if( second_enemies[i].HP > 0 && !second_enemies[i].hidden ){
                al_draw_rectangle( second_enemies[i].x-second_enemies[i].w/2, second_enemies[i].y+second_enemies[i].h/2+10,
                                   second_enemies[i].x-second_enemies[i].w/2+second_enemies[i].w, second_enemies[i].y+second_enemies[i].h/2,
                                   al_map_rgb(255,255,255) , 3);
             }

        }


        //--if plane bullet hit first enemies and explode
        now = al_get_time();
        for (i = 0; i < FIRST_ENEMY; i++){
            if(!first_explode[i].hidden) {
                //printf("enemy_hidden : %d , explode_hidden : %d \n",enemies[5].hidden,explode[5].hidden);
                if(now - first_img_explode_last_time[i] >= IMAGE_EXPLODE_COOLDOWN){

                    first_img_explode_last_time[i] = now;
                    first_img_explode_count[i] ++;
                    //printf("%d ",img_explode_count);

                }
                al_draw_bitmap(img_explode[first_img_explode_count[i]],first_enemies[i].x-first_enemies[i].w/2,first_enemies[i].y-first_enemies[i].h/2,0);
                if(first_img_explode_count[i] == IMAGE_EXPLODE-1) {
                    first_img_explode_count[i] = -1;
                    first_explode[i].hidden = true;
                }
            }
        }

        //--if plane bullet hit second enemies and explode
        now = al_get_time();
        for (i = 0; i < SECOND_ENEMY; i++){
            if(!second_explode[i].hidden) {
                //printf("enemy_hidden : %d , explode_hidden : %d \n",enemies[5].hidden,explode[5].hidden);
                if(now - second_img_explode_last_time[i] >= IMAGE_EXPLODE_COOLDOWN){

                    second_img_explode_last_time[i] = now;
                    second_img_explode_count[i] ++;
                    //printf("%d ",img_explode_count);

                }
                al_draw_bitmap(img_explode[second_img_explode_count[i]],second_enemies[i].x-second_enemies[i].w/2,second_enemies[i].y-second_enemies[i].h/2,0);
                if(second_img_explode_count[i] == IMAGE_EXPLODE-1) {
                    second_img_explode_count[i] = -1;
                    second_explode[i].hidden = true;
                }
            }
        }

    }
    else if(window == SCENE_SECOND_GAME_BOSS){
        //-draw boss_1
        draw_movable_object(boss1);
        //--draw_boss_2
        for ( i=0 ; i<MAX_BOSS_2 ; i++){
           draw_movable_object(boss2[i]);
        }
        //--draw boss 1 bullet
        for ( i=0 ; i<MAX_BOSS_ENEMY_BULLET ; i++){
           draw_movable_object(boss1_bullets[i]);
        }

        //--draw boss 1 warning
        for( i=0 ; i<MAX_MINE ; i++){
            draw_movable_object(boss1_mine[i]);
        }

        //--draw boss 1 mine
        now = al_get_time();
        if(warning_cooldown == 2){
            if(now - img_mine_last_time >= IMAGE_MINE_COOLDOWN ){
                img_mine_last_time = now;
                img_mine_count++;
            }
            for(i=0 ; i<MAX_MINE ; i++){
                al_draw_bitmap(img_mine[img_mine_count],boss1_mine[i].x-boss1_mine[i].w/2,boss1_mine[i].y-boss1_mine[i].h/2,0);
            }

            if(img_mine_count == IMAGE_MINE-1){
                img_mine_count = -1;
                warning_cooldown = 0;
            }
        }

        //--draw boss 2 laser
        for(i=0 ; i<MAX_BOSS_LASER ; i++){
            draw_movable_object(boss_laser[i]);
        }
        //--draw boss 2 bullet
        for ( i=0 ; i<MAX_FIRST_ENEMY_BULLET ; i++){
           draw_movable_object(boss2_bullets[i]);
        }
        //--draw boss1 hp
        if( boss1.HP > 0 ) al_draw_filled_rectangle( 10 , 10 , (WIDTH-10)*boss1.HP/boss1.MAX_HP , 30 , al_map_rgb(255,0,0) );
        if( boss1.HP > 0 ) al_draw_rectangle( 10 , 10 , (WIDTH-10), 30 , al_map_rgb(255,255,255) , 5 );
        //--draw boss2 hp
        for( i=0 ; i<MAX_BOSS_2 ; i++ ){
            if( boss2[i].HP > 0 ) al_draw_filled_rectangle( boss2[i].x-boss2[i].w/2 , boss2[i].y-boss2[i].h/2 -10 ,
                                                           boss2[i].x - boss2[i].w/2 + boss2[i].w*boss2[i].HP/boss2[i].MAX_HP,
                                                           boss2[i].y-boss2[i].h/2 , al_map_rgb(255,0,0) );
            if( boss2[i].HP > 0 ) al_draw_rectangle( boss2[i].x-boss2[i].w/2 , boss2[i].y-boss2[i].h/2 -10 ,
                                                    boss2[i].x - boss2[i].w/2 + boss2[i].w,
                                                    boss2[i].y-boss2[i].h/2 , al_map_rgb(255,255,255) ,3 );
        }

        now = al_get_time();
        for (i = 0; i < MAX_BOSS_2; i++){
            if(!boss_explode[i].hidden) {
                if(now - first_img_explode_last_time[i] >= IMAGE_EXPLODE_COOLDOWN){

                    first_img_explode_last_time[i] = now;
                    first_img_explode_count[i] ++;
                    printf("%d ",first_img_explode_count[i]);

                }
                al_draw_bitmap(img_explode[first_img_explode_count[i]],boss2[i].x-boss2[i].w/2,boss2[i].y-boss2[i].h/2,0);
                if(first_img_explode_count[i] == IMAGE_EXPLODE-1) {
                    first_img_explode_count[i] = -1;
                    boss_explode[i].hidden = true;
                }
            }
        }

        //--draw boss1 ultimate

        if(!boss1_ultimate.hidden){
            draw_movable_object(boss1_ultimate);
        }

    }

}

void second_game_generate_enemies(){

    FIRST_ENEMY -= 2;
    SECOND_ENEMY += 2;

    //--all enemies are defeated
    if(FIRST_ENEMY == 0){
        enemy_clear = true;
        return;
    }

    for(i=0 ; i<FIRST_ENEMY ; i++){
        first_enemies[i].hidden = false;
    }

    for(i=0 ; i<SECOND_ENEMY ; i++){
        second_enemies[i].hidden = false;
    }


    for(i=0 ; i<ENEMY_Y ; i++){
        for(j=0 ; j<ENEMY_X ; j++){
            first_enemies[ENEMY_X*i+j].x = first_enemy_x[j];
            first_enemies[ENEMY_X*i+j].y = first_enemy_y[i];
            first_enemies[ENEMY_X*i+j].init_vx = init_first_enemy_vx[j];
            first_enemies[ENEMY_X*i+j].init_vy = init_first_enemy_vy[i];
            first_enemies[ENEMY_X*i+j].HP = 1000;
            first_enemies[ENEMY_X*i+j].MAX_HP = 1000;
            //printf("%d %d\n",enemy_x[i],enemy_y[i]);
        }
    }



    for(i=0 ; i<ENEMY_Y ; i++){
        for(j=0 ; j<ENEMY_X ; j++){
            second_enemies[ENEMY_X*i+j].x = second_enemy_x[j];
            second_enemies[ENEMY_X*i+j].y = second_enemy_y[i];
            second_enemies[ENEMY_X*i+j].init_vx = 0;
            second_enemies[ENEMY_X*i+j].init_vy = init_second_enemy_vy[i];
            second_enemies[ENEMY_X*i+j].HP = 1500;
            second_enemies[ENEMY_X*i+j].MAX_HP = 1500;
        }
    }

}

void second_game_restart(){

    FIRST_ENEMY = 8;
    SECOND_ENEMY = -2;
    second_game_generate_enemies();

    //--隱藏子彈
    for( i=0 ; i<MAX_ENEMY ; i++ ){
        for( j=0 ; j<MAX_FIRST_ENEMY_BULLET ; j++ ){
            first_enemies_bullets[i][j].hidden = true;
            second_enemies_bullets[i][j].hidden = true;
        }
    }

    plane.x = WIDTH/2;
    plane.y = HEIGHT-100;
    plane.HP = plane.MAX_HP;
    boss1.HP = boss1.MAX_HP;
    boss2[0].HP = boss2[0].MAX_HP;
    boss2[1].HP = boss2[1].MAX_HP;
    start_time = al_get_time();
}

void second_game_character_destory(){
    al_destroy_bitmap(start_img_plane_1);
	al_destroy_bitmap(start_img_plane_2);
	al_destroy_bitmap(start_img_plane_3);

	al_destroy_bitmap(start_img_enemy_1);
	al_destroy_bitmap(start_img_enemy_2);
	al_destroy_bitmap(start_img_enemy_3);

    al_destroy_bitmap(img_boss_1);
	al_destroy_bitmap(img_boss_2);

	al_destroy_bitmap(img_bullet_2);
	al_destroy_bitmap(img_bullet_3);

	for(i=0 ; i< IMAGE_LASER ; i++){
        al_destroy_bitmap(img_laser[i]);
	}

	for(i=0 ; i<IMAGE_EXPLODE ; i++){
        al_destroy_bitmap(img_explode[i]);
	}

	for(i=0 ; i<IMAGE_FIRE_PUSH ; i++){
        al_destroy_bitmap(img_fire_push[i]);
	}

	al_destroy_bitmap(img_first_enemy_bullet);
	al_destroy_bitmap(img_HP_drink);
	al_destroy_bitmap(img_ULT_drink);

	al_destroy_bitmap(img_boss2_laser);
	al_destroy_bitmap(img_enemy_bullet_2);
	al_destroy_bitmap(img_boss1_bullet);

}
