#include "library_list.h"

/* 初始化library */
int library_init(LIBRARY_LIST_TYPE *library)
{
	/* 分配头结点 */
    if (((*library) = (struct _library_node*)malloc(sizeof(struct _library_node))) == NULL) {
    	return LIBALLOCERR;
    }
	/* 初始化头结点 */
    memset((*library), '\0', sizeof(struct _library_node));
	strcpy((*library)->book.book_num, "编号");
    strcpy((*library)->book.book_name, "书籍名字");
	strcpy((*library)->book.author_name, "作者名");
	strcpy((*library)->book.publishing_time, "出版时间");
    (*library)->next = NULL;
	return LIBSUCCESS;
}

/* 在尾部增一本新书，并且检查library中是否存在这本书
 * 成功返回 ADD_SUCCESS
 * 书籍已存在返回 ADD_EXIST
 */
int library_addbook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE book_info)
{
	/* 如果图书馆未初始化，返回ADD_LIBNOINIT错误 */
	if ((*library) == NULL)
	{
		return LIBNOINIT;
	}
	/* 如果图书馆的书籍已达最大值，返回ADD_LIBMAX错误 */
	if (library_number(*library) == LIB_MAXSIZE)
	{
		return LIBMAX;
	}
	/* 定义一个工作指针和一个新节点指针 */
    LIBRARY_LIST_TYPE work_pointer, new_book;
    work_pointer = *library;

	/* 找到最后一个节点 */
    while (work_pointer->next != NULL) {
		/* 在寻找最后一个节点的过程中去寻找是否有一样的书名 */
		if(!strcmp(work_pointer->book.book_name, book_info.book_name))
		{
			/* 找到相等的书名则函数返回 */
			return LIBEXIST;
		}
		/* 没匹配成功则继续循环找最后的节点 */
        work_pointer = work_pointer->next;
    }

	/* 如果确实是最后一个节点并且书名不匹配则添加新书 */
	if(work_pointer->next == NULL && strcmp(work_pointer->book.book_name, book_info.book_name))
	{
		/* 创建新书的节点 */
		new_book = (struct _library_node*)malloc(sizeof(struct _library_node));
		if (new_book == NULL)
		{
			return LIBALLOCERR;
		}
		memset(new_book, 0, sizeof(struct _library_node));
		memcpy(&(new_book->book), &book_info, sizeof(BOOK_INFO_TYPE));
		new_book->next = NULL;
		/* 将新节点接在library尾部 */
		work_pointer->next = new_book;
		return LIBSUCCESS;
	}
	return LIBEXIST;
}

/* 通过文件名删除图书
 * 删除成功返回DEL_SUCCESS
 * 文件不存在返回DEL_NOEXIST
 */
int library_delbook(LIBRARY_LIST_TYPE *library, char *book_name)
{
	if ((*library) == NULL)
	{
		return LIBNOINIT;
	}
	/* 先判断library是否为空 */
	if(library_empty(*library))
	{
		return LIBEMPTY;
	}

	/* 定义一个工作指针，去寻找要删除的节点
     * 定义一个前指针，指向要删除节点的前一个节点
	 */
	LIBRARY_LIST_TYPE work_pointer, prev_pointer;
	prev_pointer = *library;
	work_pointer = (*library)->next;

	/* 寻找要删除的节点
	 * 在找到要删除的节点或者没有找到会跳出循环
	 */
	while (work_pointer != NULL)
	{
		/* 如果找到了要删除的书籍名字，则跳出循环，
		 * 这时工作指针指向要删除节点，前指针指向前一个节点
		 */
		if(!strcmp(work_pointer->book.book_name, book_name))
		{
			break;
		}
		/* 没找到即移到下一个节点 */
		prev_pointer = prev_pointer->next;
		work_pointer = work_pointer->next;
	}

	/* 判断是否真的找到了 */
	if (work_pointer != NULL)
	{
		/* 真的找到了就将这个节点释放掉 */
		prev_pointer->next = work_pointer->next;
		free(work_pointer);
		return LIBSUCCESS;
	}
	/* 没有找到就返回不存在 */
	return LIBNOEXIST;
}

/* 通过书籍名去修改图书的信息 */
int library_changebook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE book_info)
{
	/* 如果图书馆未初始化，则返回CH_LIBNOINIT错误 */
	if ((*library) == NULL)
	{
		return LIBNOINIT;
	}
	/* 判断图书馆中是否有书籍，没有就返回CH_EMPTY错误 */
	if (library_empty(*library))
	{
		return LIBEMPTY;
	}

	/*定义一个工作指针指向第一个节点 */
	LIBRARY_LIST_TYPE work_pointer;
	work_pointer = (*library)->next;

	/* 开始循环，当到达尾节点或者匹配到相应的书籍时跳出循环 */
	while (work_pointer != NULL)
	{
		if (!strcmp(work_pointer->book.book_name, book_info.book_name)) {
			break;
		}
		work_pointer = work_pointer->next;
	}

	/* 如果没有找到书籍，则返回CH_NOEXIST错误 */
	if (work_pointer == NULL) {
		return LIBNOEXIST;
	}

	/* 确实已经找到了要修改的书籍，则修改书籍信息 */
	if(!strcmp(work_pointer->book.book_name, book_info.book_name))
	{
		memcpy(&(work_pointer->book), &book_info, sizeof(book_info));
		return LIBSUCCESS;
	}
	return LIBNOEXIST;
}

/* 通过book_info中的文件名查找图书信息 */
int library_findbook(LIBRARY_LIST_TYPE *library, BOOK_INFO_TYPE *book_info)
{
	/* 如果图书馆未初始化，则返回FIND_LIBNOINIT错误 */
	if ((*library) == NULL)
	{
		return LIBNOINIT;
	}
	/* 判断是否为空 */
	if (library_empty(*library))
	{
		return LIBEMPTY;
	}
	LIBRARY_LIST_TYPE work_pointer;
	work_pointer = (*library)->next;
	while (work_pointer != NULL)
	{
		/* 匹配名字 */
		if(!strcmp(work_pointer->book.book_name, book_info->book_name))
		{
			break;
		}
		work_pointer = work_pointer->next;
	}
	if (work_pointer == NULL)
	{
		return LIBNOEXIST;
	}
	if (!strcmp(work_pointer->book.book_name, book_info->book_name))
	{
		/* 把要查找的书籍的信息付给book_info结构体指针指向的结构体 */
		memcpy(book_info, &work_pointer->book, sizeof(BOOK_INFO_TYPE));
		return LIBSUCCESS;
	}
	return LIBNOEXIST;
}

/* 判断链表是否为空
 * 为空返回1
 * 不为空返回0
 */
int library_empty(LIBRARY_LIST_TYPE library)
{
	/* 判断第一个节点是否存在 不存在则返回1，存在则返回0 */
	return library->next == NULL? 1: 0;
}

/* 计算library中的图书的数量
 * 返回计算的数量
 */
int library_number(LIBRARY_LIST_TYPE library)
{
	/* 定义一个num用来保存图书的数量
	 * 一个工作指针指向第一个节点
	 */
	if (library == NULL) {
		 return -1;
	}
	LIBRARY_LIST_TYPE work_pointer;
	int num = 0;
	work_pointer = library->next;
	/* 当工作指针为NULL时跳出循环，尾节点也计算在内 */
	while (work_pointer != NULL)
	{
		work_pointer = work_pointer->next;
		num++;
	}
	return num;
}

/* 打印library中的书籍 */
int library_display(LIBRARY_LIST_TYPE library)
{
	if (library == NULL)
	{
		printf("请调用library_init函数将图书馆初始化\n");
		return LIBNOINIT;
	}
	/* 定义一个工作指针指向头结点 */
    LIBRARY_LIST_TYPE work_pointer;
    work_pointer = library;
	//循环到文件尾
    while (work_pointer != NULL)
    {
		/* 没有到达文件尾则打印书籍信息并继续循环 */
        book_display(work_pointer->book);
		work_pointer = work_pointer->next;
	}
	return LIBSUCCESS;
}

/* 打印图书的信息 */
void book_display(BOOK_INFO_TYPE book_info)
{
    printf("%s\t\t%s\t\t%s\t\t%s\n", book_info.book_num,\
            book_info.book_name, book_info.author_name,\
            book_info.publishing_time);
}
