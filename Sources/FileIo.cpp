#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//��ȡ�ļ��е�����
//�ļ���ʽ�����ݼӿո�
//������p����ָ�룬arraySize�����С��filenName�ļ���
bool FScanfArray(int *p,int arraySize,const char fileName[])
{
	//��׳��Ϊ0//���������ļ����жϣ��ļ����ݸ�ʽ�ж�//�ļ��������ж�

	FILE* fp;
	fp=fopen(fileName, "r");

	for (int i = 0; i < arraySize; i++)
	{
		fscanf(fp, "%7d", &p[i]);
	}

	fclose(fp);
	
	return true;
}

//������д���ļ�
//�ļ���ʽ�����ݼӿո�
//������p����ָ�룬arraySize�����С��filenName�ļ���
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