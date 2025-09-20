#include <math.h>

int DataSize();
void whatever();
int main(int argc, char const *argv[])
{
	/*常数项c < 对数项log n< 平方根项√n < 线性项n < n*log n < 平方项n^2 
	< 指数项2^n < 阶乘项n! */

	/* 初始化数据输入量n = |DataSize| */
	int n = DataSize();
	/* 单句操作语句k++ */
	int k = 0;

	/*1.常数项c: f(n) = c, O(1)*/
	//对应的for循环结构，将c指定为一个常数
	//故无论输入量n如何变化，语句产生量函数ƒ(n)都为常数c
	//其增长趋势是O(1)
	for (int i = 0; i < 1000; ++i)
		k++;
	//注意：当常数c很大时，比如c=100亿，f(n) = c, O(1)也会很大

	/*2.幂项n^k: f(n) = n, n^2, n^3, O(n),O(n^2),O(n^3)*/
	//2.1, k=1, 线性项f(n) = n，O(n) = n
	//常见于线性枚举/遍历一维数组
	for (int i = 0; i < n; ++i)
		//∑(i=1, n]) [1] = n
		k++;

	//2.1, k=2, 平方项f(n) = n^2，O(n) = n^2
	//(1)一个for循环，常见于数学算法处理
	for (int i = 0; i < n * n; ++i)
		//∑(i=1, n * n]) [1] = n * n
		k++;
	
	//嵌套循环"语句产生量"的计算方式：
	//𝑇𝑜𝑡𝑎𝑙(𝑛,𝑚,𝑞)= 𝑓(𝑛)∗𝑔(𝑚)∗ℎ(𝑞)
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < q; ++k)
				whatever();


	//(2)2个嵌套的for循环，常见于线性枚举/遍历二维数组
	//处理一个n*n大小的二维数组
	//平方项f(n) = n^2，O(n) = n^2
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			k++;
	//OR处理m遍大小为n的一维数组
	//假设有Table[i][j] = {{},{},...{}};
	//数据输入量是：
	int NumOfRows, NumOfColumns;
	//𝑇𝑜𝑡𝑎𝑙(𝑛,𝑚)= 𝑓(𝑛)∗𝑔(𝑚)= NumOfRows * NumOfColumns
	for (int i = 0; i < NumOfRows; ++i)
		//i常用于遍历行
		for (int j = 0; j < NumOfColumns; ++j)
			//j常用于遍历列
			k++;


	//2.2 k=3, 立方项f(n) = n^3，O(n) = n^3
	//3个嵌套的for循环
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				whatever();

	/*3.根项n^1/k: f(n) = n^1/2, n^1/3, n^1/4, O(n^1/2),O(n^1/3),O(n^1/4)*/
	//3.1 f(n) = n^1/2, O(n^1/2)
	//ex：试除法进行质因数分解𝑛=𝑎∙𝑏的质因数上限
	for (int i = 0; i < floor(sqrt(n)); ++i)
		k++;

	//3.2 f(n) = n^1/3, O(n^1/3)
	//ex：试除法进行3次质因数分解𝑛=𝑎∙𝑏∙𝑐的质因数上限
	for (int i = 0; i < floor(cbrt(n)); ++i)
		k++;

	//3.3 f(n) = n^1/k, O(n^1/k)
	//ex：试除法进行k次质因数分解𝑛=𝑎∙𝑏∙𝑐...的质因数上限
	for (int i = 0; i < floor(pow(n, 1.0 / k)); ++i)
		k++;

	//3层循环并不总是产生立方项O(n) = n^3！
	//这个3层循环的O(n) = n^3/2
	for (int i = 0; i < floor(sqrt(n)); ++i)
		for (int j = 0; j < floor(sqrt(n)); ++j)
			for (int k = 0; i < floor(sqrt(n)); ++k)
				whatever();

	//这个3层循环的O(n) = n
	for (int i = 0; i < floor(cbrt(n)); ++i)
		for (int j = 0; j < floor(cbrt(n)); ++j)
			for (int k = 0; i < floor(cbrt(n)); ++k)
				whatever();

	/*4.对数项: f(n) = log(n), O(log(n))*/
	//加法递增式枚举/步进 = 线性项次数；
	//乘法指数式枚举/步进 = 对数项次数
	for (int i = 0; i < n; i*=2)
		k++;

	while(n >= 1)
		n /= 2;


	/*5.指数项: f(n) = 2^n, O(2^n)*/
	//给定一个集合 nums = [1, 2, 3]，请生成它的所有子集（即幂集）
	//一个大小为𝑛的集合有2^𝑛个子集（每个元素选/不选）
	//所以时间复杂度为：O(2ⁿ)

	/*6.阶乘项: f(n) = n!, O(n!)*/
	//定一个不重复元素的数组 nums = [1, 2, 3]，请输出所有排列
	//排列个数：对𝑛个数，全排列一共𝑛!种
	//每种都要递归/输出一次 ⇒ 时间复杂度：O(n!)


	
	return 0;
}