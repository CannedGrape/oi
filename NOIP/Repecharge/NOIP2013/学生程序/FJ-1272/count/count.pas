program count;
var a:array[1..100]of longint;
t,tot,ni,n,x,i,j,lena:longint;
begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 readln(n,x);
 lena:=1;ni:=n;
 while ni<>0 do begin a[lena]:=ni mod 10;ni:=ni div 10;inc(lena);end;
 for i:=1 to n do
 begin
  for j:=1 to lena do
  begin
   if a[j]=x then inc(tot);
  end;
  a[1]:=a[1]-1;
  if a[1]=-1 then begin t:=-1;a[1]:=9;j:=2;end
  else t:=0;
  while (t=-1)and(j<=lena) do
  begin
   a[j]:=a[j]+t;
   if a[j]=-1 then begin t:=-1;a[j]:=9;j:=j+1;end
   else t:=0;
  end;
  if a[lena]=0 then lena:=lena-1;
 end;
 writeln(tot);
 close(input);close(output);
end.
