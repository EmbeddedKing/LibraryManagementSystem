# LibraryManagementSystem
# 图书管理系统
## 2018.4.20更新：
>     通过线性单向链表保存图书的信息
>     新增一个文件，1个源文件
>     mian.c

## 2018.4.21更新：
>     图书馆书籍信息可以保存名为library.data的本地文件
>     当链表初始化时会读取library.data本地文件，将之前保存的信息录入到链表中
>     将函数分类成多个头文件，模块化编程
>     新增8个文件，4个头文件，3个源文件，1个data文件
>     global.h、library_file.h、library_list.h、library_management_system.h
>     library_file.c、library_list.c、library_management_system.c
>     library.data

## 2018.4.22更新：
>     制作了图书管理系统的UI即菜单，优化了代码
>     系统不间断工作（while循环），由用户来决定要操作的功能
>     新增两个文件，1个头文件，1个源文件
>     library_menu.h、library_menu.c

## 2018.4.28更新
>     制作了图书管理系统的简单登录界面
>     登录超过三次就会退出
>     bug：程序出错按Ctrl+C会将文件内容全部清空
>     新增两个文件，一个头文件，一个源文件
>     library_passwd.h、library_passwd

## 2018.4.30深夜更新
>     将图书管理系统分为服务器端和客户端
>     通过udp协议传输文件
>     修复了程序出错按Ctrl+C会将文件内容全部清空的bug
>     新增两个文件，一个头文件，一个源文件
>     library_socket.h、library_socket.c
