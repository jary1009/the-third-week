#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__


//ð���Ż�1����־
//����:p����ָ�룬size�����С��state'r'�ұߴ�'l'��ߴ�
bool BubbleSortFlag(int* p, int size, char state);

//ð���Ż�2��˫��
//����:p����ָ�룬size�����С��state'r'�ұߴ�'l'��ߴ�
bool BubbleSortTwoWay(int* p, int size, char state);

//ð���Ż�3��˫��+��־
//����:p����ָ�룬size�����С��state'r'�ұߴ�'l'��ߴ�
bool BubbleSortTwoWayFlag(int* p, int size, char state);

//����������
//����:a,bָ�룬���ؽ������ֵ
bool swap(int* a, int* b);


#endif // !__BUBBLESORT_H__
