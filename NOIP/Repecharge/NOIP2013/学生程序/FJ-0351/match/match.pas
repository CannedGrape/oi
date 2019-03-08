var n:longint;
      a:array[1..1020]of int64;
	  b:array[1..1020]of int64;
	  i,j:longint;
      m,p:int64;  q:integer;
{procedure qs(l,r:integer);
var i,j:integer;mid,p:integer;
begin
i:=l;j:=r;
mid:=a[(l+r) div 2];
repeat
while a[i]<mid do inc(i);
while a[j]>mid do dec(j);
if i<j then
begin p:=a[i];a[i]:=a[j];a[j]:=p;
		 p:=b[i];b[i]:=b[j];b[j]:=p;
inc(i);dec(j);
end;
until i>=j;
if l<j then qs(l,j);
if r>i then qs(i,r);
end;}

procedure qs;
var i,j,q:integer;
begin
for q:=1 to 2 do
for i:=1 to n-1 do
  begin
   j:=i+1;
if a[i]>a[j] then
   begin
     p:=a[i];a[i]:=a[j];a[j]:=p;
      p:=b[i];b[i]:=b[j];b[j]:=p;
      end;

    if a[i]=a[j] then
    if b[i]>b[j] then
   begin
     p:=a[i];a[i]:=a[j];a[j]:=p;
      p:=b[i];b[i]:=b[j];b[j]:=p;
      end;
    end;

end;

procedure  pan(i,j:integer);
var e,r,t,y:int64;
begin
if j>n then exit;
e:=(a[i]-b[i])*(a[i]-b[i]);
r:=(a[j]-b[j])*(a[j]-b[j]);
t:=(a[i]-b[j])*(a[i]-b[j]);
y:=(a[j]-b[i])*(a[j]-b[i]);
if a[i]=a[j] then
if (e+r)>=(t+y) then begin p:=b[i];b[i]:=b[j];b[j]:=p;inc(m);end;
end;

begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to n do read(b[i]);
m:=0;
i:=1;
j:=i+1;
while j<=n do begin pan(i,j);inc(i);inc(j);
     end;
m:=m mod 99999997;
writeln(m);
close(input);
close(output);
end.



