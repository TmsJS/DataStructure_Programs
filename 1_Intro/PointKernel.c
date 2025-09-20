/* 1. Point类 (二维坐标点 Point)
属性：{
	1.x轴坐标点
	2.y轴坐标点
}

行为：{
	0.对象实例化 CreatePoint(float x, float y)
	1.平移 move(p, dx, dy)
	2.求距离 distance(p1, p2)
	3.显示坐标 printPo(p)
	4.交换2个坐标点的值PointSwap(p1, p2)
}
*/

/*属性：{
1.x轴坐标点
2.y轴坐标点
}*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* (1)在pointKernel.c内核文件里写类属性的结构体实现 */
struct PointRep
{
	float x;//x轴坐标点是小数类型
	float y;//y轴坐标点是小数类型
};

/*(3)里外保持一致，统一用结构体指针操控数据*/
//在pointKernel.c内核文件里使用头文件里封装好的类型指针
#include "point.h"//inc的是typedef struct PointRep* Point;

//必须要用封装好的的类型指针，如果内核文件继续使用结构体原型struct PointRep，
//那么内核文件使用的是结构体变量struct PointRep xxxx，
//外面使用的是结构体指针struct PointRep* yyyy,
//将会出现结构体数据，变量形式和指针形式类型不一致的冲突

//下面的函数声明，如果用struct PointRep CreatePoint(float x, float y)
//会和外面main调用和头文件里的Point CreatePoint(float x, float y);不一致

//外部：结构体指针---->内核：也使用结构体指针
//此外，如果结构体很大很大的话，如果你内核也用结构体变量的形式，函数参数也会占用很大的内存
//所以里外都用结构体指针来操控结构体变量是最好的办法了

/*行为：{
	0.对象实例化 CreatePoint(float x, float y)
	1.平移 move(p, dx, dy)
	2.求距离 distance(p1, p2)
	3.显示坐标 printPo(p)
	4.交换2个点的坐标值PointSwap(Point * p1, Point * p2)
}*/

Point CreatePoint(float x, float y)
{
	Point p = malloc(sizeof(struct PointRep));
	assert(p != NULL);
	p->x = x;
	p->y = y;
	return p;
}

void MovePoint(Point p, float dx, float dy)
{
	p->x += dx;
	p->y += dy;
}

float Distance(const Point p1, const Point p2)
{
	//distance = sqrt[(x1-x2)^2 + (y1-y2)^2]
	return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

void PrintPoint(const Point p)
{
	printf("(%.2f, %.2f)\n", p->x, p->y);
}

void PointSwap(Point * p1, Point * p2)
{
	Point temp = *p2;
	*p2 = *p1;
	*p1 = temp;
}
