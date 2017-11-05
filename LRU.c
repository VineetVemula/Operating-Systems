#include<stdio.h>
#include<conio.h>

typedef struct node
{
  int fno,c;
}node;
void inc(node f[],int n)
{
  int i;
  for(i=0;i<n;i++)
      f[i].c++;
}
int replaceIndex(node f[],int n)
{
  int i,max,j=0;
  max=f[0].c;
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
    printf("fn: %d  c: %d   ",x[i].fno,x[i].c);
  printf("\n");
}
int search(int ele,node x[],int n)
{
  int i;
  for(i=0;i<n;i++)
    if (x[i].fno==ele)
      return i;
  return 0;
}
void main()
{
int ip[100],i,j=0,n,n1,h=0,k;
node f[10];
clrscr();
for(i=0;i<10;i++)
{
  f[i].fno=-1;
  f[i].c=0;
}
printf("enter no.of frames\n");
scanf("%d",&n);
printf("enter no. of frames\n");
scanf("%d",&n1);
printf("enter frame numbers\n");
for(i=0;i<n1;i++)
  scanf("%d",&ip[i]);
for(i=0;i<n;i++)
{
  f[i].fno=ip[i];
  f[i].c=n-(i+1);
}
for(i=3;i<n1;i++)
{
   if(search(ip[i],f,n))
   {
     h++;
     inc(f,n);
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
printf("Hits: %d",h);
getch();
}
