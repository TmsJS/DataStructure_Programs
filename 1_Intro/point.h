#ifndef _POINT_H
#define _POINT_H
//类型Type封装口诀：
//(1)实现在内(.c)；(2)(前向)封装在头(.h)；(3)里(k.c)外(main.c)都用封装好的结构体指针操控数据

/* (2)在point.h头文件里，通过typedef Type结构体指针(必须得是指针) Type，
对内核文件的类属性(结构体模板)进行前向声明和Type的完全封装*/
typedef struct PointRep* Point;

//一旦类属性的结构体模板PointRep在头文件里被封装成结构体指针Point
//头文件和main调用文件，甚至是内核文件都全部改用结构体指针Point
//不再使用原始的结构体模板PointRep
//直观理由：你现在封装出来的Type是Point了，就按照Point用呗
//要是还用原来的struct PointRep，不是白封装了么？

//要么你就不封装Type，把结构体模板PointRep直接暴露在头文件里，然后用原始的结构体模板做Type声明
//注意：不要用结构体指针把Type封装好了之后，再使用原始的结构体模板PointRep
//(1)一旦在头文件里把Type用前向声明封装好了之后，编译器也不知道你封装了什么
//在main调用里，Point p1; p1->x就是错的，因为编译器不知道你的Point封装了什么属性
//只有在pointKernel里p1->x是对的，因为结构体原型就在这个文件里，编译器和链接器能找到原型定义
//(2)内核实现文件也必须采用结构体指针，因为现在外面的数据都是指针形式，里外必须保持一致，
//否则编译器将会出现变量形式和指针形式不匹配的冲突
//(3)结构体指针的效率 >> 结构体变量的效率

Point CreatePoint(float x, float y);
void MovePoint(Point p, float dx, float dy);
float Distance(const Point p1, const Point p2);
void PrintPoint(const Point p);
void PointSwap(Point * p1, Point * p2);

#endif