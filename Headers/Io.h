#ifndef __IO_H__
#define __IO_H__


//������ȫ�������stdout��
//������p����ָ�룬size�����С
bool PrintArray(int* p, int size);

//��ȡ����
//������resultָ�룬���ػ�ȡ������
bool GetNum(int* result);
//��ȡ�з�Χ������
//������min,max���ֵķ�Χ�ڴ�֮�䣬�����߽�,resultָ�룬���ػ�ȡ������
bool GetNumLimit(int min, int max, int* result);

#endif // !__IO_H__