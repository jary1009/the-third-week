#ifndef __MERGESORT_H__
#define __MEGRESORT_H__

//�鲢���� 
//������p����ָ�룬start��ʼ������end��β����,state��r���ұߴ�l����ߴ�
bool MergeSort(int* p, int start, int end, char state);

//�鲢����
//������p����ָ�룬start���������mid�ұ�������end��ֹ������state��r���ұߴ�state����l����ߴ�
bool Merge(int* p, int start, int mid, int end, char state);

#endif // !__MEGRESORT_H__
