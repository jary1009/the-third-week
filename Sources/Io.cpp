#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//������ȫ�������stdout��
//������p����ָ�룬size�����С
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


//��ȡ����
//������resultָ�룬���ػ�ȡ������
bool GetNum(int* result)
{
	int num = 0;
	//while ((judge = getchar()) != '\n');//ˢ�»����� //����
	scanf("%d", &num);
	char judge = getchar();
	while (judge != '\n')
	{
		puts("����������");
		while ((judge = getchar()) != '\n');//ˢ�»�����
		//fflush(stdin);//�ҵ�vs��亯������ˢ�»�����,
		scanf("%d", &num);
		judge = getchar();
	}
	*result = num;
	return true;
}

//��ȡ�з�Χ������
//������min,max���ֵķ�Χ�ڴ�֮�䣬�����߽�,resultָ�룬���ػ�ȡ������
bool GetNumLimit(int min, int max, int* result)
{
	int flag;
	GetNum(&flag);
	while (flag > max || flag < min)
	{
		printf("����������%d��%d\n", min, max);
		GetNum(&flag);
	}
	*result = flag;
	return true;
}