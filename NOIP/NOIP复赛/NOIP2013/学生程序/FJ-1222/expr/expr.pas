type se=array[1..4]of integer;
var a:array[0..100005]of se;
    q:array[0..100005]of char;
    r:array[0..4]of longint;
    k,i,j,b,p,n:longint;
    s,l,s1:ansistring;
    x:boolean;
procedure cf(o:longint);
var c:array[1..4,1..4]of longint;
    t,w,v,y:longint;
begin
 fillchar(c,sizeof(c),0);
 for t:=1 to 4 do
 begin
  if a[o+1,t]>0 then
  begin
   w:=5-t;
   y:=0;
   for v:=1 to w do
   begin
    if v+t-1<=4 then
    begin
     c[t,v+t-1]:=y+a[o+1,t]*a[o,v];
     y:=c[t,v] div 10;
     c[t,v]:=c[t,v] mod 10;
    end;
   end;
  end;
 end;
 y:=0;
 for t:=1 to 4 do
 begin
  a[o+1][t]:=0;
  a[o][t]:=y;
  for v:=1 to t do
   a[o][t]:=a[o][t]+c[v][t];
  y:=a[o][t] div 10;
  a[o][t]:=a[o][t] mod 10;
 end;
end;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 fillchar(a,sizeof(a),0);
 readln(s);
 s1:=s;
 k:=pos('+',s);
 b:=pos('*',s);
 i:=0;
 while (k>0)or(b>0)do
 begin
  inc(i);
  if ((k<b)and(k>0))or(b<=0)then
   begin
    q[i]:='+';
    l:=copy(s,1,k-1);
    delete(s,1,k);
    val(l,j);
    p:=0;
    k:=pos('+',s);
    b:=pos('*',s);
    while j<>0 do
    begin
     inc(p);
     a[i][p]:=j mod 10;
     j:=j div 10;
     if p>=4 then break;
    end;
   end
  else
  if b>0 then
   begin
    q[i]:='*';
    l:=copy(s,1,b-1);
    delete(s,1,b);
    val(l,j);
    p:=0;
    b:=pos('*',s);
    k:=pos('+',s);
    while j<>0 do
     begin
      inc(p);
      a[i][p]:=j mod 10;
      j:=j div 10;
      if p>=4 then break;
     end;
   end;
 end;
 p:=length(s);
 for j:=p downto 1 do
  a[i+1,j]:=ord(s[p+1-j])-48;
 n:=i+1;
 p:=0;
for i:=1 to n-1 do
 if q[i]='*' then cf(i);
fillchar(r,sizeof(r),0);
for j:=1 to 4 do
begin
 r[j]:=r[j]+p;
 for i:=1 to n do
  r[j]:=r[j]+a[i][j];
 p:=r[j] div 10;
 r[j]:=r[j] mod 10;
end;
x:=false;
for i:=4 downto 1 do
 if (r[i]<>0)or(x) then
 begin
  write(r[i]);
  x:=true;
 end;
close(input);close(output);
end.
