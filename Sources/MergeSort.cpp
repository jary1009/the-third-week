#include<stdlib.h>

#include"MergeSort.h"//�Ҳ���merge���� ������ ������ͷ�ļ�

//�鲢���� 
//������p����ָ�룬start��ʼ������end��β����,state��r���ұߴ�l����ߴ�
bool MergeSort(int* p,int start,int end,char state)
{
	//���������鳤�ȣ��Ǳ������޷���������
	//int left[size / 2]; //����malloc ��free  //��ռ� ��Ҫ��һ��
	//
	if (p == NULL)return false;
	if (start>=end)return true;  //kao

	int mid = (end + start) / 2; //endΪʲô��С��0����  //+!!  3��4 mid3
	MergeSort(p, start, mid,state);
	MergeSort(p, mid + 1, end,state);
	Merge(p, start, mid, end,state);
}

//�鲢����
//������p����ָ�룬start���������mid�ұ�������end��ֹ������state��r���ұߴ�state����l����ߴ�
bool Merge(int* p, int start, int mid, int end,char state)
{
	//������ԭ������в������Ḳ�ǵ�
	//int temp[end - start + 1] = { 0 };//����
	int* temp = (int*)malloc(sizeof(int)*(end - start + 1));//©д*sizeof(int)
	int tempIndex = 0;
	int leftIndex = start;
	int rightIndex = mid + 1;

	if (state == 'r')
	{
		while (leftIndex <= mid && rightIndex <= end)
		{
			if (p[leftIndex] < p[rightIndex])
			{
				temp[tempIndex] = p[leftIndex];
				leftIndex++;
				tempIndex++;
			}
			else if (p[leftIndex] >= p[rightIndex])
			{
				temp[tempIndex] = p[rightIndex];//���Ժϲ�����û��Ҫ
				rightIndex++;
				tempIndex++;
			}
		}
	}
	else if (state == 'l')
	{
		while (leftIndex <= mid && rightIndex <= end)
		{
			if (p[leftIndex] >= p[rightIndex])
			{
				temp[tempIndex] = p[leftIndex];
				leftIndex++;
				tempIndex++;
			}
			else if (p[leftIndex] < p[rightIndex])
			{
				temp[tempIndex] = p[rightIndex];//���Ժϲ�����û��Ҫ
				rightIndex++;
				tempIndex++;
			}
		}
	}
	while (leftIndex <= mid)
	{
		temp[tempIndex] = p[leftIndex];
		leftIndex++;
		tempIndex++;
	}
	while (rightIndex <= end)
	{
		temp[tempIndex] = p[rightIndex];
		rightIndex++;
		tempIndex++;
	}
	for (int i = 0; i < end - start + 1; i++)
	{
		p[start+i] = temp[i];
	}
	free(temp);
	temp = NULL;
	return true;
}