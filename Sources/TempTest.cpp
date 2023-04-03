//
//
//#include<stdlib.h>
//#include<stdio.h>
//#include<time.h>
//
//
//#include"CreatRandomArray.h"
//#include"FileIo.h"
//#include"InsertSort.h"
//#include"Io.h"
//#include"MergeSort.h"
//#include"QuickSort.h"
//#include"CountSort.h"
//#include"RadixCountSort.h"
//#include"QuickSort.h"
//#include"BubbleSort.h"
//int main()
//{
//	//test CreatRandomArray success
//
//	/*int a[100];
//	CreatRandomArray(a, 10,-1000, 100);
//	for (int i = 0; i < 10;i++)
//	{
//		printf("%d ", a[i]);
//	}*/
//
//
//	//test FPrintArray FScanfArray success
//
//	/*int a[100];
//	CreatRandomArray(a, 100, -1000, 100);
//	int b[100];
//
//	FPrintArray(a, 100, "Array.txt");
//	FScanfArray(b, 100, "Array.txt");
//
//	for (int i = 0; i < 100; i++)
//	{
//		printf("%d ", b[i]);
//	}*/
//
//	//test clock success
//
//	//clock_t start = clock();
//
//	//for (int i = 0; i < 100000000; i++);
//
//	//clock_t end = clock();
//	//printf("%d", (end - start));
//	//system("pause");
//
//
//	//test insertsort  success
//
//	//int a[10];
//	//CreatRandomArray(a, 10, -10, 10);
//	//PrintArray(a, 10);
//	//InsertSort(a, 10, 'l');
//	//PrintArray(a, 10);
//
//
//	//test mergesort success
//
//	//int a[10];
//	//CreatRandomArray(a, 10, 0, 10);
//	//PrintArray(a, 10);
//	//MergeSort(a, 0, 9,'r');
//	//PrintArray(a, 10);
//
//	//test quicksort success
//
//	//int a[10];
//	//FScanfArray(a, 10, "Array.txt");
//	//CreatRandomArray(a, 10, 0, 10);
//	//PrintArray(a, 10);
//	//QuickSort(a, 0, 9,'l');
//	//PrintArray(a, 10);
//	//FPrintArray(a, 10, "Array.txt");
//
//	//test countsort success
//
//	/*int a[10000];
//	CreatRandomArray(a, 10000,-30000 , 30000);
//	printf("ÅÅÐòÇ°\n");
//	PrintArray(a, 10000);
//	CountSort(a, 10000,'r');
//	printf("ÅÅÐòºó\n");
//	PrintArray(a, 10000);
//	FPrintArray(a, 10000, "Array.txt");*/
//
//	//test radixcountsort  success
//
//	int a[200000];
//	CreatRandomArray(a, 200000,-20000 , 20000);
//	printf("ÅÅÐòÇ°\n");
//	PrintArray(a, 200000);
//	RadixCountSort(a, 200000,'l');
//	printf("ÅÅÐòºó\n");
//	PrintArray(a, 200000);
//	FPrintArray(a, 200000, "Array.txt");
//
//	//test QuicksortnoRucurtion  success
//
//	//int a[10];
//	//CreatRandomArray(a, 10,-10 , 10);
//	//printf("ÅÅÐòÇ°\n");
//	//PrintArray(a, 10);
//	//QuickSortNoRecursion(a, 0, 9, 'l');
//	//printf("ÅÅÐòºó\n");
//	//PrintArray(a, 10);
//	//FPrintArray(a, 10, "Array.txt");
//
//	//test Quicksortrandom  success
//
//	//int a[10];
//	//CreatRandomArray(a, 10, -10, 10);
//	//printf("ÅÅÐòÇ°\n");
//	//PrintArray(a, 10);
//	//QuickSortRandom(a, 0, 9, 'r');
//	//printf("ÅÅÐòºó\n");
//	//PrintArray(a, 10);
//	//FPrintArray(a, 10, "Array.txt");
//
//	//test QuicksortThreeMid  success
//
//	/*int a[10];
//	CreatRandomArray(a, 10, -10, 10);
//	printf("ÅÅÐòÇ°\n");
//	PrintArray(a, 10);
//	QuickSortThreeMid(a, 0, 9, 'l');
//	printf("ÅÅÐòºó\n");
//	PrintArray(a, 10);
//	FPrintArray(a, 10, "Array.txt");*/
//
//	//test bubblesort  success
//
//	//int a[10];
//	//CreatRandomArray(a, 10, -10, 10);
//	//printf("ÅÅÐòÇ°\n");
//	//PrintArray(a, 10);
//	//BubbleSortTwoWay(a, 10, 'l');
//	//printf("ÅÅÐòºó\n");
//	//PrintArray(a, 10);
//	//FPrintArray(a, 10, "Array.txt");
//
//}