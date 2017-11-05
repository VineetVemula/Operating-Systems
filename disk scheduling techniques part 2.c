#include <stdio.h>
#include<math.h>
#include<stdlib.h>

void sort(int x[], int n)
{
  int i,j,t;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(x[j]>x[j+1])
      {
        t=x[j];
        x[j]=x[j+1];
        x[j+1]=t;
      }
    }
  }
}


void main()
{
  int i,j=1,hd=0,move=0,cyl,ch,flag=0,b,ri,li,pos,min,max,ds,c;
  int seq[100],hm[100],res[100];
  printf("Enter number of cylinders and size of disk\n");
  scanf("%d%d", &cyl,&ds);
  printf("Enter sequence\n");
  for(i=0;i<cyl;i++)
  {
    scanf("%d", &seq[i]);
  }

  sort(seq,cyl);
	min=seq[0];
	max=seq[cyl-1];
  printf("Enter current head position\n");
  scanf("%d", &hd);
	pos=hd;
  printf("Enter choice: 1. SCAN 2. C SCAN 3. LOOK 4. C LOOK 5. EXIT\n");
  scanf("%d", &ch);
  if(ch==5)
  {
    return;
  }

  switch(ch)
  {
    case 1:
    c=0;
		j=1;
		pos=hd;
      move=0;

		res[0]=hd;
		for(i=cyl-1;seq[i]>pos;i--)
		{
			ri=i;
			li=i;
		}
		li--;
		 if(seq[li]==hd)
			li--;
		for(i=hd;i<ds;i++)
		{
			if(i==seq[ri])
			{
			res[j++]=seq[ri];
			ri++;
			}
		}
	 for(i=hd-1;i>=0;i--)
	{
		if(i==seq[li])
			{
			res[j++]=seq[li];
			li--;
			}
	}
		for(i=0;i<cyl;i++)
		{
      if(res[i+1]<res[i] && c==0)
      {
        c=1;
        move=move+(abs(res[i+1]-res[i]))+2*(ds-res[i])-2;
      }

      else move=move+(abs(res[i+1]-res[i]));

		}
for(i=0;i<cyl+1;i++)
		{
			printf("%d ", res[i]);
		}
		printf("Total head movements = %d\n", move);


      break;
    case 2:
		j=1;
		pos=hd;
      move=0;
		res[0]=hd;
		for(i=cyl-1;seq[i]>pos;i--)
		{
			ri=i;
		}
		li=0;
		for(i=hd;i<ds;i++)
		{
			if(i==seq[ri])
			{
			res[j++]=seq[ri];
			ri++;
			}
		}
	 for(i=0;i<hd;i++)
	{
		if(i==seq[li])
			{
			res[j++]=seq[li];
			li++;
			}
	}
		for(i=0;i<cyl;i++)
		{
      if(res[i+1]<res[i])
      {
        move=move+ds-res[i]-1+res[i+1];
      }
      else move=move+(abs(res[i+1]-res[i]));
		}
for(i=0;i<cyl+1;i++)
		{
			printf("%d ", res[i]);
		}
		printf("Total head movements = %d\n", move);


      break;
	case 3:
		j=1;
    c=0;
		pos=hd;
      move=0;
		res[0]=hd;
		for(i=cyl-1;seq[i]>pos;i--)
		{
			ri=i;
			li=i;
		}
		li--;
		for(i=hd;i<=max;i++)
		{
			if(i==seq[ri])
			{
			res[j++]=seq[ri];
			ri++;
			}
		}
	 for(i=hd-1;i>=min;i--)
	{
		if(i==seq[li])
			{
			res[j++]=seq[li];
			li--;
			}
	}
		for(i=0;i<cyl;i++)
		{
       move=move+(abs(res[i+1]-res[i]));
		}
for(i=0;i<cyl+1;i++)
		{
			printf("%d ", res[i]);
		}
		printf("Total head movements = %d\n", move);


      break;
 case 4:
		j=1;
		pos=hd;
      move=0;
		res[0]=hd;
		for(i=cyl-1;seq[i]>pos;i--)
		{
			ri=i;
		}
		li=0;
		for(i=hd;i<=max;i++)
		{
			if(i==seq[ri])
			{
			res[j++]=seq[ri];
			ri++;
			}
		}
	 for(i=min;i<hd;i++)
	 {
		   if(i==seq[li])
			 {
			    res[j++]=seq[li];
			    li++;
			 }
	  }
    for(i=0;i<cyl;i++)
    {
      if(res[i+1]>res[i])
        move=move+(abs(res[i+1]-res[i]));
      }
    for(i=0;i<cyl+1;i++)
		{
			printf("%d ", res[i]);
		}
		printf("Total head movements = %d\n", move);
    break;
    }
}
