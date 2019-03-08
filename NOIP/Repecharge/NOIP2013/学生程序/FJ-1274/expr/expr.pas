var a:array[-10..1000000]of int64;
    b:array[-10..1000000]of char;
    s:string;
    o,k,i,tot,ans,v,e,g:int64;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
readln(s);
o:=1;
k:=1;
i:=1;
while i<=length(s) do
begin
if (s[i]>='0')and(s[i]<='9') then
begin
while(s[i]>='0')and(s[i]<='9')  do
begin
a[o]:=a[o]*10+(ord(s[i])-48);
i:=i+1;
end;
o:=o+1;
end;
if s[i]='+' then begin b[k]:=s[i]; i:=i+1; k:=k+1; end;
if s[i]='*' then begin b[k]:=s[i]; i:=i+1; k:=k+1; end;
end;
i:=1;
v:=o-1;
o:=1;
tot:=0;
while i<v do
begin
if b[i]='+' then begin tot:=(tot+a[i])mod 10000; i:=i+1; end;
if b[i]='*' then begin
repeat
o:=(o*a[i])mod 10000;
i:=i+1;
e:=1;
until (b[i]='+')or(i=k);
o:=(o*a[i])mod 10000;
i:=i+1;
if e=1 then begin tot:=(tot+o)mod 10000;  e:=0; end;
o:=1;
end;
end;
if b[i-1]='+' then tot:=(tot+a[i])mod 10000;
tot:=tot mod 10000;
writeln(tot);
close(input);close(output);
end.
