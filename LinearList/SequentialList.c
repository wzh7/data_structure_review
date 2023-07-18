//
// Created by 63410 on 2023/7/18.
//

// include
#include "stdio.h"
#include "stdlib.h"
#include "ElemType.h"

// define
#define InitSize 10

// struct
typedef struct{
    ElemType data[InitSize];
    int length;
}StaticSqList; // static
typedef struct{
    ElemType *data;
    int MaxSize;
    int length;
}SqList; // non-static

// function declares
void InitStaticList(SqList *L);
void InitList(SqList *L);

// main
int main()
{
    SqList sqList;
    InitList(&sqList);
}

// functions
// init a sequential list.
void InitStaticList(SqList *L)
{
    for(int i = 0; i < InitSize; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

void InitList(SqList *L)
{
    L->data = (ElemType *) malloc(sizeof(ElemType) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

void IncreaseSize(SqList *L, int len)
{
    ElemType *p = L->data;  // temporary save data.
    L->data = (ElemType *) malloc(
            sizeof(ElemType) * (L->MaxSize + len)
            ); // get new space
    for(int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    } // copy data
    L->MaxSize += len; // add maxsize
    free(p); // release old space.
}