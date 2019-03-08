program level;
var a,b:array [1..1000] of longint;
    c:array [1..350000] of boolean;
    i,j,s,n,m,y:longint;
 begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(n,m);
  fillchar(c,sizeof(c[i]),false);
  for i:=1 to m do
  begin
   read(a[i]);
   y:=0;
   for j:=1 to a[i] do
   begin
    read(b[j]);
    if not(c[b[j]]) then inc(y);
    c[b[j]]:=true;
   end;
   if y<>0 then inc(s);
   readln;
  end;
  if a[1]<>n then writeln(s+1)
  else writeln(s);
  close(input);close(output);
 end.

