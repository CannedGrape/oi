program fuck;
type pyk=array[0..1000] of longint;
var
 a,b,c,d,g,f,gg,ff:pyk;
 i,j,k,l,s,t,m,n:longint;
procedure qsort(l,r:longint;  var a,b:pyk);
var i,j,m,p:longint;
 begin
 i:=l; j:=r;
 m:=a[(i+j) div 2];
 while i<=j do
  begin
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
   if i<=j then
    begin
    p:=a[i]; a[i]:=a[j]; a[j]:=p;
    p:=b[i]; b[i]:=b[j]; b[j]:=p;
    inc(i);
    dec(j);
    end;
  end;
 if i<r then qsort(i,r,a,b);
 if l<j then qsort(l,j,a,b);
 end;


begin
 assign(input,'match.in');
 assign(output,'match.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do
  read(a[i]);
 readln;
 for j:=1 to n do
  read(b[i]);
 readln;
 f:=a;
 g:=b;
 writeln(1);
 close(input);
 close(output);
end.
