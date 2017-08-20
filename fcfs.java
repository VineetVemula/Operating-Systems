import java.util.*;

class proc
{
 int pid;
 int at;
 int bt;
 int ct;
 int tat;
 int wt;
}

class fcfs
{
 public static void main(String args[])
 {
  int i,j,ct=0,wt,avgwt=0,avgtat=0;
  float awt=0,atat=0;
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter number of processes");
  int n = sc.nextInt();
  proc p[]= new proc[100];
  proc t= new proc();
  System.out.println("Enter process id, arrival time, burst time");
  for(i=0;i<n;i++)
  {
   p[i]=new proc();
   p[i].pid=sc.nextInt();
   p[i].at=sc.nextInt();
   p[i].bt=sc.nextInt();
  }
  System.out.println("PID\tAT\tBT");
 for(i=0;i<n;i++)
  {
   System.out.println(p[i].pid+"\t"+ p[i].at+"\t"+ p[i].bt);
  }
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
 System.out.println("PID\tAT\tBT");
 for(i=0;i<n;i++)
 {
   System.out.println(p[i].pid+"\t"+ p[i].at+"\t"+ p[i].bt);
 }

 for(i=0;i<n;i++)
 {
   if(ct<p[i].at)
     ct=p[i].at;
   ct=ct+p[i].bt;
   p[i].ct=ct;
   p[i].tat=p[i].ct-p[i].at;
   p[i].wt=p[i].tat-p[i].bt;
   avgwt= avgwt+p[i].wt;
   avgtat = avgtat+p[i].tat;
 }
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
 System.out.println("PID\tAT\tBT\tCT\tTAT\tWT");
 for(i=0;i<n;i++)
 {
   System.out.println(p[i].pid+"\t"+ p[i].at+"\t"+ p[i].bt+"\t"+p[i].ct+"\t"+ p[i].tat+"\t"+ p[i].wt);
 }
 awt = (float)avgwt/n;
 atat =(float)avgtat/n;
 System.out.println("avg TAT = "+atat+" avg WT= "+awt);
 }
}



OUTPUT-------

Enter number of processes
5
Enter process id, arrival time, burst time
1 0 4
2 1 3
3 2 1
4 3 2
5 4 5
PID	AT	BT
1	0	4
2	1	3
3	2	1
4	3	2
5	4	5
PID	AT	BT
1	0	4
2	1	3
3	2	1
4	3	2
5	4	5
PID	AT	BT	CT	TAT	WT
1	0	4	4	4	0
2	1	3	7	6	3
3	2	1	8	6	5
4	3	2	10	7	5
5	4	5	15	11	6
avg TAT = 6.8 avg WT= 3.8
