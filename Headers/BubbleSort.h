#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__


//冒泡优化1：标志
//参数:p数组指针，size数组大小，state'r'右边大'l'左边大
bool BubbleSortFlag(int* p, int size, char state);

//冒泡优化2：双向
//参数:p数组指针，size数组大小，state'r'右边大'l'左边大
bool BubbleSortTwoWay(int* p, int size, char state);

//冒泡优化3：双向+标志
//参数:p数组指针，size数组大小，state'r'右边大'l'左边大
bool BubbleSortTwoWayFlag(int* p, int size, char state);

//交换两个数
//参数:a,b指针，返回交换后的值
bool swap(int* a, int* b);


#endif // !__BUBBLESORT_H__
