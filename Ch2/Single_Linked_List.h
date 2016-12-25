#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct sNode{
    DataType data;
    struct sNode* next;
}LNode,* pLinkedList;

//1.创建空单链表
pLinkedList Create_LinkedList();

//2.销毁单链表
void Distroy_LinkedList(pLinkedList pHead);

//3.求单链表表长
int Length_LinkedList(pLinkedList pHead);

//4.查找操作：返回位置为i的地址
pLinkedList Locate_LinkedList_Pos(pLinkedList pHead,int i);

//5.查找操作：查找值为key的结点，返回结点地址
pLinkedList Locate_LinkedList_Vaule(pLinkedList pHead,DataType key);

//6. 插入操作:在第i个位置前插入一个值为x的新节点，
int Insert_LinkedList(pLinkedList pHead,int i,DataType key);

//7.删除操作：删除第i个结点
int Delete_LinkedList(pLinkedList pHead,int i);

//8.遍历单链表
void Print_LinkedList(pLinkedList pHead);
