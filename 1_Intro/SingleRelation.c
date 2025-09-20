#include <stdio.h>
#include "SingleRelation.h"
int main(int argc, char const *argv[])
{
	/*1.数据对象集合：DataObject = {...}*/
	Human John, Julie;
	Web PageA, PageB;
	Pdf pdf_file1, pdf_file2;

	/*2.数据关系集合：DataRelation = {...}*/
	/*(1)使用数组arr[2]存储单个二元关系组：*/
	//1.（男A，女B) ∈ R：单向喜欢关系
	Human Like[2] = {John, Julie};//John--(Like)-->Julie

	//2.（网页A，网页B） ∈ R：单向打开到
	Web Open[2] = {PageA, PageB};//PageA--(Open)-->PageB

	//3.（pdf5，pdf4） ∈ R：单向等待
	Pdf Wait[2]= {pdf_file1, pdf_file2};//pdf_file1--(Wait)-->pdf_file2

	/*(2)使用指针存储单个二元关系组：*/
	/*在使用指针法存储关系时，为了表示“元素1通过指针指向元素2”，除了指向元素2的指针，
	还需要给出是谁指向的，即还需要把元素1，和指向元素2的指针一起绑定起来
	一个是元素变量，另一个是元素指针，所以无法用数组，只能用结构体变量了
	即：使用指针存储单个二元关系组 = 
	声明结构体模板struct{指向元素；被指向元素的地址(一个同元素类型指针)}
	然后通过这个模板，声明一个结构体变量*/

	//1.（男A，女B) ∈ R：单向喜欢关系
	struct LikeRelation{
		Human People;//指向元素
		Human* BeLiked;//被指向元素的地址
	};
	/*使用结构体变量来表示二元关系组*/
	struct LikeRelation likrel1;
	likrel1.People = John;
	likrel1.BeLiked = &Julie;

	//2.（网页A，网页B） ∈ R：单向打开到
	struct OpenRelation{
		Web Page;//指向元素
		Web* BeOpened;//被指向元素的地址
	};
	/*使用结构体变量来表示二元关系组*/
	struct OpenRelation operel1;
	operel1.Page = PageA;
	operel1.BeOpened = &PageB;

	//3.（pdf5，pdf4） ∈ R：单向等待
	struct WaitRelation{
		Pdf File;//指向元素
		Pdf* BeWaited;//被指向元素的地址
	};
	/*使用结构体变量来表示二元关系组*/
	struct WaitRelation waireal1;
	waireal1.File = pdf_file1;
	waireal1.BeWaited = &pdf_file2;

	return 0;
}