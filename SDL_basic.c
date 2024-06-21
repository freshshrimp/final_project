#include "SDL_basic.h"
////
//初始化及銷毀
//////////////////////////////
SDL_Window *win = NULL;
SDL_Renderer *rdr = NULL;
int init() //初始化
{
    //初始化
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("Init failed: %s", SDL_GetError());
        return -1;
    }
    //創建窗口
    win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_LENGTH,0);
    if(win == NULL)
    {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        return -1;
    }
    //創建渲染器(創見與窗口有關的渲染器)
    rdr = SDL_CreateRenderer(win, -1, 0);
    if(rdr == NULL)
    {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return -1;
    }

    return 0;
}

void deinit() //銷毀
{
    //銷毀選染器
    SDL_DestroyRenderer(rdr);
    //銷毀窗口
    SDL_DestroyWindow(win);
    //退出
    SDL_Quit();
}
//////////////////////////////

//顯示工具
//////////////////////////////
void draw_text(const char *string, int word_size, int x_position, int y_position)   //印出黑色文字
{
    // 初始化TTF
    if(TTF_Init() < 0)
    {
        SDL_Log("TTF_Init failed: %s", TTF_GetError());
        return;
    }

    // 打開字體
    TTF_Font *font = TTF_OpenFont("word.ttc", word_size);
    if(font == NULL)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return;
    }

    // 渲染字體
    SDL_Color color = {0, 0, 0, 255};
    SDL_Surface *txt_surf = TTF_RenderUTF8_Blended(font, string, color);
    if(txt_surf == NULL)
    {
        SDL_Log("TTF_RenderText_Solid failed: %s", TTF_GetError());
        return;
    }
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(rdr, txt_surf);
    if (text_texture == NULL) 
    {
        SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        return;
    }

    //呈現文字
    SDL_Rect text_rect = {x_position, y_position, txt_surf->w, txt_surf->h};
    SDL_RenderCopy(rdr, text_texture, NULL, &text_rect);
    SDL_RenderPresent(rdr);

    // 釋放資源
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(txt_surf);
    TTF_CloseFont(font);
}

void draw_white_text(const char *string, int word_size, int x_position, int y_position)   //印出白色文字
{
    // 初始化TTF
    if(TTF_Init() < 0)
    {
        SDL_Log("TTF_Init failed: %s", TTF_GetError());
        return;
    }

    // 打開字體
    TTF_Font *font = TTF_OpenFont("word.ttc", word_size);
    if(font == NULL)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return;
    }

    // 渲染字體
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *txt_surf = TTF_RenderUTF8_Blended(font, string, color);
    if(txt_surf == NULL)
    {
        SDL_Log("TTF_RenderText_Solid failed: %s", TTF_GetError());
        return;
    }
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(rdr, txt_surf);
    if (text_texture == NULL) 
    {
        SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        return;
    }

    //呈現文字
    SDL_Rect text_rect = {x_position, y_position, txt_surf->w, txt_surf->h};
    SDL_RenderCopy(rdr, text_texture, NULL, &text_rect);
    SDL_RenderPresent(rdr);

    // 釋放資源
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(txt_surf);
    TTF_CloseFont(font);
}

void draw_yellow_text(const char *string, int word_size, int x_position, int y_position)   //印出黃色文字
{
    // 初始化TTF
    if(TTF_Init() < 0)
    {
        SDL_Log("TTF_Init failed: %s", TTF_GetError());
        return;
    }

    // 打開字體
    TTF_Font *font = TTF_OpenFont("word.ttc", word_size);
    if(font == NULL)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return;
    }

    // 渲染字體
    SDL_Color color = {255, 255, 0, 255};
    SDL_Surface *txt_surf = TTF_RenderUTF8_Blended(font, string, color);
    if(txt_surf == NULL)
    {
        SDL_Log("TTF_RenderText_Solid failed: %s", TTF_GetError());
        return;
    }
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(rdr, txt_surf);
    if (text_texture == NULL) 
    {
        SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        return;
    }

    //呈現文字
    SDL_Rect text_rect = {x_position, y_position, txt_surf->w, txt_surf->h};
    SDL_RenderCopy(rdr, text_texture, NULL, &text_rect);
    SDL_RenderPresent(rdr);

    // 釋放資源
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(txt_surf);
    TTF_CloseFont(font);
}

int draw_picture(const char *picture_name, int x_position, int y_position, SDL_Rect* rect)  //繪製畫面
{
    // 渲染圖片
    SDL_Surface *img_surf = SDL_LoadBMP(picture_name);
    if (img_surf == NULL)
    {
        SDL_Log("SDL_LoadBMP failed: %s", SDL_GetError());
        return -1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(rdr, img_surf);
    if (texture == NULL)
    {
        SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        return -1;
    }

    // 渲染圖片
    *rect = {x_position, y_position, img_surf->w, img_surf->h}; // 設置圖片顯示位置和大小
    SDL_RenderCopy(rdr, texture, NULL, rect); // 複製圖片到渲染器
    SDL_RenderPresent(rdr);

    // 釋放資源
    SDL_FreeSurface(img_surf); // 釋放表面
    SDL_DestroyTexture(texture); // 銷毀紋理

    return 0;
}
//////////////////////////////


//響應事件的函式
//////////////////////////////
void click_botton_event(SDL_Rect rect)  //響應點擊按鈕事件
{
    //事件監聽(是否點擊關閉視窗)與響應
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
                    if(SDL_PointInRect(&mouse_point, &rect))
                    {
                        return;
                    }

                default:
                    break;
            }
        }
    }
}

void personal_menu_click_event(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2)
{
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
                        *botton_selection = 1;
                        return;
                    }
                    else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                    {
                        *botton_selection = 2;
                        return;
                    }

                default:
                    break;
            }
        }
    }
}

void leave_menu_click_event(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2)
{
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
                        *botton_selection = 1;
                        return;
                    }
                    else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                    {
                        *botton_selection = 2;
                        return;
                    }

                default:
                    break;
            }
        }
    }
}
//////////////////////////////


//各種菜單
//////////////////////////////
void position_transport_menu(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2, SDL_Rect picture_rect_3, SDL_Rect picture_rect_4, int *selection_of_location)
{
    //顯示背景
    SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);//設置渲染顏色
    SDL_RenderClear(rdr);//刷新屏幕
    SDL_RenderPresent(rdr);//顯示屏幕

    //地點選擇場景
    draw_text("選擇場景", 30, 340, 10);
    draw_picture("img_cross.bmp", 740, 5, &picture_rect_1);
    draw_picture("img_botton.bmp", 310, 200, &picture_rect_2);
    draw_text("賽馬集中區", 24, 340, 205);
    draw_picture("img_botton.bmp", 310, 300, &picture_rect_3);
    draw_text("馬券購買處", 24, 340, 305);
    draw_picture("img_botton.bmp", 310, 400, &picture_rect_4);
    draw_text("賽馬分析師的攤位", 20, 320, 410);

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
                        *selection_of_location = 0;
                        return;
                    }
                    else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                    {
                        *selection_of_location = 1;
                        return;
                    }
                    else if(SDL_PointInRect(&mouse_point, &picture_rect_3))
                    {
                        *selection_of_location = 2;
                        return;
                    }
                    else if(SDL_PointInRect(&mouse_point, &picture_rect_4))
                    {
                        *selection_of_location = 3;
                        return;
                    }

                default:
                    break;
            }
        }
    }
}

void concentration_area_menu_click_event(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2)
{
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
                        *botton_selection = 1;
                        return;
                    }
                    else if(SDL_PointInRect(&mouse_point, &picture_rect_2))
                    {
                        *botton_selection = 2;
                        return;
                    }

                default:
                    break;
            }
        }
    }
}
//////////////////////////////

//隨機變數
//////////////////////////////
int random(int number)//隨機變數，當輸入5，就會隨機取0~5的其中一個數字
{
    return (rand() % (number + 1));
}

void random_horse_ability() //產生每天馬的數值
{
    for(int index = 0;index < NUMBER_OF_HORSE;index++)
    {
        int horse_extra_ability;//宣告變數存取馬的額外數值加成
        horse = (struct horse_data *)malloc(sizeof(struct horse_data));//建議一個新的型態為 struct horse_data 的 structure

        horse_extra_ability = random(200) - 100;//馬的額外數值加成在 -100~100之間
        horse->speed = BASIC_ABILITY_OF_HORSE + horse_extra_ability;//設定馬的速度數值
        horse_extra_ability = random(200) - 100;//馬的額外數值加成在 -100~100之間
        horse->stamina = BASIC_ABILITY_OF_HORSE + horse_extra_ability;//設定馬的耐力數值
        horse_extra_ability = random(200) - 100;//馬的額外數值加成在 -100~100之間
        horse->telegent = BASIC_ABILITY_OF_HORSE + horse_extra_ability;//設定馬的智力數值

        ///////////////////////////////////
        horse->fatigue_speed = 0;
        horse->racing_rank = 0;
        ///////////////////////////////////

        horse_data_array[index] = horse;//將這匹馬的資訊存入陣列中
    }
}
//////////////////////////////
