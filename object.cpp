#include "object.h"
#include "scene.h"

//ALLEGRO_FONT *font_36 = NULL;

ALLEGRO_BITMAP* UFO_component_pic;
ALLEGRO_BITMAP* paste_pic;

//---------second  game---------//


void object_init(){

    font_36 = al_load_ttf_font("./font/pirulen.ttf",36,0);
    if(!font_36)
        game_abort("failed to load font: pirulen.ttf with size 36");

    UFO_component_pic = al_load_bitmap("./image/tool_1.png");
    if (!UFO_component_pic)
		game_abort("failed to load image: UFO_component_pic");

    paste_pic = al_load_bitmap("./image/main_char_paste.png");
    if (!paste_pic)
		game_abort("failed to load image: paste_pic");

    //--place
    for(int i=0 ; i<UFO_NUM ; i++){
        UFO_component[i].img = UFO_component_pic;
        UFO_component[i].w = al_get_bitmap_width(UFO_component_pic);
        UFO_component[i].h = al_get_bitmap_height(UFO_component_pic);
    }

    paste.img = paste_pic;
    paste.w = al_get_bitmap_width(paste.img);
    paste.h = al_get_bitmap_height(paste.img);

}

void UFO_get(){
    UFO_count++;
    UFO_get_animation_and_sound = true;
    last_get_animation_time = al_get_time();
}

void paste_get(){
    paste_count++;
    if(!get_first_paste) get_first_paste = true;
    paste_get_animation_and_sound = true;
    last_get_animation_time = al_get_time();
}

void password_validation(){
    for(int i=0 ; i<10 ; i++){
        if(password_insert[i] && password_cursor < 4){
            char tmp = char(i+48);
            printf("%c\n",tmp);
            password_in[password_cursor] = tmp;
            password_cursor++;
        }
    }
    if(password_insert[10] && password_cursor > 0){
        password_cursor--;
        password_in[password_cursor] = '\0';
    }
    if(password_insert[11] && password_cursor == 4){

        if(strncmp(password_in,password,4) == 0){
            //printf("*");
            password_done = true;
            UFO_get();
        }
        else{
            //printf("string compare : %d\n",strncmp(password_in,password,4));
            password_done = false;
        }
    }
    printf("password insert : %s\n",password_in);
    //printf("password : %s\n",password);
}

//--在螢幕最左上角顯示飛碟零件找到之數量
void UFO_count_draw(){
    al_draw_bitmap(UFO_component_pic,0,40,0);
    al_draw_textf(font_36, al_map_rgb(0,0,0),UFO_component[0].w-10,UFO_component[0].h/2+20,0," : %d/3",UFO_count);
}

void paste_count_draw(){
    al_draw_bitmap(paste_pic,0,120,0);
    al_draw_textf(font_36, al_map_rgb(0,0,0),paste.w-10,100+paste.h/2,0," : %d/5",paste_count);
}


void object_draw(){
    for(int i=0 ; i<UFO_NUM ; i++){
        //printf("%d %d\n",window,UFO_component[i].window);
        if(window == UFO_component[i].window && !UFO_component[i].get){//--還沒有拿到
            //printf("draw %d %d\n",i,UFO_component[i].get);
            al_draw_bitmap(UFO_component[i].img,UFO_component[i].x,UFO_component[i].y,0);
        }
    }
}

void object_destroy(){
    al_destroy_bitmap(UFO_component_pic);
}

//---------second  game---------//
