#ifndef __LIBRARY_FILE_H__
#define __LIBRARY_FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library_list.h"
#include "library_management_system.h"
#include "global.h"

/* 打开数据文件，并将数据写入到library中 */
int file_init(LIBRARY_LIST_TYPE *library, FILE **library_fp);
/* 将library中的数据写入数据缓冲区文件 */
int file_write(LIBRARY_LIST_TYPE *library, FILE *data_file);
/* 关闭数据文件 */
int file_close(FILE *data_file);

#endif
