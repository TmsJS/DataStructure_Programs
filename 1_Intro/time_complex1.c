//数据量:{整数k}(n = 1)
//常数型循环语句的增长趋势 = O(1)
//本例O(1)的操作次数:ƒ(n) = 100亿，对整数k执行100亿次自增操作
//查看C执行100亿次自增++操作的实际运行时间
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	clock_t start, end;//定义clock_t类型的2个变量
	double cpu_time_used;
	start = clock();//clock函数返回从程序启动到调用该函数时所经过的时钟计时单元数。
	//通过记录程序开始执行之前和结束执行之后的时钟计时单元数，可以计算出程序的运行时间。
	unsigned long k = 0;
	printf("k从0自增10000*10000*100次:\n");
	for (long i = 0; i < 10000*10000*100L; ++i)
		k++;
			
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	//将时钟计时单元数转换为秒数
	//end - start的值是23
	//CLOCKS_PER_SEC的值是1000000
	//printf("%ld\n",(end - start));
	//printf("%ld\n",CLOCKS_PER_SEC);
	printf("k = %lu\n",k);
	printf("(在你电脑上)C执行100亿次自增操作的实际运行时间:%f 秒\n", cpu_time_used);
	return 0;
}