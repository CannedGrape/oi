program classroom;    //baoli


var
  i,j,n,m:longint;
  r,d,s,t:array [1..10000] of longint;

procedure init;
begin
  readln(n,m);
  for i:=1 to n-1 do
    read(r[i]);
  readln(r[n]);
  for i:=1 to m do
    readln(d[i],s[i],t[i]);
end;

begin
  assign(input,'classroom.in');
  reset(input);
  assign(output,'classroom.out');
  rewrite(output);
  init;
  for i:=1 to m do
    for j:=s[i] to t[i] do
    begin
      r[j]:=r[j]-d[j];
      if r[j]<0 then
      begin
        writeln('-1');
        writeln(i);
        halt;
      end;
    end;
  close(input);
  close(output);
end.
