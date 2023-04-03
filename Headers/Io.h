#ifndef __IO_H__
#define __IO_H__


//将数组全部输出到stdout上
//参数：p数组指针，size数组大小
bool PrintArray(int* p, int size);

//获取数字
//参数：result指针，返回获取的数字
bool GetNum(int* result);
//获取有范围的数字
//参数：min,max数字的范围在此之间，包括边界,result指针，返回获取的数字
bool GetNumLimit(int min, int max, int* result);

#endif // !__IO_H__