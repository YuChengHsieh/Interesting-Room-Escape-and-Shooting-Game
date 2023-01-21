#include "global.h"
//--initialize font
ALLEGRO_FONT *font_12 = NULL;
ALLEGRO_FONT *font_18 = NULL;
ALLEGRO_FONT *font_36 = NULL;
ALLEGRO_FONT *font_60 = NULL;

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 1500;
const int HEIGHT = 900;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
//--keyboard
bool key_state[ALLEGRO_KEY_MAX] = {false};
// 1 is for left, 2 is for right, 3 is for middle.
bool *mouse_state;
// Mouse position.
int mouse_x, mouse_y;

bool judge_next_window = false;
int window = SCENE_MENU;
//--特例可以超出screen
bool special_case = false;
//--draw_code 0 --> first scene ,1 --> sceond scene
bool code = 0;

double now;

int i,j,k;

// the state of main character
Character main_chara;
Character guard;

//--記住所有背景的指標
ALLEGRO_BITMAP* first_game_bg_ptr[10];
//--記住background的寬跟高
Background first_game_bg[10];


//-- living room scene 1--> kitchen , 2--> bathroom ,3 --> intro , 4 --> passsword
int livingroom_scene = 0;
//-- living room scene 1--> livingroom , 2--> underground
int bathroom_scene = 0;


//--the UFO components
const int UFO_NUM = 3;
Object UFO_component[UFO_NUM];
int UFO_count = 0;

Object paste;
int paste_count = 0;

const float CHANGE_HEAD_COOLDOWN = 1.0f;
//--轉換圖片的時間要大於1.5秒
const float START_ANIMATION_LASTTIME = 8.5f;
const float SECOND_START_UP_ANIMATION_LASTTIME = 3.0f;
const float SECOND_START_DOWN_ANIMATION_LASTTIME = 2.0f;
const float WALK_CHANGE_FOOT_COOLDOWN = 0.5f;
const float GET_UFO_COMPONENT_COOLDOWN = 1.0f;
const float PASSWORD_INSERT_COOLDOWN = 0.2f;
const float GET_ANIMATION_LASTTIME = 6.0f;
const float GET_UFO_LASTTIME = 6.0f;
const float GUARD_ATK_COOLDOWN = 3.0f;
const float GUARD_ATK_CONT_COOLDOWN = 0.5f;
const float BETWEEN_TWO_SPACE_COOLDOWN = 0.5f;
const float NOT_ENOUGH_UFO_ANIMATION_LASTTIME = 3.0f;
const float TREASURE_APPEAR_INTERVAL = 0.1f;

//--
double last_change_head_time = 0;
double start_animation_time = 0;
double sec_start_down_animation_time = 0;
double sec_start_up_animation_time = 0;
double last_change_foot_time = 0;
double last_get_UFO_component_time = 0;
double last_password_insert_time = 0;
double last_get_animation_time = 0;
double last_get_sound_time = 0;
double last_guard_atk_time_1 = 0;
double last_guard_atk_time_2 = 0;
double last_guard_stop_time = 0;
double last_push_space_time = 0;
double last_open_UFO_attempt_time = 0;
double last_treasure_appear_time = 0;

bool change_head = false;
//--坐下來
bool sit_count = false;
//--一開始掉下來的動畫
bool start_ani = false;
bool hide_char = true;
//--組完飛碟要飛上去動畫
bool sec_start_ani_down = false;
bool sec_start_ani_up = false;
//--看有沒有在bitmap裡
bool change_step = false;
bool in_UFO = false;
bool in_password = false;
bool in_dog = false;
bool dog_smile = false;
bool in_toilet = false;
bool in_chicken = false;
bool in_treasure_map = false;
bool treasure_get = false;
bool take_chicken = false;
//--true if attempt to open UFO
bool open_UFO_attempt = false;
//--true if get first paste
bool get_first_paste = false;
//--
bool get_intro_paste = false;
bool get_livingroom_paste = false;
bool get_kitchen_paste = false;
bool get_bathroom_paste = false;
bool get_underground_paste = false;
//--treasure map
bool read_treasure_map = false;
bool treasure_appear = false;
bool treasure_ani_done = false;


//--guard
bool in_atk_1 = false;
bool in_atk_2 = false;
//--password
//-- 0~9 for 0~9 , 10 for delete , 11 for ok
bool password_insert[12] = {false};
//--密碼鍵的長寬
const int password_W = 150;
const int password_H = 100;
const int password_loc_x[3] = {566,747,920};
const int password_loc_y[3] = {581,448,315};
const int star_position[4] = {544,676,800,924};
//--密碼輸入
const char password[] = "1396";
char password_in[5] = "\0";
int password_cursor = 0;
//--密碼破解 true -- success , false -- failure
bool password_done = false;

//--underground bitmap height
int underground_bitmap_height;

//--拿到UFO零件動畫
bool UFO_get_animation_and_sound = false;
bool paste_get_animation_and_sound = false;

//--
//Animation in_tube_ani[IMAGE_IN_TUBE];
double img_in_tube_last_time = 0;
int img_bathroom_tube_count = -1;
int img_underground_tube_count = -1;
int img_treasure_count = IMAGE_TREASURE-1;
bool in_tube = false;
bool go_out_tube = false;
bool go_into_tube = false;
int down_flag;
int up_flag;

//--finish first game
bool open_UFO = false;
bool first_game_done = false;
bool first_game_bonus = false;



//---------second  game---------//

//--background velocity
const int background_velocity = 5;
//--remember background y-coordinate
int background_position = 0;
//--1 for enemy_1,2 for enemy_2,3 for enemy_3
int enemy_code = 1;
//----1 for plane_1,2 for plane_2,3 for plane_3
int plane_code =1;

//--if ultimate = true, then plane is in ultimate
bool ultimate = false;
//--if laser is true, then plane_3 use laser rather than bullets
bool laser_appearance = false;
//-- if shield is true, call shield
bool shield_appearance = false;
//--true if all enemies were defeated
bool generate_enemies = false;
//--true if in clear
bool invincible = false;
//--true if all enemy defeated
bool enemy_hidden = false;
//--true if you are dead
bool dead = false;
//--true if first game -> second game
bool first_change_to_second = true;

MovableObject plane;
MovableObject small_plane[MAX_SMALL_PLANE];
MovableObject first_enemies[MAX_ENEMY];
MovableObject second_enemies[MAX_ENEMY];
MovableObject bullets[MAX_BULLET];
MovableObject small_bullets[MAX_SMALL_PLANE][MAX_BULLET];
MovableObject ultimate_bullets[MAX_BULLET];
MovableObject first_enemies_bullets[MAX_ENEMY][MAX_FIRST_ENEMY_BULLET];
MovableObject second_enemies_bullets[MAX_ENEMY][MAX_SECOND_ENEMY_BULLET];
MovableObject HP_drink;
MovableObject ULT_drink;

const float CHANGE_TIME_COOLDOWN = 1.5f;
const float MAX_COOLDOWN = 0.5f;
const float LASER_LAST_TIME = 0.8f;//--only for plane_3 ultimate
const float SMALL_BULLET_MAX_COOLDOWN = 0.8f;
const float ENEMY_MAX_COOLDOWN = 2.5f;
const float BULLET_HIT_ENEMY_INTERVAL = 0.5f;
const float BULLET_HIT_PLANE_INTERVAL = 0.5f;
const float ENEMY_CLASH_PLANE_INTERVAL = 1;
const float GAME_DRAW_TEXT_LAST_TIME = 3;
const float ULTIMATE_LAST_TIME = 6;
const float ENEMY_APPEARANCE_COOLDOWN = 1;
//--invincible time
const float INVINCIBLE_COOLDOWN = 1.5f;
const float INVINCIBLE_PLANE_DRAW_COOLDOWN = 0.1f;

//--轉換場景時間
double first_change_to_second_time = 0;
double last_plane_shoot_timestamp = 0;
double last_plane_shoot_laser_timestamp = 0;//--only for plane_3 ultimate
double last_small_plane_shoot_timestamp = 0;
double last_bullet_hit_enemy_timestamp = 0;
double last_first_enemy_shoot_timestamp = 0;
double last_second_enemy_shoot_timestamp = 0;
double last_bullet_hit_plane_timestamp = 0;
double last_enemy_clash_plane_timestamp = 0;
double last_text_time = 0;
double ultimate_trigger_time = 0;
double all_eneimes_defeated_time = 0;
double last_invincible_time = 0;
double last_invincible_plane_draw_time = 0;

//--start -> boss
bool start_to_boss = false;
//--true draw plane
bool plane_draw_key = true;

//--avoid first time
bool draw_count = false;
//--true if all enemies are defeated
bool enemy_clear = false;
//--small plane appear
bool small_plane_appear = true;

Animation first_explode[MAX_ENEMY];
Animation second_explode[MAX_ENEMY];
Animation mine[MAX_MINE];
Animation laser;
Animation boss_explode[MAX_BOSS_2];
Animation boss1_ultimate_ani;


float img_shield_w,img_shield_h;

int score = 0;
int highest_score = 0;


//--boss scene
#define MAX_BOSS_2 2
MovableObject boss1;
MovableObject boss2[MAX_BOSS_2];
MovableObject boss1_bullets[MAX_BOSS_ENEMY_BULLET];
MovableObject boss1_mine[MAX_MINE];
MovableObject boss_laser[MAX_BOSS_LASER];
MovableObject boss2_bullets[MAX_FIRST_ENEMY_BULLET];
MovableObject boss1_ultimate;

//--一開始進場的時候不攻擊
const float BOSS_COOLDOWN = 3.0f;
const float BOSS2_LASER_MAX_COOLDOWN = 4.5f;
const float BOSS1_BULLET_INTERVAL = 0.2f;
const float BOSS1_BULLET_MAX_COOLDOWN = 3.5f;
const float BOSS1_WARNING_COOLDOWN = 2.0f;
const float BOSS1_MINE_COOLDOWN = 8.0f;
const float BOSS2_BULLET_MAX_COOLDOWN = 3.5f;
const float BOSSLASER_HIT_PLANE_INTERVAL = 1.5f;
const float BOSS_BULLET_HIT_PLANE_INTERVAL = 2.5f;
const float BOSS1_LAUNCH_ULTIMATE_INTERVAL = 10.0f;
const float HP_DRINK_APPEARANCE_INTERVAL = 15.0f;

double first_in_boss_scene_time = 0;
double last_boss2_shoot_laser_timestamp = 0;
double last_boss1_shoot_time = 0;
double last_boss1_shoot_bullet_timestamp = 0;
double last_boss1_warning_time = 0;
double last_boss1_mine_time = 0;
double last_boss2_shoot_bullet_timestamp = 0;
double last_laser_hit_plane_timestamp = 0;
double last_boss1_bullet_hit_plane_timestamp = 0;
double last_boss2_bullet_hit_plane_timestamp = 0;
double last_boss2_clash_plane_timestamp = 0;
double last_boss1_clash_plane_timestamp = 0;
double last_boss1_launch_ultimate_timestamp = 0;
double last_HP_drink_appearance_timestamp = 0;

//--true if boss_2_1 stop
bool boss_2_1_stop = false;
bool boss_2_2_stop = false;
//--true if changed music
bool chg_music = false;

//--enemy number and position
int FIRST_ENEMY;//---改
int SECOND_ENEMY;
//--first enemy init
int first_enemy_x[ENEMY_X] = {-300,WIDTH+300};
int first_enemy_y[ENEMY_Y] = {HEIGHT/4,HEIGHT/2,-300};
float init_first_enemy_vx[ENEMY_X] = {3,-3};
float init_first_enemy_vy[ENEMY_Y] = {0,0,2};
//--second enemy init
int second_enemy_x[ENEMY_X] = {WIDTH/4,3*WIDTH/4};
int second_enemy_y[ENEMY_Y] = {-300,HEIGHT+300,-300};
float init_second_enemy_vy[ENEMY_Y] = {2,-2};
//--一開始敵人等一下再進場
const float ENEMY_APPEAR_COOLDOWN = 5.0f;
const float IMAGE_EXPLODE_COOLDOWN = 0.1f;
const float IMAGE_MINE_COOLDOWN = 0.1f;
const float IMAGE_FIRE_PUSH_COOLDOWN = 0.1f;
const float IMAGE_LASER_COOLDOWN = 0.1f;
const float IMAGE_ELECTRIC_COOLDOWN = 0.1f;
const float IMAGE_SHIELD_COOLDOWN = 0.1f;
const float IMAGE_BOSS1_ULTIMATE_COOLDOWN = 0.1f;


double start_time = 0;
double first_img_explode_last_time[MAX_ENEMY] = {0};
double second_img_explode_last_time[MAX_ENEMY] = {0};
double img_mine_last_time = 0;
double img_fire_push_last_time = 0;
double img_laser_last_time = 0;
double img_electric_last_time = 0;
double img_shield_last_time = 0;
double img_boss1_ultimate_last_time = 0;

int first_img_explode_count[MAX_ENEMY];
int second_img_explode_count[MAX_ENEMY];
int img_mine_count = -1;
int img_fire_push_count = -1;
int img_laser_count = -1;
int img_electric_count = -1;
int img_shield_count = -1;
int img_boss1_ultimate_count = -1;

//--laser true if end laser animation
bool laser_animation = false;
//-- 0 cooldown 1 warning 2 mine
int warning_cooldown = 0;
//--true hit by mine
bool hit_by_mine = false;

//--boss scene
int boss_bullet_count = 0;
int boss_bullet_mode = 0;
int sign = 1;
int mine_pos_y[MAX_MINE/2] = {0};

//--restart
bool restart = false;

//--draw movable object
void draw_movable_object(MovableObject obj) {
	if (obj.hidden) return;
	al_draw_bitmap(obj.img, round(obj.x - obj.w / 2), round(obj.y - obj.h / 2), 0);
}

void plane_draw_movable_object(MovableObject obj) {
	if (obj.hidden) return;
	if(ultimate) al_draw_bitmap(obj.img_ult, round(obj.x - obj.w / 2), round(obj.y - obj.h / 2), 0);
	else al_draw_bitmap(obj.img, round(obj.x - obj.w / 2), round(obj.y - obj.h / 2), 0);
}

//--judge the collision of two object
bool pnt_in_rect(int px, int py, int x, int y, int w, int h) {
//--determine little object collision and mouse
	if( px >= x-w/2 && px <= x+w/2 && py >= y-h/2 && py <= y+h/2 )
	return true ;
	else return false;
}

//--judge the collision of two object

bool rect_in_rect(int x1, int y1,int w1,int h1,int x2, int y2, int w2, int h2) {
//--determine whether plane clash enemy
    int sensitive = 30;
    if(
       (x1 >= x2-w2/2 + sensitive && x1 <= x2+w2/2 - sensitive  && y1 >= y2-h2/2-h1/2 + sensitive && y1 <= y2+h2/2-h1/2 - sensitive) ||
       (x1 >= x2-w2/2 + sensitive && x1 <= x2+w2/2 - sensitive  && y1 >= y2-h2/2+h1/2 + sensitive && y1 <= y2+h2/2+h1/2 - sensitive) ||
       (x1 >= x2-w2/2+w1/2 + sensitive && x1 <= x2+w2/2+w1/2 - sensitive && y1 >= y2-h2/2 + sensitive && y1 <= y2+h2/2 - sensitive ) ||
       (x1 >= x2-w2/2-w1/2 + sensitive && x1 <= x2+w2/2-w1/2 - sensitive && y1 >= y2-h2/2 + sensitive && y1 <= y2+h2/2 - sensitive ) )
	return true ;
	else return false;
}


//--laser hit enemy
bool determine_laser_hit_enemy(int x1,int w1,int x2,int w2){
    if( x1 <= x2+w2 && x1 >= x2-w2 ){
        //printf("determine_laser_hit_enemy\n");
        w1 = w1;
        return true;
    }
    else return false;

}

//--for debugging
void game_abort(const char* format, ...) {
	va_list arg;
	va_start(arg, format);
	game_vlog(format, arg);
	va_end(arg);
	fprintf(stderr, "error occured, exiting after 2 secs");
	// Wait 2 secs before exiting.
	al_rest(2);
	// Force exit program.
	exit(1);
}

void game_log(const char* format, ...) {
	va_list arg;
	va_start(arg, format);
	game_vlog(format, arg);
	va_end(arg);
}

void game_vlog(const char* format, va_list arg) {
	static bool clear_file = true;
	vprintf(format, arg);
	printf("\n");
	// Write log to file for later debugging.
	FILE* pFile = fopen("log.txt", clear_file ? "w" : "a");
	if (pFile) {
		vfprintf(pFile, format, arg);
		fprintf(pFile, "\n");
		fclose(pFile);
	}
	clear_file = false;
}

