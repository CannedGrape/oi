program core1;
const N1=301;
      N2=45000;
      M1=21;
type arr1=array[0..N1] of integer;
     arr2=array[0..N1] of arr1;
     arr3=array[0..3] of integer;
     arr4=array[0..4] of integer;
     arr5=array[0..2] of integer;
     arrm=array[0..M1] of integer;
     arrm2=array[0..M1] of arr5;
var  file1:string[30];
     text1,text2:text;
     pathlen,pathlen2,flag,edge2:arr2;
     pathlen3:array[0..N2] of arr4;
     edge:array[0..N1] of arr3;
     pathstr:array[0..N1] of arr2;
     diam:array[0..4] of arrm;
     diam2:array[0..N1] of arrm2;
     i,n,s,center0,diameter,count:integer;
     cn2,min_ecc,new1:longint;

procedure readdata_core;
var i:integer;
begin
  writeln('input filename for input:');
  readln(file1);
  assign(text1,file1); reset(text1);
  readln(text1,n,s);
  for i:=1 to n-1 do
   readln(text1,edge[i][0],edge[i][1],edge[i][2]);
 close(text1);
end;

procedure link1(t1,t2,t3, t4,i,j:longint);
 {(t1,t2)(t3,t4),t1=t3,生成(t2,t4)}
var k,k3:integer;
begin
 inc(new1);
 pathlen3[new1][0]:=t2;   pathlen3[new1][1]:=t4;
 pathlen3[new1][2]:=pathlen3[i][2]+pathlen3[j][2];
 k3:=pathlen3[j][3];
 pathlen3[new1][3]:=1+k3;
 flag[t2][t4]:=1;
 flag[t4][t2]:=1;
 pathstr[t2][t4][1]:=t3;
 for k:=1 to k3 do
    pathstr[t2][t4][k+1]:=pathstr[t3][t4][k];
 for k:=1 to k3+1 do
    pathstr[t4][t2][k]:=pathstr[t2][t4][k3-k+1];
end;

procedure init2;
var i,j,k,t1,t2,t3,t4,start1,end1,u,v,kp:longint;
begin
 for i:=1 to n do
 begin
   for j:=1 to n do
    begin
      flag[i][j]:=0;
      pathlen[i][j]:=0;
      pathlen2[i][j]:=0;
     pathstr[i][j][0]:=i;
     for k:=1 to n do  pathstr[i][j][k]:=0;
    end;
  flag[i][i]:=1;
 end;
 for i:=1 to n-1 do
   begin
    for j:=0 to 2 do
      pathlen3[i][j]:=edge[i][j];
    pathlen3[i][3]:=1;
    u:=edge[i][0];  v:=edge[i][1];
    edge2[u][v]:=edge[i][2]; edge2[v][u]:=edge[i][2];
    flag[u][v]:=1; flag[v][u]:=1;
    pathstr[u][v][1]:=v;
    pathstr[v][u][1]:=u;
  end;
 cn2:=n*(n-1) div 2;
 end1:=n-1;
 new1:=n-1;
 kp:=1;
 while (new1<cn2) do
  begin{1}
   for i:=1 to n-1 do
     begin{2}
      if(kp=1) then
       start1:=i+1;
      for j:=start1 to end1 do
        begin
         t1:=pathlen3[i][0]; t2:=pathlen3[i][1];
         t3:=pathlen3[j][0]; t4:=pathlen3[j][1];
         if ((t1=t3) and(flag[t2][t4]=0)) then
             link1(t1,t2,t3,t4,i,j)
 	 else if ((t2=t4) and(flag[t1][t3]=0)) then
             link1(t2,t1,t4,t3,i,j)
         else if ((t2=t3) and (flag[t1][t4]=0)) then
	     link1(t2,t1,t3,t4,i,j)
          else if ((t1=t4) and(flag[t2][t3]=0)) then
	     link1(t1,t2,t4,t3,i,j);
       end;
    end;{2}
  if(kp=1) then kp:=2;
  start1:=end1+1;
      end1:=new1;
 end;{1}
  for i:=1 to cn2 do
   begin
     t1:=pathlen3[i][0];
     t2:=pathlen3[i][1];
     pathlen[t1][t2]:=pathlen3[i][2];
     pathlen[t2][t1]:=pathlen3[i][2];
     pathlen2[t1][t2]:=pathlen3[i][3];
     pathlen2[t2][t1]:=pathlen3[i][3];
   end;
 min_ecc:=100000000;
end;

procedure proc1;
var i,j,t1,t2,t3:integer;
begin
 diameter:=0; count:=0;
 for i:=1 to n-1 do
  for j:=i+1 to n do
    if (pathlen[i][j]>diameter) then
    	diameter:=pathlen[i][j];
 for i:=1 to n-1 do
   for j:=i+1 to n do
    if((pathlen[i][j]=diameter) and(count<20)) then
      begin
	inc(count);
	diam[0][count]:=i;diam[1][count]:=j;
	 diam[2][count]:=pathlen2[i][j];
     end;
  for i:=1 to count do
   begin
   t1:=diam[0][i];
   t2:=diam[1][i];
   t3:=diam[2][i];
   for j:=0 to t3 do
     diam2[j][i][0]:=pathstr[t1][t2][j];
   end;
end;

procedure center1(icount:integer);
var i1,j1,k,bestr,r:integer;
    half,halfpath,left,right:double;
begin
 half:=diameter/2.0;
 bestr:=0;
 i1:=diam[0][icount];  k:=diam[2][icount]; {直径边数}
 halfpath:=0;
 for r:=1 to k do
  begin
   j1:=diam2[r][icount][0];
   if (abs(halfpath+edge2[i1][j1]-half)<0.001) then
    begin
      halfpath:=halfpath+edge2[i1][j1];
      center0:=j1; bestr:=r;
      break;
    end
   else if((halfpath+edge2[i1][j1]>half) and (halfpath<half)) then
    begin
      left:=half-halfpath;
      right:=edge2[i1][j1]-left;
      if left<right then
        begin center0:=i1; bestr:=r-1; end
      else
        begin center0:=j1; bestr:=r; end;
      break;
    end
  else if (halfpath+edge2[i1][j1]<half)  then
     begin
	halfpath:=halfpath+edge2[i1][j1];
	 i1:=j1;
      end
  else
    break;
 end;
 diam[3][icount]:=bestr;
end;


function ecc1(icount:integer):integer;
var  ecc,j,k,t1,t2,t3,edgenum:integer;
begin
 ecc:=0;
 edgenum:=diam[2][icount];
 for k:=0 to edgenum do
   if (diam2[k][icount][1]=2) then
     begin
      t1:=diam2[k][icount][0];
      if((k<edgenum) and(diam2[k+1][icount][1]=2)) then
        t2:=diam2[k+1][icount][0]
      else
	t2:=t1;
      if((k>0)and(diam2[k-1][icount][1]=2)) then
	 t3:=diam2[k-1][icount][0]
      else
	 t3:=t1;
      for j:=1 to n do
	if((j<>t1)and(pathlen[t1][j]>ecc)and(pathstr[t1][j][1]<>t2)
          and(pathstr[t1][j][1]<>t3)) then
	   ecc:=pathlen[t1][j];
      end;
 ecc1:=ecc;
end;

procedure writeone(icount:integer);
var k:integer;
begin
 for k:=0 to diam[2][icount] do
      diam2[k][icount][1]:=1;
end;

procedure search1(icount:integer);
var i,j,t1,t2,edgenum,center:integer;
    s_core,ecc2:longint;
begin
 edgenum:=diam[2][icount];
 center1(icount);
 center:=diam[3][icount];{中心所在边,先计算中心单点为核的偏心距}
 writeone(icount);
 diam2[center][icount][1]:=2;
 min_ecc:=ecc1(icount);
 for i:=1 to edgenum do  {找出所有可能的准核}
  begin{1}
    writeone(icount);
    s_core:=0;
    for j:=i to edgenum do
      begin
        t1:=diam2[j-1][icount][0];
        t2:=diam2[j][icount][0];
        if(s_core+edge2[t1][t2]<=s) then
        begin
          s_core:=s_core+edge2[t1][t2];
         diam2[j-1][icount][1]:=2; {将该边两端点纳入准核}
	 diam2[j][icount][1]:=2;
       end
       else
	 break;
      end;
    if (s_core>0) then
      begin
       ecc2:=ecc1(icount);
       if (min_ecc>ecc2) then
         min_ecc:=ecc2;
      end;
   end;{1}
end;

procedure out_core;
var j,k:integer;
begin
 writeln('input filename for output:');
 readln(file1);
 assign(text2,file1); rewrite(text2);
 writeln(text2,min_ecc);
 close(text2);
end;

begin
 readdata_core;
 init2;
 proc1;
 for i:=1 to count do  search1(i);
 out_core;
end.

