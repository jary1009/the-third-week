#include<stdlib.h>
#include<time.h>

//�������������
//������pָ�룬size�����С��min��max������Ԫ�ط�Χ  
//ע����int ���� -32������ ����
bool CreatRandomArray(int *p,double size,int min,int max)
{
	//���������
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)//��������200000�Ͳ�̫�����ˣ�������rand����������
	{
		p[i] = rand() % (max - min + 1) + min;
	}
	return true;
}