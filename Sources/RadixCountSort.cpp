#include<stdlib.h>
#include<string.h>

//基数排序
//参数：p数组指针，size数组大小,state'l'左边大'r'右边大
bool RadixCountSort(int* p, int size,char state)
{
	//负数呢？同计数排序，映射，先全部加上绝对值（统一的操作），排完序再减去最小值的绝对值。

	//从低位到高位排序，并且保持稳定

	int min = p[0];
	int max = p[0];
	for (int i = 1; i < size; i++)
	{
		if (max < p[i])
		{
			max = p[i];
		}
		if (min > p[i])
		{
			min = p[i];
		}
	}

	int changeNum = 0;
	if (min <= 0)
	{
		changeNum = -min;
	}
	else if (min > 0)
	{
		changeNum = min;
	}
	for (int i = 0; i < size; i++)
	{
		p[i] += changeNum;
	}

	//基数即是排序次数
	int base = 1;
	int* tempArray = (int*)malloc(sizeof(int) * size);
	memset(tempArray, 0, sizeof(int) * size);
	while (max / base != 0)
	{
		int countArray[10] = { 0 };

		for (int i = 0; i < size; i++)
		{
			int index = p[i] / base % 10;//bug漏了除于10,已修正.
			countArray[index]++;
		}

		for (int i = 1; i < 10; i++)
		{
			countArray[i] += countArray[i - 1];
		}

		//从后往前，保证数组排序稳定
		for (int i = size - 1; i >= 0; i--)
		{
			int index = p[i] / base % 10;
			tempArray[countArray[index] - 1] = p[i];//记得要减去1，从0开始的。//错误的：应该是realindex=countArray[index]-1,已解决
			countArray[index]--;
		}

		//暂时放回去
		for (int i = 0; i < size; i++)
		{
			p[i] = tempArray[i];
		}

		base *= 10;
	}

	free(tempArray);

	//数组复原，加上原来减去的那个数
	for (int i = 0; i < size; i++)
	{
		p[i] -= changeNum;
	}

	//左边大就逆转数组，其实都可以放到外面的。
	if (state == 'l')
	{
		int* tempArray = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++)
		{
			tempArray[i] = p[i];
		}
		for (int i = 0; i < size; i++)
		{
			p[i] = tempArray[size - i - 1];
		}
		free(tempArray);
	}
	return true;
}