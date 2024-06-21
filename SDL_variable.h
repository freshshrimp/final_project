#ifndef SDL_VARIABLE_H
#define SDL_VARIABLE_H

#include <SDL2/SDL.h>

#define NUMBER_OF_HORSE 4 //賽馬數量
#define BASIC_ABILITY_OF_HORSE 500 //賽馬基礎數值

//全域變數
///////////////////////////////////////////////
extern SDL_Rect picture_rect_1;
extern SDL_Rect picture_rect_2;
extern SDL_Rect picture_rect_3;
extern SDL_Rect picture_rect_4;
extern SDL_Rect picture_rect_5;

extern int selection_of_location;
extern int player_money ; //玩家資產
extern int day; //遊戲進行到的天數 
extern int money; //玩家要下注的金額

//馬的能力
struct horse_data //遊戲中馬的能力值
{                           
    int speed; //馬的速度
    int stamina; //馬的耐力
    int telegent; //馬的智力
    int attention_rank; //馬的關注度排行 (關注度越高，排行較大)
    int fatigue_speed; //馬疲勞後的速度
    int racing_rank; //跑完後的排行
};

extern struct horse_data ** horse_data_array;
extern struct horse_data *horse;
extern int bet_number;
////////////////////////////////////////////////

#endif