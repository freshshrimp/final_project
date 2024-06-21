#include "SDL_breeding_farm_menu.h"
#include "SDL_basic.h"

SDL_Rect picture_rect_1;
SDL_Rect picture_rect_2;
SDL_Rect picture_rect_3;
SDL_Rect picture_rect_4;
SDL_Rect picture_rect_5;

int draw_breeding_farm_menu()   //育馬場菜單
{
    while(1)
    {
        breeding_farm_first_page:
        //顯示背景
        SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
        SDL_RenderClear(rdr);//刷新屏幕
        SDL_RenderPresent(rdr);//顯示屏幕
        draw_picture("img_concentration_area_background.bmp", 0, 0, &picture_rect_1);
        draw_picture("img_trainer_1.bmp", 285, 220, &picture_rect_1);
        draw_text("育馬場", 30, 340, 10);

        //和培育員對話的按鈕
        draw_picture("img_botton.bmp", 100, 500, &picture_rect_1);
        draw_text("對話", 24, 165, 505);
        
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
            draw_picture("img_concentration_area_background.bmp", 0, 0, &picture_rect_1);
            draw_picture("img_trainer_2.bmp", 285, 220, &picture_rect_1);
            //顯示對話框
            SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
            SDL_Rect rect = {50, 500, 700, 70};
            SDL_RenderFillRect(rdr, &rect);//填滿矩形
            SDL_RenderPresent(rdr);
            draw_text("你好，我是訓練員，你有什麼想要詢問的嗎?", 24, 60, 520);
            SDL_Delay(1000);



            talk_menu:
            //顯示背景
            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
            SDL_RenderClear(rdr);//刷新屏幕
            SDL_RenderPresent(rdr);//顯示屏幕
            draw_picture("img_concentration_area_background.bmp", 0, 0, &picture_rect_1);

            //顯示按鈕
            draw_picture("img_botton.bmp", 300, 125, &picture_rect_1);
            draw_text("關於一號賽馬", 24, 320, 130);
            draw_picture("img_botton.bmp", 300, 200, &picture_rect_2);
            draw_text("關於二號賽馬", 24, 320, 205);
            draw_picture("img_botton.bmp", 300, 275, &picture_rect_3);
            draw_text("關於三號賽馬", 24, 320, 280);
            draw_picture("img_botton.bmp", 300, 350, &picture_rect_4);
            draw_text("關於四號賽馬", 24, 320, 355);
            draw_picture("img_botton.bmp", 300, 425, &picture_rect_5);
            draw_text("沒有想問的了", 24, 320, 430);

            //事件監聽
            SDL_Event event;
            while(1)
            {
                while(SDL_PollEvent(&event))
                {
                    SDL_Point mouse_point;//滑鼠位置
                    if(event.type == SDL_MOUSEBUTTONDOWN)
                    {
                        mouse_point = {event.button.x, event.button.y};//儲存滑鼠位置
                        if(SDL_PointInRect(&mouse_point, &picture_rect_1))
                        {
                            //顯示背景
                            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                            SDL_RenderClear(rdr);//刷新屏幕
                            SDL_RenderPresent(rdr);//顯示屏幕
                            draw_picture("img_concentration_area_background.bmp", 0, 0, &picture_rect_1);
                            draw_picture("img_trainer_2.bmp", 285, 220, &picture_rect_1);
                            
                            //顯示對話
                            //速度
                            if(horse_data_array[0]->speed > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬只能用一道閃電來形容!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他的每一次起跑都是一場令人驚嘆的速度秀!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場都盡全力的飛馳著，讓人目不暇給!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的速度和優雅的奔跑而驚嘆不已！", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->speed <= 560) && (horse_data_array[0]->speed > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬簡直就像台小跑車一樣！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的加速度驚人", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠在瞬間拉開與其他馬匹的距離", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("展現出速度優勢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它如同風一般迅速，讓其他馬匹都很難跟上呢", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->speed <= 520) && (horse_data_array[0]->speed > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的速度比一般的馬還快上一些", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠以穩定的步伐奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但在爭冠的比賽中可能需要更多的策略來取得勝利", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總之，它展現出不錯的速度表現", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->speed <= 480) && (horse_data_array[0]->speed > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的奔跑速度稍嫌緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然拼命追趕其他馬匹，但經常在比賽中處於後段位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("得花上更多力氣才能追趕到前面", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[0]->speed <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的非常速度緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("很常都追趕不上其他馬匹", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它必須要更努力，來提高自己的速度", 24, 60, 520);
                                click_check();
                            }
                            
                            //耐力
                            if(horse_data_array[0]->stamina > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場，他總是毫不費力地飛馳著", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總是能從比賽一開始，就全力衝刺到最後", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("讓人目不暇給", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的深不見底的耐力而驚嘆不已", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->stamina <= 560) && (horse_data_array[0]->stamina > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它總是體力充沛", 24, 60, 520);
                                click_check();
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("基本上都能持續地保持高速奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("毫不畏縮地迎接每一場挑戰", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的勇氣和毅力令人敬佩", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->stamina <= 520) && (horse_data_array[0]->stamina > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，這匹馬的體力處於普通水準", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它需要在比賽中保持節奏", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("有時候需要在馬群中蓄力才能恢復元氣", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("若讓他一直衝刺的話，他可是會失速的喔", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->stamina <= 480) && (horse_data_array[0]->stamina > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他常常在賽程中感到疲憊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的調整和休息來調整狀態", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他在比賽最後關頭也鮮少能衝出馬群取得勝利", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[0]->stamina <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬總是顯得疲憊，無法長時間地保持高速", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("經常需要停下來喘息", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我都不知道他到底是在偷懶還是真的體力不好了", 24, 60, 520);
                                click_check();
                            }
                            
                            //智力
                            if(horse_data_array[0]->telegent > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力可高了呢！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠因應各種狀況，做出精確的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("使自己處於最有利的位置", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->telegent <= 560) && (horse_data_array[0]->telegent > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬具有不錯的智慧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠靈活應對比賽中的變化，做出明智的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->telegent <= 520) && (horse_data_array[0]->telegent > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力就算一般水準吧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然偶爾會有一些判斷失誤", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但大多數情況下能夠做出合理的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[0]->telegent <= 480) && (horse_data_array[0]->telegent > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬有點不機靈啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中出現一些錯誤的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多訓練和經驗來提升智慧水準", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[0]->telegent <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的挺笨的呢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中因為判斷失誤而處於不利位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的指導和訓練來改善狀況", 24, 60, 520);
                                click_check();
                            }
                            
                            goto talk_menu;
                            
                            
                            
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                        {
                            //顯示背景
                            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                            SDL_RenderClear(rdr);//刷新屏幕
                            SDL_RenderPresent(rdr);//顯示屏幕
                            draw_picture("img_concentration_area_background.bmp", 0, 0, &picture_rect_1);
                            draw_picture("img_trainer_2.bmp", 285, 220, &picture_rect_1);
                            
                            //顯示對話
                            //速度
                            if(horse_data_array[1]->speed > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬只能用一道閃電來形容!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他的每一次起跑都是一場令人驚嘆的速度秀!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場都盡全力的飛馳著，讓人目不暇給!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的速度和優雅的奔跑而驚嘆不已！", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->speed <= 560) && (horse_data_array[1]->speed > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬簡直就像台小跑車一樣！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的加速度驚人", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠在瞬間拉開與其他馬匹的距離", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("展現出速度優勢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它如同風一般迅速，讓其他馬匹都很難跟上呢", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->speed <= 520) && (horse_data_array[1]->speed > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的速度比一般的馬還快上一些", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠以穩定的步伐奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但在爭冠的比賽中可能需要更多的策略來取得勝利", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總之，它展現出不錯的速度表現", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->speed <= 480) && (horse_data_array[1]->speed > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的奔跑速度稍嫌緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然拼命追趕其他馬匹，但經常在比賽中處於後段位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("得花上更多力氣才能追趕到前面", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[1]->speed <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的非常速度緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("很常都追趕不上其他馬匹", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它必須要更努力，來提高自己的速度", 24, 60, 520);
                                click_check();
                            }
                            
                            //耐力
                            if(horse_data_array[1]->stamina > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場，他總是毫不費力地飛馳著", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總是能從比賽一開始，就全力衝刺到最後", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("讓人目不暇給", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的深不見底的耐力而驚嘆不已", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->stamina <= 560) && (horse_data_array[1]->stamina > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它總是體力充沛", 24, 60, 520);
                                click_check();
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("基本上都能持續地保持高速奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("毫不畏縮地迎接每一場挑戰", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的勇氣和毅力令人敬佩", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->stamina <= 520) && (horse_data_array[1]->stamina > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，這匹馬的體力處於普通水準", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它需要在比賽中保持節奏", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("有時候需要在馬群中蓄力才能恢復元氣", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("若讓他一直衝刺的話，他可是會失速的喔", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->stamina <= 480) && (horse_data_array[1]->stamina > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他常常在賽程中感到疲憊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的調整和休息來調整狀態", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他在比賽最後關頭也鮮少能衝出馬群取得勝利", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[1]->stamina <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬總是顯得疲憊，無法長時間地保持高速", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("經常需要停下來喘息", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我都不知道他到底是在偷懶還是真的體力不好了", 24, 60, 520);
                                click_check();
                            }
                            
                            //智力
                            if(horse_data_array[1]->telegent > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力可高了呢！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠因應各種狀況，做出精確的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("使自己處於最有利的位置", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->telegent <= 560) && (horse_data_array[1]->telegent > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬具有不錯的智慧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠靈活應對比賽中的變化，做出明智的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->telegent <= 520) && (horse_data_array[1]->telegent > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力就算一般水準吧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然偶爾會有一些判斷失誤", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但大多數情況下能夠做出合理的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[1]->telegent <= 480) && (horse_data_array[1]->telegent > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬有點不機靈啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中出現一些錯誤的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多訓練和經驗來提升智慧水準", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[1]->telegent <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的挺笨的呢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中因為判斷失誤而處於不利位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的指導和訓練來改善狀況", 24, 60, 520);
                                click_check();
                            }
                            
                            goto talk_menu;
                            
                            
                            
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_3))
                        {
                            //顯示背景
                            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                            SDL_RenderClear(rdr);//刷新屏幕
                            SDL_RenderPresent(rdr);//顯示屏幕
                            draw_picture("img_concentration_area_background.bmp", 0, 0, &picture_rect_1);
                            draw_picture("img_trainer_2.bmp", 285, 220, &picture_rect_1);
                            
                            //顯示對話
                            //速度
                            if(horse_data_array[2]->speed > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬只能用一道閃電來形容!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他的每一次起跑都是一場令人驚嘆的速度秀!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場都盡全力的飛馳著，讓人目不暇給!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的速度和優雅的奔跑而驚嘆不已！", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->speed <= 560) && (horse_data_array[2]->speed > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬簡直就像台小跑車一樣！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的加速度驚人", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠在瞬間拉開與其他馬匹的距離", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("展現出速度優勢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它如同風一般迅速，讓其他馬匹都很難跟上呢", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->speed <= 520) && (horse_data_array[2]->speed > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的速度比一般的馬還快上一些", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠以穩定的步伐奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但在爭冠的比賽中可能需要更多的策略來取得勝利", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總之，它展現出不錯的速度表現", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->speed <= 480) && (horse_data_array[2]->speed > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的奔跑速度稍嫌緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然拼命追趕其他馬匹，但經常在比賽中處於後段位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("得花上更多力氣才能追趕到前面", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[2]->speed <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的非常速度緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("很常都追趕不上其他馬匹", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它必須要更努力，來提高自己的速度", 24, 60, 520);
                                click_check();
                            }
                            
                            //耐力
                            if(horse_data_array[2]->stamina > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場，他總是毫不費力地飛馳著", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總是能從比賽一開始，就全力衝刺到最後", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("讓人目不暇給", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的深不見底的耐力而驚嘆不已", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->stamina <= 560) && (horse_data_array[2]->stamina > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它總是體力充沛", 24, 60, 520);
                                click_check();
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("基本上都能持續地保持高速奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("毫不畏縮地迎接每一場挑戰", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的勇氣和毅力令人敬佩", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->stamina <= 520) && (horse_data_array[2]->stamina > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，這匹馬的體力處於普通水準", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它需要在比賽中保持節奏", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("有時候需要在馬群中蓄力才能恢復元氣", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("若讓他一直衝刺的話，他可是會失速的喔", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->stamina <= 480) && (horse_data_array[2]->stamina > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他常常在賽程中感到疲憊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的調整和休息來調整狀態", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他在比賽最後關頭也鮮少能衝出馬群取得勝利", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[2]->stamina <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬總是顯得疲憊，無法長時間地保持高速", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("經常需要停下來喘息", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我都不知道他到底是在偷懶還是真的體力不好了", 24, 60, 520);
                                click_check();
                            }
                            
                            //智力
                            if(horse_data_array[2]->telegent > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力可高了呢！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠因應各種狀況，做出精確的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("使自己處於最有利的位置", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->telegent <= 560) && (horse_data_array[2]->telegent > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬具有不錯的智慧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠靈活應對比賽中的變化，做出明智的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->telegent <= 520) && (horse_data_array[2]->telegent > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力就算一般水準吧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然偶爾會有一些判斷失誤", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但大多數情況下能夠做出合理的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[2]->telegent <= 480) && (horse_data_array[2]->telegent > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬有點不機靈啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中出現一些錯誤的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多訓練和經驗來提升智慧水準", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[2]->telegent <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的挺笨的呢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中因為判斷失誤而處於不利位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的指導和訓練來改善狀況", 24, 60, 520);
                                click_check();
                            }
                            
                            goto talk_menu;
                            
                            
                            
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_4))
                        {
                            //顯示背景
                            SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
                            SDL_RenderClear(rdr);//刷新屏幕
                            SDL_RenderPresent(rdr);//顯示屏幕
                            draw_picture("img_concentration_area_background.bmp", 0, 0, &picture_rect_1);
                            draw_picture("img_trainer_2.bmp", 285, 220, &picture_rect_1);
                            
                            //顯示對話
                            //速度
                            if(horse_data_array[3]->speed > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬只能用一道閃電來形容!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他的每一次起跑都是一場令人驚嘆的速度秀!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場都盡全力的飛馳著，讓人目不暇給!", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的速度和優雅的奔跑而驚嘆不已！", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->speed <= 560) && (horse_data_array[3]->speed > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬簡直就像台小跑車一樣！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的加速度驚人", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠在瞬間拉開與其他馬匹的距離", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("展現出速度優勢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它如同風一般迅速，讓其他馬匹都很難跟上呢", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->speed <= 520) && (horse_data_array[3]->speed > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的速度比一般的馬還快上一些", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠以穩定的步伐奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但在爭冠的比賽中可能需要更多的策略來取得勝利", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總之，它展現出不錯的速度表現", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->speed <= 480) && (horse_data_array[3]->speed > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的奔跑速度稍嫌緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然拼命追趕其他馬匹，但經常在比賽中處於後段位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("得花上更多力氣才能追趕到前面", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[3]->speed <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我跟你說啊，這匹賽馬的非常速度緩慢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("很常都追趕不上其他馬匹", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它必須要更努力，來提高自己的速度", 24, 60, 520);
                                click_check();
                            }
                            
                            //耐力
                            if(horse_data_array[3]->stamina > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("每次上場，他總是毫不費力地飛馳著", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("總是能從比賽一開始，就全力衝刺到最後", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("讓人目不暇給", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("觀眾們總是為它的深不見底的耐力而驚嘆不已", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->stamina <= 560) && (horse_data_array[3]->stamina > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它總是體力充沛", 24, 60, 520);
                                click_check();
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("基本上都能持續地保持高速奔跑", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("毫不畏縮地迎接每一場挑戰", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它的勇氣和毅力令人敬佩", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->stamina <= 520) && (horse_data_array[3]->stamina > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，這匹馬的體力處於普通水準", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("它需要在比賽中保持節奏", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("有時候需要在馬群中蓄力才能恢復元氣", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("若讓他一直衝刺的話，他可是會失速的喔", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->stamina <= 480) && (horse_data_array[3]->stamina > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他常常在賽程中感到疲憊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的調整和休息來調整狀態", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("他在比賽最後關頭也鮮少能衝出馬群取得勝利", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[3]->stamina <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("另外，關於他的體力啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬總是顯得疲憊，無法長時間地保持高速", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("經常需要停下來喘息", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("我都不知道他到底是在偷懶還是真的體力不好了", 24, 60, 520);
                                click_check();
                            }
                            
                            //智力
                            if(horse_data_array[3]->telegent > 560)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力可高了呢！", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠因應各種狀況，做出精確的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("使自己處於最有利的位置", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->telegent <= 560) && (horse_data_array[3]->telegent > 520))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬具有不錯的智慧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("能夠靈活應對比賽中的變化，做出明智的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->telegent <= 520) && (horse_data_array[3]->telegent > 480))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的智力就算一般水準吧", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("雖然偶爾會有一些判斷失誤", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("但大多數情況下能夠做出合理的決策", 24, 60, 520);
                                click_check();
                            }
                            else if((horse_data_array[3]->telegent <= 480) && (horse_data_array[3]->telegent > 440))
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬有點不機靈啊", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中出現一些錯誤的判斷", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多訓練和經驗來提升智慧水準", 24, 60, 520);
                                click_check();
                            }
                            else if(horse_data_array[3]->telegent <= 440)
                            {
                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("喔對！忘記跟你說了", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("這匹馬的挺笨的呢", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("常常在比賽中因為判斷失誤而處於不利位置", 24, 60, 520);
                                click_check();

                                SDL_SetRenderDrawColor(rdr, 255, 191, 255, 255);
                                rect = {50, 500, 700, 70};
                                SDL_RenderFillRect(rdr, &rect);
                                SDL_RenderPresent(rdr);
                                draw_text("需要更多的指導和訓練來改善狀況", 24, 60, 520);
                                click_check();
                            }
                            
                            goto talk_menu;
                        }
                        else if(SDL_PointInRect(&mouse_point, &picture_rect_5))
                        {
                            goto breeding_farm_first_page;
                        }
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
            draw_text("住家", 24, 380, 305);
            
            //按鈕響應
            leave_menu_click_event(&botton_selection, picture_rect_1, picture_rect_2);
            if(botton_selection == 2)
            {
                return 0;
            }
        }
    }
}

void click_check()
{
    //事件監聽(是否點擊關閉視窗)與響應
    SDL_Event event;
    while(1)
    {
        while(SDL_PollEvent(&event))
        {
            SDL_Point mouse_point;//滑鼠位置
            if(event.type == SDL_MOUSEBUTTONDOWN) return;
        }
    }
}