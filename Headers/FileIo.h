#ifndef __FILE_H__
#define __FILE_H__


//��ȡ�ļ��е�����
//�ļ���ʽ�����ݼӿո�
//������p����ָ�룬arraySize�����С��filenName�ļ���
bool FScanfArray(int* p, int arraySize,const char fileName[]);


//������д���ļ�
//�ļ���ʽ�����ݼӿո�
//������p����ָ�룬arraySize�����С��filenName�ļ���
bool FPrintArray(const int* p, int arraySize,const char fileName[]);

#endif // !__FILE_H__