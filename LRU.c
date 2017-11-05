#include<stdio.h>

typedef struct node
{
  int fno,c;
}node;
void inc(node f[],int n)
{
  int i=0;
  for(i=0;i<n;i++)
      f[i].c++;
}
int replaceIndex(node f[],int n)
{
  int i,max,j=0;
  max=f[0].c;
  for(i=0;i<n;i++)
  {
    if(f[i].fno==-1)
      return i;
  }
  for(i=1;i<n;i++)
  {
    if(f[i].c>max)
    {
      max=f[i].c;
      j=i;
    }
  }
  return j;
}
void display(node x[],int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("fn: %d ",x[i].fno);
  printf("\n");
}
int search(int ele,node x[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    if((x[i].fno)==ele)
    {
      //printf("i=%d fno=%d ele=%d\n",i,x[i].fno,ele);
      return i;
    }
  }
  return -1;
}
void main()
{
int ip[100],i,j=0,n,n1,h=0,k;
node f[40];
for(i=0;i<10;i++)
{
  f[i].fno=-1;
  f[i].c=0;
}
printf("enter no.of frames\n");
scanf("%d",&n);
printf("enter length of sequence \n");
scanf("%d",&n1);
printf("enter frame numbers\n");
for(i=0;i<n1;i++)
{
  scanf("%d",&ip[i]);
}
/*for(i=0;i<n;i++)
{
  f[i].fno=ip[i];
  f[i].c=n-(i+1);
  display(f,n);
}*/
for(i=0;i<n1;i++)
{
  //printf("search = %d \n",search(ip[i],f,n));
   if(search(ip[i],f,n)!=-1)
   {
     h++;
     inc(f,n);
     //printf("search = %d \n",search(ip[i],f,n));
     f[search(ip[i],f,n)].c=0;

   }
   else{
   k=replaceIndex(f,n);
   inc(f,n);
   f[k].fno=ip[i];
   f[k].c=0;

   }
   display(f,n);
}
printf("Hits: %d\n",h);
}


OUTPUT

enter no.of frames
3
enter length of sequence 
20
enter frame numbers
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
fn: 7 fn: -1 fn: -1 
fn: 7 fn: 0 fn: -1 
fn: 7 fn: 0 fn: 1 
fn: 2 fn: 0 fn: 1 
fn: 2 fn: 0 fn: 1 
fn: 2 fn: 0 fn: 3 
fn: 2 fn: 0 fn: 3 
fn: 4 fn: 0 fn: 3 
fn: 4 fn: 0 fn: 2 
fn: 4 fn: 3 fn: 2 
fn: 0 fn: 3 fn: 2 
fn: 0 fn: 3 fn: 2 
fn: 0 fn: 3 fn: 2 
fn: 1 fn: 3 fn: 2 
fn: 1 fn: 3 fn: 2 
fn: 1 fn: 0 fn: 2 
fn: 1 fn: 0 fn: 2 
fn: 1 fn: 0 fn: 7 
fn: 1 fn: 0 fn: 7 
fn: 1 fn: 0 fn: 7 
Hits: 8
