#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct sNode{
    DataType data;
    struct sNode* next;
}LNode,* pLinkedList;

//1.�����յ�����
pLinkedList Create_LinkedList();

//2.���ٵ�����
void Distroy_LinkedList(pLinkedList pHead);

//3.�������
int Length_LinkedList(pLinkedList pHead);

//4.���Ҳ���������λ��Ϊi�ĵ�ַ
pLinkedList Locate_LinkedList_Pos(pLinkedList pHead,int i);

//5.���Ҳ���������ֵΪkey�Ľ�㣬���ؽ���ַ
pLinkedList Locate_LinkedList_Vaule(pLinkedList pHead,DataType key);

//6. �������:�ڵ�i��λ��ǰ����һ��ֵΪx���½ڵ㣬
int Insert_LinkedList(pLinkedList pHead,int i,DataType key);

//7.ɾ��������ɾ����i�����
int Delete_LinkedList(pLinkedList pHead,int i);

//8.����������
void Print_LinkedList(pLinkedList pHead);
