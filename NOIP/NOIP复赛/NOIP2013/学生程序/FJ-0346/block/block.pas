program block;
var a:array[1..100000] of integer;
    i,j,ans,o,p,n,temp:longint;
    b:array[1..50000] of longint;
    c:array[1..50000] of longint;
procedure init;
begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);

read(n);
for i:=1 to n do read(a[i]);

end;

procedure search;
var i,j:longint;

begin
o:=1;

fillchar(b,sizeof(b),0);
fillchar(c,sizeof(c),0);
if a[1]<>0 then b[1]:=1;
    for i:=1 to n do
    begin

        if a[i]<>0 then inc(c[o])
        else
        begin
            inc(o);
            b[o]:=i+1;
        end;
    end;
end;

begin
init;
p:=0;
repeat search;
ans:=0;
for i:=1 to o+1 do if c[i]>ans then begin ans:=c[i]; temp:=i; end;
for i:=b[temp] to b[temp]+c[temp]-1 do dec(a[i]); inc(p);
until b[n+1]=n+1;

write(p-1);
close(input);
close(output);

end.
