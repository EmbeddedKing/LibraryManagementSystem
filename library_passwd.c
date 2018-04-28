#include "library_passwd.h"

/* 登录界面UI */
void passwd_ui()
{
    printf("======================欢迎使用图书管理系统======================\n");
    printf("=========================作者：舒艺彬===========================\n");
    printf("=======================copyright©：舒艺彬=======================\n");
}

/* 密码匹配 */
int passwd_match(const char *account, const char *passwd)
{
    if (strcmp(account, admin))
    {
        return PWNOEXIST;
    }
    if (!strcmp(passwd, adminpw))
    {
        return PWSUCCESS;
    }
    return PWFAIL;
}
