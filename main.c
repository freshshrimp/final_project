#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "SDL_basic.h"
#include "SDL_music.h"
#include "SDL_variable.h"
#include "SDL_home_menu.h"
#include "SDL_breeding_farm_menu.h"
#include "SDL_advisory_office_menu.h"
#include "SDL_ticket_office_menu.h"
#include "SDL_racingmenu.h"

#undef main //防止 SDLmain bug 產生

//全域變數
struct horse_data ** horse_data_array;
struct horse_data *horse;
int player_money = 4000, //玩家資產
    day, //遊戲進行到的天數 
    money, //玩家下注的金額
    selection_of_location = 0, //存取要傳送去哪個菜單的變數
    bet_number,///下注的賽馬編號
    win_horse;//跑第一名的賽馬編號

int main()
{
    //隨機參數的前處理
    time_t t; //為了讓rand()可以產生較隨機的數值，宣告一個 time_t 型別的變數 t，用於取得時間值以生成隨機數
    srand((unsigned)time(&t)); // 使用 time 函數取得當前時間的數值，轉換成 unsigned 類型後作為種子傳遞給 srand 函數，以初始化亂數發生器

    //初始化
    if(init() < 0)
    {
        return -1;
    }

    //撥放音樂
    //play_music("1.wav");

    //遊戲開始畫面
    draw_start_menu();

    //開始為期 30 天的賭馬遊戲
    for(day = 1; (day < 30) && (player_money >= 1000); day++)
    {
        //賽馬能力處理
        horse_data_array = (struct horse_data **)malloc(NUMBER_OF_HORSE * sizeof(struct horse_data *));//建立一個一維裝pointer的陣列，裡面裝的是struct horse_data 的 pointer
        random_horse_ability(); //設定每日的馬的數值

        //玩家菜單
        home_menu:
        draw_personal_menu(player_money, day);

        //離開玩家菜單前往其他場景
        if(selection_of_location == 1)
        {
            goto breeding_farm;
        }
        else if(selection_of_location == 2)
        {
            goto ticket_office;
        }
        else if(selection_of_location == 3)
        {
            goto advisory_office;
        }

        //場景
        breeding_farm://育馬場的菜單
        draw_breeding_farm_menu();
        goto home_menu;

        advisory_office://諮詢處的菜單
        draw_advisory_office_menu();
        goto home_menu;

        ticket_office://買馬券下注的菜單
        selection_of_location = draw_ticket_office_menu();
        if(selection_of_location == 0) goto home_menu;
        else if(selection_of_location == 1) goto racing_menu;

        racing_menu://賽馬比賽的菜單
        reset_racing_virable();
        win_horse = racing_event_loop(horse_data_array);
        goto checkout_menu;

        checkout_menu:
        SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
        SDL_RenderClear(rdr);//刷新屏幕
        SDL_RenderPresent(rdr);//顯示屏幕
        draw_text("結算", 40, 300, 10);
        if(bet_number == win_horse)
        {
            int bet_amount_list[4], total = 0;
            float odds_list[4];

            //計算下每匹馬的下注金額
            for(int i = 0; i < NUMBER_OF_HORSE; i++)
            {
                bet_amount_list[i] = (horse_data_array[i]->speed) * (horse_data_array[i]->attention_rank);
            }
            total = bet_amount_list[0] + bet_amount_list[1] + bet_amount_list[2] + bet_amount_list[3];

            //計算下每匹馬的賠率
            for(int i = 0; i < NUMBER_OF_HORSE; i++)
            {
                odds_list[i] = (float)total / bet_amount_list[i];
                odds_list[i] = round(odds_list[i] * 10) / 10;
            }

            char str[300];
            int num = money * odds_list[win_horse - 1];
            sprintf(str, "本日成績: +%d", num);//顯示賭贏的錢
            draw_text(str, 30, 300, 300);

            player_money = player_money + (money * odds_list[win_horse - 1]);//顯示玩家目前資產
            sprintf(str, "目前資產: %d", player_money);
            draw_text(str, 30, 300, 400);

            click_check();
        }
        else
        {
            char str[300];
            sprintf(str, "本日成績: -%d", money);//顯示賭輸的錢
            draw_text(str, 30, 300, 300);

            sprintf(str, "目前資產: %d", player_money);//顯示玩家目前金額
            draw_text(str, 30, 300, 400);

            click_check();
        }

    }
    
    //銷毀
    //deinit_music();
    deinit();

    return 0;
}