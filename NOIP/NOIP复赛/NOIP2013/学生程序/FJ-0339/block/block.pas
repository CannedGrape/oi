program block;
var
 a:array[1..100001]of longint;
 n,i,j:longint;
 sum:int64;

procedure mid(l,r:longint);
var
 i,j,min:longint;
begin
 if l=r then
 begin
  sum:=sum+a[l];
  exit;
 end;
 min:=10001;
 for i:=l to r do
  if a[i]<min then
  begin
   min:=a[i];
   j:=i;
  end;
 sum:=sum+min;
 for i:=l to r do a[i]:=a[i]-min;
 if l<j then mid(l,j-1);
 if j<r then mid(j+1,r);
end;

begin
 assign(input,'block.in'); reset(input);
 assign(output,'block.out'); rewrite(output);
 readln(n);
 for i:=1 to n do read(a[i]);
 mid(1,n);
 writeln(sum);
 close(input); close(output);
end.
