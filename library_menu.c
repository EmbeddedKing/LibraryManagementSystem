#include "library_menu.h"

/* 打印UI菜单 */
void menu_display()
{
    printf("==========图书管理系统==========\n");
    printf("=        1.添加一本书籍        =\n");
    printf("=        2.删除一本书籍        =\n");
    printf("=        3.更改书籍信息        =\n");
    printf("=        4.查询书籍信息        =\n");
    printf("=    5.显示图书馆中所有的图书  =\n");
    printf("=     6.退出图书管理系统       =\n");
    printf("================================\n");
    printf("请选择：");
}

/* 处理用户选择的操作，返回处理结果
 * 传入你要的操作和链表头
 */
int menu_handle(int sel, LIBRARY_LIST_TYPE *library)
{
    /* 定义一个书籍信息结构体和一个ret
     * 结构体用来录入信息，ret用来接收返回值
     */
    BOOK_INFO_TYPE book_info = {};
    int ret = 0;
    switch (sel) {
        /* 添加图书操作 */
        case OPTADDBOOK:
            printf("添加一本图书:\n");
            printf("请输入书籍的编号：");
            scanf("%s", book_info.book_num);
            scanf("%*[^\n]%*c");
            printf("请输入书籍名：");
            scanf("%s", book_info.book_name);
            scanf("%*[^\n]%*c");
            printf("请输入书籍的作者：");
            scanf("%s", book_info.author_name);
            scanf("%*[^\n]%*c");
            printf("请输入书籍的出版时间：");
            scanf("%s", book_info.publishing_time);
            scanf("%*[^\n]%*c");
            ret = library_addbook(library, book_info);
            break;
        /* 删除图书操作 */
        case OPTDELBOOK:
            printf("删除一本图书：\n");
            printf("请输入要删除的书籍名：");
            scanf("%s", book_info.book_name);
            scanf("%*[^\n]%*c");
            ret = library_delbook(library, book_info.book_name);
            break;
        /* 修改图书操作 */
        case OPTCHBOOK:
            printf("更改书籍信息：\n");
            printf("请输入要书籍更改之后的编号：");
            scanf("%s", book_info.book_num);
            scanf("%*[^\n]%*c");
            printf("请输入书籍名：");
            scanf("%s", book_info.book_name);
            scanf("%*[^\n]%*c");
            printf("请输入书籍更改之后的作者：");
            scanf("%s", book_info.author_name);
            scanf("%*[^\n]%*c");
            printf("请输入书籍更改之后的出版时间：");
            scanf("%s", book_info.publishing_time);
            scanf("%*[^\n]%*c");
            ret = library_changebook(library, book_info);
            break;
        /* 查找图书操作 */
        case OPTFINDBOOK:
            printf("查询书籍信息：\n");
            printf("请输入要查找的书籍名：");
            scanf("%s", book_info.book_name);
            scanf("%*[^\n]%*c");
            ret = library_findbook(library, &book_info);
            book_display(book_info);
            break;
        /* 显示图书馆中所有的图书操作 */
        case OPTDISPLAYLIB:
            printf("显示图书馆中所有的图书\n");
            ret = library_display(*library);
            break;
        /* 退出图书管理系统的操作 */
        case OPTEXIT:
            ret = SYSEXIT;
            break;
        default:
            printf("无法识别的操作\n");
            break;
    }
    /* 返回操作结果 */
    return ret;
}
