import java.util.*;

class bankers
{
 public static int res=0;
 public static void main(String args[])
 {
  int i,j,k;
  int c=0,m,n;
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter number of processes and resources");
  n = sc.nextInt();
  m = sc.nextInt();
  int req[] = new int[m];
  int max[][] = new int[n][m];
  int curavail[] = new int[m];
  int need[][] = new int[n][m];
  int alloc[][] = new int[n][m];
  int avail[] = new int[m];
  int sum[] = new int[m]; // max - alloc = need; inital avail is sum of alloc column
  System.out.println("Enter available array");
  for(j=0;j<m;j++)
  {
   avail[j]=sc.nextInt();
  }

  System.out.println("Enter max matrix");
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
    max[i][j]=sc.nextInt();
   }
  }

  System.out.println("Enter alloc matrix");
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
    alloc[i][j]=sc.nextInt();
   }
  }

  //Need Calculation
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
    need[i][j]=max[i][j]-alloc[i][j];
   }
  }

//Current Available Calculation
  for(j=0;j<m;j++)
  {
   for(i=0;i<n;i++)
   {
    sum[j]=sum[j]+alloc[i][j];
   }
   curavail[j]=avail[j]-sum[j];
  }
System.out.println();
System.out.println();
System.out.println("Current Available");
  for(j=0;j<m;j++)
  {
   System.out.print(curavail[j] + " ");
 }

 System.out.println("Enter Requesting Process & Request Vector");

 int no = sc.nextInt();
 no--;
 for(j=0;j<m;j++)
 {
   req[j]=sc.nextInt();
 }

safety(req,no,max,curavail,need,alloc,avail,sum,m,n,c);

 if(res==1)
 {
   System.out.println("Safe operation, request accepted");
 }
 else
 {
   System.out.println("Unsafe operation, not permitted");
 }
}

//Safety Algorithm

  public static void safety(int req[], int no, int max[][], int curavail[], int need[][], int alloc[][], int avail[], int sum[], int m, int n, int c)
  {
    c=0;
    int end=0,index=0,dead=0,i,j;
    int flag[] = new int[n];
    int newcuravail[] = new int[m];
    int newneed[][] = new int[n][m];
    int newalloc[][] = new int[n][m];

    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        newneed[i][j]=need[i][j];
        newalloc[i][j]=alloc[i][j];
      }
    }

    for(j=0;j<m;j++)
    {
      newcuravail[j]=curavail[j];
    }

    for(j=0;j<m;j++)
    {
      newcuravail[j]=curavail[j]-req[j];
      newalloc[no][j]=alloc[no][j]+req[j];
      newneed[no][j]=need[no][j]-req[j];
    }

    //New Need matrix

    System.out.println("New Need");
    for(i=0;i<n;i++)
    {
     for(j=0;j<m;j++)
     {
      System.out.print(newneed[i][j]);
     }
     System.out.println();
    }

    //New Alloc Matrix

    System.out.println("New Alloc");
    for(i=0;i<n;i++)
    {
     for(j=0;j<m;j++)
     {
      System.out.print(newalloc[i][j]);
     }
     System.out.println();
    }

    //New Current Available matrix

    System.out.println("New Current Available");
     for(j=0;j<m;j++)
     {
      System.out.print(newcuravail[j]);
    }


    for(int l=0;l<n;l++)
    {
      for(i=0;i<n;i++)
      {
       for(j=0;j<m;j++)
       {
         if(flag[i]==0)
         {
           if(newneed[i][j]<=newcuravail[j])
         	  c++;
         }
       }
       if(c==m)
       {
         index=i+1;
         flag[i]=1;
        for(j=0;j<m;j++)
        {
         newcuravail[j]=newcuravail[j]+newalloc[i][j];
         if(newcuravail[j]==avail[j])
         {
           end++;
         }
        }
        System.out.println();
        System.out.println("Process P" + index + " can finish");
        System.out.println("New Current Available");
        for(j=0;j<m;j++)
        {
          System.out.print(newcuravail[j] + " ");
        }
        if(end==m)
        {
          System.out.println("All needs are satisfied");
          for(int v=0;v<n;v++)
          {
            for(int b=0;b<m;b++)
            {
              need[v][b]=newneed[v][b];
              alloc[v][b]=newalloc[v][b];
            }
          }

          for(int b=0;b<m;b++)
          {
            curavail[b]=newcuravail[b];
          }
          res=1;
          return;
        }
      }
      //if(c==0)
      else
      {
        dead++;
        //System.out.println("dead= "+dead);
      }
      c=0;
      end=0;
     }
     if(dead==n)
     {
       System.out.println();
       System.out.println("FLAG ARRAY WHEN DEADLOCK");
       for(int q=0;q<n;q++)
       {
         System.out.print(flag[q] + " ");
       }
       System.out.println();
       System.out.println("END = " + end);
       System.out.println();
       System.out.println("System is in deadlock");
       res=0;
     }
     dead=0;
    }
  }
}

OUTPUT----------
Enter number of processes and resources
3
3
Enter available array
6 6 6
Enter max matrix
4 4 4
4 4 4 
2 2 2
Enter alloc matrix
2 2 2
2 2 2
1 1 2


Current Available
1 1 0 Enter Requesting Process & Request Vector
1 0 0
0
New Need
222
222
110
New Alloc
222
222
112
New Current Available
110dead= 1
dead= 2

Process P3 can finish
New Current Available
2 2 2 
Process P1 can finish
New Current Available
4 4 4 
Process P2 can finish
New Current Available
6 6 6 All needs are satisfied
Safe operation, request accepted
