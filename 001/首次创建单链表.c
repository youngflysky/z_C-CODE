#include<stdio.h>
#include<stdlib.h>

//定义单个节点的数据结构
typedef struct note{
	int val;
	struct note* last;	
} Note;

//创建一个结构体指向表头；无论表头是否为空，该结构体地址不为空，
//取其地址后作为头节点，利于后续操作；
typedef struct list{
	Note* head;
} List;

//该函数用来将新节点链到链表表头作为链表新的头节点
void add(List*,int);

//跟函数用来输出链表中的所有值
void print(List*);

//该函数用来最好free申请的内存
void Free(List* plist);


int main()
{
	List list;
	
	//初始化头节点为空；
	list.head=NULL;
	int number;
	do
	{
		scanf("%d",&number);
		if(number!=-1)
		{
			add(&list,number);
		}
	}while(number!=-1);
	
	print(&list);
	Free(&list);


 	return 0;
}

void add(List* plist,int number)
{
	Note *p=(Note*)malloc(sizeof(Note));
	p->val=number;
	p->last=NULL;
	if(!plist->head)
	{
		plist->head=p;
	}
	else
	{
		p->last=plist->head;
		plist->head=p;	
	}
}

void print(List* plist)
{
	Note* p=NULL;
	for(p=plist->head;p;p=p->last)
	{
		printf("%d ",p->val);
	}
}

void Free(List* plist)
{
	Note* p=plist->head;
	Note *q;
	while(p)
	{
		q=p;
		p=p->last;
		free(q);
	}
}