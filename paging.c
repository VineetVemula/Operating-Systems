#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct pg
{
	int valid;
	int fr[50];
}pg;

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

int main()
{
	int	c,i,j,la,pa,p,temp,loglen,phylen,pglen,n,pgeno,fno,ld,m,pageno=0,k=0,p1,p2,dec=0;
	printf("Enter logical address size\n");
	scanf("%d", &la);
	printf("Enter physical address size\n");
	scanf("%d", &pa);
	printf("Enter page size\n");
	scanf("%d", &p);
	pg a[100];

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
	printf("Enter number of pte to enter\n");
	scanf("%d", &n);
	p1=phylen-pglen;
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &pgeno, &fno);
		binarys(a,pgeno,p1,fno);
	}

	printf("Loglen = %d, Phylen = %d, pglen = %d", loglen,phylen,pglen);

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

	printf("Enter logical address in decimal\n");
	scanf("%d",&ld);
	binary(log,loglen,ld);

	printf("\nLogical address in binary is:\n");

  for(i=0;i<loglen;i++)
  {
	 	  printf("%d", log[i]);
  }

	m=loglen-pglen;

	int pgno[m];
	int frame[pglen];
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
  for(i=m-1;i>=0;i--)
  {
    pageno=(pgno[i]*pow(2,j))+pageno;
    j++;
  }

	printf("\npage number in decimal is: %d\n",pageno);

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

  printf("Physical Address in Decimal: %d\n", dec);
}


--OUTPUT--

Enter logical address size
64
Enter physical address size
1024
Enter page size
2
Enter number of pte to enter
3
3 9
4 2
2 11
Loglen = 16, Phylen = 20, pglen = 11
The array of structure is
2	000001011
3	000001001
4	000000010

Enter logical address in decimal
6050

Logical address in binary is:
0001011110100010
Page number in binary is 
00010
page number in decimal is: 2

 frame is
11110100010
physical address in binary is:
00000101111110100010
Physical Address in Decimal: 24482
