#include "SDL_home_menu.h"

int draw_start_menu() //繪製玩家菜單
{
    //顯示遊戲封面
    SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
    SDL_RenderClear(rdr);//刷新屏幕
    SDL_RenderPresent(rdr);//顯示屏幕
    draw_picture("img_game_cover.bmp", 0, 0, &picture_rect_1);
    draw_text("HORSE", 50, 25, 10);
    draw_text("BETTING", 50, 25, 70);

    //繪製遊戲開始按鈕
    draw_picture("img_botton.bmp", 300, 500, &picture_rect_1);
    draw_text("START!", 24, 355, 505);

    //點下開始按鈕開始遊戲
    click_botton_event(picture_rect_1);

    return 0;
}

int draw_personal_menu(int player_money, int day) //繪製遊戲開始菜單
{
    while(1)
    {
        //顯示背景
        SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
        SDL_RenderClear(rdr);//刷新屏幕
        SDL_RenderPresent(rdr);//顯示屏幕
        draw_picture("img_player_house.bmp", 0, 0, &picture_rect_1);

        //顯示玩家的資產
        char str[300]; // 儲存結果的字串
        sprintf(str, "資產： %d", player_money);
        draw_text(str, 30, 15, 5);

        //顯示今天是第幾天
        sprintf(str, "DAY: %d", day);
        draw_text(str, 48, 620, 5);

        //顯示玩家圖片
        draw_picture("img_player_1.bmp", 260, 150, &picture_rect_1);

        //前往其他場景的按鈕
        draw_picture("img_botton.bmp", 550, 500, &picture_rect_1);
        draw_text("離開", 24, 615, 505);

        //查看成就的按鈕
        draw_picture("img_botton.bmp", 100, 500, &picture_rect_2);
        draw_text("成就", 24, 165, 505);

        //判斷使否點下按鈕
        int botton_selection = 0;
        personal_menu_click_event(&botton_selection, picture_rect_1,picture_rect_2);
        if (botton_selection == 1)//選擇要去的場景
        {
            position_transport_menu(&botton_selection, picture_rect_1, picture_rect_2, picture_rect_3, picture_rect_4, &selection_of_location);
            if((selection_of_location > 0) && (selection_of_location < 4))
            {
                return 0;
            }
        }
        else if(botton_selection == 2)//前往成就頁面
        {
            //顯示背景
            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
            SDL_RenderClear(rdr);//刷新屏幕
            SDL_RenderPresent(rdr);//顯示屏幕
            draw_text("成就頁面", 30, 340, 10);

            //顯示返回建
            draw_picture("img_cross.bmp", 750, 5, &picture_rect_1);

            //顯示獎盃
            draw_picture("img_cabinet_1.bmp", 13, 70, &picture_rect_2);
            draw_picture("img_platinum_trophy_1.bmp", 75, 175, &picture_rect_2);
            draw_picture("img_gold_trophy.bmp", 320, 170, &picture_rect_2);
            draw_picture("img_gold_trophy.bmp", 570, 170, &picture_rect_2);
            draw_picture("img_silver_trophy_2.bmp", 75, 375, &picture_rect_2);
            draw_picture("img_silver_trophy_2.bmp", 320, 375, &picture_rect_2);
            draw_picture("img_silver_trophy_2.bmp", 570, 375, &picture_rect_2);
            
            click_botton_event(picture_rect_1);
        }
    }
}

