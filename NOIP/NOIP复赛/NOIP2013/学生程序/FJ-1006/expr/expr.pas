const fn='expr';
var s:ansistring;i,j,l,dnp:qword;
data:array[0..800000]of qword;
procedure flink;begin assign(input,fn+'.in');assign(output,fn+'.out');reset(input);rewrite(output) end;
procedure fclose;begin close(output);close(input) end;

function getnum(a,b:longword):qword;
begin getnum:=0;for a:=a to b do getnum:=getnum*10 +ord(s[a])-48 end;
	
begin
flink;
read(s);
l:=length(s);
i:=1;dnp:=0;
while i<=l do begin 
j:=i;
while (s[i]in['0'..'9'])and(i<=l)do inc(i);
	dec(i);
if i=l then break;
inc(dnp);data[dnp]:=getnum(j,i);
inc(i);
if s[i]='*' then 
	begin j:=i;inc(i);
while (s[i]in['0'..'9'])and(i<=l)do inc(i);
	dec(i); if i=l then break;data[dnp+1]:=getnum(j,i);data[dnp]:=(data[dnp]*data[dnp+1]) mod 10000 end;
inc(i) 
end;
while dnp>1 do begin
	dec(dnp);data[dnp]:=(data[dnp]+data[dnp+1]) mod 10000 end;
write(data[1]);
fclose;
end.