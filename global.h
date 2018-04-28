#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 图书馆最多放置的书籍 */
#define LIB_MAXSIZE       200

/* library return value */
#define LIBSUCCESS        0    /* library操作成功 */
#define LIBALLOCERR       1    /* 空间分配失败 */
#define LIBEXIST          2    /* 书籍已存在 */
#define LIBNOEXIST        3    /* 书籍不存在 */
#define LIBEMPTY          4    /* library为空 */
#define LIBNOEMPTY        5    /* library不为空 */
#define LIBMAX            6    /* 存储数量已达最大值 */
#define LIBNOINIT         7    /* library未初始化 */
#define FILESUCCESS       8    /* file操作成功 */
#define FILENOOPEN        9    /* file未打开 */
#define FILECLOSE         10   /* file关闭失败 */
#define PWSUCCESS         11   /* 登录成功 */
#define PWNOEXIST         12   /* 账号不存在 */
#define PWFAIL            13   /* 密码错误 */
#define SYSEXIT           14   /* 系统退出 */

static char admin[20] = "admin";
static char adminpw[20] = "123456";

/* 书籍信息结构体
 * 增加属性需要修改以下函数内容
 * int file_write(LIBRARY_LIST_TYPE *library, FILE *data_file);
 * int file_init(LIBRARY_LIST_TYPE *library, FILE **library_fp);
 * void book_display(BOOK_INFO_TYPE book_info);
 */
typedef struct _book_info {
	char book_num[20];
	char book_name[50];
	char author_name[50];
	char publishing_time[20];
}BOOK_INFO_TYPE;

/* library节点结构体 */
typedef struct _library_node {
    struct _book_info book;
    struct _library_node *next;
}LIBRARY_NODE_TYPE, *LIBRARY_LIST_TYPE;

#endif
