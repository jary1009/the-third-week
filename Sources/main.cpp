#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<time.h>


#include"CreatRandomArray.h"
#include"FileIo.h"
#include"InsertSort.h"
#include"Io.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"CountSort.h"
#include"RadixCountSort.h"
#include"QuickSort.h"
#include"BubbleSort.h"
#include"Menu.h"
int main()
{

	int flag1 = -1;
	int flag2 = -1;
	int flag3 = -1;
	int flag4 = -1;
	int flag5 = -1;

	int a[200000] = { 0 };
	int size = 0;
	int min = 0;
	int max = 0;
	int abs = 0;

	double time = 0;
	double start = 0;
	double end = 0;
	double start1 = 0;
	double end1 = 0;


	while (flag1 != 4)
	{
		system("cls");
		menu2();
		GetNumLimit(1, 4, &flag1);
		switch (flag1)
		{
		case 1:
			while (1)
			{
				flag2 = -1;

				system("cls");
				printf("请输入随机数组的数据量，最大值和最小值\n");
				printf("数据量<=200000,数据的绝对值<=10000\n");
				printf("数据量：\n");
				GetNumLimit(0, 200000, &size);
				printf("数据的绝对值：\n");
				GetNumLimit(0, 10000, &abs);

				CreatRandomArray(a, size, -abs, abs);
				PrintArray(a, size);
				printf("生成成功\n");
				system("pause");

				system("cls");
				menu1();
				printf("请输入选项\n");
				GetNumLimit(1, 12, &flag2);


				switch (flag2)
				{
				case (1):
					InsertSort(a, size, 'r');
					break;
				case (2):
					MergeSort(a, 0, size, 'r');
					break;
				case (3):
					QuickSort(a, 0, size, 'r');
					break;
				case (4):
					QuickSortNoRecursion(a, 0, size, 'r');
					break;
				case (5):
					QuickSortRandom(a, 0, size, 'r');
					break;
				case (6):
					QuickSortThreeMid(a, 0, size, 'r');
					break;
				case (7):
					CountSort(a, size, 'r');
					break;
				case (8):
					RadixCountSort(a, size, 'r');
					break;
				case (9):
					BubbleSortFlag(a, size, 'r');
					break;
				case (10):
					BubbleSortTwoWay(a, size, 'r');
					break;
				case (11):
					BubbleSortTwoWayFlag(a, size, 'r');
					break;
				case (12):
					break;
				}
				if (flag2 == 12)break;

				PrintArray(a, size);
				printf("排序后数组输出在上面：\n");
				FPrintArray(a, size, "Array.txt");
				printf("排序后的数组已成功输出到文件Array.txt中\n");
				system("pause");

			}

			break;

		case(2):
			while (1)
			{
				flag3 = -1;

				system("cls");
				menu3();

				printf("请输入选项\n");
				GetNumLimit(1, 4, &flag3);

				switch (flag3)
				{
				case (1):
					while (1)
					{
						flag2 = -1;

						CreatRandomArray(a, 10000, -10000, 10000);

						system("cls");
						menu1();
						printf("请输入选项\n");
						GetNumLimit(1, 12, &flag2);

						start = clock();
						switch (flag2)
						{
						case (1):
							InsertSort(a, 10000, 'r');
							break;
						case (2):
							MergeSort(a, 0, 10000, 'r');
							break;
						case (3):
							QuickSort(a, 0, 10000, 'r');
							break;
						case (4):
							QuickSortNoRecursion(a, 0, 10000, 'r');
							break;
						case (5):
							QuickSortRandom(a, 0, 10000, 'r');
							break;
						case (6):
							QuickSortThreeMid(a, 0, 10000, 'r');
							break;
						case (7):
							CountSort(a, 10000, 'r');
							break;
						case (8):
							RadixCountSort(a, 10000, 'r');
							break;
						case (9):
							BubbleSortFlag(a, 10000, 'r');
							break;
						case (10):
							BubbleSortTwoWay(a, 10000, 'r');
							break;
						case (11):
							BubbleSortTwoWayFlag(a, 10000, 'r');
							break;
						case (12):
							break;
						}
						end = clock();
						if (flag2 == 12)break;
						else printf("耗时：%fms\n", end - start);
						system("pause");
					}
					break;
				case (2):
					while (1)
					{
						flag2 = -1;

						CreatRandomArray(a, 50000, -10000, 10000);

						system("cls");
						menu1();
						printf("请输入选项\n");
						GetNumLimit(1, 12, &flag2);

						start = clock();
						switch (flag2)
						{
						case (1):
							InsertSort(a, 50000, 'r');
							break;
						case (2):
							MergeSort(a, 0, 50000, 'r');
							break;
						case (3):
							QuickSort(a, 0, 50000, 'r');
							break;
						case (4):
							QuickSortNoRecursion(a, 0, 50000, 'r');
							break;
						case (5):
							QuickSortRandom(a, 0, 50000, 'r');
							break;
						case (6):
							QuickSortThreeMid(a, 0, 50000, 'r');
							break;
						case (7):
							CountSort(a, 50000, 'r');
							break;
						case (8):
							RadixCountSort(a, 50000, 'r');
							break;
						case (9):
							BubbleSortFlag(a, 50000, 'r');
							break;
						case (10):
							BubbleSortTwoWay(a, 50000, 'r');
							break;
						case (11):
							BubbleSortTwoWayFlag(a, 50000, 'r');
							break;
						case (12):
							break;
						}
						end = clock();
						if (flag2 == 12)break;
						else printf("耗时：%fms\n", end - start);
						system("pause");
					}
					break;
				case (3):
					while (1)
					{
						flag2 = -1;

						system("cls");
						menu1();
						printf("请输入选项\n");
						GetNumLimit(1, 12, &flag2);

						CreatRandomArray(a, 200000, -10000, 10000);

						start = clock();
						switch (flag2)
						{
						case (1):
							InsertSort(a, 200000, 'r');
							break;
						case (2):
							MergeSort(a, 0, 200000, 'r');
							break;
						case (3):
							QuickSort(a, 0, 200000, 'r');
							break;
						case (4):
							QuickSortNoRecursion(a, 0, 200000, 'r');
							break;
						case (5):
							QuickSortRandom(a, 0, 200000, 'r');
							break;
						case (6):
							QuickSortThreeMid(a, 0, 200000, 'r');
							break;
						case (7):
							CountSort(a, 200000, 'r');
							break;
						case (8):
							RadixCountSort(a, 200000, 'r');
							break;
						case (9):
							BubbleSortFlag(a, 200000, 'r');
							break;
						case (10):
							BubbleSortTwoWay(a, 200000, 'r');
							break;
						case (11):
							BubbleSortTwoWayFlag(a, 200000, 'r');
							break;
						case (12):
							break;
						}
						end = clock();
						if (flag2 == 12)break;

						printf("耗时：%fms\n", (end - start));
						system("pause");
					}
					break;
				case (4):
					break;
				}
				if (flag3 == 4)break;

			}

			break;

		case (3):
			while (1)
			{
				flag4 = -1;

				system("cls");
				menu4();

				printf("请输入选项\n");
				GetNumLimit(1, 4, &flag4);

				switch (flag4)
				{
				case (1):
					while (1)
					{
						flag2 = -1;

						system("cls");
						menu1();
						printf("请输入选项\n");
						GetNumLimit(1, 12, &flag2);

						start = clock();

						for (int i = 0; i < 10000; i++)
						{
							CreatRandomArray(a, 100, -10000, 10000);//位置不对
							switch (flag2)
							{
							case (1):
								InsertSort(a, 100, 'r');
								break;
							case (2):
								MergeSort(a, 0, 100, 'r');
								break;
							case (3):
								QuickSort(a, 0, 100, 'r');
								break;
							case (4):
								QuickSortNoRecursion(a, 0, 100, 'r');
								break;
							case (5):
								QuickSortRandom(a, 0, 100, 'r');
								break;
							case (6):
								QuickSortThreeMid(a, 0, 100, 'r');
								break;
							case (7):
								CountSort(a, 100, 'r');
								break;
							case (8):
								RadixCountSort(a, 100, 'r');
								break;
							case (9):
								BubbleSortFlag(a, 100, 'r');
								break;
							case (10):
								BubbleSortTwoWay(a, 100, 'r');
								break;
							case (11):
								BubbleSortTwoWayFlag(a, 100, 'r');
								break;
							case (12):
								break;
							}
							if (flag2 == 12)break;
						}

						end = clock();
						if (flag2 == 12)break;

						start1 = clock();
						for (int i = 0; i < 10000; i++)
						{
							CreatRandomArray(a, 100, -10000, 10000);
						}
						end1 = clock();
						

						printf("耗时：%fms\n", end - start );
						system("pause");
					}

					break;
				case (2):
					while (1)
					{
						flag2 = -1;

						system("cls");
						menu1();
						printf("请输入选项\n");
						GetNumLimit(1, 12, &flag2);

						start = clock();
						for (int i = 0; i < 50000; i++)
						{
							CreatRandomArray(a, 100, -10000, 10000);
							switch (flag2)
							{
							case (1):
								InsertSort(a, 100, 'r');
								break;
							case (2):
								MergeSort(a, 0, 100, 'r');
								break;
							case (3):
								QuickSort(a, 0, 100, 'r');
								break;
							case (4):
								QuickSortNoRecursion(a, 0, 100, 'r');
								break;
							case (5):
								QuickSortRandom(a, 0, 100, 'r');
								break;
							case (6):
								QuickSortThreeMid(a, 0, 100, 'r');
								break;
							case (7):
								CountSort(a, 100, 'r');
								break;
							case (8):
								RadixCountSort(a, 100, 'r');
								break;
							case (9):
								BubbleSortFlag(a, 100, 'r');
								break;
							case (10):
								BubbleSortTwoWay(a, 100, 'r');
								break;
							case (11):
								BubbleSortTwoWayFlag(a, 100, 'r');
								break;
							case (12):
								break;
							}
							if (flag2 == 12)break;
						}
						end = clock();
						if (flag2 == 12)break;

						start1 = clock();
						for (int i = 0; i < 50000; i++)
						{
							CreatRandomArray(a, 100, -10000, 10000);
						}
						end1 = clock();

						printf("耗时：%fms\n", end - start - (end1 - start1));
						system("pause");
					}
					break;
				case (3):
					while (1)
					{
						flag2 = -1;

						system("cls");
						menu1();
						printf("请输入选项\n");
						GetNumLimit(1, 12, &flag2);

						start = clock();
						for (int i = 0; i < 200000; i++)
						{
							CreatRandomArray(a, 100, -10000, 10000);
							switch (flag2)
							{
							case (1):
								InsertSort(a, 100, 'r');
								break;
							case (2):
								MergeSort(a, 0, 100, 'r');
								break;
							case (3):
								QuickSort(a, 0, 100, 'r');
								break;
							case (4):
								QuickSortNoRecursion(a, 0, 100, 'r');
								break;
							case (5):
								QuickSortRandom(a, 0, 100, 'r');
								break;
							case (6):
								QuickSortThreeMid(a, 0, 100, 'r');
								break;
							case (7):
								CountSort(a, 100, 'r');
								break;
							case (8):
								RadixCountSort(a, 100, 'r');
								break;
							case (9):
								BubbleSortFlag(a, 100, 'r');
								break;
							case (10):
								BubbleSortTwoWay(a, 100, 'r');
								break;
							case (11):
								BubbleSortTwoWayFlag(a, 100, 'r');
								break;
							case (12):
								break;
							}
							if (flag2 == 12)break;
						}
						end = clock();
						if (flag2 == 12)break;

						start1 = clock();
						for (int i = 0; i < 200000; i++)
						{
							CreatRandomArray(a, 100, -10000, 10000);
						}
						end1 = clock();

						printf("耗时：%fms\n", end - start - (end1 - start1));
						system("pause");
					}
					break;
				case (4):
					break;
				}
				if (flag4 == 4)break;
			}

			break;

		}



	}
}
