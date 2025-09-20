#include <stdio.h>
#include "point.h"

int main(int argc, char const *argv[])
{
	/*1.创建2个点*/
	Point p1 = CreatePoint(1.0, 2.0);
	Point p2 = CreatePoint(2.0, 3.0);
	printf("p1 =");
	PrintPoint(p1);
	printf("p2 =");
	PrintPoint(p2);
	/*2.平移点p1*/
	printf("MovePoint(p1, 2.0, 2.0)---->");
	MovePoint(p1, 2.0, 2.0);
	printf("p1 =");
	PrintPoint(p1);
	/*3.计算点p1和p2的距离值*/
	float d1 = Distance(p1,p2);
	printf("distance(p1,p2) = %f\n", d1);
	/*4.交换点p1和p2*/
	printf("Swap p1 and p2:\n");
	PointSwap(&p1, &p2);
	printf("p1 =");
	PrintPoint(p1);
	printf("p2 =");
	PrintPoint(p2);
	return 0;
}