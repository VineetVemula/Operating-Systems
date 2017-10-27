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

void main()
{
int i,j=1,hd=0,move=0,cyl,ch,flag=0,b,ri,li,pos,min,max,ds;
int seq[100],hm[100],res[100];
printf(&quot;Enter number of cylinders and size of disk\n&quot;);
scanf(&quot;%d%d&quot;, &amp;cyl,&amp;ds);
printf(&quot;Enter sequence\n&quot;);
for(i=0;i&lt;cyl;i++)
{
scanf(&quot;%d&quot;, &amp;seq[i]);
}
sort(seq,cyl);
min=seq[0];
max=seq[cyl-1];
printf(&quot;Enter current head position\n&quot;);
scanf(&quot;%d&quot;, &amp;hd);
pos=hd;
printf(&quot;Enter choice: 1. SCAN 2. C SCAN 3. LOOK 4. C LOOK 5. EXIT\n&quot;);
scanf(&quot;%d&quot;, &amp;ch);
if(ch==5)
{
return;
}
switch(ch)
{
case 1:
j=1;
pos=hd;

move=0;

res[0]=hd;
for(i=cyl-1;seq[i]&gt;pos;i- -)

{
ri=i;
li=i;
}
li-- ;
for(i=hd;i&lt;ds;i++)
{
if(i==seq[ri])
{
res[j++]=seq[ri];
ri++;
}
}
for(i=hd-1;i&gt;=0;i- -)
{
if(i==seq[li])
{
res[j++]=seq[li];
li-- ;
}

}
for(i=0;i&lt;cyl;i++)
{
move=move+(abs(res[i+1]-res[i]));
}
for(i=0;i&lt;cyl+1;i++)
{
printf(&quot;%d &quot;, res[i]);
}
printf(&quot;Total head movements = %d\n&quot;, move);

break;
case 2:
j=1;
pos=hd;

move=0;

res[0]=hd;
for(i=cyl-1;seq[i]&gt;pos;i- -)
{
ri=i;
}
li=0;
for(i=hd;i&lt;ds;i++)
{
if(i==seq[ri])
{
res[j++]=seq[ri];
ri++;
}
}
for(i=0;i&lt;hd;i++)
{

if(i==seq[li])
{
res[j++]=seq[li];
li++;
}

}
for(i=0;i&lt;cyl;i++)
{
move=move+(abs(res[i+1]-res[i]));
}
for(i=0;i&lt;cyl+1;i++)
{
printf(&quot;%d &quot;, res[i]);
}
printf(&quot;Total head movements = %d\n&quot;, move);

break;
case 3:
j=1;
pos=hd;

move=0;

res[0]=hd;
for(i=cyl-1;seq[i]&gt;pos;i- -)
{
ri=i;
li=i;
}
li-- ;
for(i=hd;i&lt;=max;i++)
{
if(i==seq[ri])
{
res[j++]=seq[ri];
ri++;
}
}
for(i=hd-1;i&gt;=min;i- -)
{
if(i==seq[li])
{
res[j++]=seq[li];
li-- ;
}

}
for(i=0;i&lt;cyl;i++)
{
move=move+(abs(res[i+1]-res[i]));
}
for(i=0;i&lt;cyl+1;i++)
{
printf(&quot;%d &quot;, res[i]);
}

printf(&quot;Total head movements = %d\n&quot;, move);

break;
case 4:

j=1;
pos=hd;

move=0;

res[0]=hd;
for(i=cyl-1;seq[i]&gt;pos;i- -)
{
ri=i;
}
li=0;
for(i=hd;i&lt;=max;i++)
{
if(i==seq[ri])
{
res[j++]=seq[ri];
ri++;
}
}
for(i=min;i&lt;hd;i++)
{
if(i==seq[li])
{
res[j++]=seq[li];
li++;
}

}
for(i=0;i&lt;cyl;i++)
{
move=move+(abs(res[i+1]-res[i]));
}
for(i=0;i&lt;cyl+1;i++)
{
printf(&quot;%d &quot;, res[i]);
}
printf(&quot;Total head movements = %d\n&quot;, move);

break;
}
}
