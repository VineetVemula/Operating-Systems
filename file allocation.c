#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct fa
{
  char type;
  char name[20];
  int alloc[20];
  int next;
}fa;

int main()
{
  int ps,bs,fs,nb,len,ch,lo=1,ib,ch1,ch2,ch3,point=0;
  int i,j,p,fc=0,e,al=0,ac;
  char fname[20];
  char freea[5];
  strcpy(freea,"free");
  //printf("%s",freea);
  printf("Enter the size of partition \n");
  scanf("%d",&ps);
  printf("Enter the size of block \n");
  scanf("%d",&bs);
  len= ps/bs;
  fa a[len];
  for(i=0;i<len;i++)
  {
    strcpy(a[i].name,"free");
    a[i].next=-2;
    a[i].type='-';
  }
  //printf("%s",a[0].name);
  while(1)
  {
    printf("Choose file allocation method \n 1.contiguous 2.continuous 3.indexed 4.exit\n");
    scanf("%d",&ch);
    if(ch==4)
      return 0;

    switch(ch)
    {
      //THIS IS CONTIGUOUS
      case 1:
        while(1) {
          printf("1.create 2.delete 3.display 4.exit\n");
          scanf("%d",&ch1);
          if(ch1==4)
            return 0;
          switch(ch1)
          {
            case 1:
              printf("Enter file name\n");
              scanf("%s",fname);
              printf("Enter file size\n");
              scanf("%d",&fs);
              nb=fs/bs;
              ib=fs%bs;
              if(ib>0)
                nb++;
              fc=0;
              for(i=0;i<len;i++)
              {
                if(strcmp(a[i].name,freea)==0)
                {
                  fc++;
                  if(fc==1)
                    e=i;
                  if(fc==nb)
                   break;
                }
                else fc=0;
              }
              if(fc==nb)
              {
                for(i=e;i<e+nb;i++)
                {
                  strcpy(a[i].name,fname);
                }
              }
              else printf("the file cannot be allocated\n");
              break;
            case 2:
              printf("Enter file name\n");
              scanf("%s",fname);
              for(j=0;j<len;j++)
              {
                if(strcmp(a[j].name,fname)==0)
                  strcpy(a[j].name,"free");
              }
              for(j=0;j<len;j++)
              {
                if(strcmp(a[j].name,freea)==0)
                  break;
              }
              point=j;
              break;
            case 3:
              printf("no\tname\n");
              for(j=0;j<len;j++)
              {
                printf("%d\t%s\n",j,a[j].name);
              }
              break;
          }
        }
        break;
        // THIS IS CONTINUOUS
      case 2:
      while(1) {
        printf("1.create 2.delete 3.display 4.exit\n");
        scanf("%d",&ch2);
        if(ch2==4)
          return 0;
        switch(ch2)
        {
          case 1:
            printf("Enter file name\n");
            scanf("%s",fname);
            printf("Enter file size\n");
            scanf("%d",&fs);
            nb=fs/bs;
            ib=fs%bs;
            if(ib>0)
              nb++;
            for(i=point,p=point,j=0;j<nb;i++,j++)
            {
              while(strcmp(a[i].name,freea)!=0)
              {
                i++;
              }
              strcpy(a[i].name,fname);
              a[p].next=i;
              p=i;
            }
            a[p].next=-1;
            point=i;
            break;
          case 2:
            printf("Enter file name\n");
            scanf("%s",fname);
            for(j=0;j<len;j++)
            {
              if(strcmp(a[j].name,fname)==0)
              {
                strcpy(a[j].name,"free");
                a[j].next=-2;
              }
            }
            for(j=0;j<len;j++)
            {
              if(strcmp(a[j].name,freea)==0)
                break;
            }
            point=j;
            break;
          case 3:
            printf("no\tname\tnext\n");
            for(j=0;j<len;j++)
            {
              printf("%d\t%s\t%d\n",j,a[j].name,a[j].next);
            }
            break;
        }
      }
      break;
      //THIS IS INDEXED
      case 3:
      while(1) {
        printf("1.create 2.delete 3.display 4.exit\n");
        scanf("%d",&ch3);
        if(ch3==4)
          return 0;
        switch(ch3)
        {
          case 1:
            printf("Enter file name\n");
            scanf("%s",fname);
            printf("Enter file size\n");
            scanf("%d",&fs);
            nb=fs/bs;
            ib=fs%bs;
            if(ib>0)
              nb++;
              al=0;
            for(i=point,j=0;j<=nb;i++,j++)
            {
              while(strcmp(a[i].name,freea)!=0)
              {
                i++;
              }
              strcpy(a[i].name,fname);
              //a[p].next=i;
              //p=i;
              if(j==0)
              {
                a[i].type='I';
                ac=i;
                continue;
              }
              else
              {
                a[i].type='D';
              }
              a[ac].alloc[al]=i;
              al++;
            }
            a[ac].alloc[al]=-2;
            //a[p].next=-1;
            //point=i;
            break;
          case 2:
            printf("Enter file name\n");
            scanf("%s",fname);
            for(i=0;i<len;i++)
            {
              if(a[i].type=='I' && strcmp(a[i].name,fname)==0)
              {
                break;
              }
            }
            for(j=0;a[i].alloc[j]!=-2;j++)
            {
              strcpy(a[a[i].alloc[j]].name,freea);
              a[a[i].alloc[j]].type='-';
              //a[a[i].alloc[j]].next=-2;
            }
            strcpy(a[i].name,freea);
            a[i].type='-';
            a[i].next=-2;
            printf("deleted\n");
            break;

          case 3:
            printf("no\ttype\tcontents\n");
            for(j=0;j<len;j++)
            {
              if(a[j].type=='D' || a[j].type=='-')
                printf("%d\t%c\t%s\n",j,a[j].type,a[j].name);
              else
              {
                printf("%d\t%c\t",j,a[j].type);
                for(i=0;a[j].alloc[i]!=-2;i++)
                {
                  printf("%d ",a[j].alloc[i]);
                }
                printf("\n");
              }
            }
            break;
        }
      }
      break;

    }
  }
}


OUTPUT

Enter the size of partition 
10
Enter the size of block 
1
Choose file allocation method 
 1.contiguous 2.continuous 3.indexed 4.exit
3
1.create 2.delete 3.display 4.exit
1
Enter file name
vin
Enter file size
3
1.create 2.delete 3.display 4.exit
1
Enter file name
psh
Enter file size
2
1.create 2.delete 3.display 4.exit
1
Enter file name
kaus
Enter file size
1
1.create 2.delete 3.display 4.exit
2
Enter file name
psh
deleted
1.create 2.delete 3.display 4.exit
1
Enter file name
vid
Enter file size
3
1.create 2.delete 3.display 4.exit
3
no	type	contents
0	I	1 2 3 
1	D	vin
2	D	vin
3	D	vin
4	I	5 6 9 
5	D	vid
6	D	vid
7	I	8 
8	D	kaus
9	D	vid
1.create 2.delete 3.display 4.exit
4


Enter the size of partition 
10
Enter the size of block 
1
Choose file allocation method 
 1.contiguous 2.continuous 3.indexed 4.exit
1
1.create 2.delete 3.display 4.exit
1
Enter file name
vin
Enter file size
3
1.create 2.delete 3.display 4.exit
1
Enter file name
psh
Enter file size
3
1.create 2.delete 3.display 4.exit
1
Enter file name
kaus
Enter file size
2
1.create 2.delete 3.display 4.exit
2
Enter file name
psh
1.create 2.delete 3.display 4.exit
1
Enter file name
vid
Enter file size
2
1.create 2.delete 3.display 4.exit
3
no	name
0	vin
1	vin
2	vin
3	vid
4	vid
5	free
6	kaus
7	kaus
8	free
9	free
1.create 2.delete 3.display 4.exit
