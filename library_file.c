#include "library_file.h"

/* 将library.data中已有的文件数据添加到library链表中
 * 并清空library文件
 */
int file_init(LIBRARY_LIST_TYPE *library, FILE **data_file)
{
	/* 如果链表没有被初始化，则返回LIBNOINIT错误 */
	if ((*library) == NULL)
	{
		return LIBNOINIT;
	}
	/* 如果链表不为空，则返回LIBNOEMPTY错误 */
	if (!library_empty(*library))
	{
		return LIBNOEMPTY;
	}
	/* 先将文件以只读的方式打开 */
	(*data_file) = fopen("library.data", "r");
	/* 如果文件存在则将数据全部读出 */
	if((*data_file) != NULL)
	{
		/* 定义一个工作指针始终指向尾节点
		 * 定义一个新书类型用来接收文件中的数据
		 */
		LIBRARY_LIST_TYPE new_book, work_pointer;
		work_pointer = *library;
		char buf[100];
		/* 如果读到文件尾则跳出循环 */
		while (!feof(*data_file))
		{
			/* 给新节点分配空间 */
			new_book = NULL;
			new_book = (struct _library_node*)malloc(sizeof(struct _library_node));
			/* 分配失败返回LIBALLOCERR错误 */
			if (new_book == NULL)
			{
				return LIBALLOCERR;
			}
			/* 分配成功把数据清空 */
			memset(new_book, 0, sizeof(struct _library_node));
			/*把书号取出来 */
			if (fgets(buf, sizeof(buf), *data_file) != NULL)
			{
				/* 把取出来的数据存入到buf中，并把尾部的换行符去掉 */
				strncpy(new_book->book.book_num, buf, strlen(buf)-1);
				/* 清空缓存区 */
				memset(buf, 0, sizeof(buf));
			}
			else
			{
				/* 读取失败释放掉新节点空间并跳出循环 */
				free(new_book);
				break;
			}
			/* 把书名取出来 */
			if (fgets(buf, sizeof(buf), *data_file) != NULL)
			{
				strncpy(new_book->book.book_name, buf, strlen(buf)-1);
				memset(buf, 0, sizeof(buf));
			}
			else
			{
				free(new_book);
				break;
			}
			/* 把作者名取出来 */
			if (fgets(buf, sizeof(buf), *data_file) != NULL)
			{
				strncpy(new_book->book.author_name, buf, strlen(buf)-1);
				memset(buf, 0, sizeof(buf));
			}
			else
			{
				free(new_book);
				break;
			}
			/* 把出版时间取出来 */
			if (fgets(buf, sizeof(buf), *data_file) != NULL)
			{
				strncpy(new_book->book.publishing_time, buf, strlen(buf)-1);
				memset(buf, 0, sizeof(buf));
			}
			else
			{
				free(new_book);
				break;
			}
			/* 新节点的下一个节点指向NULL */
			new_book->next = NULL;
			/* 接在尾节点后面 */
			work_pointer->next = new_book;
			work_pointer = work_pointer->next;
		}
		/* 操作完毕，关闭文件 */
		fclose(*data_file);
	}
	/* 将数据文件再次以只写的方式打开，里面的数据会被清空 */
	(*data_file) = fopen("library.data", "w");
	/* 如果打开失败，则返回FILENOOPEN错误 */
	if ((*data_file) == NULL)
	{
		return FILENOOPEN;
	}
	/* 否则返回FILESUCCESS错误 */
	return FILESUCCESS;
}

/* 此函数将链表数据写入到缓冲区
 * 最好只调用一次，否则会出错
 */
int file_write(LIBRARY_LIST_TYPE *library, FILE *data_file)
{
	/* 如果文件未打开，则返回FILENOOPEN错误 */
	if (data_file == NULL)
	{
		return FILENOOPEN;
	}
	/* 如果library未初始化或初始化失败，则返回LIBNOINIT错误 */
	if ((*library) == NULL)
	{
		return LIBNOINIT;
	}
	/* 如果library为空，则返回LIBEMPTY错误 */
	if (library_empty(*library))
	{
		return LIBEMPTY;
	}
	/* 定义一个工作指针，工作指针指向第一个节点 */
	LIBRARY_LIST_TYPE work_pointer;
	work_pointer = (*library)->next;
	/* 当读到最后一本书则循环退出 */
	while (work_pointer != NULL)
	{
		/* 将数据以一个属性为一行的形式进行存储 */
		fputs((work_pointer->book).book_num, data_file);
		fputc('\n', data_file);
		fputs((work_pointer->book).book_name, data_file);
		fputc('\n', data_file);
		fputs((work_pointer->book).author_name, data_file);
		fputc('\n', data_file);
		fputs((work_pointer->book).publishing_time, data_file);
		fputc('\n', data_file);
		work_pointer = work_pointer->next;
	}
	/* 全部写完返回FILESUCCESS */
	return FILESUCCESS;
}

/* 用来关闭一个文件，并检查这个文件是否打开 */
int file_close(FILE *data_file)
{
	if (data_file == NULL)
	{
		return FILENOOPEN;
	}
	if (fclose((data_file)) == EOF)
	{
		return FILECLOSE;
	}
	return FILESUCCESS;
}
