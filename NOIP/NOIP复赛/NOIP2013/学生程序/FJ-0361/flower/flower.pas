var
   n,i,j:Longint;
   h:array[0..200000] of longint;
   f:array[0..200000,1..2] of longint;

function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;

begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input); rewrite(output);
   readln(n);
   for i:=1 to n do
   read(h[i]);
   fillchar(f,sizeof(f),0);
   f[1,1]:=1;
   f[1,2]:=1;
   for i:=2 to n do
    for j:=1 to i-1 do
    begin
      if ((f[j,1] mod 2=0) and (h[i]>h[j])) or ((f[j,1] mod 2<>0) and (h[i]<h[j])) then
        f[i,1]:=max(f[i,1],f[j,1]+1);
      if ((f[j,2] mod 2=0) and (h[i]<h[j])) or ((f[j,2] mod 2<>0) and (h[i]>h[j])) then
        f[i,2]:=max(f[i,2],f[j,2]+1);
    end;
    writeln(max(f[n,1],f[n,2]));


close(input); close(output);
end.
