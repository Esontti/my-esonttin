// test2.cpp : �������̨Ӧ�ó������ڵ㡣
//�Ҽٱ�

#include "stdafx.h"
#include"stdlib.h"
#include"ctime"
#define MAX 100
int a[9] = {2,2,2,2,1,2,2,2,2};
#include<iostream>
using namespace std;

//��������Ӳ�ҵ�������
int sum(int begin,int end)
{
    int all = 0;
    for (int i = begin; i <=end;i++)
    {
        all += a[i];
    }
    return all;
}
//�ҼٱҺ���
void find(int begin,int end)
{
    int mid = (begin + end) / 2;
    if(end-begin==1&&a[begin]>a[end])  //�ݹ���ڣ�ֻʣ��2��������ż����
    {
        cout << "Ӳ��" << end+1 <<"Ϊ�ٱ�"<< endl;
        return ;
    }
    if(end-begin==1&&a[begin]<a[end]) //�ݹ���ڣ�ֻʣ2��������ΪΪż����
    {
        cout << "Ӳ��" << begin+1 <<"Ϊ�ٱ�"<< endl;
        return ;
    }
    if(begin-end==0)//�ݹ���ڣ�end-begin����ֻʣһ����(��Ը���Ϊ����)
    {
		
        cout << "Ӳ��" <<a[mid]<<"�Ǽٱ�"<< endl;
        return ;
    }
 
    if((begin+end)%2==1)//�������Ӳ�Ҹ�����ż��ʱ
    {
        if(sum(begin,mid)<sum(mid+1,end)) //(ǰ����)
        {
             find(begin,  mid );
        }
        if(sum(mid+1,end)<sum(begin,mid))//������
        {
             find(mid+1,  end);
        }
    }
    if((begin+end)%2==0&&sum(begin,mid-1)==sum(mid+1,end))//����������ͬ���м伴Ϊ�ٱ�
    {
        cout<<"����������ȣ���Ӳ��"<<mid<<"Ϊ�ٱ�"<<endl;
        return;
    }
    if((begin+end)%2==0)//������Ӳ�Ҹ���������ʱ
    {
        if(sum(begin,mid-1)<sum(mid+1,end))//ǰ���ᣬ�ݹ�ǰ��
        {
             find(begin, mid - 1);
        }
        if(sum(begin,mid-1)>sum(mid+1,end))//�����ᣬ�ݹ����
        {
             find( mid + 1, end);
        }
    }
    
}
//����
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