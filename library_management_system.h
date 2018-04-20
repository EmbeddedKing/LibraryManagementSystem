#ifndef __LIBRARY_MANAGEMENT_SYSTEM_H__
#define __LIBRARY_MANAGEMENT_SYSTEM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 图书馆最多放置的书籍 */
#define LIB_MAXSIZE  200

//init library return value
#define INIT_SUCCESS   0
#define INIT_ALLOCERR  1

//add book return value
#define	ADD_SUCCESS	   0   /* 添加成功 */
#define ADD_ALLOCERR   1   /* 分配空间失败 */
#define ADD_EXIST      2   /* 书籍已存在 */
#define ADD_LIBMAX     3   /* 书本已达最大值 */

//delete book return value
#define DEL_SUCCESS    0    /* 删除成功 */
#define DEL_NOEXIST    1    /* 书籍不存在 */
#define DEL_EMPTY      2    /* library为空 */

//change book return value
#define CH_SUCCESS     0    /* 修改成功 */
#define CH_NOEXIST     1    /* 书籍不存在 */
#define CH_EMPTY       2    /* library为空 */

//find book return value
#define FIND_SUCCESS   0    /* 查找成功 */
#define FIND_NOEXIST   1    /* 书籍不存在 */
#define FIND_EMPTY     2    /* library为空 */

/* 修改图书信息时只要修改library_display()函数中的输出格式即可，其他的函数可以不用修改 */
typedef struct _book_info {
	int book_num;
	char book_name[50];
	char author_name[50];
	char publishing_time[10];
}BOOK_INFO_TYPE;

typedef struct _library_node {
    struct _book_info book;
    struct _library_node *next;
}LIBRARY_NODE_TYPE, *LIBRARY_LIST_TYPE;

/* 初始化图书管理系统 */
void init_library_management_system(LIBRARY_LIST_TYPE *library, FILE **library_fp);
//void init_file(FILE **library_fp);
/* 创建一个图书馆 */
int init_library(LIBRARY_LIST_TYPE *library);

//void get_book(LIBRARY_LIST_TYPE *book_library, FILE *fp);

/* 向图书馆中添加图书 */
int library_addbook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE book_info);
/* 打印图书添加结果 */
void print_addresult(int addresult);
/* 通过书籍名删除图书馆中的图书 */
int library_delbook(LIBRARY_LIST_TYPE *library, char *book_name);
/* 打印图书删除结果 */
void print_delresult(int delresult);
/* 通过文件名去修改图书的信息 */
int library_changebook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE book_info);
/* 打印图书修改结果 */
void print_changeresult(int changeresult);
/* 通过book_info中的文件名查找图书信息 */
int library_findbook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE *book_info);
/* 打印图书查找结果 */
void print_findresult(int findresult);
/* 显示图书馆中全部的图书 */
void library_display(LIBRARY_LIST_TYPE library);
//void library_close(LIBRARY_LIST_TYPE library, FILE *library_fp);
/* 判断图书馆是否有书籍 */
int library_empty(LIBRARY_LIST_TYPE library);
/* 计算图书馆中书籍的数量 */
int library_number(LIBRARY_LIST_TYPE library);

#endif
