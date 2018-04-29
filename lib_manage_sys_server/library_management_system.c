#include "library_management_system.h"

void lib_manage_sys_init(LIBRARY_LIST_TYPE *library)
{
	printf("正在启动初始化程序...");
	print_result(library_init(library));
	printf("正在将文件中的数据读入到library链表中并清空文件...");
	print_result(file_init(library));
}

void lib_manage_sys_exit(LIBRARY_LIST_TYPE *library)
{
	printf("正在启动退出程序...\n");
	printf("正在将数据写入文件...");
	print_result(file_write(library));
}

/* 打印操作结果 */
void print_result(int result)
{
	switch (result) {
		case LIBSUCCESS:
			printf("操作成功\n");
			break;
		case LIBALLOCERR:
			printf("操作失败：图书空间分配失败\n");
			break;
		case LIBEXIST:
			printf("操作失败：书籍已存在\n");
			break;
		case LIBNOEXIST:
			printf("操作失败：书籍不存在\n");
			break;
		case LIBEMPTY:
			printf("操作失败：表为空\n");
			break;
		case LIBNOEMPTY:
			printf("操作失败：表不为空\n");
			break;
		case LIBMAX:
			printf("操作失败：已达存储最大值\n");
			break;
		case LIBNOINIT:
			printf("操作失败：图书馆未初始化\n");
			break;
		case FILESUCCESS:
			printf("文件操作成功\n");
			break;
		case FILENOOPEN:
			printf("文件打开失败\n");
			break;
		case FILECLOSE:
			printf("文件关闭失败\n");
			break;
		case PWSUCCESS:
			printf("登录成功\n");
			break;
		case PWNOEXIST:
			printf("账号不存在\n");
			break;
		case PWFAIL:
			printf("密码错误\n");
			break;
		case SOCKINITSUCCESS:
			printf("套接字初始化成功\n");
			break;
		case SOCKINITERR:
			printf("套接字初始化出错\n");
			break;
		case SYSEXIT:
			printf("退出图书管理系统\n");
			break;
		default:
			printf("无法识别的错误类型\n");
			break;
	}
	return;
}
