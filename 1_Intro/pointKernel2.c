/* 1. Point类 (二维坐标点 Point)
属性：{
	1.x轴坐标点
	2.y轴坐标点
}

行为：{
	1.平移 move(p, dx, dy)
	2.求距离 distance(p1, p2)
	3.显示坐标 printPo(p)
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
//#include "point.h"

typedef struct PointRep
{
	float x;//x轴坐标点是小数类型
	float y;//y轴坐标点是小数类型
} *Point;

/*行为：{
	0.对象实例化 CreatePoint(float x, float y)
	1.平移 move(p, dx, dy)
	2.求距离 distance(p1, p2)
	3.显示坐标 printPo(p)
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
	printf("point = (%.2f, %.2f)\n", p->x, p->y);
}

void PointSwap(Point * p1, Point * p2)
{
	Point temp = *p2;
	*p2 = *p1;
	*p1 = temp;
}