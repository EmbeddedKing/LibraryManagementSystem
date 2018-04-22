#ifndef __LIBRARY_MENU_H__
#define __LIBRARY_MENU_H__

#include "global.h"
#include "library_list.h"

/* 选择的宏定义 */
#define OPTADDBOOK     1
#define OPTDELBOOK     2
#define OPTCHBOOK      3
#define OPTFINDBOOK    4
#define OPTDISPLAYLIB  5
#define OPTEXIT        6

/* 打印UI菜单 */
void menu_display();
/* 处理用户选择的操作 */
int menu_handle(int sel, LIBRARY_LIST_TYPE *library);

#endif
