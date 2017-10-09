#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct pg
{
	int valid;
	int fr[50];
}pg;

typedef struct node
{
  int data;
  int count;
  int tym;
  struct node* next;
}node;

void binary(int a[],int n,int fno)
{
	int j=0;
	for(j=0;j<n;j++)
	{
		a[j]=0;
	}
	int i=n-1;
	while(fno>0)
	{
		a[i]=fno%2;
		fno=fno/2;
		i--;
	}
}

void binarys(pg a[],int i,int n,int fno)
{
	int j;
	j=n-1;
	a[i].valid=1;
	while(fno>0)
	{
		a[i].fr[j]=fno%2;
		fno=fno/2;
		j--;
	}
}

void addnode(node** head,int pno,int* timee)
{
  node* q,*p;
  q=(node*)malloc(sizeof(node));
  q->data=pno;
  q->count=0;
  q->tym=*timee;
  q->next=NULL;
  if(*head==NULL)
  {
    *head=q;
    return;
  }
  else
  {
    p=*head;
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->next=q;
  }
  q=NULL;
}

int main()
{
  node *start,*trav;
  node *r,*min;
  node**heady;
  start=NULL;
  heady=&start;
  int	c,i,j,la,pa,p,temp,loglen,phylen,pglen,n,pgeno,fno,ld,m,pageno=0,k=0,p1,p2,dec=0,t,ch,e,fff,deci=0,mintime;
  int county,tyme=0;
  pg a[100];

  printf("Enter logical address size\n");
	scanf("%d", &la);
	printf("Enter physical address size\n");
	scanf("%d", &pa);
	printf("Enter page size\n");
	scanf("%d", &p);

  printf("Enter the number of frames\n");
  scanf("%d",&n);
  int framelist[n];
  for(j=0;j<n;j++)
  {
    framelist[j]=0;
  }
	temp=la;
	while(temp!=0)
	{
		temp=temp/2;
		c++;
	}

	c=c+9;
	loglen=c;
	int log[loglen];
	c=0;
	temp=pa;
	while(temp!=0)
	{
		temp=temp/2;
		c++;
	}

	c=c+9;
	phylen=c;
	int phy[phylen];
	c=0;
	temp=p;
	while(temp!=0)
	{
		temp=temp/2;
		c++;
	}

	c=c+9;
	pglen=c;
	//int page[pglen];
	c=0;

	for(i=0;i<100;i++)
	{
		a[i].valid=0;
	}

	p1=phylen-pglen;

	printf("Loglen = %d, Phylen = %d, pglen = %d", loglen,phylen,pglen);

/* PRINTING ARRAY OF STRUCTS
	printf("\nThe array of structure is\n");
	for(i=0;i<100;i++)
	{
		if(a[i].valid==1)
		{
			printf("%d\t",i);
			for(j=0;j<p1;j++)
			{
				printf("%d",a[i].fr[j]);
			}
			printf("\n");
		}
	}
  printf("\n");
*/

int frame[pglen];
m=loglen-pglen;

int pgno[m];
while(1)
{
  printf("1.EXIT 2.CONTINUE\n");
  scanf("%d",&fff);
  if(fff==1)
  {
    break;
  }
  printf("\nEnter logical address in decimal\n");
	scanf("%d",&ld);
	binary(log,loglen,ld);

	printf("\nLogical address in binary is:\n");

  for(i=0;i<loglen;i++)
  {
	 	  printf("%d", log[i]);
  }



	for(i=0;i<m;i++)
	{
		pgno[i]=log[i];
	}

	printf("\nPage number in binary is \n");

  for(i=0;i<m;i++)
  {
    printf("%d", pgno[i]);
  }

	j=0;
  pageno=0;
  for(i=m-1;i>=0;i--)
  {
    pageno=(pgno[i]*pow(2,j))+pageno;
    j++;
  }

	printf("\npage number in decimal is: %d\n",pageno);

  a:;

  if(a[pageno].valid==1)
  {

     for(i=m,j=0;i<loglen;i++,j++)
	   {
		      frame[j]=log[i];
     }

	   printf("\n frame is\n");

     for(i=0;i<pglen;i++)
     {
       printf("%d", frame[i]);
     }

     p2=pglen;
	   for(i=0;i<p1;i++)
	   {
		     phy[i]=a[pageno].fr[i];
     }

     j=0;
     deci=0;
     for(i=p1-1;i>=0;i--)
     {
       deci=(phy[i]*pow(2,j))+deci;
       j++;
     }
     trav=start;
     while(trav->data!=deci && trav!=NULL)
     {
       trav=trav->next;
     }
     trav->count=trav->count +1;
     trav->tym=tyme;
	   for(i=p1,j=0;i<phylen;i++,j++)
	   {
		    phy[i]=frame[j];
	   }

	   printf("\nphysical address in binary is:\n");
     for(i=0;i<phylen;i++)
     {
       printf("%d", phy[i]);
     }

	   j=0;
     dec=0;
     for(i=phylen-1;i>=0;i--)
     {
       dec=(phy[i]*pow(2,j))+dec;
       j++;
     }

     printf("\n");

     printf("Physical Address in Decimal: %d \n", dec);
     tyme++;
  }
  else
  {
    for(t=0;t<n;t++)
    {
      if(framelist[t]==0)
        break;
    }
    if(t!=n)
    {
      framelist[t]=1;
      binarys(a,pageno,p1,t);
      addnode(heady,t,&tyme);

      goto a;
    }
    printf("Enter your choice\n 1.FIFO 2.LRU 3.LFU 4.EXIT\n");
    scanf("%d",&ch);
    if(ch==4)
      break;
    switch(ch)
    {
      case 1:
        e= start->data;
        start=start->next;
        binarys(a,pageno,p1,e);
        addnode(heady,e,&tyme);
        goto a;
        break;

      case 3:

        r=start;
        min=start;
        county=start->count;
        while(r->next!=NULL)
        {
          if(r->next->count<county)
          {
            min=r;
            county=r->next->count;
          }
          r=r->next;
        }
        e=min->next->data;
        min->next=min->next->next;
        min=NULL;
        r=NULL;
        binarys(a,pageno,p1,e);
        addnode(heady,e,&tyme);
        goto a;
        break;

        case 2:

          r=start;
          min=start;
          mintime=start->tym;
          while(r->next!=NULL)
          {
            if(r->next->tym<mintime)
            {
              min=r;
              mintime=r->next->tym;
            }
            r=r->next;
          }
          e=min->next->data;
          min->next=min->next->next;
          min=NULL;
          r=NULL;
          binarys(a,pageno,p1,e);
          addnode(heady,e,&tyme);
          goto a;
          break;
    }

  }


}
}

OUTPUT

Enter logical address size
8
Enter physical address size
4
Enter page size
1
Enter the number of frames
3
Loglen = 13, Phylen = 12, pglen = 101.EXIT 2.CONTINUE
2

Enter logical address in decimal
5151

Logical address in binary is:
1010000011111
Page number in binary is 
101
page number in decimal is: 5

 frame is
0000011111
physical address in binary is:
000000011111
Physical Address in Decimal: 31 
1.EXIT 2.CONTINUE
2  

Enter logical address in decimal
7179

Logical address in binary is:
1110000001011
Page number in binary is 
111
page number in decimal is: 7

 frame is
0000001011
physical address in binary is:
010000001011
Physical Address in Decimal: 1035 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
6175

Logical address in binary is:
1100000011111
Page number in binary is 
110
page number in decimal is: 6

 frame is
0000011111
physical address in binary is:
100000011111
Physical Address in Decimal: 2079 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
5151

Logical address in binary is:
1010000011111
Page number in binary is 
101
page number in decimal is: 5

 frame is
0000011111
physical address in binary is:
000000011111
Physical Address in Decimal: 31 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
6175

Logical address in binary is:
1100000011111
Page number in binary is 
110
page number in decimal is: 6

 frame is
0000011111
physical address in binary is:
100000011111
Physical Address in Decimal: 2079 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
4127

Logical address in binary is:
1000000011111
Page number in binary is 
100
page number in decimal is: 4
Enter your choice
 1.FIFO 2.LRU 3.LFU 4.EXIT
2

 frame is
0000011111
physical address in binary is:
010000011111
Physical Address in Decimal: 1055 
1.EXIT 2.CONTINUE
1


Enter logical address size
8
Enter physical address size
4
Enter page size
1
Enter the number of frames
3
Loglen = 13, Phylen = 12, pglen = 101.EXIT 2.CONTINUE
2

Enter logical address in decimal
7179

Logical address in binary is:
1110000001011
Page number in binary is 
111
page number in decimal is: 7

 frame is
0000001011
physical address in binary is:
000000001011
Physical Address in Decimal: 11 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
6175

Logical address in binary is:
1100000011111
Page number in binary is 
110
page number in decimal is: 6

 frame is
0000011111
physical address in binary is:
010000011111
Physical Address in Decimal: 1055 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
5151

Logical address in binary is:
1010000011111
Page number in binary is 
101
page number in decimal is: 5

 frame is
0000011111
physical address in binary is:
100000011111
Physical Address in Decimal: 2079 
1.EXIT 2.CONTINUE
2   

Enter logical address in decimal
7179

Logical address in binary is:
1110000001011
Page number in binary is 
111
page number in decimal is: 7

 frame is
0000001011
physical address in binary is:
000000001011
Physical Address in Decimal: 11 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
5151

Logical address in binary is:
1010000011111
Page number in binary is 
101
page number in decimal is: 5

 frame is
0000011111
physical address in binary is:
100000011111
Physical Address in Decimal: 2079 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
5151

Logical address in binary is:
1010000011111
Page number in binary is 
101
page number in decimal is: 5

 frame is
0000011111
physical address in binary is:
100000011111
Physical Address in Decimal: 2079 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
4127

Logical address in binary is:
1000000011111
Page number in binary is 
100
page number in decimal is: 4
Enter your choice
 1.FIFO 2.LRU 3.LFU 4.EXIT
3

 frame is
0000011111
physical address in binary is:
010000011111
Physical Address in Decimal: 1055 
	
Enter logical address size
8
Enter physical address size
4
Enter page size
1
Enter the number of frames
3
Loglen = 13, Phylen = 12, pglen = 101.EXIT 2.CONTINUE
2

Enter logical address in decimal
5151

Logical address in binary is:
1010000011111
Page number in binary is 
101
page number in decimal is: 5

 frame is
0000011111
physical address in binary is:
000000011111
Physical Address in Decimal: 31 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
6175

Logical address in binary is:
1100000011111
Page number in binary is 
110
page number in decimal is: 6

 frame is
0000011111
physical address in binary is:
010000011111
Physical Address in Decimal: 1055 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
7179

Logical address in binary is:
1110000001011
Page number in binary is 
111
page number in decimal is: 7

 frame is
0000001011
physical address in binary is:
100000001011
Physical Address in Decimal: 2059 
1.EXIT 2.CONTINUE
2

Enter logical address in decimal
4127

Logical address in binary is:
1000000011111
Page number in binary is 
100
page number in decimal is: 4
Enter your choice
 1.FIFO 2.LRU 3.LFU 4.EXIT
1

 frame is
0000011111
physical address in binary is:
000000011111
Physical Address in Decimal: 31 
