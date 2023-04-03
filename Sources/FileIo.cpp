#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//读取文件中的数据
//文件格式：数据加空格
//参数：p数组指针，arraySize数组大小，filenName文件名
bool FScanfArray(int *p,int arraySize,const char fileName[])
{
	//健壮性为0//后续加上文件名判断，文件数据格式判断//文件数据量判断

	FILE* fp;
	fp=fopen(fileName, "r");

	for (int i = 0; i < arraySize; i++)
	{
		fscanf(fp, "%7d", &p[i]);
	}

	fclose(fp);
	
	return true;
}

//将数据写入文件
//文件格式：数据加空格
//参数：p数组指针，arraySize数组大小，filenName文件名
bool FPrintArray(const int* p, int arraySize,const char fileName[])
{
	FILE* fp;
	fp = fopen(fileName, "w");

	for (int i = 0; i < arraySize; i++)
	{
		if (i % 5 == 0&&i!=0)fprintf(fp, "\n");
		fprintf(fp, "%7d ", p[i]);
	}

	fclose(fp);

	return true;
}