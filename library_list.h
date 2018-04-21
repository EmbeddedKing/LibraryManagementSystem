#ifndef __LIBRARY_LIST_H__
#define __LIBRARY_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library_file.h"
#include "library_management_system.h"
#include "global.h"

/* 创建一个library链表 */
int library_init(LIBRARY_LIST_TYPE *library);
/* 向library中添加book */
int library_addbook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE book_info);
/* 通过书籍名删除library中的book */
int library_delbook(LIBRARY_LIST_TYPE *library, char *book_name);
/* 通过书籍名去修改book info */
int library_changebook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE book_info);
/* 通过book_info中的书籍名查找book info */
int library_findbook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE *book_info);
/* 判断图书馆是否有书籍 */
int library_empty(LIBRARY_LIST_TYPE library);
/* 计算library中book的数量 */
int library_number(LIBRARY_LIST_TYPE library);
/* 显示图书馆中全部的图书 */
void library_display(LIBRARY_LIST_TYPE library);

#endif
