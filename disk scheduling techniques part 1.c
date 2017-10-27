#include &lt;stdio.h&gt;
#include&lt;math.h&gt;
#include&lt;stdlib.h&gt;

void sort(int x[], int n)
{
int i,j,t;
for(i=0;i&lt;n-1;i++)
{
for(j=0;j&lt;n-1;j++)
{
if(x[j]&gt;x[j+1])
{
t=x[j];
x[j]=x[j+1];
x[j+1]=t;
}
}
}
}
void sstf(int seq[], int pos, int n, int res[])
{
int i, li,ri,j=1;
int hp;
hp=pos;
res[0]=hp;
for(i=0;seq[i]&lt;pos;i++)
{
li=i;
}
for(i=n-1;seq[i]&gt;pos;i- -)
{
ri=i;
}
for(i=0;i&lt;n;i++)
{
if(seq[i]==pos)
{
pos=i;
break;
}
}
if(i==n)
{
if(abs(seq[li]-pos)&lt;abs(seq[ri]- pos))
{
pos=li;
}
else
pos=ri;

}
for(j=1;j&lt;=n;j++)
{
if(abs(seq[pos]-seq[ri])&lt;abs(seq[pos]- seq[li]))
{
pos=ri;

ri++;
}
else
{
pos=li;
li-- ;
}
if(li==-1)
{
res[j++]=seq[pos];
for(i=j;i&lt;=n;i++)
{
res[i]=seq[ri];
ri++;
}
break;
}
if(ri==n)
{
res[j++]=seq[pos];
for(i=j;i&lt;=n;i++)
{
res[i]=seq[li];
li-- ;
}
break;
}
res[j]=seq[pos];
}
}
void main()
{
int i,j,hd=0,move=0,cyl,ch,flag=0,b;
int seq[100],hm[100],res[100];
printf(&quot;Enter number of cylinders\n&quot;);
scanf(&quot;%d&quot;, &amp;cyl);
printf(&quot;Enter sequence\n&quot;);
for(i=0;i&lt;cyl;i++)
{
scanf(&quot;%d&quot;, &amp;seq[i]);
}
//sort(seq,cyl);
printf(&quot;Enter current head position\n&quot;);
scanf(&quot;%d&quot;, &amp;hd);
printf(&quot;Enter choice: 1. FCFS 2. SSTF 3. EXIT\n&quot;);
scanf(&quot;%d&quot;, &amp;ch);
if(ch==3)
{
return;
}
switch(ch)
{
case 1:
move=0;
flag=hd;
for(i=0;i&lt;cyl;i++)

{
if(seq[i]&gt;flag)
{
hm[i]=seq[i]-flag;
}
else
{
hm[i]=flag-seq[i];
}
flag=seq[i];
}
for(i=0;i&lt;cyl;i++)
{
move = move + hm[i];
}
printf(&quot;Total head movements = %d\n&quot;, move);
break;
case 2:

move=0;
sort(seq,cyl);
sstf(seq,hd,cyl,res);
/*for(i=0;i&lt;cyl+1;i++)
{
printf(&quot;%d &quot;, res[i]);
}*/
for(i=0;i&lt;cyl;i++)
{
move=move+(abs(res[i+1]-res[i]));
}
printf(&quot;Total head movements = %d\n&quot;, move);

break;
}
}
