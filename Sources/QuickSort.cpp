#include"QuickSort.h"
#include"LinkStack.h"
#include<time.h>
#include<stdlib.h>

//快速排序
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSort(int *p,int start,int end,char state)
{
	if (start < end)
	{
		int partitionIndex;

		Partition(p, start, end,state, &partitionIndex);
		QuickSort(p, start, partitionIndex-1, state);//漏写-1
		QuickSort(p, partitionIndex + 1, end, state);
	}
	return true;
}

//大致分隔函数
//参数:p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大，partitionIndex分隔后的索引，
bool Partition(int* p, int start, int end, int state,int* partitionIndex)
{
	//双指针法也行
	int pivot = p[end];//轴点 随机取会更好，避免o（n^2）的最坏情况
	*partitionIndex = start;//记录
	if (state == 'r')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] < pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;//错误 ，++ * 优先级一样，从右到左，要加括号
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


//快速排序（非递归版）
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSortNoRecursion(int* p, int start, int end, char state)
{
	//思路：将递归改成循环，要用到之前实现的栈  非常巧妙 ，栈 的运用 ：树的层序遍历也是 ，同样的思路
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
			pushLStack(&stack, partitionIndex - 1);//下一组要处理的数据（索引）
		}

		if (right > partitionIndex + 1)
		{
			pushLStack(&stack, partitionIndex+1);
			pushLStack(&stack, right);//下一组要处理的数据（索引）
		}

	}
	destroyLStack(&stack);

	return true;
}

//快速排序(随机取轴版)
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSortRandom(int* p, int start, int end, char state)
{
	if (start < end)
	{
		int partitionIndex;

		PartitionRandom(p, start, end, state, &partitionIndex);
		QuickSort(p, start, partitionIndex - 1, state);//漏写-1
		QuickSort(p, partitionIndex + 1, end, state);
	}
	return true;
}


//大致分隔函数(随机取轴版)
//参数:p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大，partitionIndex分隔后的索引，
bool PartitionRandom(int* p, int start, int end, int state, int* partitionIndex)
{
	//双指针法也行
	srand((unsigned int)time(NULL));
	int index = rand() % (end - start + 1) + start;
	int pivot = p[index];//轴点 随机取会更好，避免o（n^2）的最坏情况
	
	
	int temp = p[end];
	p[end] = p[index];
	p[index] = temp;//化归回第一种情况。

	*partitionIndex = start;//记录
	if (state == 'r')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] < pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;//错误 ，++ * 优先级一样，从右到左，要加括号
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


//快速排序(三数取中版)
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSortThreeMid(int* p, int start, int end, char state)
{
	if (start < end)
	{
		int partitionIndex;

		PartitionThreeMid(p, start, end, state, &partitionIndex);
		QuickSort(p, start, partitionIndex - 1, state);//漏写-1
		QuickSort(p, partitionIndex + 1, end, state);
	}
	return true;
}


//大致分隔函数(三数取中版)
//参数:p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大，partitionIndex分隔后的索引，
bool PartitionThreeMid(int* p, int start, int end, int state, int* partitionIndex)
{
	//双指针法也行
	int mid;
	intArrayMidIndex(p,start, (start + end) / 2, end, &mid);

	int pivot = p[mid];//轴点 随机取会更好，避免o（n^2）的最坏情况


	int temp = p[end];
	p[end] = p[mid];
	p[mid] = temp;//化归回第一种情况。

	*partitionIndex = start;//记录
	if (state == 'r')
	{
		for (int i = start; i < end; i++)
		{
			if (p[i] < pivot)
			{
				int temp = p[i];
				p[i] = p[*partitionIndex];
				p[*partitionIndex] = temp;
				(*partitionIndex)++;//错误 ，++ * 优先级一样，从右到左，要加括号
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

//返回数组中处于中间的数的索引
//参数：p数组指针，a，b，c索引，mid指针，返回处于中间的索引
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