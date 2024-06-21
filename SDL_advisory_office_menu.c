#include "SDL_advisory_office_menu.h"

int draw_advisory_office_menu() //諮詢處菜單
{
    while(1)
    {
        advisory_office_menu_first_page:
        //顯示背景
        SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
        SDL_RenderClear(rdr);//刷新屏幕
        SDL_RenderPresent(rdr);//顯示屏幕
        draw_picture("img_server_1.bmp", 285, 220, &picture_rect_1);
        draw_text("賽馬分析師的攤位", 30, 290, 10);

        //向分析師諮詢的按鈕
        draw_picture("img_botton.bmp", 100, 500, &picture_rect_1);
        draw_text("諮詢", 24, 165, 505);
        
        //前往其他場景的按鈕
        draw_picture("img_botton.bmp", 550, 500, &picture_rect_2);
        draw_text("離開", 24, 615, 505);

        //響應點擊按鈕事件
        int botton_selection;
        concentration_area_menu_click_event(&botton_selection,picture_rect_1,picture_rect_2);
        
        if(botton_selection == 1)
        {
            //諮詢
            //顯示背景
            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
            SDL_RenderClear(rdr);//刷新屏幕
            SDL_RenderPresent(rdr);//顯示屏幕
            draw_picture("img_server_2.bmp", 285, 220, &picture_rect_1);
            //顯示對話框
            SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
            SDL_Rect rect = {50, 500, 700, 70};
            SDL_RenderFillRect(rdr, &rect);//填滿矩形
            SDL_RenderPresent(rdr);
            draw_text("你好，我是諮詢員，你有什麼想要詢問的嗎?", 24, 60, 520);
            SDL_Delay(750);



            //顯示背景
            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
            SDL_RenderClear(rdr);//刷新屏幕
            SDL_RenderPresent(rdr);//顯示屏幕

            //顯示按鈕
            draw_picture("img_botton.bmp", 300, 200, &picture_rect_1);
            draw_text("今天的哪隻馬會跑贏", 20, 305, 210);
            draw_picture("img_botton.bmp", 300, 275, &picture_rect_2);
            draw_text("還是算了", 24, 345, 280);


            //事件監聽
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
                                if(player_money >= 3000) //玩家有錢可以諮詢今天哪匹馬比較可能會贏
                                {
                                    int best_horse_id = 0, highest_rating_score = (horse_data_array[0]->speed) + (horse_data_array[0]->stamina) + (horse_data_array[0]->telegent);
                                    for(int i = 0; i < 4; i++)//四匹馬
                                    {
                                        int num = (horse_data_array[i]->speed) + (horse_data_array[i]->stamina) + (horse_data_array[i]->telegent);
                                        if(num > highest_rating_score) 
                                        {
                                            best_horse_id = i;
                                        }
                                    }
                                    
                                    //背景
                                    SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                                    SDL_RenderClear(rdr);//刷新屏幕
                                    SDL_RenderPresent(rdr);//顯示屏幕
                                    draw_picture("img_server_2.bmp", 285, 220, &picture_rect_1);

                                    //顯示對話框
                                    SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                    SDL_Rect rect = {50, 500, 700, 70};
                                    SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                    SDL_RenderPresent(rdr);
                                    draw_text("天下沒有白吃的午餐，想問我問題，先交錢", 24, 60, 520);
                                    SDL_Delay(1000);


                                    //顯示背景
                                    SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                                    SDL_RenderClear(rdr);//刷新屏幕
                                    SDL_RenderPresent(rdr);//顯示屏幕
                                    draw_picture("img_botton.bmp", 300, 200, &picture_rect_1);
                                    draw_text("交付 2000 元", 20, 335, 210);
                                    draw_picture("img_botton.bmp", 300, 275, &picture_rect_2);
                                    draw_text("還是算了", 24, 345, 280);

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
                                                        player_money = player_money - 2000;
                                                        goto tell_the_analyze;
                                                    }
                                                    else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                                                    {
                                                        goto advisory_office_menu_first_page;
                                                    }

                                                default:
                                                    break;
                                            }
                                        }
                                    }


                                    tell_the_analyze:
                                    //背景
                                    SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                                    SDL_RenderClear(rdr);//刷新屏幕
                                    SDL_RenderPresent(rdr);//顯示屏幕
                                    draw_picture("img_server_2.bmp", 285, 220, &picture_rect_1);
                                    //顯示對話框
                                    SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                    rect = {50, 500, 700, 70};
                                    SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                    SDL_RenderPresent(rdr);
                                    draw_text("嗯...就我看來...", 24, 60, 520);
                                    click_check();

                                    if(best_horse_id == 0)
                                    {
                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        SDL_Rect rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("一號賽馬今天狀態比較好，", 24, 60, 520);
                                        click_check();

                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("會贏喔", 24, 60, 520);
                                        draw_picture("img_will_win.bmp", 335, 250, &picture_rect_1);
                                        click_check();
                                        goto advisory_office_menu_first_page;

                                    }
                                    else if(best_horse_id == 1)
                                    {
                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        SDL_Rect rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("二號賽馬今天狀態比較好，", 24, 60, 520);
                                        click_check();

                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("會贏喔", 24, 60, 520);
                                        draw_picture("img_will_win.bmp", 335, 250, &picture_rect_1);
                                        click_check();
                                        goto advisory_office_menu_first_page;
                                    }
                                    else if(best_horse_id == 2)
                                    {
                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        SDL_Rect rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("三號賽馬今天狀態比較好，", 24, 60, 520);
                                        click_check();

                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("會贏喔", 24, 60, 520);
                                        draw_picture("img_will_win.bmp", 335, 250, &picture_rect_1);
                                        click_check();
                                        goto advisory_office_menu_first_page;
                                    }
                                    else
                                    {
                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        SDL_Rect rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("四號賽馬今天狀態比較好，", 24, 60, 520);
                                        click_check();

                                        SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                        rect = {50, 500, 700, 70};
                                        SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                        SDL_RenderPresent(rdr);
                                        draw_text("會贏喔", 24, 60, 520);
                                        draw_picture("img_will_win.bmp", 335, 250, &picture_rect_1);
                                        click_check();
                                        goto advisory_office_menu_first_page;
                                    }

                                }
                                else if(player_money < 2000) //玩家沒有錢可以諮詢今天哪匹馬會贏
                                {
                                    //顯示背景
                                    SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                                    SDL_RenderClear(rdr);//刷新屏幕
                                    SDL_RenderPresent(rdr);//顯示屏幕
                                    draw_picture("img_server_3.bmp", 285, 220, &picture_rect_1);
                                    
                                    //顯示對話
                                    SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                    rect = {50, 500, 700, 70};
                                    SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                    SDL_RenderPresent(rdr);
                                    draw_text("你連 2000 元都沒有", 24, 60, 520);
                                    click_check();

                                    SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                    rect = {50, 500, 700, 70};
                                    SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                    SDL_RenderPresent(rdr);
                                    draw_text("連錢都沒帶夠，是在哭喔?", 24, 60, 520);
                                    SDL_Delay(1000);
                                    goto advisory_office_menu_first_page;
                                }
                                else
                                {
                                    //顯示背景
                                    SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                                    SDL_RenderClear(rdr);//刷新屏幕
                                    SDL_RenderPresent(rdr);//顯示屏幕
                                    draw_picture("img_server_3.bmp", 285, 220, &picture_rect_1);
                                    
                                    //顯示對話
                                    SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                    rect = {50, 500, 700, 70};
                                    SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                    SDL_RenderPresent(rdr);
                                    draw_text("你不能這麼做", 24, 60, 520);
                                    click_check();

                                    //顯示對話
                                    SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                    rect = {50, 500, 700, 70};
                                    SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                    SDL_RenderPresent(rdr);
                                    draw_text("你花錢跟我詢問完後", 24, 60, 520);
                                    click_check();

                                    
                                    SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                    rect = {50, 500, 700, 70};
                                    SDL_RenderFillRect(rdr, &rect);//填滿矩形
                                    SDL_RenderPresent(rdr);
                                    draw_text("你就沒錢買馬券了，你在想什麼?", 24, 60, 520);
                                    SDL_Delay(1000);
                                    goto advisory_office_menu_first_page;
                                }
                            }
                            else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                            {
                               goto  advisory_office_menu_first_page;
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
            if(botton_selection == 2)
            {
                return 2;
            }
        }
    }

}