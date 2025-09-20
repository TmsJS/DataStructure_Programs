#include <stdbool.h>
void add(int a, int b, int c);
int main(int argc, char const *argv[])
{
	int N = 25*10000*10000;//数据量=25亿
	bool isPrime_list[N] = {...};//该布尔数组用于判断下标n是否是质数
	//[1]:True; [2]:True; [3]:True; [4]:False; [5]:True; [6]:False
	//以下算法是对数字n用试除法进行3次质因数分解𝑛=𝑎∙𝑏∙𝑐(a≤b≤c且a,b,c是质数)的数学算法
	//if筛：isPrime_list[a]，即只有当a是质数是才开启内层循环
	//根据质数分布定理，有π(x)∼ x/ln(x)
	//π(x)表示小于等于 x 的所有质数的个数
	//故for+if(质数筛) = f(n)/ln(f(n))

	for (int a = 2; a <= (int)floor(cbrt(N)) + 1; ++a)
		//a^3 ≤ n, thus a's range is (2, 3, 5, ... n^1/3)
		if (isPrime_list[a] == True)
			//isPrime_list[a] used for checking if a is prime or not
			//if a is prime, b keeps; if a isn't prime, ++a
			for (int b = a; b <= (int)floor(sqrt(N/a)) + 1; ++b)
				//a * b * b ≤ n, thus b's range is (a...prime numbers...⌊√(n/a)⌋)
				if (isPrime_list[b] == True)
					//isPrime_list[b] used for checking if b is prime or not
					//if b is prime, c keeps; if b isn't prime, ++b
					for (int c = b; c <= (int)floor(N/(a*b)) + 1; ++c)
						//a * b * c ≤ n, thus c's range is 
						//(b...prime numbers...⌊n/(a*b)⌋)
						add(a,b,c);//Collect 3 prime numbers
	return 0;
}
