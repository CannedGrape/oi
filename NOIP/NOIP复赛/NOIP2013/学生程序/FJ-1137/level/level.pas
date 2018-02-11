program level;
var
  i,j,n,m,k,x,sum,ji:longint;
  a:array[1..10000]of longint;
  e:real;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),0);  sum:=0;  ji:=0;
  for i:=1 to m do
  begin
    read(k);
    for j:=1 to k do
    begin
      read(x);
      inc(a[x]);
    end;
    readln;
  end;
  for i:=1 to n do
  begin
    if a[i]<>0 then
    begin
      sum:=sum+a[i];
      inc(ji);
    end;
  end;
  e:=sum/ji;
  if trunc(e)<>e then e:=trunc(e)+1
  else e:=e+1;
  writeln(e:0:0);
  close(input);
  close(output);
end.