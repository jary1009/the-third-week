#include <stdlib.h>
#include <string.h>

//��������
//������p����ָ�룬size�����С,state'l'��ߴ�'r'�ұߴ�
bool CountSort(int* p, int size,char state)
{
	//����и��� ��ԭ���뷨���������������飬�������ۣ�����ģ��鷳�ġ�
	//Ӧ������Ե�ӳ�������ü������飬ֻ������һ����

	//�ҵ������Сֵ�����ü������飬ͬʱ����СֵΪ��׼�����ü���������ŵ�ӳ���ϵ
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

	//��������,��ʼ����
	int* countArray = (int*)malloc(sizeof(int) * countArraySize);
	memset(countArray, 0, sizeof(int) * countArraySize);
	for (int i = 0; i < size; i++) //bug sizeд��countArraySize,��������
	{
		int index = p[i] - min;
		countArray[index]++;
	}

	//��Ϊ���λ�õ�����,�����
	//for (int i = 1; i < size; i++)
	//{
	//	p[i] += p[i - 1];
	//}

	//�ó�����,�Ӻ���ǰ�ã������ȶ������λ�ò��䣩,�����
	/*for (int i = size; i > 0; i--)
	{
	}*/

	//�ó�����
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


	free(countArray);

	return true;
}