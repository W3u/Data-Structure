//-------------------------------------------------------------
//Problem Descirption:
//����n����Χ����һ��Բ����Χ���ִӵ�s���˿�ʼ��1����������m���˳��У�
//Ȼ��ӳ��е���һ�������¿�ʼ��1����������m���ٳ���...
//��˷�����ֱ�������˶����У�������еĴ���
//
//�㷨˼·:
//����˳���洢�ṹ����n���˵ı��˳������˳����У�
//��˳����еĵ�s��Ԫ�ؿ�ʼѰ�ҵ�s+m-1��Ԫ�أ��ҵ����������Ѱ�ҹ�����������β��
//��������ʼλ�ã�ͨ��ȡģʵ�֣�����ɾ����Ԫ�أ���һ�δӸ�λ���ظ��������̡�
//-------------------------------------------------------------

#include <stdio.h>
#include "Sequence_List.h"

//Լɪ������
void Josephus();

int Josephus_SeqList(pSeqList pL,int s,int m);

int main()
{
    Josephus();
    return 0;
}

//Լɪ������
void Josephus()
{
	pSeqList pL = Init_SeqList();
	int i;
	for (i = 1; i<11; i++)
	{
		Insert_SeqList(pL, i, i);
	}
	Print_SeqList(pL);
	Josephus_SeqList(pL, 2, 5);
}

int Josephus_SeqList(pSeqList pL, int s, int m)
{
	if (pL == NULL)
	{
		printf("˳�������\n");
		return -2;
	}
	if (s<1 || s>pL->length)   //s��Ч��Χ1��length
	{
		printf("s������Ч��Χ��\n");
		return -1;
	}
	if (m < 0)
	{
		printf("m��Ч\n");
		return 0;
	}
	int s1 = s - 1;
	int i;
	while (pL->length != 0)
	{
		s1 = s1 + m - 1;
		//s1 % pL->length�Ľṹֵ����Ϊ0��0�����������±꣬��������λ��ֵ
		//��s1��ֵΪs-1;
		i = s1 % pL->length;		//ȡģ

		printf("%d ", pL->data[i]);
		Delete_SeqList(pL, i + 1);
	}
	return 1;
}

