
#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#define GAME_TERMINATE -1
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "algif.h"
#include <math.h>
#include <string.h>
//--initialize font
extern ALLEGRO_FONT *font_12;
extern ALLEGRO_FONT *font_18;
extern ALLEGRO_FONT *font_36;
extern ALLEGRO_FONT *font_60;

// note that you can't assign initial value here!
extern const float FPS;
extern const int WIDTH;
extern const int HEIGHT;
extern bool key_state[ALLEGRO_KEY_MAX];
extern bool *mouse_state;
extern int mouse_x, mouse_y;
extern bool judge_next_window;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *fps;
extern int window;
//--特例可以超出screen
extern bool special_case;
//--draw_code 0 --> first scene ,1 --> sceond scene
extern bool code;

extern double now;
extern int i,j,k;

//--scene
enum{
    SCENE_MENU = 1,
    SCENE_FIRST_GAME_INTRO = 2,
    SCENE_FIRST_GAME_LIVINGROOM = 3,
    SCENE_FIRST_GAME_KITCHEN = 4,
    SCENE_FIRST_GAME_BATHROOM = 5,
    SCENE_FIRST_GAME_PASSWORD = 6,
    SCENE_FIRST_GAME_UNDERGROUND = 7,
    SCENE_FIRST_GAME_TREASURE_MAP = 8,

    //---------second  game---------//
    SCENE_SECOND_GAME_START = 9,
	SCENE_SECOND_GAME_GAMEOVER = 10,
	SCENE_SECOND_GAME_RESTART = 11,
    SCENE_SECOND_GAME_EXIT = 12,
    SCENE_SECOND_GAME_BOSS = 13,
    SCENE_SECOND_GAME_VICTORY = 14,
    SCENE_SECOND_GAMESETTINGS = 15,
};

// the state of main character
enum {STOP = 0, MOVE};
typedef struct character
{
    int x, y; // the position of image
    int w, h; // the width and height of image
    bool dir; // left: false, right: true
    int state; // the state of character
    ALLEGRO_BITMAP *img_UFO;
    ALLEGRO_BITMAP *img_atk[2];
    ALLEGRO_BITMAP *img_move[2];
    ALLEGRO_BITMAP *img_sit[2];
    ALLEGRO_BITMAP *img_dir[2];
    ALLEGRO_BITMAP *img_take_chicken_move[2];
    ALLEGRO_BITMAP *img_take_chicken_dir[2];
    int anime; // counting the time of animation
    int anime_time; // indicate how long the animation
}Character;
extern Character main_chara;
extern Character guard;

typedef struct object{
    int x,y;
    int w,h;
    ALLEGRO_BITMAP *img;
    int window;
    bool get;
}Object;

typedef struct background{
    int w,h;
}Background;

//--記住所有背景的指標
extern ALLEGRO_BITMAP* first_game_bg_ptr[10];
//--記住background的寬跟高
extern Background first_game_bg[10];
//-- living room scene 1--> kitchen , 2--> bathroom ,3 --> intro , 4 --> passsword
extern int livingroom_scene;
//-- living room scene 1--> livingroom , 2--> underground
extern int bathroom_scene;

extern Object UFO_component[];
extern const int UFO_NUM;
extern int UFO_count;

extern Object paste;
extern int paste_count;
//--
extern const float CHANGE_HEAD_COOLDOWN;
extern const float START_ANIMATION_LASTTIME;
extern const float SECOND_START_UP_ANIMATION_LASTTIME;
extern const float SECOND_START_DOWN_ANIMATION_LASTTIME;
extern const float WALK_CHANGE_FOOT_COOLDOWN;
extern const float GET_UFO_COMPONENT_COOLDOWN;
extern const float PASSWORD_INSERT_COOLDOWN;
extern const float GET_ANIMATION_LASTTIME;
extern const float GET_UFO_LASTTIME;
extern const float GUARD_ATK_COOLDOWN;
extern const float GUARD_ATK_CONT_COOLDOWN;
extern const float BETWEEN_TWO_SPACE_COOLDOWN;
extern const float NOT_ENOUGH_UFO_ANIMATION_LASTTIME;
extern const float TREASURE_APPEAR_INTERVAL;
//--
extern double last_change_head_time;
extern double start_animation_time;
extern double sec_start_down_animation_time;
extern double sec_start_up_animation_time;
extern double last_change_foot_time;
extern double last_get_UFO_component_time;
extern double last_password_insert_time;
extern double last_get_animation_time;
extern double last_get_sound_time;
extern double last_guard_atk_time_1;
extern double last_guard_atk_time_2;
extern double last_guard_stop_time;
extern double last_push_space_time;
extern double last_open_UFO_attempt_time;
extern double last_treasure_appear_time;

extern bool change_head;
extern bool sit_count;
extern bool start_ani;
extern bool hide_char;
extern bool sec_start_ani_down;
extern bool sec_start_ani_up;
extern bool change_step;
extern bool in_UFO;
extern bool in_password;
extern bool in_dog;
extern bool dog_smile;
extern bool in_toilet;
extern bool in_chicken;
extern bool in_treasure_map;
extern bool treasure_get;
extern bool take_chicken;
extern bool open_UFO_attempt;
extern bool get_first_paste;
extern bool get_intro_paste;
extern bool get_livingroom_paste;
extern bool get_kitchen_paste;
extern bool get_bathroom_paste;
extern bool get_underground_paste;
//--treasure map
extern bool read_treasure_map;
extern bool treasure_appear;
extern bool treasure_ani_done;

//--guard
extern bool in_atk_1;
extern bool in_atk_2;

//--password
//-- 0~9 for 0~9 , 10 for delete , 11 for ok
extern bool password_insert[12];
//--密碼鍵的長寬
extern const int password_W;
extern const int password_H;
extern const int password_loc_x[];
extern const int password_loc_y[];
extern const int star_position[];
//--密碼輸入
extern const char password [];
extern char password_in[];
extern int password_cursor;
//--密碼破解 true -- success , false -- failure
extern bool password_done;

//--underground bitmap height
extern int underground_bitmap_height;

//--拿到UFO零件動畫
extern bool UFO_get_animation_and_sound;
extern bool paste_get_animation_and_sound;

#define IMAGE_BATHROOM_TUBE 16
#define IMAGE_UNDERGROUND_TUBE 19
#define IMAGE_TREASURE 11
//extern Animation in_tube_ani[IMAGE_IN_TUBE];
extern double img_in_tube_last_time;
extern int img_bathroom_tube_count;
extern int img_underground_tube_count;
extern int img_treasure_count;
extern bool in_tube;
extern bool tube_draw;
extern bool go_into_tube;
extern bool go_out_tube;
extern int down_flag;
extern int up_flag;


//--finish first game
extern bool open_UFO;
extern bool first_game_done;
extern bool first_game_bonus;

//---------second  game---------//
#define MAX_SMALL_PLANE 2
#define MAX_ENEMY 6
#define MAX_BULLET 5
#define MAX_FIRST_ENEMY_BULLET 4
#define MAX_SECOND_ENEMY_BULLET 12
#define MAX_BOSS_ENEMY_BULLET 10
#define MAX_MINE 12
#define IMAGE_EXPLODE 9
#define IMAGE_MINE 12
#define IMAGE_FIRE_PUSH 6
#define IMAGE_LASER 7
#define IMAGE_ELECTRIC 13
#define IMAGE_SHIELD 18
#define IMAGE_BOSS1_ULTIMATE 10

//--movable object
typedef struct {
	float x, y;
	float w, h;
	float vx, vy;
	float init_vx,init_vy;
	int HP;
	int MAX_HP;
	float ULT;
	float MAX_ULT;
	bool hidden;//--true : not draw, false : draw
	ALLEGRO_BITMAP* img;
	ALLEGRO_BITMAP* img_ult;
} MovableObject;

//--animation
typedef struct {
	bool hidden;//--true : not draw, false : draw
	// The pointer to the object¡¦s image.
	ALLEGRO_BITMAP* img[10];
	float x, y;
	float w, h;
	int HP;
} Animation;

//--background velocity
extern const int background_velocity;
//--remember background y-coordinate
extern int background_position;
//--1 for enemy_1,2 for enemy_2,3 for enemy_3
extern int enemy_code;
//----1 for plane_1,2 for plane_2,3 for plane_3
extern int plane_code;

//--if ultimate = true, then plane is in ultimate
extern bool ultimate;
//--if laser is true, then plane_3 use laser rather than bullets
extern bool laser_appearance;
//-- if shield is true, call shield
extern bool shield_appearance;
//--true if all enemies were defeated
extern bool generate_enemies;
//--true if in clear
extern bool invincible;
//--true if all enemy defeated
extern bool enemy_hidden;
//--true if you are dead
extern bool dead;
extern bool first_change_to_second;

extern MovableObject plane;
extern MovableObject small_plane[MAX_SMALL_PLANE];
extern MovableObject first_enemies[MAX_ENEMY];
extern MovableObject second_enemies[MAX_ENEMY];
extern MovableObject bullets[MAX_BULLET];
extern MovableObject small_bullets[MAX_SMALL_PLANE][MAX_BULLET];
extern MovableObject first_enemies_bullets[MAX_ENEMY][MAX_FIRST_ENEMY_BULLET];
extern MovableObject second_enemies_bullets[MAX_ENEMY][MAX_SECOND_ENEMY_BULLET];
extern MovableObject HP_drink;
extern MovableObject ULT_drink;

extern const float CHANGE_TIME_COOLDOWN;
extern const float MAX_COOLDOWN;
extern const float LASER_LAST_TIME;//--only for plane_3 ultimate
extern const float SMALL_BULLET_MAX_COOLDOWN;
extern const float ENEMY_MAX_COOLDOWN;
extern const float BULLET_HIT_ENEMY_INTERVAL;
extern const float BULLET_HIT_PLANE_INTERVAL;
extern const float ENEMY_CLASH_PLANE_INTERVAL;
extern const float GAME_DRAW_TEXT_LAST_TIME;
extern const float ULTIMATE_LAST_TIME;
extern const float ENEMY_APPEARANCE_COOLDOWN;
//--invincible time
extern const float INVINCIBLE_COOLDOWN;
extern const float INVINCIBLE_PLANE_DRAW_COOLDOWN;

extern double first_change_to_second_time;
extern double last_plane_shoot_timestamp;
extern double last_plane_shoot_laser_timestamp;//--only for plane_3 ultimate
extern double last_small_plane_shoot_timestamp;
extern double last_bullet_hit_enemy_timestamp;
extern double last_first_enemy_shoot_timestamp;
extern double last_second_enemy_shoot_timestamp;
extern double last_bullet_hit_plane_timestamp;
extern double last_enemy_clash_plane_timestamp;
extern double last_text_time;
extern double text_time;
extern double ultimate_trigger_time;
extern double all_eneimes_defeated_time;
extern double last_invincible_time;
extern double last_invincible_plane_draw_time;

//--start -> boss
extern bool start_to_boss;
//--true draw plane
extern bool plane_draw_key;

//--avoid first time
extern bool draw_count;
//--true if all enemies are defeated
extern bool enemy_clear;

extern bool small_plane_appear;

extern Animation first_explode[MAX_ENEMY];
extern Animation second_explode[MAX_ENEMY];
extern Animation laser;
extern Animation boss1_ultimate_ani;

extern float img_shield_w,img_shield_h;

extern int score;
extern int highest_score;

//--boss scene
#define MAX_BOSS_2 2
#define MAX_BOSS_LASER 3
extern MovableObject boss1;
extern MovableObject boss2[MAX_BOSS_2];
extern MovableObject boss1_bullets[MAX_BOSS_ENEMY_BULLET];
extern MovableObject boss1_mine[MAX_MINE];
extern MovableObject boss_laser[MAX_BOSS_LASER];
extern MovableObject boss2_bullets[MAX_FIRST_ENEMY_BULLET];
extern MovableObject boss1_ultimate;

extern const float BOSS_COOLDOWN;
extern const float BOSS2_LASER_MAX_COOLDOWN;
extern const float BOSS1_BULLET_INTERVAL;
extern const float BOSS1_BULLET_MAX_COOLDOWN;
extern const float BOSS1_WARNING_COOLDOWN;
extern const float BOSS1_MINE_COOLDOWN;
extern const float BOSS2_BULLET_MAX_COOLDOWN;
extern const float BOSSLASER_HIT_PLANE_INTERVAL;
extern const float BOSS_BULLET_HIT_PLANE_INTERVAL;
extern const float BOSS1_LAUNCH_ULTIMATE_INTERVAL;
extern const float HP_DRINK_APPEARANCE_INTERVAL;

extern double first_in_boss_scene_time;
extern double last_boss2_shoot_laser_timestamp;
extern double last_boss1_shoot_time;
extern double last_boss1_shoot_bullet_timestamp;
extern double last_boss1_warning_time;
extern double last_boss1_mine_time;
extern double last_boss2_shoot_bullet_timestamp;
extern double last_laser_hit_plane_timestamp;
extern double last_boss1_bullet_hit_plane_timestamp;
extern double last_boss2_bullet_hit_plane_timestamp;
extern double last_boss2_clash_plane_timestamp;
extern double last_boss1_clash_plane_timestamp;
extern double last_boss1_launch_ultimate_timestamp;
extern double last_HP_drink_appearance_timestamp;

//--true if boss_2_1 stop
extern bool boss_2_1_stop;
extern bool boss_2_2_stop;
//--true if changed music
extern bool chg_music;

extern Animation boss_explode[MAX_BOSS_2];


//--enemy number and position
#define ENEMY_X 2
#define ENEMY_Y 3
extern int FIRST_ENEMY;
extern int SECOND_ENEMY;

extern int first_enemy_x[ENEMY_X];
extern int first_enemy_y[ENEMY_Y];
extern float init_first_enemy_vx[ENEMY_X];
extern float init_first_enemy_vy[ENEMY_Y];

extern int second_enemy_x[ENEMY_X];
extern int second_enemy_y[ENEMY_Y];
extern float init_second_enemy_vy[ENEMY_Y];

//--一開始敵人等一下再進場
extern const float ENEMY_APPEAR_COOLDOWN;

extern const float IMAGE_EXPLODE_COOLDOWN;
extern const float IMAGE_MINE_COOLDOWN;
extern const float IMAGE_FIRE_PUSH_COOLDOWN;
extern const float IMAGE_LASER_COOLDOWN;
extern const float IMAGE_ELECTRIC_COOLDOWN;
extern const float IMAGE_SHIELD_COOLDOWN;
extern const float IMAGE_BOSS1_ULTIMATE_COOLDOWN;

extern double start_time;
extern double first_img_explode_last_time[MAX_ENEMY];
extern double second_img_explode_last_time[MAX_ENEMY];
extern double img_mine_last_time;
extern double img_fire_push_last_time;
extern double img_laser_last_time;
extern double img_electric_last_time;
extern double img_shield_last_time;
extern double img_boss1_ultimate_last_time;


extern int first_img_explode_count[MAX_ENEMY];
extern int second_img_explode_count[MAX_ENEMY];
extern int img_mine_count;
extern int img_fire_push_count;
extern int img_laser_count;
extern int img_electric_count;
extern int img_shield_count;
extern int img_boss1_ultimate_count;

//--laser true if end laser animation
extern bool laser_animation;
//-- 0 cooldown 1 warning 2 mine
extern int warning_cooldown;
//--true hit by mine
extern bool hit_by_mine;

//--boss scene
extern int boss_bullet_count;
extern int boss_bullet_mode;
extern int sign;
extern int mine_pos_y[MAX_MINE/2];

//--restart
extern bool restart;

extern void draw_movable_object(MovableObject obj);
extern void plane_draw_movable_object(MovableObject obj);
//--judge the collision of two object
extern bool pnt_in_rect(int px, int py, int x, int y, int w, int h);
extern bool rect_in_rect(int x1, int y1,int w1,int h1,int x2, int y2, int w2, int h2);
extern bool determine_laser_hit_enemy(int x1,int w1,int x2,int w2);

//--for debugging
extern void game_abort(const char* format, ...);
extern void game_log(const char* format, ...);
extern void game_vlog(const char* format, va_list arg);

#endif

