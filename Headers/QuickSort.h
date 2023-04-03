#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

//��������
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSort(int* p, int start, int end, char state);

//���·ָ�����
//����:p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�partitionIndex�ָ����������
bool Partition(int* p, int start, int end, int state, int* partitionIndex);

//�������򣨷ǵݹ�棩
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSortNoRecursion(int* p, int start, int end, char state);


//��������(���ȡ���)
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSortRandom(int* p, int start, int end, char state);


//���·ָ�����(���ȡ���)
//����:p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�partitionIndex�ָ����������
bool PartitionRandom(int* p, int start, int end, int state, int* partitionIndex);


//��������(����ȡ�а�)
//������p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�
bool QuickSortThreeMid(int* p, int start, int end, char state);

//���·ָ�����(����ȡ�а�)
//����:p����ָ�룬start��ʼ������end����������state��l����ߴ�r���ұߴ�partitionIndex�ָ����������
bool PartitionThreeMid(int* p, int start, int end, int state, int* partitionIndex);

//���������д����м����������
//������p����ָ�룬a��b��c������midָ�룬���ش����м������
bool intArrayMidIndex(int* p, int a, int b, int c, int* mid);

#endif // !__QUICKSORT_H__
