program match;
const
 maxn=99999997;

var
 n,i,ans:longint;
 a,b:array[1..100000] of longint;

procedure fin;
begin
 assign(input,'match.in'); reset(input);
 assign(output,'match.out'); rewrite(output);
end;

procedure fout;
begin
 close(input);
 close(output);
end;

procedure swap(var a,b:longint);
var
 p:longint;
begin
 p:=a;
 a:=b;
 b:=p;
end;

procedure qsort(l,r:longint);
var
 i,j,mid:longint;
begin
 i:=l;
 j:=r;
 mid:=a[(l+r) div 2];
 repeat
  while a[i]<mid do inc(i);
  while a[j]>mid do dec(j);
  if i<=j then
  begin
   swap(a[i],a[j]);
   swap(b[i],b[j]);
   inc(i);
   dec(j);
  end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;

procedure msort;
var
 i,j:longint;
begin
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if b[i]>b[j] then
   begin
    swap(b[i],b[j]);
    ans:=(ans+1) mod maxn;
   end;
end;

begin
 fin;
 readln(n);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do read(b[i]);
 qsort(1,n);
 ans:=0;
 msort;
 writeln(ans);
 fout;
end.
