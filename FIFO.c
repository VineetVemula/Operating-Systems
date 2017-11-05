#include<stdio.h>
#include<conio.h>

void display(int x[],int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d ",x[i]);
  printf("\n");
}
int search(int ele,int x[],int n)
{
  int i;
  for(i=0;i<n;i++)
    if (x[i]==ele)
      return 1;
  return 0;
}
void main()
{
int f[100]={-1},ip[100],i,j=0,n,n1,h=0;
clrscr();
printf("enter no.of frames\n");
scanf("%d",&n);
printf("enter no. of frames\n");
scanf("%d",&n1);
printf("enter frame numbers\n");
for(i=0;i<n1;i++)
  scanf("%d",&ip[i]);
for(i=0;i<n1;i++)
{
   if(search(ip[i],f,n))
     h++;
   else{
   f[j]=ip[i];
   j=(j+1)%n;
   }
   display(f,n);
}
printf("Hits: %d",h);
getch();
}
