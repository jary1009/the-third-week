#include<stdlib.h>

//��������
//������p����ָ�룬size�����С��state��l����ߴ�r���ұߴ�
bool InsertSort(int* p, int size,char state)
{
	//��׳�Է��� ����ָ�� �������С ������ʽ
	if (p == NULL)return false;


	//����
	int hole=1;//Ҫ�������ݵ�λ��

	if (state == 'r')
	{
		for (int i = 1; i < size ; i++)
		{
			hole = i;//����Ҫ���������
			int value = p[i];//��ʱ�ó�����
			while (hole > 0 && p[hole - 1] > value)
				//����������0���Ѿ���ͷ�����뽫��������ǰ�ƣ�
				//���綴ǰ������ݱ�Ҫ�����ֵ��������һλ��������ǰ��һλ��
			{
				p[hole] = p[hole - 1];
				hole--;
			}
			p[hole] = value;
		}
	}
	else if (state == 'l')
	{
		for (int i = 1; i < size ; i++)
		{
			hole = i;//����Ҫ���������
			int value = p[i];//��ʱ�ó�����
			while (hole > 0 && p[hole - 1] < value)
				//����������0���Ѿ���ͷ�����뽫��������ǰ�ƣ�
				//���綴ǰ������ݱ�Ҫ�����ֵС������һλ��������ǰ��һλ��
			{
				p[hole] = p[hole - 1];
				hole--;
			}
			p[hole] = value;
		}
	}
	else return false;
	return true;
}