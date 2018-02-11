program count;
var n,b,c,d,x:longint;
    a:array[1..1000000] of longint;
begin
assign(input,'count.in'); reset(input);
assign(output,'count.out'); rewrite(output);
read(n);
read(x);
c:=0;
for b:=1 to n do
  begin
   a[b]:=b;
   if a[b] div 10=x then c:=c+1;
    begin
     d:=a[b] mod 10;
     a[b]:=d;
     if d=x then c:=c+1;
    end;
  end;
write(c);
close(input);close(output);
end.
