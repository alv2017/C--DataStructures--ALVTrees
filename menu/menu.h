#ifndef MENU_H
#define MENU_H

void display_menu(const char **menu);
short get_menu_length(const char **menu);
short select_option(short minopt, short maxopt);
int enter_value();

#endif
