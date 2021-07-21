// 注意: 这里千万不要包含mymem.h, 否则程序陷入死循环
// #include "./mem_checker.h"

/**
 * 5 可以自己跟踪动态内存使用情况, 当实现内存泄漏监测时就可用到.在写内存泄漏程序时要注意的：
 * 5.1 使用上面第一种方式，
       #define malloc(size) my_malloc(size, __FUNCTION__, __LINE__)
       #define free(ptr) my_free(ptr, __FUNCTION__, __LINE__);
   因为这样可以跟踪分配及释放内存的具体位置。
   5.2 每次调用malloc时， 将调用的具体位置(file, function, line)， 内存的起始地址， 内存长度等记录下来， 放在链表中。每次调用free时， 删除链表中相应的记录。
   5.3 分配时， 多分配一定数目的内存， 返回所分配内存的起始地址， 并将多分配的那一段的内存初始化为预定义的值。 以便在后续调用free时检查多分配的那一段内存的值， 看其值是否为预定义的值， 否则有非法内存访问。
   5.4 malloc时， 检查所分配的内存是否在链表中， 若是， 则内存分配有误。free时， 检查所释放的内存起始地址是否在链表中， 若是， 则释放该段内存，并删除链表中的记录； 否则， 为释放时非法内存。
   5.5 strdup 也分配了内存， 用上面的方法无法跟踪， 可用跟malloc/free相同的方法自定义strdup.
   5.6 new/delete, 可以用同样的方法做内存检测。
 */

// 标准c库的头文件, malloc及free需要试用.
#include <stdlib.h> 
#include <stdio.h>

void *my_malloc(unsigned int uSize, const char *pszFunc, unsigned int uLine)
{
    printf("MALLOC: func:%s; line:%d\r\n", pszFunc, uLine);
    return malloc(uSize); //调用标准C库的malloc.
}

void my_free(void *pPtr, const char *pszFunc, unsigned int uLine)
{
    printf("FREE: func:%s; line:%d\r\n", pszFunc, uLine);
    return free(pPtr); //调用标准C库的free.
}