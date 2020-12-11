// 2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
void meanu()/*自定义函数实现菜单功能*/
{
	printf("\n\n\n\n\n");
    printf("\t\t|----------STUDENT----------|\n");
	printf("\t\t|\t 0. exit                 |\n");
	printf("\t\t|\t 1. input  record        |\n");
	printf("\t\t|\t 2. search record        |\n");
	printf("\t\t|\t 3. delete record        |\n");
	printf("\t\t|\t 4. modify record        |\n");
	printf("\t\t|\t 5. insert record        |\n");
	printf("\t\t|\t 6. order                |\n");
	printf("\t\t|\t 7. number               |\n");
	printf("\t\t|---------------------------                |\n");
	printf("\t\t\t choose(0-7):");
}

int main(int argc, char const *argv[])
{
	meanu();
	return 0;
}


