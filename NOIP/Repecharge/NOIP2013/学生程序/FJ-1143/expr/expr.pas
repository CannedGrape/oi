const
jz:array[1..4] of longint=(1,10,100,1000);
var
try,ans,pd,n,ls,i:longint;
data:array[0..1000000] of longint;
fh:array[1..1000000] of char;
lc:string;
a:ansistring;
begin
assign(input,'expr.in'); reset(input);
assign(output,'expr.out'); rewrite(output);
readln(a);
try:=length(a);
data[0]:=0;
n:=0;
ls:=0;
pd:=0;
for i:=length(a) downto 1 do
begin
lc:=copy(a,i,1);
if ('0'<=lc)and(lc<='9') then begin if pd<4 then
begin inc(pd); ls:=ls+(ord(lc[1])-ord('0'))*jz[pd] end; end else
begin inc(data[0]); data[data[0]]:=ls; pd:=0; ls:=0;
inc(n); fh[n]:=lc[1]; end;
end;
inc(data[0]); data[data[0]]:=ls;
ls:=1;
for i:=n downto 1 do
begin
ls:=ls*data[i+1];
ls:=ls mod 10000;
if fh[i]='+' then begin ans:=ans+ls; ls:=1; end;
end;
ans:=ans+ls*data[1];
writeln(ans mod 10000);
close(input);
close(output);
end.