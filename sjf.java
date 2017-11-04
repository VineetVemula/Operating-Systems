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
}

class sjfs
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
   System.out.println(p[i].pid+"\t"+ p[i].at+"\t"+ p[i].bt);
 }
 while(c<n)
 {
    index=-1;
    for(i=0;i<n;i++)
    {
      if(p[i].at<=tym &&(p[i].son)==0)
      {
        index=i;
        break;
      }
    }

    if(tym>=busy && index!=-1)
    {

    busy=tym + p[index].bt;
    p[index].ct=busy;
    p[index].son=1;
    c++;
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



OUTPUT-----------------
Enter number of processes
5
Enter process id, arrival time, burst time
1 0 8
2 1 1
3 2 3
4 3 2
5 4 6
PID	AT	BT
1	0	8
2	1	1
3	2	3
4	3	2
5	4	6
PID	AT	BT
2	1	1
4	3	2
3	2	3
5	4	6
1	0	8
PID	AT	BT	CT	TAT	WT	SON
1	0	8	8	8	0	1
2	1	1	9	8	7	1
3	2	3	14	12	9	1
4	3	2	11	8	6	1
5	4	6	20	16	10	1
avg TAT = 10.4 avg WT= 6.4
