program circle;
var j,i,n,m,k,x,ans:longint;
    a:array[0..1000000] of longint;
    b:array[0..10000000] of integer;
    temp:longint;

procedure init;
begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
read(n,m,k,x);
end;
procedure fclose;
begin
close(input);
close(output);
end;
procedure count;
var i:longint;
    o:longint;
begin
temp:=10;
if k=1 then
ans:=temp mod i
else begin
ans:=10;
    for i:=2 to k do
    begin
    temp:=ans*10;
    ans:=temp mod i;
    if ans=0 then exit
    end;


end;
end;

begin
init;
ans:=x;
i:=0;
a[0]:=x;
repeat ans:=ans+m; if ans>n-1 then
begin
ans:=abs(n-1-ans)-1;
end;
inc(i);
a[i]:=ans;
until a[i]=a[0];

count;

write(a[ans]);

close(input);
close(output);
end.


