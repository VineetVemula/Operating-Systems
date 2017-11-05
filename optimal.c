#include<stdio.h>

int find_index;

int search(int ele, int x[][2], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(ele==x[i][1])
		{
			find_index=i;
			return 1;
		}
	}
	return -1;
}

int count_search(int ele, int seq[], int l, int i)
{
	int count=0;
	for(i=i;i<l;i++)
	{
		if(ele!=seq[i])
		{
			count++;
		}
		if(ele==seq[i])
		{
			return count;
		}
	}
	if(count==0)
	{
		count=999;
	}
	return count;
}

int max(int count[], int n)
{
	int i,index=0;
	int max=count[0];
	for(i=1;i<n;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			index=i;
		}
	}
	return index;
}

void main()
{
	int i,j,n,l,h=0,q,maxi,r,e;
	int x[100][2],seq[100];
	int count[100];
	//Accept all the values

	printf("Enter no of frames\n");
	scanf("%d", &n);
	printf("Enter length of sequence\n");
	scanf("%d", &l);
	printf("Enter the sequence\n");
	for(i=0;i<l;i++)
	{
		scanf("%d", &seq[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			x[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		x[i][0]=i;
	}

	//Fill up the frames with initial values

	for(i=0;i<n;i++)
	{
		x[i][1]=seq[i];
	}

	/*for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}*/

	//Search ahead in array for farthest away page

	for(i=i;i<l;i++)
	{
		if(search(seq[i],x,n)==1)
		{
			h++;
		}
		else
		{
			for(j=0;j<n;j++)
			{
				q=x[j][1];
				count[j]=count_search(q,seq,l,i);
			}
			maxi=max(count,n);
			x[maxi][1]=seq[i];
			count[i]=0;
		}
		//printf("\n");
		//printf("\n");

		/*printf("Count Array\n");
		for(r=0;r<n;r++)
		{
			printf("%d ", count[r]);
		}
		printf("\n");
		printf("\n");
		for(r=0;r<n;r++)
		{
			for(e=0;e<2;e++)
			{
				printf("%d ", x[r][e]);
			}
			printf("\n");
		}*/
	}

	printf("Number of hits: %d\n", h);

}
