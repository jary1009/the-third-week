#ifndef __FILE_H__
#define __FILE_H__


//读取文件中的数据
//文件格式：数据加空格
//参数：p数组指针，arraySize数组大小，filenName文件名
bool FScanfArray(int* p, int arraySize,const char fileName[]);


//将数据写入文件
//文件格式：数据加空格
//参数：p数组指针，arraySize数组大小，filenName文件名
bool FPrintArray(const int* p, int arraySize,const char fileName[]);

#endif // !__FILE_H__