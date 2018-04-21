#include <stdio.h>
#include "library_management_system.h"

int main(int argc, char **argv)
{
	LIBRARY_LIST_TYPE library = NULL;
	BOOK_INFO_TYPE info = {};
	FILE *data_file = NULL;

	library_init(&library);
	printf("将文件中的数据读入到library链表中并清空文件：");
	print_result(file_init(&library, &data_file));

	strcpy(info.book_num, "1");
	strcpy(info.book_name, "百年孤独");
	strcpy(info.author_name, "加西亚·马尔克斯");
	strcpy(info.publishing_time, "1967-0-0");
	printf("添加书籍：");
	print_result (library_addbook(&library, info));
	strcpy(info.book_num, "2");
	strcpy(info.book_name, "蛙");
	strcpy(info.author_name, "莫言");
	strcpy(info.publishing_time, "2009-0-0");
	printf("添加书籍：");
	print_result (library_addbook(&library, info));
	strcpy(info.book_num, "3");
	strcpy(info.book_name, "红玫瑰");
	strcpy(info.author_name, "张爱玲");
	strcpy(info.publishing_time, "1944-0-0");
	printf("添加书籍：");
	print_result (library_addbook(&library, info));
	strcpy(info.book_num, "123");
	strcpy(info.book_name, "红玫瑰与白玫瑰");
	strcpy(info.author_name, "张爱玲");
	strcpy(info.publishing_time, "1944-0-0");
	printf("更改书籍：");
	print_result (library_changebook(&library, info));
	strcpy(info.book_name, "蛙");
	printf("查找书籍：");
	print_result (library_findbook(&library, &info));
	library_display(library);
	printf("num = %d\n", library_number(library));

	printf("写入文件：");
	print_result(file_write(&library, data_file));
	printf("关闭文件：");
	print_result(file_close(data_file));

	return 0;
}
