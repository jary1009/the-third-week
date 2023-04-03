#include"BubbleSort.h"


//ð���Ż�1����־
//����:p����ָ�룬size�����С��state'r'�ұߴ�'l'��ߴ�
bool BubbleSortFlag(int* p, int size,char state)
{
	int flag = 0;//��û�н�����

	if (state == 'r')
	{
		for (int i = 0; i < size-1; i++)
		{
			flag = 0;
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (p[j + 1] < p[j])
				{
					swap(&p[j+ 1], &p[j]);
					flag = 1;
				}
			}
			if (flag == 0)
				break;
		}	
	}
	else if (state == 'l')
	{
		for (int i = 0; i < size - 1; i++)
		{
			flag = 0;
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (p[j + 1] > p[j])
				{
					swap(&p[j + 1], &p[j]);
					flag = 1;
				}
			}
			if (flag == 0)
				break;
		}
	}
	return true;
}

//ð���Ż�2��˫��
//����:p����ָ�룬size�����С��state'r'�ұߴ�'l'��ߴ�
bool BubbleSortTwoWay(int* p, int size, char state)
{
	if (state == 'r')
	{
		for (int i = 0; i < size / 2; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (p[j + 1] < p[j])
				{
					swap(&p[j + 1], &p[j]);
				}
			}
			for (int k = size - 1 - i; k > 0; k--)
			{
				if (p[k ] < p[k-1])
				{
					swap(&p[k - 1], &p[k]);
				}
			}
		}
	}
	else if (state == 'l')
	{
		for (int i = 0; i < size / 2; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (p[j + 1] > p[j])
				{
					swap(&p[j + 1], &p[j]);
				}
			}
			for (int k = size - 1 - i; k > 0; k--)
			{
				if (p[k] > p[k - 1])
				{
					swap(&p[k - 1], &p[k]);
				}
			}
		}
	}

	return true;
}

//ð���Ż�3��˫��+��־
//����:p����ָ�룬size�����С��state'r'�ұߴ�'l'��ߴ�
bool BubbleSortTwoWayFlag(int* p, int size, char state)
{
	int flag = 0;//û������

	if (state == 'r')
	{
		flag = 0;
		for (int i = 0; i < size / 2; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (p[j + 1] < p[j])
				{
					swap(&p[j + 1], &p[j]);
					flag = 1;
				}
			}
			for (int k = size - 1 - i; k > 0; k--)
			{
				if (p[k] < p[k - 1])
				{
					swap(&p[k - 1], &p[k]);
					flag = 1;
				}
			}
			if (flag == 0)break;
		}
	}
	else if (state == 'l')
	{
		flag = 0;
		for (int i = 0; i < size / 2; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (p[j + 1] > p[j])
				{
					swap(&p[j + 1], &p[j]);
					flag = 1;
				}
			}
			for (int k = size - 1 - i; k > 0; k--)
			{
				if (p[k] > p[k - 1])
				{
					swap(&p[k - 1], &p[k]);
					flag = 1;
				}
			}
			if (flag == 0)break;
		}
	}

	return true;
}

//����������
//����:a,bָ�룬���ؽ������ֵ
bool swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}