#include"QuickSort.h"
#include"LinkStack.h"
#include<time.h>
#include<stdlib.h>

//��������
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSort(int *p,int start,int end,char state)
{
	if (start < end)
	{
		int partitionIndex;

		Partition(p, start, end,state, &partitionIndex);
		QuickSort(p, start, partitionIndex-1, state);//©д-1
		QuickSort(p, partitionIndex + 1, end, state);
	}
	return true;
}

//���·ָ�����
//����:p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�partitionIndex�ָ����������
bool Partition(int* p, int start, int end, int state,int* partitionIndex)
{
	//˫ָ�뷨Ҳ��
	int pivot = p[end];//��� ���ȡ����ã�����o��n^2��������
	*partitionIndex = start;//��¼
	if (state == 'r')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] < pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;//���� ��++ * ���ȼ�һ�������ҵ���Ҫ������
			}
		}
		int temp = p[end];
		p[end] = p[*partitionIndex];
		p[*partitionIndex] = temp;
	}
	else if (state == 'l')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] > pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;
			}
		}
		int temp = p[end];
		p[end] = p[*partitionIndex];
		p[*partitionIndex] = temp;
	}
	return true;

}


//�������򣨷ǵݹ�棩
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSortNoRecursion(int* p, int start, int end, char state)
{
	//˼·�����ݹ�ĳ�ѭ����Ҫ�õ�֮ǰʵ�ֵ�ջ  �ǳ����� ��ջ ������ �����Ĳ������Ҳ�� ��ͬ����˼·
	LinkStack stack;
	initLStack(&stack);
	pushLStack(&stack, start);
	pushLStack(&stack, end);

	while (isEmptyLStack(&stack) == ERROR)
	{
		int left;
		int right;
		popLStack(&stack, &right);
		popLStack(&stack, &left);

		int partitionIndex;
		Partition(p, left, right, state, &partitionIndex);

		if (left < partitionIndex-1)
		{
			pushLStack(&stack, left);
			pushLStack(&stack, partitionIndex - 1);//��һ��Ҫ��������ݣ�������
		}

		if (right > partitionIndex + 1)
		{
			pushLStack(&stack, partitionIndex+1);
			pushLStack(&stack, right);//��һ��Ҫ��������ݣ�������
		}

	}
	destroyLStack(&stack);

	return true;
}

//��������(���ȡ���)
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSortRandom(int* p, int start, int end, char state)
{
	if (start < end)
	{
		int partitionIndex;

		PartitionRandom(p, start, end, state, &partitionIndex);
		QuickSort(p, start, partitionIndex - 1, state);//©д-1
		QuickSort(p, partitionIndex + 1, end, state);
	}
	return true;
}


//���·ָ�����(���ȡ���)
//����:p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�partitionIndex�ָ����������
bool PartitionRandom(int* p, int start, int end, int state, int* partitionIndex)
{
	//˫ָ�뷨Ҳ��
	srand((unsigned int)time(NULL));
	int index = rand() % (end - start + 1) + start;
	int pivot = p[index];//��� ���ȡ����ã�����o��n^2��������
	
	
	int temp = p[end];
	p[end] = p[index];
	p[index] = temp;//����ص�һ�������

	*partitionIndex = start;//��¼
	if (state == 'r')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] < pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;//���� ��++ * ���ȼ�һ�������ҵ���Ҫ������
			}
		}
		int temp = p[end];
		p[end] = p[*partitionIndex];
		p[*partitionIndex] = temp;
	}
	else if (state == 'l')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] > pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;
			}
		}
		int temp = p[end];
		p[end] = p[*partitionIndex];
		p[*partitionIndex] = temp;
	}
	return true;

}


//��������(����ȡ�а�)
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSortThreeMid(int* p, int start, int end, char state)
{
	if (start < end)
	{
		int partitionIndex;

		PartitionThreeMid(p, start, end, state, &partitionIndex);
		QuickSort(p, start, partitionIndex - 1, state);//©д-1
		QuickSort(p, partitionIndex + 1, end, state);
	}
	return true;
}


//���·ָ�����(����ȡ�а�)
//����:p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�partitionIndex�ָ����������
bool PartitionThreeMid(int* p, int start, int end, int state, int* partitionIndex)
{
	//˫ָ�뷨Ҳ��
	int mid;
	intArrayMidIndex(p,start, (start + end) / 2, end, &mid);

	int pivot = p[mid];//��� ���ȡ����ã�����o��n^2��������


	int temp = p[end];
	p[end] = p[mid];
	p[mid] = temp;//����ص�һ�������

	*partitionIndex = start;//��¼
	if (state == 'r')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] < pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;//���� ��++ * ���ȼ�һ�������ҵ���Ҫ������
			}
		}
		int temp = p[end];
		p[end] = p[*partitionIndex];
		p[*partitionIndex] = temp;
	}
	else if (state == 'l')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] > pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;
			}
		}
		int temp = p[end];
		p[end] = p[*partitionIndex];
		p[*partitionIndex] = temp;
	}
	return true;

}

//���������д����м����������
//������p����ָ�룬a��b��c������midָ�룬���ش����м������
bool intArrayMidIndex( int *p,int a, int b, int c,int *mid)
{
	if (p[a] >= p[b] && p[a] >=p[c])
	{
		if (p[b] >= p[c])*mid = b;
		else *mid = c;
	}
	else if (p[b] >=p[a] && p[b] >= p[c])
	{
		if (p[a] >= p[c])*mid = a;
		else *mid = c;
	}
	else if (p[c] >= p[a] && p[c] >= p[b])
	{
		if (p[a] >= p[b])*mid = a;
		else *mid = b;
	}
	return true;
}