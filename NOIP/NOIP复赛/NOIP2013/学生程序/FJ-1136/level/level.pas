program level;
var
  i,j,n,m,x,y,ans:longint;
  s,a:array[0..1006] of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    begin
      read(s[i]);
      read(x);
      for j:=2 to s[i] do
       begin
         read(y);
         inc(a[x]);
       end;
    end;
  ans:=0;
  for i:=1 to n do
    if a[i]>0 then inc(ans);
  writeln(ans);
  close(input);
  close(output);
end.