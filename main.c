#include <stdio.h>
#include "library_management_system.h"

int main(int argc, char **argv)
{
	LIBRARY_LIST_TYPE library;
	FILE *library_fp;
	int ret;
	BOOK_INFO_TYPE info;

	/*
	init_library_management_system(&library, &library_fp);
	library_addbook(&library, 1, "速度与激情");
	library_addbook(&library, 15, "速度与激情1");
	library_display(library);
	library_close(library, library_fp);*/

	init_library(&library);

	info.book_num = 1;
	strcpy(info.book_name, "百年孤独");
	strcpy(info.author_name, "加西亚·马尔克斯");
	strcpy(info.publishing_time, "1967-0-0");
	print_addresult (library_addbook(&library, info));
	info.book_num = 2;
	strcpy(info.book_name, "蛙");
	strcpy(info.author_name, "莫言");
	strcpy(info.publishing_time, "2009-0-0");
	print_addresult (library_addbook(&library, info));
	info.book_num = 3;
	strcpy(info.book_name, "红玫瑰与白玫瑰");
	strcpy(info.author_name, "张爱玲");
	strcpy(info.publishing_time, "1944-0-0");
	print_addresult (library_addbook(&library, info));
	info.book_num = 123;
	strcpy(info.book_name, "红玫瑰与白玫瑰");
	strcpy(info.author_name, "张爱玲");
	strcpy(info.publishing_time, "1944-0-0");
	print_changeresult (library_changebook(&library, info));
	strcpy(info.book_name, "蛙");
	print_findresult (library_findbook(&library, &info));
	library_display(library);
	printf("num = %d\n", library_number(library));

	return 0;
}
