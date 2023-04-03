#ifndef __MERGESORT_H__
#define __MEGRESORT_H__

//归并排序 
//参数：p数组指针，start开始索引，end结尾索引,state‘r’右边大‘l’左边大
bool MergeSort(int* p, int start, int end, char state);

//归并操作
//参数：p数组指针，start左边索引，mid右边索引，end终止索引，state‘r’右边大，state，‘l’左边大
bool Merge(int* p, int start, int mid, int end, char state);

#endif // !__MEGRESORT_H__
