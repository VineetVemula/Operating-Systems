#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int size;
  char type;
  struct node* next;
}node;
void printll(node *start)
{
  node *p;
  p=start;
  printf("the list is\n");
  while(p!=NULL)
  {
    printf("%c %d\n",p->type,p->size);
    p=p->next;
  }
}

void firstfit(node *start,int x)
{
  node *p,*q;
  p=start;
  while(p!=NULL)
  {
    if(p->type=='p')
    {
      p=p->next;
      continue;
    }
    if(p->size>=x)
    {
      q=(node*)malloc(sizeof(node));
      q->type='h';
      q->size=(p->size-x);
      p->size=x;
      p->type='p';
      q->next=p->next;
      p->next=q;
      q=NULL;
      return;
    }
    p=p->next;
  }
  if(p==NULL)
  {
    printf("operation not possible\n");
  }
}

void bestfit(node *start,int x)
{
  node *p,*q,*r;
  r=start;
  p=NULL;
  int v=99999;
  while(r!=NULL)
  {
    if(r->type=='h')
    {
      if(r->size<v && r->size>=x)
      {
        v=r->size;
        p=r;
      }
    }
    r=r->next;
  }
  if(p==NULL)
  {
    printf("operation not possible\n");
    return;
  }
  q=(node*)malloc(sizeof(node));
  q->type='h';
  q->size=(p->size-x);
  p->size=x;
  p->type='p';
  q->next=p->next;
  p->next=q;
  q=NULL;
}

void worstfit(node *start,int x)
{
  node *p,*q,*r;
  r=start;
  p=NULL;
  int v=0;
  while(r!=NULL)
  {
    if(r->type=='h')
    {
      if(r->size>v && r->size>=x)
      {
        v=r->size;
        p=r;
      }
    }
    r=r->next;
  }
  if(p==NULL)
  {
    printf("operation not possible\n");
    return;
  }
  q=(node*)malloc(sizeof(node));
  q->type='h';
  q->size=(p->size-x);
  p->size=x;
  p->type='p';
  q->next=p->next;
  p->next=q;
  q=NULL;
}

void nextfit(node *start,int x,node** next)
{
  node *r,*q;
  if(*next==NULL)
    *next=start;
  r=*next;
  do
  {
    if((*next)->type=='p')
    {
      *next=(*next)->next;
      continue;
    }
    if((*next)->size>=x)
    {
      q=(node*)malloc(sizeof(node));
      q->type='h';
      q->size=((*next)->size-x);
      (*next)->size=x;
      (*next)->type='p';
      q->next=(*next)->next;
      (*next)->next=q;
      *next=(*next)->next->next;
      if(*next==NULL)
        *next=start;
      q=NULL;
      return;
    }
    (*next)=(*next)->next;
    if(*next==NULL)
      *next=start;
  }while(*next!=r);
  if(*next==r)
  {
    printf("operation not possible\n");
  }
}
int main()
{
  node *start,*p,*q,*next;
  node **nxt;
  int n,c,size,ch,x;
  char type;
  start=NULL;
  next=NULL;
  nxt=&next;
  p=NULL;
  printf("enter the number of processes\n");
  scanf("%d",&n);
  c=n;
  printf("Enter the type and size of all \n");
  while(c>0)
  {
    while(type!='p' && type!='h')
    {
      scanf("%c",&type);
    }
    scanf("%d",&size);
    q=(node*)malloc(sizeof(node));
    q->size=size;
    q->type=type;
    if(start==NULL)
    {
      start=q;
      p=start;
      p->next=NULL;
    }
    else
    {
      p->next=q;
      p=q;
      p->next=NULL;
    }
    q=NULL;
    c--;
    type='.';
  }
  printll(start);
  while(1)
  {
    printf("choose option 1.firstfit 2.bestfit 3.worstfit 4.nextfit 5.exit\n");
    scanf("%d",&ch);
    if(ch==5)
      return 0;
    switch(ch)
    {
      case 1:
        printf("enter the size\n");
        scanf("%d",&x);
        firstfit(start,x);
        printll(start);
        break;
      case 2:
        printf("enter the size\n");
        scanf("%d",&x);
        bestfit(start,x);
        printll(start);
        break;
      case 3:
        printf("enter the size\n");
        scanf("%d",&x);
        worstfit(start,x);
        printll(start);
        break;
      case 4:
        printf("enter the size\n");
        scanf("%d",&x);
        nextfit(start,x,nxt);
        printll(start);
        break;
    }
  }

}
