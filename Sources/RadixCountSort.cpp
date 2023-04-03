#include<stdlib.h>
#include<string.h>

//��������
//������p����ָ�룬size�����С,state'l'��ߴ�'r'�ұߴ�
bool RadixCountSort(int* p, int size,char state)
{
	//�����أ�ͬ��������ӳ�䣬��ȫ�����Ͼ���ֵ��ͳһ�Ĳ��������������ټ�ȥ��Сֵ�ľ���ֵ��

	//�ӵ�λ����λ���򣬲��ұ����ȶ�

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

	//���������������
	int base = 1;
	int* tempArray = (int*)malloc(sizeof(int) * size);
	memset(tempArray, 0, sizeof(int) * size);
	while (max / base != 0)
	{
		int countArray[10] = { 0 };

		for (int i = 0; i < size; i++)
		{
			int index = p[i] / base % 10;//bug©�˳���10,������.
			countArray[index]++;
		}

		for (int i = 1; i < 10; i++)
		{
			countArray[i] += countArray[i - 1];
		}

		//�Ӻ���ǰ����֤���������ȶ�
		for (int i = size - 1; i >= 0; i--)
		{
			int index = p[i] / base % 10;
			tempArray[countArray[index] - 1] = p[i];//�ǵ�Ҫ��ȥ1����0��ʼ�ġ�//����ģ�Ӧ����realindex=countArray[index]-1,�ѽ��
			countArray[index]--;
		}

		//��ʱ�Ż�ȥ
		for (int i = 0; i < size; i++)
		{
			p[i] = tempArray[i];
		}

		base *= 10;
	}

	free(tempArray);

	//���鸴ԭ������ԭ����ȥ���Ǹ���
	for (int i = 0; i < size; i++)
	{
		p[i] -= changeNum;
	}

	//��ߴ����ת���飬��ʵ�����Էŵ�����ġ�
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