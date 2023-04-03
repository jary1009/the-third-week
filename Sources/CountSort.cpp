#include <stdlib.h>
#include <string.h>

//计数排序
//参数：p数组指针，size数组大小,state'l'左边大'r'右边大
bool CountSort(int* p, int size,char state)
{
	//如果有负数 ，原来想法：设两个计数数组，分类讨论，错误的，麻烦的。
	//应该用相对的映射来设置计数数组，只用设置一个。

	//找到最大最小值，设置计数数组，同时以最小值为基准，设置计数数组序号的映射关系
	int min = p[0];
	int max = p[0];
	for (int i = 1; i < size; i++)
	{
		if (p[i] < min)
		{
			min = p[i];
		}
		if (p[i] > max)
		{
			max = p[i];
		}
	}
	int countArraySize = max - min+1;

	//计数数组,开始计数
	int* countArray = (int*)malloc(sizeof(int) * countArraySize);
	memset(countArray, 0, sizeof(int) * countArraySize);
	for (int i = 0; i < size; i++) //bug size写成countArraySize,已修正。
	{
		int index = p[i] - min;
		countArray[index]++;
	}

	//变为相对位置的数组,错误的
	//for (int i = 1; i < size; i++)
	//{
	//	p[i] += p[i - 1];
	//}

	//拿出数据,从后往前拿，保持稳定（相对位置不变）,错误的
	/*for (int i = size; i > 0; i--)
	{
	}*/

	//拿出数据
	int indexP = 0;
	for (int i = 0; i < countArraySize; i++)
	{
		while (countArray[i] != 0)
		{
			p[indexP] = i + min;
			indexP++;
			countArray[i]--;
		}
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


	free(countArray);

	return true;
}