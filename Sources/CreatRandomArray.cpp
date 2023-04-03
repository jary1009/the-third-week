#include<stdlib.h>
#include<time.h>

//生成随机的数组
//参数：p指针，size数组大小，min，max，数组元素范围  
//注明：int 类型 -32。。。 别超了
bool CreatRandomArray(int *p,double size,int min,int max)
{
	//生成随机数
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)//数据量到200000就不太均匀了，可能是rand函数的问题
	{
		p[i] = rand() % (max - min + 1) + min;
	}
	return true;
}