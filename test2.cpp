// test2.cpp : 定义控制台应用程序的入口点。
//找假币

#include "stdafx.h"
#include"stdlib.h"
#include"ctime"
#define MAX 100
int a[9] = {2,2,2,2,1,2,2,2,2};
#include<iostream>
using namespace std;

//用来计算硬币的总重量
int sum(int begin,int end)
{
    int all = 0;
    for (int i = begin; i <=end;i++)
    {
        all += a[i];
    }
    return all;
}
//找假币函数
void find(int begin,int end)
{
    int mid = (begin + end) / 2;
    if(end-begin==1&&a[begin]>a[end])  //递归出口，只剩下2个数，且偶数个
    {
        cout << "硬币" << end+1 <<"为假币"<< endl;
        return ;
    }
    if(end-begin==1&&a[begin]<a[end]) //递归出口，只剩2个数，且为为偶数个
    {
        cout << "硬币" << begin+1 <<"为假币"<< endl;
        return ;
    }
    if(begin-end==0)//递归出口，end-begin代表只剩一个数(针对个数为奇数)
    {
		
        cout << "硬币" <<a[mid]<<"是假币"<< endl;
        return ;
    }
 
    if((begin+end)%2==1)//当传入的硬币个数是偶数时
    {
        if(sum(begin,mid)<sum(mid+1,end)) //(前面轻)
        {
             find(begin,  mid );
        }
        if(sum(mid+1,end)<sum(begin,mid))//后者轻
        {
             find(mid+1,  end);
        }
    }
    if((begin+end)%2==0&&sum(begin,mid-1)==sum(mid+1,end))//两边重量相同则中间即为假币
    {
        cout<<"两边重量相等，则硬币"<<mid<<"为假币"<<endl;
        return;
    }
    if((begin+end)%2==0)//当传入硬币个数是奇数时
    {
        if(sum(begin,mid-1)<sum(mid+1,end))//前者轻，递归前面
        {
             find(begin, mid - 1);
        }
        if(sum(begin,mid-1)>sum(mid+1,end))//后者轻，递归后面
        {
             find( mid + 1, end);
        }
    }
    
}
//测试
int main()
{
    /*int n=10;
	
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++)
		a[i]=2;
	a[rand()%n]=1;*/ 
    //int a1[10] = {1,2,2,2,2,2,2,2,2,2};
    //find(a1, 0,sizeof(a1)/sizeof(int)-1);
   // int a2[9] = {2,2,2,2,1,2,2,2,2};
    //find(a2, 0,sizeof(a2)/sizeof(int)-1);
	find(0,9);

    return 0;
}