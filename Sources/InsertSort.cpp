#include<stdlib.h>

//插入排序
//参数：p数组指针，size数组大小，state‘l’左边大‘r’右边大
bool InsertSort(int* p, int size,char state)
{
	//健壮性方向 数组指针 ，数组大小 ，排序方式
	if (p == NULL)return false;


	//变量
	int hole=1;//要插入数据的位置

	if (state == 'r')
	{
		for (int i = 1; i < size ; i++)
		{
			hole = i;//数据要插入的索引
			int value = p[i];//暂时拿出数据
			while (hole > 0 && p[hole - 1] > value)
				//假如索引到0，已经到头，无须将索引再向前移，
				//假如洞前面的数据比要插入的值大向右移一位，索引向前移一位。
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
			hole = i;//数据要插入的索引
			int value = p[i];//暂时拿出数据
			while (hole > 0 && p[hole - 1] < value)
				//假如索引到0，已经到头，无须将索引再向前移，
				//假如洞前面的数据比要插入的值小向右移一位，索引向前移一位。
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