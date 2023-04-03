#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

//快速排序
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSort(int* p, int start, int end, char state);

//大致分隔函数
//参数:p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大，partitionIndex分隔后的索引，
bool Partition(int* p, int start, int end, int state, int* partitionIndex);

//快速排序（非递归版）
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSortNoRecursion(int* p, int start, int end, char state);


//快速排序(随机取轴版)
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSortRandom(int* p, int start, int end, char state);


//大致分隔函数(随机取轴版)
//参数:p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大，partitionIndex分隔后的索引，
bool PartitionRandom(int* p, int start, int end, int state, int* partitionIndex);


//快速排序(三数取中版)
//参数：p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大
bool QuickSortThreeMid(int* p, int start, int end, char state);

//大致分隔函数(三数取中版)
//参数:p数组指针，start开始索引，end结束索引，state‘l’左边大‘r’右边大，partitionIndex分隔后的索引，
bool PartitionThreeMid(int* p, int start, int end, int state, int* partitionIndex);

//返回数组中处于中间的数的索引
//参数：p数组指针，a，b，c索引，mid指针，返回处于中间的索引
bool intArrayMidIndex(int* p, int a, int b, int c, int* mid);

#endif // !__QUICKSORT_H__
