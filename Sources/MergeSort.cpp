#include<stdlib.h>

#include"MergeSort.h"//找不到merge函数 ，引用 ，引用头文件

//归并排序 
//参数：p数组指针，start开始索引，end结尾索引,state‘r’右边大‘l’左边大
bool MergeSort(int* p,int start,int end,char state)
{
	//不能用数组长度，是变量，无法定义数组
	//int left[size / 2]; //可以malloc 再free  //算空间 多要了一点
	//
	if (p == NULL)return false;
	if (start>=end)return true;  //kao

	int mid = (end + start) / 2; //end为什么会小于0？？  //+!!  3到4 mid3
	MergeSort(p, start, mid,state);
	MergeSort(p, mid + 1, end,state);
	Merge(p, start, mid, end,state);
}

//归并操作
//参数：p数组指针，start左边索引，mid右边索引，end终止索引，state‘r’右边大，state，‘l’左边大
bool Merge(int* p, int start, int mid, int end,char state)
{
	//不能在原数组进行操作，会覆盖掉
	//int temp[end - start + 1] = { 0 };//不行
	int* temp = (int*)malloc(sizeof(int)*(end - start + 1));//漏写*sizeof(int)
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
				temp[tempIndex] = p[rightIndex];//可以合并，但没必要
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
				temp[tempIndex] = p[rightIndex];//可以合并，但没必要
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