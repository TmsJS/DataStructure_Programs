//数据量:{整数k}(n = 1)
//常数型循环语句的增长趋势 = O(1)
//本例O(1)的操作次数:ƒ(n) = 20亿，调用20亿次modulo函数
//查看C调用20亿次modulo函数的实际运行时间
#include <stdio.h>
#include <time.h>
void modulo(unsigned long k);
int main(int argc, char const *argv[])
{
	clock_t start, end;//定义clock_t类型的2个变量
	double cpu_time_used;
	start = clock();//clock函数返回从程序启动到调用该函数时所经过的时钟计时单元数。
	//通过记录程序开始执行之前和结束执行之后的时钟计时单元数，可以计算出程序的运行时间。
	unsigned long k = 100000000L;
	printf("void modulo(unsigned long k)\n"
           "{\n"
           "    //modulo函数只包含了5句取余操作\n"
           "    k = k %% 11;\n"
           "    k = k %% 7;\n"
           "    k = k %% 5;\n"
           "    k = k %% 3;\n"
           "    k = k %% 2;\n"
           "}\n");
	printf("(在你电脑上)C调用20亿次modulo(%lu)的实际运行时间:\n", k);
	//调用10000*10000*20L次modulo函数
	for (long i = 0; i < 10000*10000*20L; ++i)
		modulo(k);
			
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	//将时钟计时单元数转换为秒数
	//end - start的值是23
	//CLOCKS_PER_SEC的值是1000000
	//printf("%ld\n",(end - start));
	//printf("%ld\n",CLOCKS_PER_SEC);
	
	printf("%f 秒\n", cpu_time_used);
	return 0;
}

void modulo(unsigned long k)
{
	//modulo函数只包含了5句取余操作
	k = k % 11;
	k = k % 7;
	k = k % 5;
	k = k % 3;
	k = k % 2;
}