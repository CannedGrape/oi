program expr;
var n,b,c,d,x,l,h,k,z,p:longint;
    a:array[1..1000000] of string;
    s,m,t:string;
begin
assign(input,'expr.in'); reset(input);
assign(output,'expr.out'); rewrite(output);

read(s);
b:=length(s);
for c:=1 to b do
  begin
  a[c]:=copy(s,c,1);
   if a[c]='*' then
     begin
      d:=c;
      for x:=d downto 1 do
        begin
         if a[x]='+' then l:=x;
         m:=copy(s,l+1,d-l-1);
         if a[x]<>'+' then
         m:=copy(s,1,d);
        end;
      for h:=d to b do
        begin
         if a[h]='+' then k:=h;
         t:=copy(s,d+1,k-1);
         if a[h]<>'+' then
         t:=copy(s,d+1,b);
        end;
     end;
  end;
if (a[c]<>'+')or(a[c]<>'*') then write(s);
close(input);close(output);
end.







