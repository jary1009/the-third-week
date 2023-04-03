#include"BubbleSort.h"


//冒泡优化1：标志
//参数:p数组指针，size数组大小，state'r'右边大'l'左边大
bool BubbleSortFlag(int* p, int size,char state)
{
	int flag = 0;//有没有交换过

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

//冒泡优化2：双向
//参数:p数组指针，size数组大小，state'r'右边大'l'左边大
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

//冒泡优化3：双向+标志
//参数:p数组指针，size数组大小，state'r'右边大'l'左边大
bool BubbleSortTwoWayFlag(int* p, int size, char state)
{
	int flag = 0;//没交换过

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

//交换两个数
//参数:a,b指针，返回交换后的值
bool swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}