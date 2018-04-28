#ifndef __LIBRARY_MANAGEMENT_SYSTEM_H__
#define __LIBRARY_MANAGEMENT_SYSTEM_H__

#include "global.h"
#include "library_file.h"
#include "library_menu.h"
#include "library_list.h"
#include "library_passwd.h"

/* 初始化图书管理系统 */
void lib_manage_sys_init(LIBRARY_LIST_TYPE *library, FILE **data_file);
/* 退出图书管理系统 */
void lib_manage_sys_exit(LIBRARY_LIST_TYPE *library, FILE **data_file);
/* 打印操作结果 */
void print_result(int result);

#endif
