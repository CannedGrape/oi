#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <math.h>
#define N 301 //结点数
#define N2 45000 //结点平方之半
#define M 21  //最大直径数 
int pathlen[N][N]={0}, pathlen2[N][N]={0};
int pathlen3[N2][4]; // [0]左端点 [1]右端点 [2]长度 [3]边数
int flag[N][N]={0};
int edge[N][3],edge2[N][N]={0},diam[4][M];
int n,s,center0,diameter,count; 
int pathstr[N][N][N]={0},diam2[N][M][2];
long cn2,min_ecc,new1;
char fname1[30],fname2[30];

void readdata_core() //输入原始数据 
{int i;
 cout <<"enter filename for input data:"<<endl;
 cin >>fname1;   
 ifstream myinf(fname1,ios::nocreate);
 if(myinf.fail())
    {cerr<<"error opening file myname\n";
     return;
    }
 myinf >>n>>s;
 for(i=1;i<=n-1;i++)
   myinf >>edge[i][0]>>edge[i][1]>>edge[i][2];
  myinf.close();
}

void link1(long t1,long t2,long t3,long t4,long i,long j)
 //(t1,t2)(t3,t4),t1=t3,生成(t2,t4)
{int k,k3;
 new1++;
 pathlen3[new1][0]=t2;   pathlen3[new1][1]=t4; 
 pathlen3[new1][2]=pathlen3[i][2]+pathlen3[j][2]; 
 k3=pathlen3[j][3];
 pathlen3[new1][3]=1+k3;
 flag[t2][t4]=flag[t4][t2]=1; 
 pathstr[t2][t4][1]=t3;
 for(k=1;k<=k3;k++)
    pathstr[t2][t4][k+1]=pathstr[t3][t4][k];
 for(k=1;k<=k3+1;k++)
    pathstr[t4][t2][k]=pathstr[t2][t4][k3-k+1];
}  

void init2()
{long i,j,k,t1,t2,t3,t4,start1,end1,u,v,kp;
 for(i=1;i<=n;i++)
  {for(j=1;j<=n;j++)
    {flag[i][j]=0;     
     pathlen[i][j]=pathlen2[i][j]=0;
     pathstr[i][j][0]=i;
     for(k=1;k<=n;k++) pathstr[i][j][k]=0;
    }  
   flag[i][i]=1;
  } 
 for(i=1;i<=n-1;i++)
   {for(j=0;j<3;j++)
      pathlen3[i][j]=edge[i][j];
    pathlen3[i][3]=1;
    u=edge[i][0];  v=edge[i][1];
    edge2[u][v]=edge2[v][u]=edge[i][2];
	flag[u][v]=flag[v][u]=1;
    pathstr[u][v][1]=v;   
    pathstr[v][u][1]=u;  
  }
 cn2=n*(n-1)/2;
 end1=n-1;
 new1=n-1;
 kp=1;
 while(new1<cn2)
   {for(i=1;i<=n-1;i++)//No.1
     {if(kp==1)//No.2
       start1=i+1;
      for(j=start1;j<=end1;j++)
        {t1=pathlen3[i][0]; t2=pathlen3[i][1];//No.3
         t3=pathlen3[j][0]; t4=pathlen3[j][1];
         if ((t1==t3)&&(flag[t2][t4]==0))
		     link1(t1,t2,t3,t4,i,j);    
 	     else if ((t2==t4)&&(flag[t1][t3]==0))
		     link1(t2,t1,t4,t3,i,j);   
         else if ((t2==t3)&&(flag[t1][t4]==0))
		    link1(t2,t1,t3,t4,i,j);    
          else if ((t1==t4)&&(flag[t2][t3]==0))
		    link1(t1,t2,t4,t3,i,j);    
         }//No.3
	}
  if(kp==1) kp=2;    
 start1=end1+1;
      end1=new1;
     }//No.1
 for(i=1;i<=cn2;i++)
	{t1=pathlen3[i][0];
     t2=pathlen3[i][1];
     pathlen[t1][t2]=pathlen[t2][t1]=pathlen3[i][2];
     pathlen2[t1][t2]=pathlen2[t2][t1]=pathlen3[i][3];
	}
 min_ecc=100000000;
 } 

void proc1()// 计算数组 diam,求中心及所在边。
{int i,j,t1,t2,t3;
 diameter=0; count=0;
 for(i=1;i<n;i++)
  for(j=i+1;j<=n;j++)
    if(pathlen[i][j]>diameter)
    	diameter=pathlen[i][j]; 
 for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
    if((pathlen[i][j]==diameter)&&(count<20))
    //对于直径diam[][],[0]:起点，[1]:终点，[2]：边数 [3]：中心所在边
	{count++;
	 diam[0][count]=i;diam[1][count]=j;
	 diam[2][count]=pathlen2[i][j];
	}
   //计算第2个直径数组diam2[][][]
 for(i=1;i<=count;i++)
  {t1=diam[0][i];
   t2=diam[1][i];
   t3=diam[2][i];
   for(j=0;j<=t3;j++)
     diam2[j][i][0]=pathstr[t1][t2][j];
  }
}


void center1(int icount)//求中心
{int i1,j1,k,bestr,r;
 double half,halfpath,left,right; 
 half=diameter/2.0;
 bestr=0;
 i1=diam[0][icount];  k=diam[2][icount];//直径边数
 halfpath=0;
 for(r=1;r<=k;r++)
  {j1=diam2[r][icount][0];
   if(fabs(halfpath+edge2[i1][j1]-half)<0.001)//中心恰好是一个结点
     {halfpath+=edge2[i1][j1];
      center0=j1; bestr=r;
      break;
     }
   else if((halfpath+edge2[i1][j1]>half)&&(halfpath<half))//中心在某边内部
     {left=half-halfpath;
      right=edge2[i1][j1]-left;
      if(left<right)
        {center0=i1; bestr=r-1;}
      else
        {center0=j1; bestr=r;}
      break;  
     }
  else if (halfpath+edge2[i1][j1]<half)   //继续加边
	{halfpath+=edge2[i1][j1];
	 i1=j1;
	}
  else
    break;
 }
 diam[3][icount]=bestr;
}


int ecc1(int icount)
{int ecc,j,k,t1,t2,t3,edgenum;
 ecc=0;
 edgenum=diam[2][icount];//直径边数
 for(k=0;k<=edgenum;k++)
   if(diam2[k][icount][1]==2) 
     {t1=diam2[k][icount][0]; //边的左结点号
      if((k<edgenum)&&(diam2[k+1][icount][1]==2)) 
        t2=diam2[k+1][icount][0]; //边的右结点号
      else
	t2=t1;
      if((k>0)&&(diam2[k-1][icount][1]==2))
	 t3=diam2[k-1][icount][0];
      else
	 t3=t1;
      for(j=1;j<=n;j++)//搜索全部结点
	 if((j!=t1)&&(pathlen[t1][j]>ecc)&&(pathstr[t1][j][1]!=t2)&&(pathstr[t1][j][1]!=t3))
	   ecc=pathlen[t1][j];
      }
 return ecc;
}

void writeone(int icount)//结点均未纳入准核
{int k;
 for(k=0;k<=diam[2][icount];k++)
      diam2[k][icount][1]=1; 
}

void search1(int icount)
// 核心计算，搜索最小偏心距,icount:直径序号
{int i,j,t1,t2,edgenum,center;
 long s_core,ecc2;
 edgenum=diam[2][icount];//直径边数
 center1(icount); 
 center=diam[3][icount];//中心所在边,先计算中心单点为核的偏心距
 writeone(icount);
 diam2[center][icount][1]=2;
 min_ecc=ecc1(icount);
 for(i=1;i<=edgenum;i++)//找出所有可能的准核
  { writeone(icount);
    s_core=0;
    for(j=i;j<=edgenum;j++) 
      {t1=diam2[j-1][icount][0];  
       t2=diam2[j][icount][0];
       if(s_core+edge2[t1][t2]<=s)
        {s_core+=edge2[t1][t2];
         diam2[j-1][icount][1]=2; //将该边两端点纳入准核  
	 diam2[j][icount][1]=2;
       	}
       else
	 break;
      }
    if(s_core>0)
      {ecc2=ecc1(icount);
       if(min_ecc>ecc2)
         min_ecc=ecc2;
      }
   }
}

void out_core()
{ cout <<"enter filename for output data:"<<endl;
 cin >>fname1;   
 ofstream myoutf1(fname1);
 if(myoutf1.fail())
     {cerr<<"error opening file myname\n";
      return;
     }
 myoutf1 <<min_ecc<<endl;
 myoutf1.close();
 cout<<"the result: "<<min_ecc<<endl;
}

void main()
{int i;
 readdata_core();
 init2();
 proc1();
 for(i=1;i<=count;i++) search1(i);//对所有直径进行判断
 out_core();
}

