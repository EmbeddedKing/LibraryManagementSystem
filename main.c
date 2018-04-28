#include <stdio.h>
#include "library_management_system.h"

int main(int argc, char **argv)
{
	LIBRARY_LIST_TYPE library = NULL;
	BOOK_INFO_TYPE info = {};
	FILE *data_file = NULL;
	int ret = 0;
	int sel = 0;
	char account[20] = {};
	char passwd[20] = {};
	while (ret != PWSUCCESS)
	{
		system("clear");
		print_result(ret);
		passwd_ui();
		printf("请输入账号：");
		scanf("%s", account);
		scanf("%*[^\n]%*c");
		printf("请输入密码：");
		scanf("%s", passwd);
		scanf("%*[^\n]%*c");
		ret = passwd_match(account, passwd);
	}
	system("clear");
	print_result(ret);
	lib_manage_sys_init(&library, &data_file);
	while (1)
	{
		menu_display();
		scanf("%d", &sel);
		scanf("%*[^\n]%*c");
		ret = menu_handle(sel, &library);
		if (sel == OPTDISPLAYLIB || sel == OPTFINDBOOK) {
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
