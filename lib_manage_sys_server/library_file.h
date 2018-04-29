#ifndef __LIBRARY_FILE_H__
#define __LIBRARY_FILE_H__

#include "global.h"
#include "library_list.h"

/* 打开数据文件，并将数据写入到library中 */
int file_init(LIBRARY_LIST_TYPE *library);
/* 将library中的数据写入数据缓冲区文件 */
int file_write(LIBRARY_LIST_TYPE *library);

#endif
