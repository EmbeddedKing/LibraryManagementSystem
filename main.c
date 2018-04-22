#include <stdio.h>
#include "library_management_system.h"

int main(int argc, char **argv)
{
	LIBRARY_LIST_TYPE library = NULL;
	BOOK_INFO_TYPE info = {};
	FILE *data_file = NULL;
	int ret = 0;
	int sel = 0;
	system("clear");
	lib_manage_sys_init(&library, &data_file);
	while (1)
	{
		scanf("%*[^\n]%*c");
		menu_display();
		scanf("%d", &sel);
		ret = menu_handle(sel, &library);
		if (sel == OPTDISPLAYLIB) {
			sleep(5);
		}
		system("clear");
		print_result(ret);
		if (ret == SYSEXIT) {
			break;
		}
	}
	lib_manage_sys_exit(&library, &data_file);

	return 0;
}
