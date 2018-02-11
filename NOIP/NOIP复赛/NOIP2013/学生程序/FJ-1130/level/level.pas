program level;

const MAXN=1000;

var
 flag:array[0..MAXN,0..MAXN]of boolean;
 lev,sum,st,en:array[0..MAXN]of longint;
 i,j,m,max,min,nn,t:longint;

function next(c,d:longint):longint;
var i:longint;
begin
 for i:=d+1 to nn do
  if flag[c,i]=true then exit(i);
 exit(0);
end;

function check(e,a,b:longint):boolean;
var i:longint;
begin
 for i:=1 to m do
 begin
  if (a>=st[i]) and (a<=en[i]) and (e<>i) then
   if ((flag[i,a]=true) and (lev[a]<b))
   or ((lev[a]>=b) and (flag[i,a]=false)) then exit(false);
 end;
 exit(true);
end;

procedure search(k,n,maxlevel:longint);
var i:longint;
begin
 if k>m then
 begin
  if maxlevel<min then min:=maxlevel;
  exit;
 end;
 {if lev[n]<>0 then
 begin
  if next(k,n)=0 then search(k+1,next(k+1,0),maxlevel)
  else search(k,next(k,n),maxlevel);
 end
 else
 begin}
  for i:=lev[i]+1 to nn do
   if check(k,n,i) then
   begin
    lev[n]:=i;
    if i>maxlevel then maxlevel:=i;
    if next(k,n)=0 then search(k+1,next(k+1,0),maxlevel)
    else search(k,next(k,n),maxlevel);
   end;
 //end;
end;

begin
 //assign(input,'level.in'); reset(input);
 //assign(output,'level.out'); rewrite(output);
 min:=maxlongint;  max:=1;
 readln(nn,m);
 for i:=1 to nn do lev[i]:=1;
 for i:=1 to m do
 begin
  read(sum[i]);
  for j:=1 to sum[i] do
  begin
   read(t);
   flag[i,t]:=true;
   if j=1 then st[i]:=t;
   if j=sum[i] then en[i]:=t;
  end;
 end;
 search(1,next(1,0),max);
 writeln(min);
 //close(input); close(output);
end.
