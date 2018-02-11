var n:longint;
    h:array[0..100001] of longint;
procedure init;
var i:longint;
begin
  readln(n);
  for i:=1 to n do read(h[i]);
  readln;
end;
procedure force;
var last,ans:longint;
    i:longint;
begin
  last:=0; ans:=0;
  for i:=1 to n do
  begin
    if h[i]-last>0 then ans:=ans+h[i]-last;
    last:=h[i];
  end;
  writeln(ans);
end;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  init;
  force;
  close(input);
  close(output);
end.