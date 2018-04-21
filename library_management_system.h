#ifndef __LIBRARY_MANAGEMENT_SYSTEM_H__
#define __LIBRARY_MANAGEMENT_SYSTEM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library_list.h"
#include "library_file.h"
#include "global.h"

/* 初始化图书管理系统 */
void init_library_management_system(LIBRARY_LIST_TYPE *library, FILE **library_fp);
/* 打印操作结果 */
void print_result(int result);

#endif
