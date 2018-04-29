#ifndef __LIBRARY_PASSWD_H__
#define __LIBRARY_PASSWD_H__

#include "global.h"

/* 登录界面UI */
void passwd_ui();
/* 密码匹配 */
int passwd_match(const char *account, const char *passwd);

#endif
