#ifndef SDL_BASIC_H
#define SDL_BASIC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDL_variable.h"

#define WINDOW_WIDTH 800 //窗口寬度
#define WINDOW_LENGTH 600 //窗口長度
extern SDL_Window *win;
extern SDL_Renderer *rdr;
extern int init();
extern void deinit();

extern void draw_text(const char *string, int word_size, int x_position, int y_position);
extern void draw_white_text(const char *string, int word_size, int x_position, int y_position);
extern void draw_yellow_text(const char *string, int word_size, int x_position, int y_position);
extern int draw_picture(const char *picture_name, int x_position, int y_position, SDL_Rect* rect);

extern void click_botton_event(SDL_Rect rect);
extern void personal_menu_click_event(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2);
extern void leave_menu_click_event(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2);

extern void position_transport_menu(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2, SDL_Rect picture_rect_3, SDL_Rect picture_rect_4, int *selection_of_location);
extern void concentration_area_menu_click_event(int *botton_selection, SDL_Rect picture_rect_1, SDL_Rect picture_rect_2);

extern int random(int number);
extern void random_horse_ability();

#endif