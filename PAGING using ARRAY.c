#include<stdio.h>
#define MAX 50
int main()
{
  int page[MAX],i,n,f,ps,off,pno;
  printf("\nEnter the no of pages in memory : ");
  scanf("%d",&n);
  printf("\nEnter page size : ");
  scanf("%d",&ps);
  printf("\nEnter the no of frames : ");
  scanf("%d",&f);
  for(i=0;i<n;i++)
  {
    page[i]=-1;
  }
  printf("\nEnter page table: ");
  printf("\npageno\tframeno\n-------\t-------");
  for(i=0;i<n;i++)
  {
    printf("\n\n%d\t",i);
    scanf("%d",&page[i]);
  }
  printf("\n\nEnter the logical address(i.e page no & offset): ");
  scanf("%d %d",&pno,&off);
  printf("\n\nPhysical address(i.e. frame no & offset): %d,%d\n",page[pno],off);
}




OUTPUT

Enter the no of pages in memory : 5

Enter page size : 10

Enter the no of frames : 2

Enter page table: 
pageno	frameno
-------	-------

0	1


1	2


2	3


3	4


4	5


Enter the logical address(i.e page no & offset): 1 2


Physical address(i.e. frame no & offset): 2,2
