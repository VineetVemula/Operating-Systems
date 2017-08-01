import java.util.*;

class proc
{
 int pid;
 int at;
 int bt;
 int ct;
 int tat;
 int wt;
 int son;
 int rt;
}

class srtn
{
 public static void main(String args[])
 {
  int i,j,ct=0,avgwt=0,c=0,tym=0,busy=0,index=-1,avgtat=0;
  float awt=0,atat=0;
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter number of processes");
  int n = sc.nextInt();
  proc p[]= new proc[n];
  proc t= new proc();
  System.out.println("Enter process id, arrival time, burst time");
  for(i=0;i<n;i++)
  {
   p[i]=new proc();
   p[i].pid=sc.nextInt();
   p[i].at=sc.nextInt();
   p[i].bt=sc.nextInt();
   p[i].rt=p[i].bt;
   p[i].son=0;
  }
  System.out.println("PID\tAT\tBT");
 for(i=0;i<n;i++)
 {
   System.out.println(p[i].pid+"\t"+ p[i].at+"\t"+ p[i].bt);
 }
 Vector <proc>v = new Vector<proc> (n);
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-1;j++)
  {
   if((p[j].at)>(p[j+1].at))
   {
    t=p[j];
    p[j]=p[j+1];
    p[j+1]=t;
   }
  }
 }
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-1;j++)
  {
   if((p[j].bt)>(p[j+1].bt))
   {
    t=p[j];
    p[j]=p[j+1];
    p[j+1]=t;
   }
  }
 }
 System.out.println("PID\tAT\tBT");
 for(i=0;i<n;i++)
 {
   System.out.println(p[i].pid+"\t"+ p[i].at+"\t"+ p[i].bt );
 }
 while(c<n)
 {
   for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-1;j++)
    {
     if((p[j].at)>(p[j+1].at))
     {
      t=p[j];
      p[j]=p[j+1];
      p[j+1]=t;
     }
    }
   }
   for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-1;j++)
    {
     if((p[j].rt)>(p[j+1].rt))
     {
      t=p[j];
      p[j]=p[j+1];
      p[j+1]=t;
     }
    }
   }
    for(i=0;i<n;i++)
    {
      if(p[i].at<=tym &&(p[i].son)==0)
      {
      	//System.out.print("i= "+ i);
        index=i;
        break;
      }
      else index=-1;
    }

    if(index!=-1)
    {
	//System.out.println("index = "+ index );
    p[index].rt=p[index].rt-1;
    //busy=tym + p[index].bt;
    //p[index].ct=busy;
    if(p[index].rt==0)
    {
    	p[index].son=1;
    	p[index].ct=tym+1;
    	c++;
    }

   }
   tym++;
 }
//sorting back the array
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-1;j++)
  {
   if((p[j].pid)>(p[j+1].pid))
   {
    t=p[j];
    p[j]=p[j+1];
    p[j+1]=t;
   }
  }
 }
 // calculating tat and wt
 for(i=0;i<n;i++)
 {
   p[i].tat=p[i].ct-p[i].at;
   p[i].wt=p[i].tat-p[i].bt;
   avgwt=avgwt+p[i].wt;
   avgtat=avgtat+p[i].tat;


 }
 System.out.println("PID\tAT\tBT\tCT\tTAT\tWT\tSON");
 for(i=0;i<n;i++)
 {
   System.out.println(p[i].pid+"\t"+ p[i].at+"\t"+ p[i].bt+"\t"+p[i].ct+"\t"+ p[i].tat+"\t"+ p[i].wt+"\t"+p[i].son);
 }
 awt=(float)avgwt/n;
 atat=(float)avgtat/n;
 System.out.println("avg TAT = "+atat+" avg WT= "+awt);
 }
}

OUTPUT------------------

Enter number of processes
6
Enter process id, arrival time, burst time
1	0	7
2	1	5
3	2	3
4	3	1
5	4	2
6	5	1
PID	AT	BT
1	0	7
2	1	5
3	2	3
4	3	1
5	4	2
6	5	1
PID	AT	BT
4	3	1
6	5	1
5	4	2
3	2	3
2	1	5
1	0	7
PID	AT	BT	CT	TAT	WT	SON
1	0	7	19	19	12	1
2	1	5	13	12	7	1
3	2	3	6	4	1	1
4	3	1	4	1	0	1
5	4	2	9	5	3	1
6	5	1	7	2	1	1
avg TAT = 7.1666665 avg WT= 4.0

Enter number of processes
5
Enter process id, arrival time, burst time
1	2	8
2	7	1
3	6	2
4	3	6
5	5	4
PID	AT	BT
1	2	8
2	7	1
3	6	2
4	3	6
5	5	4
PID	AT	BT
2	7	1
3	6	2
5	5	4
4	3	6
1	2	8
PID	AT	BT	CT	TAT	WT	SON
1	2	8	23	21	13	1
2	7	1	9	2	1	1
3	6	2	8	2	0	1
4	3	6	12	9	3	1
5	5	4	16	11	7	1
avg TAT = 9.0 avg WT= 4.8

