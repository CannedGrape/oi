program expr;
var a1:array[1..100000]of string[50];
a2:array[1..200000]of longint;
a:ansistring;
k,lena1,lena,j,i:longint;
t,tot:qword;
begin
 assign(input,'expr.in');reset(input);
 assign(output,'expr.out');rewrite(output);
 readln(a);
 lena:=length(a);
 j:=1;
 for i:=1 to lena do
 begin
  if (a[i]<>'+')and(a[i]<>'*') then a1[j]:=a1[j]+a[i]
  else if a[i]='+' then
  begin
   inc(j);
   a1[j]:=a1[j]+a[i];
   inc(j);
  end
  else if a[i]='*' then
  begin
   inc(j);
   a1[j]:=a1[j]+a[i];
   inc(j);
  end;
 end;
 for i:=1 to j do
 begin
  if (a1[i]<>'+')and(a1[i]<>'*') then
  begin
   lena1:=length(a1[i]);
   a2[i]:=a2[i]+ord(a1[i,1])-48;
   for k:=2 to lena1 do
   begin
    if a1[i,k]<>'0' then a2[i]:=a2[i]*10+(ord(a1[i,k])-48)
    else a2[i]:=a2[i]*10;
   end;
  end
  else a2[i]:=-1;
 end;
 for i:=1 to j do
 begin
  if a2[i]<>-1 then
  begin
   if (a1[i+1]='+')and(a1[i+3]<>'*') then
   begin
    tot:=a2[i]+a2[i+2]+tot;
    a2[i]:=-1;a2[i+2]:=-1;
   end;
   if a1[i+1]='*' then
   begin
    tot:=tot+a2[i]*a2[i+2];
    a2[i]:=-1;a2[i+2]:=-1;
   end;
   if (a1[i+1]='+')and(a1[i+3]='*') then tot:=tot+a2[i];
  end;
 end;
 if a2[i]<>-1 then tot:=tot+a2[i];
 j:=tot;k:=0;
 while j<>0 do
 begin
  j:=j div 10;
  inc(k);
 end;
 if k>4 then begin t:=tot;for i:=1 to 4 do t:=t div 10;for i:=1 to 4 do t:=t*10;end;
 if k>4 then tot:=tot-t;
 writeln(tot);
 close(input);close(output);
end.