#include <stdio.h>
#include <stdlib.h>

#include "test1.h"

// 操作没有初始化的指针
void mem_bugs_1() {
    int *p;
    *p = 1;
    printf("mem_bugs_1 %d\n", *p);
}

// 操作被释放之后的指针
void mem_bugs_2() {
    int *p = (int *) malloc(sizeof(int));
    free(p);
    *p = 2;
    printf("mem_bugs_2 %d\n", *p);
}

// 越界
void mem_bugs_3() {
    int *p = (int *) malloc(sizeof(int));
    *(p + 1) = 3;
    printf("mem_bugs_3 %d\n", *p);
}

// 内存泄漏 有分配，没有释放
void mem_bugs_4() {
    int len = 1024;
    int *p = (int *) malloc(sizeof(int) * len);

    for (int i = 0; i < len; ++i) {
        *(p + i) = i;
    }
}

// malloc/new/new[] 和 free/delete/delete[] 使用混搭
void mem_bugs_5() {
    int len = 1024;
    int *p = (int *) malloc(sizeof(int) * len);

    for (int i = 0; i < len; ++i) {
        *(p + i) = i;
    }

    delete p;
}

// 两次释放内存
void mem_bugs_6() {
    int *p = (int *) malloc(sizeof(int) * len);
    free(p);
    free(p);
}



