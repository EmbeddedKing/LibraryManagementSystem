#include "library_management_system.h"

void init_library_management_system(LIBRARY_LIST_TYPE *library, FILE **library_fp)
{

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
			printf("文件打开失败或未打开\n");
			break;
		case FILECLOSE:
			printf("文件关闭失败\n");
			break;
		default:
			printf("无法识别的错误类型\n");
			break;
	}
	return;
}
