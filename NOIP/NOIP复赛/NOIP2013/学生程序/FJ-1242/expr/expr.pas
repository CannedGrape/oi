var a:string;
    b,l,y,m,i,ans,j,x:longint;
    d:array[0..10000001] of char;
    c,q:array[0..10000001] of longint;
function lol(var n,m:longint):longint;
var j,i:longint;
    q:array[0..10001] of longint;
begin
 q[1]:=0;
 for j:=m to n do q[j-m+1]:=ord(a[j])-ord('0');
 for i:=1 to n-m+1 do lol:=lol*10+q[i];
end;
begin
 assign(input,'expr.in');reset(input);
 assign(output,'expr.out');rewrite(output);
 readln(a);
 l:=length(a);
 y:=1;
 m:=1;
 x:=1;
 while i<=l do
  begin
   inc(i);
   if (a[i]='+') or (a[i]='*') then
    begin
     x:=i-1;
     c[y]:=lol(x,m);
     m:=i+1;
     d[y]:=a[i];
     inc(y);
    end;
    end;
  lol(l,m);
  c[y]:=b;
  for i:=1 to y do
  begin
   if d[i]='*' then
    begin
     c[i+1]:=c[i]*c[i+1];
     c[i]:=0;
    end;
    end;
   for i:=1 to y do ans:=ans+c[i];
   if ans>=10000 then
    while ans>=10000 do ans:=ans-10000;
   write(ans);
 close(input);close(output);
end.
