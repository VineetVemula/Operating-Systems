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

class rr
{
 public static void main(String args[])
 {
  int i,j,ct=0,avgwt=0,c=0,tym=0,busy=0,index=-1,avgtat=0,tq=0;
  float awt=0,atat=0;
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter number of processes");
  int n = sc.nextInt();
  proc p[]= new proc[n];
  proc t= new proc();
  proc u= new proc();
  System.out.println("Enter time quantum");
  tq=sc.nextInt();
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
 Vector <proc>v = new Vector<proc> ();

 while(c<n)
 {
    for(i=0;i<n;i++)
    {
      if(p[i].at==tym)
      {
          v.add(p[i]);
      }
    }
    if(tym==busy && busy!=0 && t.son==0)
      v.add(t);
      
    if(tym>=busy)
    {
    t = v.firstElement();
    v.removeElementAt(0);

    if(t.rt<tq)
    {
        busy=tym+t.rt;
    }
    else{
    busy=tym+tq;
    }
    t.rt=t.rt-tq;
    if(t.rt<=0)
    {
        t.son=1;
        c++;
        System.out.println(" c= "+c);
        System.out.println("process scheduled:"+t.pid+" at tym="+tym+"completed at = "+busy);
        t.ct=busy;
    }
    
    }
    
   tym++;
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

OUTUT------------------
Enter number of processes
4
Enter time quantum
1
Enter process id, arrival time, burst time
1 0 8
2 1 4
3 2 9
4 3 5
PID	AT	BT
1	0	8
2	1	4
3	2	9
4	3	5
 c= 1
process scheduled:2 at tym=12completed at = 13
 c= 2
process scheduled:4 at tym=19completed at = 20
 c= 3
process scheduled:1 at tym=22completed at = 23
 c= 4
process scheduled:3 at tym=25completed at = 26
PID	AT	BT	CT	TAT	WT	SON
1	0	8	23	23	15	1
2	1	4	13	12	8	1
3	2	9	26	24	15	1
4	3	5	20	17	12	1
avg TAT = 19.0 avg WT= 12.5⁠⁠⁠⁠


Enter number of processes
5
Enter time quantum
1
Enter process id, arrival time, burst time
1 0 10
2 0 1
3 0 2
4 0 1
5 0 5
PID	AT	BT
1	0	10
2	0	1
3	0	2
4	0	1
5	0	5
 c= 1
process scheduled:2 at tym=1completed at = 2
 c= 2
process scheduled:4 at tym=3completed at = 4
 c= 3
process scheduled:3 at tym=6completed at = 7
 c= 4
process scheduled:5 at tym=13completed at = 14
 c= 5
process scheduled:1 at tym=18completed at = 19
PID	AT	BT	CT	TAT	WT	SON
1	0	10	19	19	9	1
2	0	1	2	2	1	1
3	0	2	7	7	5	1
4	0	1	4	4	3	1
5	0	5	14	14	9	1
avg TAT = 9.2 avg WT= 5.4


Enter number of processes
4
Enter time quantum
2
Enter process id, arrival time, burst time
1 0 24
2 3 7
3 5 6
4 10 10
PID	AT	BT
1	0	24
2	3	7
3	5	6
4	10	10
 c= 1
process scheduled:3 at tym=24completed at = 26
 c= 2
process scheduled:2 at tym=26completed at = 27
 c= 3
process scheduled:4 at tym=37completed at = 39
 c= 4
process scheduled:1 at tym=45completed at = 47
PID	AT	BT	CT	TAT	WT	SON
1	0	24	47	47	23	1
2	3	7	27	24	17	1
3	5	6	26	21	15	1
4	10	10	39	29	19	1
avg TAT = 30.25 avg WT= 18.5


Enter number of processes
5
Enter time quantum
2
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
 c= 1
process scheduled:2 at tym=2completed at = 3
 c= 2
process scheduled:4 at tym=7completed at = 9
 c= 3
process scheduled:3 at tym=11completed at = 12
 c= 4
process scheduled:1 at tym=16completed at = 18
 c= 5
process scheduled:5 at tym=18completed at = 20
PID	AT	BT	CT	TAT	WT	SON
1	0	8	18	18	10	1
2	1	1	3	2	1	1
3	2	3	12	10	7	1
4	3	2	9	6	4	1
5	4	6	20	16	10	1
avg TAT = 10.4 avg WT= 6.4
