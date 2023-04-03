#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//将数组全部输出到stdout上
//参数：p数组指针，size数组大小
bool PrintArray(int* p, int size)
{
	
		for (int i = 0; i < size; i++)
		{
			if(i%5==0&&i!=0)printf("\n");
			printf("%7d ", p[i]);
		}
		printf("\n");
	

	return true;
}


//获取数字
//参数：result指针，返回获取的数字
bool GetNum(int* result)
{
	int num = 0;
	//while ((judge = getchar()) != '\n');//刷新缓冲区 //不行
	scanf("%d", &num);
	char judge = getchar();
	while (judge != '\n')
	{
		puts("请输入数字");
		while ((judge = getchar()) != '\n');//刷新缓冲区
		//fflush(stdin);//我的vs这句函数不能刷新缓冲区,
		scanf("%d", &num);
		judge = getchar();
	}
	*result = num;
	return true;
}

//获取有范围的数字
//参数：min,max数字的范围在此之间，包括边界,result指针，返回获取的数字
bool GetNumLimit(int min, int max, int* result)
{
	int flag;
	GetNum(&flag);
	while (flag > max || flag < min)
	{
		printf("请输入数字%d到%d\n", min, max);
		GetNum(&flag);
	}
	*result = flag;
	return true;
}