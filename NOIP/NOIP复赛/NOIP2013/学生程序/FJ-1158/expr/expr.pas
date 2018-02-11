var
a,b:ansistring;
aa:array[0..100000] of qword;
ab:array[0..100000] of 0..2;
i,j,m,n,o,p,code:longint;
bb:boolean;
an,ans:int64;
begin
assign(input,'expr.in');reset(input);assign(output,'expr.out');rewrite(output);
fillchar(aa,sizeof(aa),0);
fillchar(ab,sizeof(ab),0);
readln(a);
n:=length(a);
o:=1;p:=1;
for i:=1 to n do
begin

if (a[i]='+')  then
begin
b:=copy(a,p,i-p);
val(b,aa[o],code);
ab[o]:=1;
inc(o);
p:=i+1;
end;

if (a[i]='*')  then
begin
b:=copy(a,p,i-p);
val(b,aa[o],code);
ab[o]:=2;
inc(o);
p:=i+1;
end;

end;
b:=copy(a,p,n-p+1);
val(b,aa[o],code);
an:=0;bb:=false;ans:=0;
for i:=1 to o-1 do
begin
if ab[i]=1 then bb:=false;
if ab[i]=2 then
if bb then begin an:=(an*aa[i+1]) mod 10000;aa[i+1]:=0;bb:=true;end
else begin ans:=(ans+an) mod 10000;an:=0;an:=an+(aa[i]*aa[i+1]) mod 10000;aa[i]:=0;aa[i+1]:=0;bb:=true;end;
end;
ans:=(ans+an) mod 10000;
for i:=1 to o do ans:=(ans+aa[i]) mod 10000;
writeln(ans mod 10000);
close(input);close(output);
end.





















