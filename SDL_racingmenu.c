#include "SDL_racingmenu.h"

//計算跑完的排名
int h_rank = 1;

//標示黑色方塊循環的次數
int h_1_round = 1, h_2_round = 1, h_3_round = 1, h_4_round = 1; 

//馬跑步的圖片檢索，控制更新的速度
int h_frameindex_1 = 1, h_frameindex_2 = 1, h_frameindex_3 = 1, h_frameindex_4 = 1;
//黑色方塊的圖片順序
int s_index_1 = 1, s_index_2 = 1, s_index_3 = 1, s_index_4 = 1; 

//踩過水坑後的失速回合 (共三回合)
int decrease_round = 0; 
//標記1~4號馬匹的即將失速
int decrease_flag_1 = 0, decrease_flag_2 = 0, decrease_flag_3 = 0, decrease_flag_4 = 0; 

//標記水坑出現
int slow_flag_1 = 0, slow_flag_2 = 0, slow_flag_3 = 0, slow_flag_4 = 0; 
//標記1~4號馬匹是否完賽
int finish_flag_1 = 0, finish_flag_2 = 0, finish_flag_3 = 0, finish_flag_4 = 0, finish_flag_event_loop = 0;

//顯示採水坑後是否減速
int brodcast_flag_1 = 1, brodcast_flag_2 = 1;
//標記清除文字
int clear_flag_1 = 0, clear_flag_2 = 0, clear_flag_3 = 0, clear_flag_4 = 0;


//觀眾席及賽道1~4的座標及大小
SDL_Rect tracks[5] = {{0, 0, 800, 120},{0, 120, 800, 120}, {0, 240, 800, 120}, {0, 360, 800, 120}, {0, 480, 800, 120}};
//距離標示1~4的座標及大小
SDL_Rect Distance_Sign[4] = {{760, 220, 40, 20}, {760, 340, 40, 20}, {760, 460, 40, 20}, {760, 580, 40, 20}};
//水坑位置
SDL_Rect paddle_position[4] = {{800, 200, 90, 30}, {800, 320, 90, 30}, {800, 440, 90, 30}, {800, 560, 90, 30}};
//SDL_Rect paddle_position[4] = {{800, 200, 80, 30}, {800, 320, 80, 30}, {800, 440, 80, 30}, {800, 560, 80, 30}};
//馬匹的位置 
SDL_Rect horse_position[4] = {{350, 130, 90, 75}, {350, 250, 90, 75}, {350, 370,  90, 75}, {350, 490, 90, 75}};

//比賽開始前的倒數
void count_down_to_start(){
 
    const char *count_texts[] = {"3", "2", "1"};
    SDL_SetRenderDrawColor(rdr, 0, 200, 0, 255); //設定背景顏色
    SDL_RenderClear(rdr);
    
    for (int i = 0; i < 3; i++) {
        //顯示數字
        draw_text(count_texts[i], 150, 350, 210); 
        SDL_RenderPresent(rdr); 
        SDL_Delay(1000); //等一秒
        
        //清除數字
        if(i == 0 || i == 1){
            SDL_SetRenderDrawColor(rdr, 0, 200, 0, 225); 
            SDL_RenderClear(rdr);
        }
        //銜接比賽畫面
        else if(i == 3){
            SDL_SetRenderDrawColor(rdr, 0, 225, 225, 255); 
            SDL_RenderClear(rdr);
            SDL_Delay(1000);
        }
    }
}

//繪製場地
int draw_Field()
{
    //設定顏色
    SDL_SetRenderDrawColor(rdr, 225, 225, 225, 255); //設定背景顏色
    SDL_RenderClear(rdr);
    SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
    SDL_RenderFillRects(rdr,tracks,5);//一次繪製五個賽道
    
    //設定分割線顏色
    SDL_SetRenderDrawColor(rdr, 140, 50, 50, 255); 
    //繪製分割線
    SDL_RenderDrawLine(rdr, 0, 120, 800, 120);
    SDL_RenderDrawLine(rdr, 0, 240, 800, 240);
    SDL_RenderDrawLine(rdr, 0, 360, 800, 360);
    SDL_RenderDrawLine(rdr, 0, 480, 800, 480);
    SDL_RenderPresent(rdr);
    return 0;
}


// void draw_DistanceSign() //繪製方塊
// {
//     SDL_SetRenderDrawColor(rdr,0,0,0,225); //設定顏色
//     SDL_RenderFillRects(rdr, Distance_Sign, 4);
//     SDL_RenderPresent(rdr);
// }

//繪製1號賽馬
void draw_horse_1(int finish){
    
    
    /////////////////將圖片順序循環寫入file字串中////////////////
    char file[20] = {0};
    if(h_frameindex_1 > 8){
        h_frameindex_1 = 0;
    }
    SDL_snprintf(file, 20, "horse_img/%d.bmp", h_frameindex_1++);
    //////////////////////////////////////////////////////////////

    //尚未完賽
    if(finish == 0){
        //導入圖片
        SDL_Surface *horse_1_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_1_texture = SDL_CreateTextureFromSurface(rdr, horse_1_bmp_surf);
        SDL_RenderCopy(rdr, horse_1_texture, NULL, horse_position);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_1_texture);
        SDL_FreeSurface(horse_1_bmp_surf);
    }

    //完賽
    else{
        //導入圖片並向前移動
        SDL_SetRenderDrawColor(rdr, 0, 200, 0, 255); //設定背景顏色
        SDL_RenderFillRect(rdr, horse_position);
        horse_position[0].x += 7;
        SDL_Surface *horse_1_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_1_texture = SDL_CreateTextureFromSurface(rdr, horse_1_bmp_surf);
        SDL_RenderCopy(rdr, horse_1_texture, NULL, horse_position);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_1_texture);
        SDL_FreeSurface(horse_1_bmp_surf);
    }
    
}

//繪製2號賽馬
void draw_horse_2(int finish){
    
    /////////////////將圖片順序循環寫入file字串中////////////////
    char file[20] = {0};
    if(h_frameindex_2 > 8){
        h_frameindex_2 = 0;
    }
    SDL_snprintf(file, 20, "horse_img/%d.bmp", h_frameindex_2++);
    ///////////////////////////////////////////////////////////

    //尚未完賽
    if(finish == 0){
        //導入圖片
        SDL_Surface *horse_2_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_2_texture = SDL_CreateTextureFromSurface(rdr, horse_2_bmp_surf);
        SDL_RenderCopy(rdr, horse_2_texture, NULL, horse_position + 1);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_2_texture);
        SDL_FreeSurface(horse_2_bmp_surf);
    }

    //完賽
    else{
        //導入圖片並向前移動
        SDL_SetRenderDrawColor(rdr, 0, 200, 0, 255); //設定背景顏色
        SDL_RenderFillRect(rdr, horse_position + 1);
        horse_position[1].x += 10;
        SDL_Surface *horse_2_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_2_texture = SDL_CreateTextureFromSurface(rdr, horse_2_bmp_surf);
        SDL_RenderCopy(rdr, horse_2_texture, NULL, horse_position + 1);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_2_texture);
        SDL_FreeSurface(horse_2_bmp_surf);
    }
}

//繪製號賽馬
void draw_horse_3(int finish){

    /////////////////將圖片順序循環寫入file字串中////////////////
    char file[20] = {0};
    if(h_frameindex_3 > 8){
        h_frameindex_3 = 0;
    }
    SDL_snprintf(file, 20, "horse_img/%d.bmp", h_frameindex_3++);
    ////////////////////////////////////////////////////////////

    //完賽
    if(finish == 0){
        //導入圖片
        SDL_Surface *horse_3_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_3_texture = SDL_CreateTextureFromSurface(rdr, horse_3_bmp_surf);
        SDL_RenderCopy(rdr, horse_3_texture, NULL, horse_position + 2);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_3_texture);
        SDL_FreeSurface(horse_3_bmp_surf);
    }

    //尚未完賽
    else{
        //導入圖片並向前移動
        SDL_SetRenderDrawColor(rdr, 0, 200, 0, 255); //設定背景顏色
        SDL_RenderFillRect(rdr, horse_position + 2);
        horse_position[2].x += 10;
        SDL_Surface *horse_3_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_3_texture = SDL_CreateTextureFromSurface(rdr, horse_3_bmp_surf);
        SDL_RenderCopy(rdr, horse_3_texture, NULL, horse_position + 2);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_3_texture);
        SDL_FreeSurface(horse_3_bmp_surf);
    }
}

//繪製4號賽馬
void draw_horse_4(int finish){

    /////////////////將圖片順序循環寫入file字串中////////////////
    char file[20] = {0};
    if(h_frameindex_4 > 8){
        h_frameindex_4 = 0;
    }
    SDL_snprintf(file, 20, "horse_img/%d.bmp", h_frameindex_4++);
    ///////////////////////////////////////////////////////////

    //完賽
    if(finish == 0){
        //導入圖片
        SDL_Surface *horse_4_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_4_texture = SDL_CreateTextureFromSurface(rdr, horse_4_bmp_surf);
        SDL_RenderCopy(rdr, horse_4_texture, NULL, horse_position + 3);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_4_texture);
        SDL_FreeSurface(horse_4_bmp_surf);
    }

    //尚未完賽
    else{
        //導入圖片
        SDL_SetRenderDrawColor(rdr, 0, 200, 0, 255); //設定背景顏色
        SDL_RenderFillRect(rdr, horse_position + 3);
        horse_position[3].x += 10;
        SDL_Surface *horse_4_bmp_surf  = SDL_LoadBMP(file);
        SDL_Texture *horse_4_texture = SDL_CreateTextureFromSurface(rdr, horse_4_bmp_surf);
        SDL_RenderCopy(rdr, horse_4_texture, NULL, horse_position + 3);
        SDL_RenderPresent(rdr);
        SDL_DestroyTexture(horse_4_texture);
        SDL_FreeSurface(horse_4_bmp_surf);
    }
}

//隨機多遠踩遇到水坑
int creat_rand_for_round(){ 

    //將範圍控制在第3輪到第5輪
    srand( time(NULL) );
    int min = 3;
    int max = 15;
    int x = rand() % (max - min + 1) + min;
    return x;
}

//決定哪隻馬遇到水坑
int creat_rand_for_horse(){ 
    
    //將範圍控制在1到4
    srand( time(NULL) );
    int min = 1;
    int max = 4;
    int x = rand() % (max - min + 1) + min;
    return x;
}

//繪製水坑
int paddle(int black_square_speed, int number){

    // SDL_SetRenderDrawColor(rdr,0,200,0,225);
    // SDL_RenderFillRect(rdr, paddle_position + number);
    // paddle_position[number].x = paddle_position[number].x - black_square_speed; //根據當時的路標移動速度改變
    // SDL_SetRenderDrawColor(rdr,0,0,90,225);
    // SDL_RenderFillRect(rdr, paddle_position + number);


    SDL_SetRenderDrawColor(rdr,0,200,0,225);
    SDL_RenderFillRect(rdr, paddle_position + number);
    paddle_position[number].x = paddle_position[number].x - black_square_speed; //根據當時的路標移動速度改變
    SDL_Surface *puddle_bmp_surf  = SDL_LoadBMP("puddle.bmp");
    SDL_Texture *puddle_texture = SDL_CreateTextureFromSurface(rdr, puddle_bmp_surf);
    SDL_RenderCopy(rdr, puddle_texture, NULL, paddle_position + number);
    SDL_RenderPresent(rdr);
    
    if(paddle_position[number].x <= 0){
        SDL_SetRenderDrawColor(rdr,0,200,0,225);
        SDL_RenderFillRect(rdr, paddle_position + number);
    }
    SDL_DestroyTexture(puddle_texture);
    SDL_FreeSurface(puddle_bmp_surf);
    return 1;

}

//顯示賽馬失速
void affect_event(int number){
    SDL_Rect fill_word = {0, 0, 30, 20};
    char step_paddle_str[100];
    sprintf(step_paddle_str, "%d號賽馬踩到水坑失速!!", number);
    draw_text(step_paddle_str, 30, 0, 0);
    brodcast_flag_1 = 0;
}

//顯示賽馬未失速
void no_affect_event(int number){
    SDL_Rect fill_word = {0, 0, 30, 20};
    char step_paddle_str[11];
    sprintf(step_paddle_str, "%d號賽馬跳過水坑!!", number);
    draw_text(step_paddle_str, 30, 0, 0);
    brodcast_flag_2 = 0;
}

//黑色方塊的移動                                         //遇見水坑的賽馬     //遇見水坑的回合                                                           
void square_move(struct horse_data ** horse_data_array, int h_paddle, int h_paddle_round)
{
    ////////////////匯入四條賽道的標誌//////////////////////////////////////////////
    char s_file_1[22] = {0}; 
    char s_file_2[22] = {0};
    char s_file_3[22] = {0};
    char s_file_4[22] = {0};

    SDL_snprintf(s_file_1, 22, "blacksquares/s_%d.bmp", s_index_1);
    SDL_snprintf(s_file_2, 22, "blacksquares/s_%d.bmp", s_index_2);
    SDL_snprintf(s_file_3, 22, "blacksquares/s_%d.bmp", s_index_3);
    SDL_snprintf(s_file_4, 22, "blacksquares/s_%d.bmp", s_index_4);
    
    //導入圖片
    SDL_Surface *s_1_bmp_surf  = SDL_LoadBMP(s_file_1);
    SDL_Surface *s_2_bmp_surf  = SDL_LoadBMP(s_file_2);
    SDL_Surface *s_3_bmp_surf  = SDL_LoadBMP(s_file_3);
    SDL_Surface *s_4_bmp_surf  = SDL_LoadBMP(s_file_4);
    
    SDL_Texture *s_1_texture = SDL_CreateTextureFromSurface(rdr, s_1_bmp_surf);
    SDL_Texture *s_2_texture = SDL_CreateTextureFromSurface(rdr, s_2_bmp_surf);
    SDL_Texture *s_3_texture = SDL_CreateTextureFromSurface(rdr, s_3_bmp_surf);
    SDL_Texture *s_4_texture = SDL_CreateTextureFromSurface(rdr, s_4_bmp_surf);
   
    /////////////////////////////////////////////////////////////////////////////////

    ////////////////決定遇見水坑的賽馬的失速狀態////////////////////
    if(h_paddle == 1) slow_flag_1 = 1;  
    else if(h_paddle == 2) slow_flag_2 = 1;
    else if(h_paddle == 3) slow_flag_3 = 1;
    else slow_flag_4 = 1;
    ////////////////////////////////////////////////////////

    //////////////一號賽馬/////////////////////////////////////
    
    //跑完第25圈的狀態
    if(h_1_round == 25){ 
        //標記完賽
        finish_flag_1 = 1;
        if(horse_data_array[0]->racing_rank == 0){
            horse_data_array[0]->racing_rank = horse_data_array[0]->racing_rank + h_rank;
            h_rank += 1;
            printf("horse 1 is number %d\n", horse_data_array[0]->racing_rank);
        }
        SDL_SetRenderDrawColor(rdr,150,50,50,225);
        SDL_RenderFillRect(rdr, Distance_Sign);
    }

    else{

        //標記尚未完賽
        finish_flag_1 = 0;
        //體力見底的狀態
        if(h_1_round > horse_data_array[0]->stamina){   
            SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
            SDL_RenderFillRect(rdr, Distance_Sign);
            Distance_Sign[0].x = Distance_Sign[0].x - horse_data_array[0]->fatigue_speed; //控制移動速度
            SDL_RenderCopy(rdr, s_1_texture, NULL, Distance_Sign);
        }

        //水坑出現的狀態                                       
        else if(h_1_round == h_paddle_round && slow_flag_1){ 

            paddle(horse_data_array[0]->speed, h_paddle - 1);//水坑出現
            SDL_SetRenderDrawColor(rdr,0,200,0,225);
            SDL_RenderFillRect(rdr, Distance_Sign);
            Distance_Sign[0].x = Distance_Sign[0].x - horse_data_array[0]->speed; //控制移動速度
            SDL_RenderCopy(rdr, s_1_texture, NULL, Distance_Sign);
            decrease_flag_1 = 1;//標記遇見水坑
        }

        else{ 
            //水坑出現後的三輪且失速有效
            if(decrease_round > 0 && decrease_round < 4  && horse_data_array[0]->telegent < 37 && slow_flag_1){

                //顯示失速狀態
                if(brodcast_flag_1){
                    affect_event(1);
                    clear_flag_1 = 1;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign);
                //SDL_RenderFillRect(rdr, tracks);
                Distance_Sign[0].x = Distance_Sign[0].x - 4; //控制移動速度
                SDL_RenderCopy(rdr, s_1_texture, NULL, Distance_Sign);
            }

            //水坑出現後的三輪且失速無效
            else if(decrease_round > 0 && decrease_round < 4  && horse_data_array[0]->telegent >= 37 && slow_flag_1){   
                
                if(brodcast_flag_2){ 
                    no_affect_event(1);                   
                    clear_flag_1 = 1;
                }
                
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign);
                Distance_Sign[0].x = Distance_Sign[0].x - horse_data_array[0]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_1_texture, NULL, Distance_Sign);
            }

            //正常的跑速;
            else{

                //清除先前的文字
                if(clear_flag_1){
                    SDL_RenderFillRect(rdr, tracks);
                    clear_flag_1 = 0;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign);
                Distance_Sign[0].x = Distance_Sign[0].x - horse_data_array[0]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_1_texture, NULL, Distance_Sign);
            }
        }

        //判斷 X 座標,創造循環效果
        if(Distance_Sign[0].x <= -40){
            Distance_Sign[0].x = 760;
            s_index_1++;
            h_1_round++;
            if(decrease_flag_1 && decrease_round < 4){
                slow_flag_1 = 0; //不要讓水坑重複出現
                decrease_round++;
            }    
        }
    }


    //////////////二號賽馬/////////////////////////////////////
    
    //跑完第25圈的狀態
    if(h_2_round == 25 ){
        finish_flag_2 = 1;
        if(horse_data_array[1]->racing_rank == 0){
            horse_data_array[1]->racing_rank = horse_data_array[1]->racing_rank + h_rank;
            h_rank += 1;
            printf("horse 2 is number %d\n", horse_data_array[1]->racing_rank);
        }
        SDL_SetRenderDrawColor(rdr,150,50,50,225);
        SDL_RenderFillRect(rdr, Distance_Sign + 1);
    }


    else{
        finish_flag_2 = 0;
        if(h_2_round > horse_data_array[1]->stamina){   //體力見底
            SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
            SDL_RenderFillRect(rdr, Distance_Sign + 1);
            Distance_Sign[1].x = Distance_Sign[1].x - horse_data_array[1]->fatigue_speed; //控制移動速度
            SDL_RenderCopy(rdr, s_2_texture, NULL, Distance_Sign + 1);
        }

        //水坑的出現                                       
        else if(h_2_round == h_paddle_round && slow_flag_2){ 
            
            paddle(horse_data_array[1]->speed, h_paddle - 1);//水坑出現
            SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
            SDL_RenderFillRect(rdr, Distance_Sign + 1);
            Distance_Sign[1].x = Distance_Sign[1].x - horse_data_array[1]->speed; //控制移動速度
            SDL_RenderCopy(rdr, s_2_texture, NULL, Distance_Sign + 1);
            decrease_flag_2 = 1;
        }

     
        else{
            //水坑出現後的三輪
            //有效
            if(decrease_round > 0 && decrease_round < 4  && horse_data_array[1]->telegent < 37 && slow_flag_2){   
                
                if(brodcast_flag_1){
                    affect_event(2);
                    clear_flag_2 = 1;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                //SDL_RenderFillRect(rdr, tracks);
                SDL_RenderFillRect(rdr, Distance_Sign + 1);
                Distance_Sign[1].x = Distance_Sign[1].x - 4; //控制移動速度
                SDL_RenderCopy(rdr, s_2_texture, NULL, Distance_Sign + 1);
            }

            //無效
            else if(decrease_round > 0 && decrease_round < 4  && horse_data_array[1]->telegent >= 37 && slow_flag_2){   
               
               if(brodcast_flag_2){
                    no_affect_event(2);
                    clear_flag_2 = 1;
                    printf("line 449\n");
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 1);
                Distance_Sign[1].x = Distance_Sign[1].x - horse_data_array[1]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_2_texture, NULL, Distance_Sign + 1);
            }

            else{

                if(clear_flag_2){
                    SDL_RenderFillRect(rdr, tracks);
                    clear_flag_2 = 0;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 1);
                Distance_Sign[1].x = Distance_Sign[1].x - horse_data_array[1]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_2_texture, NULL, Distance_Sign + 1);
            }
        }

        //判斷 X 座標,創造循環效果
        if(Distance_Sign[1].x <= -40){   
            Distance_Sign[1].x = 760;
            s_index_2++;
            h_2_round++;   
            if(decrease_flag_2 && decrease_round < 4){
                slow_flag_2 = 0; //不要讓水坑重複出現
                decrease_round++;
            }   
        }
    }


    ///////三號賽馬/////////////////////////////////////

   //跑完第25圈的狀態
    if(h_3_round == 25){ //25圈
        finish_flag_3 = 1;
        if(horse_data_array[2]->racing_rank == 0){
            horse_data_array[2]->racing_rank = horse_data_array[2]->racing_rank + h_rank;
            h_rank += 1;
            printf("horse 3 is number %d\n", horse_data_array[2]->racing_rank);
        }
        SDL_SetRenderDrawColor(rdr,150,50,50,225);
        SDL_RenderFillRect(rdr, Distance_Sign + 2);
    }
    else{
        finish_flag_3 = 0;

        if(h_3_round > horse_data_array[2]->stamina){   //看體力有沒有到底
            SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
            SDL_RenderFillRect(rdr, Distance_Sign + 2);
            Distance_Sign[2].x = Distance_Sign[2].x - horse_data_array[2]->fatigue_speed; //控制移動速度
            SDL_RenderCopy(rdr, s_3_texture, NULL, Distance_Sign + 2);
        }

        //水坑的出現                                       
        else if(h_3_round == h_paddle_round && slow_flag_3){ 
            
            paddle(horse_data_array[2]->speed, h_paddle - 1);//水坑出現
            SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
            SDL_RenderFillRect(rdr, Distance_Sign + 2);
            Distance_Sign[2].x = Distance_Sign[2].x - horse_data_array[2]->speed; //控制移動速度
            SDL_RenderCopy(rdr, s_3_texture, NULL, Distance_Sign + 2);
            decrease_flag_3 = 1;
        }

        else{

             //水坑出現後的三輪
             //有效
            if(decrease_round > 0 && decrease_round < 4  && horse_data_array[2]->telegent < 37 && slow_flag_3){   

                if(brodcast_flag_1){
                    affect_event(3);
                    clear_flag_3 = 1;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 2);
                //SDL_RenderFillRect(rdr, tracks);
                Distance_Sign[2].x = Distance_Sign[2].x - 4; //控制移動速度
                SDL_RenderCopy(rdr, s_3_texture, NULL, Distance_Sign + 2);
            }

            //無效
            else if(decrease_round > 0 && decrease_round < 4  && horse_data_array[2]->telegent >= 37 && slow_flag_3){   
                
                if(brodcast_flag_2){
                    no_affect_event(3);
                    clear_flag_3 = 1;
                    printf("line 547\n");
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 2);
                Distance_Sign[2].x = Distance_Sign[2].x - horse_data_array[2]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_3_texture, NULL, Distance_Sign + 2);
            }

            else{

                if(clear_flag_3){
                    SDL_RenderFillRect(rdr, tracks);
                    clear_flag_3 = 0;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 2);
                Distance_Sign[2].x = Distance_Sign[2].x - horse_data_array[2]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_3_texture, NULL, Distance_Sign + 2);
            }
            
        }
    
        if(Distance_Sign[2].x <= -40){   //判斷 X 座標,創造循環效果
            Distance_Sign[2].x = 760;
            s_index_3++;
            h_3_round++; 
            if(decrease_flag_3 && decrease_round < 4){
                //printf("line 460\n");
                slow_flag_3 = 0; //不要讓水坑重複出現
                decrease_round++;
            }    
        }
    }    


    //////////////四號賽馬///////////////////////
    if(h_4_round == 25){ //25圈
        finish_flag_4 = 1;
        if(horse_data_array[3]->racing_rank == 0){
            horse_data_array[3]->racing_rank = horse_data_array[3]->racing_rank + h_rank;
            h_rank += 1;
            printf("horse 4 is number %d\n", horse_data_array[3]->racing_rank);
        }
        SDL_SetRenderDrawColor(rdr,150,50,50,225);
        SDL_RenderFillRect(rdr, Distance_Sign + 3);
    }

    else{
        finish_flag_4 = 0;
        if(h_4_round > horse_data_array[3]->stamina){   //看體力有沒有到底
            SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
            SDL_RenderFillRect(rdr, Distance_Sign + 3);
            Distance_Sign[3].x = Distance_Sign[3].x - horse_data_array[3]->fatigue_speed; //控制移動速度
            SDL_RenderCopy(rdr, s_4_texture, NULL, Distance_Sign + 3);
        }

        //水坑的出現                                       
        else if(h_4_round == h_paddle_round && slow_flag_4){ 
            
            paddle(horse_data_array[3]->speed, h_paddle - 1);//水坑出現
            SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
            SDL_RenderFillRect(rdr, Distance_Sign + 3);
            Distance_Sign[3].x = Distance_Sign[3].x - horse_data_array[3]->speed; //控制移動速度
            SDL_RenderCopy(rdr, s_4_texture, NULL, Distance_Sign + 3);
            decrease_flag_4 = 1;
        }

        else{
             //水坑出現後的三輪
             //有效
            if(decrease_round > 0 && decrease_round < 4  && horse_data_array[3]->telegent < 37 && slow_flag_4){   

                if(brodcast_flag_1){
                    affect_event(4);
                    clear_flag_4 = 1;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 3);
                Distance_Sign[3].x = Distance_Sign[3].x - 4; //控制移動速度
                SDL_RenderCopy(rdr, s_4_texture, NULL, Distance_Sign + 3);
            }

            //無效
            else if(decrease_round > 0 && decrease_round < 4  && horse_data_array[3]->telegent >= 37 && slow_flag_4){   
                 
                if(brodcast_flag_2){
                    no_affect_event(4);
                    clear_flag_4 = 1;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 3);
                Distance_Sign[3].x = Distance_Sign[3].x - horse_data_array[3]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_4_texture, NULL, Distance_Sign + 3);
            }

            else{
                if(clear_flag_4){
                    SDL_RenderFillRect(rdr, tracks);
                    clear_flag_4 = 0;
                }
                SDL_SetRenderDrawColor(rdr,0,200,0,225);//跑道顏色
                SDL_RenderFillRect(rdr, Distance_Sign + 3);
                Distance_Sign[3].x = Distance_Sign[3].x - horse_data_array[3]->speed; //控制移動速度
                SDL_RenderCopy(rdr, s_4_texture, NULL, Distance_Sign + 3);
            }
                            
        }
        
        if(Distance_Sign[3].x <= -40){   //判斷 X 座標,創造循環效果
            Distance_Sign[3].x = 760;
            s_index_4++;
            h_4_round++;
            if(decrease_flag_4 && decrease_round < 4){
                slow_flag_4 = 0; //不要讓水坑重複出現
                decrease_round++;
            }      
        }

    }

    SDL_RenderPresent(rdr);
    SDL_Delay(10); //控制顯示速度

    SDL_DestroyTexture(s_1_texture);
    SDL_DestroyTexture(s_2_texture);
    SDL_DestroyTexture(s_3_texture);
    SDL_DestroyTexture(s_4_texture);

    SDL_FreeSurface(s_1_bmp_surf);
    SDL_FreeSurface(s_2_bmp_surf);
    SDL_FreeSurface(s_3_bmp_surf);
    SDL_FreeSurface(s_4_bmp_surf);
    
}

void recount_data(struct horse_data ** horse_data_array){

    for(int index = 0; index < 4; index++)
    {
        horse_data_array[index]->speed = horse_data_array[index]->speed / 47; //速度縮小到 9 ~ 13
        horse_data_array[index]->fatigue_speed = horse_data_array[index]->speed - 3; //疲累速度縮小到 6 ~ 10
        horse_data_array[index]->stamina = horse_data_array[index]->stamina / 26; //體力縮小到 15 ~ 23
        horse_data_array[index]->telegent =  horse_data_array[index]->telegent / 14; //體力縮小到 28 ~ 42

    }
}

int racing_event_loop(struct horse_data ** horse_data_array)
{
    int frameCounter = 0;  
    recount_data(horse_data_array);
    //draw_window();
    draw_Field();
    count_down_to_start();
    draw_Field();
    //draw_DistanceSign();

    int horse_paddle = 0, paddle_round;
    horse_paddle = creat_rand_for_horse();
    paddle_round = creat_rand_for_round();
                    
    while(1)
    {
        if(horse_position[0].x < 800 || horse_position[1].x < 800 || horse_position[2].x < 800 || horse_position[3].x < 800){
            
            square_move(horse_data_array, horse_paddle, paddle_round);//讓距離標誌開始移動  
            frameCounter++;
            if (frameCounter % 4 == 0) {
                draw_horse_1(finish_flag_1);
                draw_horse_4(finish_flag_4);
            }
            else if(frameCounter % 3 == 0){
                draw_horse_2(finish_flag_2);
                draw_horse_3(finish_flag_3);
            }
        }

        else{

            int first_horse = 0;
            for(int i = 0; i < 4; i++){
                if(horse_data_array[i]->racing_rank == 1){
                    first_horse = i + 1;
                    break;
                }
            }
            
            char winner_str[30];
            sprintf(winner_str, "%d號是第一名!!", first_horse);

            SDL_Surface *winner_horse_surf  = SDL_LoadBMP("winner_horse.bmp");
            SDL_Texture *winner_horse_texture = SDL_CreateTextureFromSurface(rdr, winner_horse_surf);
            SDL_RenderCopy(rdr, winner_horse_texture, NULL, NULL);
            
            draw_text(winner_str, 40, 290, 477);
            
            SDL_RenderPresent(rdr);
            SDL_DestroyTexture(winner_horse_texture);
            SDL_FreeSurface(winner_horse_surf);
            SDL_Delay(2000);
            return first_horse;
        }

    }

}

void reset_racing_virable(){

    horse_position[0] = {350, 130, 90, 75}; 
    horse_position[1] = {350, 250, 90, 75};
    horse_position[2] = {350, 370, 90, 75};
    horse_position[3] = {350, 490, 90, 75};

    paddle_position[0] = {800, 200, 90, 30};  //水坑位置
    paddle_position[1] = {800, 320, 90, 30};
    paddle_position[2] = {800, 440, 90, 30};
    paddle_position[3] = {800, 560, 90, 30};

    brodcast_flag_1 = 1;
    brodcast_flag_2 = 1;

    clear_flag_1 = 0;
    clear_flag_2 = 0;
    clear_flag_3 = 0;
    clear_flag_4 = 0;

    h_rank = 1; //計算跑完的排名 ,之後記得要reset
    h_1_round = 1; 
    h_2_round = 1;
    h_3_round = 1; 
    h_4_round = 1; //標示黑色方塊循環的次數， 之後記得要reset

    h_frameindex_1 = 1;
    h_frameindex_2 = 1; 
    h_frameindex_3 = 1; 
    h_frameindex_4 = 1; //馬跑步的圖片檢所, 之後記得要reset

    s_index_1 = 1;
    s_index_2 = 1; 
    s_index_3 = 1;
    s_index_4 = 1;  //distance sign 的圖片順序

    decrease_round = 0;

    decrease_flag_1 = 0;
    decrease_flag_2 = 0;
    decrease_flag_3 = 0;
    decrease_flag_4 = 0;

    slow_flag_1 = 0;
    slow_flag_2 = 0; 
    slow_flag_3 = 0;
    slow_flag_4 = 0; //控制水坑出現

    finish_flag_1 = 0;
    finish_flag_2 = 0; 
    finish_flag_3 = 0;
    finish_flag_4 = 0;
    finish_flag_event_loop = 0;
}

/*
printf("horse %d\n", index+1);
printf("speed %d\n", horse_data_array[index]->speed);
printf("fatigue_speed %d\n", horse_data_array[index]->fatigue_speed);
printf("telegent %d\n", horse_data_array[index]->telegent);
printf("stamina %d\n", horse_data_array[index]->stamina);
printf("rank %d\n", horse_data_array[index]->racing_rank);
printf("-------------------------------------------\n");
*/