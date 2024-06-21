
#include "SDL_ticket_office_menu.h"

int draw_ticket_office_menu() //馬券購買處菜單
{
    while(1)
    {
        ticket_office_menu:
        //顯示背景
        SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
        SDL_RenderClear(rdr);//刷新屏幕
        SDL_RenderPresent(rdr);//顯示屏幕
        draw_text("馬券購買處", 30, 320, 10);
        draw_picture("img_female_1.bmp", 310, 200, &picture_rect_1);
        draw_picture("img_table.bmp", 180, 180, &picture_rect_1);


        //顯示賽馬賠率表
        ////////////////////////////////////////////////////////////
        SDL_SetRenderDrawColor(rdr, 0, 0, 0, 255);
        SDL_Rect rect = {200, 60, 400, 190};
        SDL_RenderFillRect(rdr, &rect);//填滿矩形
        SDL_RenderPresent(rdr);
        draw_white_text("一號賽馬", 24, 220, 105);
        draw_white_text("二號賽馬", 24, 220, 140);
        draw_white_text("三號賽馬", 24, 220, 175);
        draw_white_text("四號賽馬", 24, 220, 210);
        draw_white_text("賠率", 24, 380, 70);
        draw_white_text("投注金額", 24, 480, 70);

        //排馬列匹的受關注度
        for(int i = 0; i < NUMBER_OF_HORSE; i++)
        {
            int rank = 0;
            for(int j = 0; j < NUMBER_OF_HORSE; j++)
            {
                if((horse_data_array[i]->speed) >= (horse_data_array[j]->speed))
                {
                    rank++;
                }
            }
            horse_data_array[i]->attention_rank = rank; //關注度越高，排行較大
        }

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

        //印出賽馬賠率資料
        char str[300]; // 儲存結果的字串
        sprintf(str, "%.1f", odds_list[0]);
        draw_yellow_text(str, 24, 380, 105);
        sprintf(str, "%.1f", odds_list[1]);
        draw_yellow_text(str, 24, 380, 140);
        sprintf(str, "%.1f", odds_list[2]);
        draw_yellow_text(str, 24, 380, 175);
        sprintf(str, "%.1f", odds_list[3]);
        draw_yellow_text(str, 24, 380, 210);

        sprintf(str, "%d K", bet_amount_list[0]);
        draw_yellow_text(str, 24, 480, 105);
        sprintf(str, "%d K", bet_amount_list[1]);
        draw_yellow_text(str, 24, 480, 140);
        sprintf(str, "%d K", bet_amount_list[2]);
        draw_yellow_text(str, 24, 480, 175);
        sprintf(str, "%d K", bet_amount_list[3]);
        draw_yellow_text(str, 24, 480, 210);
        ////////////////////////////////////////////////////////////


        //購買馬券的按鈕
        draw_picture("img_botton.bmp", 100, 500, &picture_rect_1);
        draw_text("購買馬券", 24, 150, 505);
        
        //前往其他場景的按鈕
        draw_picture("img_botton.bmp", 550, 500, &picture_rect_2);
        draw_text("離開", 24, 615, 505);

        //響應點擊按鈕事件
        int botton_selection;
        concentration_area_menu_click_event(&botton_selection,picture_rect_1,picture_rect_2);
        
        if(botton_selection == 1)
        {
           //顯示背景
            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
            SDL_RenderClear(rdr);//刷新屏幕
            SDL_RenderPresent(rdr);//顯示屏幕
            draw_text("馬券購買處", 30, 320, 10);
            draw_picture("img_female_2.bmp", 310, 200, &picture_rect_1);
            draw_picture("img_table.bmp", 180, 180, &picture_rect_1);

            SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
            SDL_Rect rect = {50, 500, 700, 70};
            SDL_RenderFillRect(rdr, &rect);//填滿矩形
            SDL_RenderPresent(rdr);
            draw_text("要買馬券嗎? 很高興為你服務", 24, 60, 520);
            SDL_Delay(1000);

            //顯示背景
            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
            SDL_RenderClear(rdr);//刷新屏幕
            SDL_RenderPresent(rdr);//顯示屏幕

            //draw_picture("img_cross.bmp", 740, 5, &picture_rect_1);
            draw_picture("img_botton.bmp", 310, 200, &picture_rect_1);
            draw_text("購買馬券", 24, 340, 205);
            draw_picture("img_botton.bmp", 310, 300, &picture_rect_2);
            draw_text("還是算了", 24, 340, 305);
            
            //事件響應
            SDL_Event event;
            while(1)
            {
                while(SDL_PollEvent(&event))
                {
                    SDL_Point mouse_point;//滑鼠位置
                    switch(event.type)
                    {
                        case SDL_MOUSEBUTTONDOWN:
                            mouse_point = {event.button.x, event.button.y};//儲存滑鼠位置
                            if(SDL_PointInRect(&mouse_point, &picture_rect_1))
                            {
                                goto select_the_horse_menu;
                            }
                            else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                            {
                                goto ticket_office_menu;
                            }

                        default:
                            break;
                    }
                }
            }
        }
        else if(botton_selection == 2)
        {
            //顯示背景
            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
            SDL_RenderClear(rdr);//刷新屏幕
            SDL_RenderPresent(rdr);//顯示屏幕
            draw_text("選擇場景", 30, 340, 10);

            //顯示移動選項
            draw_picture("img_cross.bmp", 740, 5, &picture_rect_1);
            draw_picture("img_botton.bmp", 310, 300, &picture_rect_2);
            draw_text("住家", 24, 340, 305);
            
            //按鈕響應
            leave_menu_click_event(&botton_selection, picture_rect_1, picture_rect_2);
            if(botton_selection == 1)
            {
                goto ticket_office_menu;
            }
            else if(botton_selection == 2)
            {
                return 0;
            }
        }

        select_the_horse_menu:
        //顯示背景
        SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
        SDL_RenderClear(rdr);//刷新屏幕
        SDL_RenderPresent(rdr);//顯示屏幕
        draw_text("請選擇下注賽馬:", 24, 310, 80);
        draw_picture("img_botton.bmp", 300, 130, &picture_rect_1);
        draw_text("一號賽馬", 24, 345, 135);
        draw_picture("img_botton.bmp", 300, 210, &picture_rect_2);
        draw_text("二號賽馬", 24, 345, 215);
        draw_picture("img_botton.bmp", 300, 290, &picture_rect_3);
        draw_text("三號賽馬", 24, 345, 295);
        draw_picture("img_botton.bmp", 300, 370, &picture_rect_4);
        draw_text("四號賽馬", 24, 345, 375);
        draw_picture("img_botton.bmp", 300, 450, &picture_rect_5);
        draw_text("還是算了", 24, 345, 455);
        
        //事件響應
        SDL_Event event;
        while(1)
        {
            while(SDL_PollEvent(&event))
            {
                SDL_Point mouse_point;//滑鼠位置
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        mouse_point = {event.button.x, event.button.y};//儲存滑鼠位置
                        if(SDL_PointInRect(&mouse_point, &picture_rect_1))
                        {
                            money = 1000;
                            bet_number = 1;
                            goto buy_ticket_menu;
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                        {
                            money = 1000;
                            bet_number = 2;
                            goto buy_ticket_menu; 
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_3))
                        {
                            money = 1000;
                            bet_number = 3;
                            goto buy_ticket_menu; 
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_4))
                        {
                            money = 1000;
                            bet_number = 4;
                            goto buy_ticket_menu; 
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_5))
                        {
                            goto ticket_office_menu; 
                        }

                    default:
                        break;
                }
            }
        }


        buy_ticket_menu:
        //顯示背景
        SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
        SDL_RenderClear(rdr);//刷新屏幕
        SDL_RenderPresent(rdr);//顯示屏幕
        //顯示下注金額
        sprintf(str, "下注賽馬: %d 號", bet_number);
        draw_text(str, 24, 200, 10);
        sprintf(str, "擁有: %d 元", player_money);
        draw_text(str, 24, 10, 10);
        sprintf(str, "下注金額:  %d 元", money);
        draw_text(str, 24, 295, 300);
        draw_picture("img_botton.bmp", 300, 420, &picture_rect_1);
        draw_text("還是算了", 24, 345, 425);
        draw_picture("img_button_2.bmp", 335, 340, &picture_rect_2);
        draw_text("+", 40, 345, 332);
        draw_picture("img_button_2.bmp", 410, 340, &picture_rect_3);
        draw_text("-", 40, 425, 332);
        draw_picture("img_botton.bmp", 300, 490, &picture_rect_4);
        draw_text("確定下注", 24, 345, 495);

        // SDL_Event event;
        while(1)
        {
            while(SDL_PollEvent(&event))
            {
                SDL_Point mouse_point;//滑鼠位置
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        mouse_point = {event.button.x, event.button.y};//儲存滑鼠位置
                        if(SDL_PointInRect(&mouse_point, &picture_rect_1))
                        {
                            goto ticket_office_menu;
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                        {
                            money += 1000;
                            goto buy_ticket_menu;
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_3))
                        {
                            money -= 1000;
                            goto buy_ticket_menu;
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_4))
                        {
                            player_money = player_money - money;
                            //進入賽馬環節
                            return 1;
                        }

                    default:
                        break;
                }
            }
        }
    }
}