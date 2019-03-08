program match;
type ni=record
         s,l:int64;
        end;
var
 a,b:array[1..100000]of ni;
 n,i:longint;
 sum:int64;

procedure sorta(l,r:longint);
var
 i,j:longint;
 m,p:int64;
begin
 i:=l; j:=r;
 m:=a[(i+j)div 2].s;
 repeat
  while a[i].s<m do inc(i);
  while a[j].s>m do dec(j);
  if i<=j then
  begin
   p:=a[i].s; a[i].s:=a[j].s; a[j].s:=p;
   p:=a[i].l; a[i].l:=a[j].l; a[j].l:=p;
   inc(i); dec(j);
  end;
 until i>j;
 if l<j then sorta(l,j);
 if i<r then sorta(i,r);
end;

procedure sortb(l,r:longint);
var
 i,j:longint;
 m,p:int64;
begin
 i:=l; j:=r;
 m:=b[(i+j)div 2].s;
 repeat
  while b[i].s<m do inc(i);
  while b[j].s>m do dec(j);
  if i<=j then
  begin
   p:=b[i].s; b[i].s:=b[j].s; b[j].s:=p;
   p:=b[i].l; b[i].l:=b[j].l; b[j].l:=p;
   inc(i); dec(j);
  end;
 until i>j;
 if l<j then sortb(l,j);
 if i<r then sortb(i,r);
end;

begin
 assign(input,'match.in'); reset(input);
 assign(output,'match.out'); rewrite(output);
 readln(n);
 for i:=1 to n do
 begin
  read(a[i].s);
  a[i].l:=i;
 end;
 for i:=1 to n do
 begin
  read(b[i].s);
  b[i].l:=i;
 end;
 sorta(1,n);
 sortb(1,n);
 for i:=1 to n do
  if a[i].l<>b[i].l then sum:=(sum+abs(a[i].l-b[i].l))mod 99999997;
 sum:=sum div 2;
 writeln(sum);
 close(input); close(output);
end.
