var
  a,f,t,len:array[0..1000] of longint;
  i,j,p,n,m,ans,v:longint;
begin
assign(input,'level.in');
assign(output,'level.out');
reset(input);
rewrite(output);
  readln(n,m);
  for i:=1 to n do t[i]:=1;
  ans:=1;
  for i:=1 to m do
    begin
    read(p);
      for j:=1 to p do
        begin
          read(a[j]);
          f[a[j]]:=i;
        end;
readln;
     if t[a[1]]<t[a[p]] then v:=t[a[1]] else v:=t[a[p]];
     for j:=a[1] to a[p] do
       if f[j]<>i then
       begin
if t[i]>=v then v:=t[i]+1;
       end;
     for j:=1 to p do
       t[a[j]]:=v;
     if v>ans then ans:=v;
    end;
  writeln(ans);
close(input);
close(output);
end.
