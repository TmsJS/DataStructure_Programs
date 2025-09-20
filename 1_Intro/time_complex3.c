//输入数据量:{array1}(n = 100)
	// ｜n｜ = sizeof(array1)/sizeof(int)
//循环算法1: 常数型循环，循环次数为常量1000
	//ƒ(n) = 1000；O(1)
//循环算法2: 变量型循环，但循环变量和输入数据量(array1)无关，是一个随机数
	//ƒ(n) = RamNum；O(RamNum)
//循环算法3：变量型循环，此时循环变量就是输入数据量(array1)的大小
	//ƒ(n) = n；O(n)
#include <stdio.h>
#include <stdlib.h>  // rand, srand
#include <time.h>
int main(int argc, char const *argv[])
{

	/* 设置随机数种子 */
	srand(time(NULL));// 设置随机种子：当前时间（每次运行不同）

	/* 使用0～99的随机数填充数组，数组的大小是n = 100 */
	int array1[100];
	//其实这个数组填充的for循环就已经是依赖输入数据量大小的循环了
	printf("array1 = \n");
	for (int i = 0; i < sizeof(array1)/sizeof(int); ++i)
	{
		array1[i] = rand() % 100;
		printf("%d ", array1[i]);
	}
	putchar('\n');


	//循环算法1: 常数型循环，循环次数为常量1000
	printf("循环算法1: 常数型循环，循环次数为常量1000\n");
	printf("计算量函数ƒ(n) = 1000；增长趋势 = O(1)\n");
	for (int i = 0; i < 1000; ++i)
	{
		array1[i%100]++;
		printf("%d ", array1[i%100]);
	}
	putchar('\n');

	//循环算法2: 变量型循环，但循环变量和输入数据量(array1)无关，是一个随机数RamNum
	int RamNum = rand() % 1234;
	printf("循环算法2:变量型循环，但循环变量和输入数据量(array1)无关，是一个随机数RamNum = %d\n", RamNum);
	printf("计算量函数ƒ(n) = RamNum；增长趋势 = O(RamNum)\n");
	for (int i = 0; i < RamNum; ++i)
	{
		array1[i%100]++;
		printf("%d ", array1[i%100]);
	}
	putchar('\n');

	//循环算法3：变量型循环，此时循环变量就是输入数据量(array1)的大小
	printf("循环算法3:变量型循环，此时循环变量就是输入数据量(array1)的大小\n");
	printf("｜n｜ = sizeof(array1)/sizeof(int) = %zu\n", sizeof(array1)/sizeof(int));
	printf("计算量函数ƒ(n) = n；增长趋势 = O(n)\n");
	for (int i = 0; i < sizeof(array1)/sizeof(int); ++i)
	{
		array1[i]++;
		printf("%d ", array1[i]);
	}
	putchar('\n');


	return 0;
}

