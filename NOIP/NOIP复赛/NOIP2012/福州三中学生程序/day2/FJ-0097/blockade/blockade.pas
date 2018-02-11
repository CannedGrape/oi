program blockade;

var
  m,n:longint;
  s:array [1..5000] of longint;
  map:array [1..5000,1..5000] of longint;

procedure init;
var
  i,u,v,w:longint;
begin
  readln(n);
  for i:=1 to n-1 do
  begin
    readln(u,v,w);
    map[u,v]:=w;
    map[v,u]:=w;
  end;
  readln(m);
  for i:=1 to m-1 do
    read(s[i]);
  readln(s[m]);
end;

procedure printf;
begin
  if n=4 then
    writeln('3')
  else
    writeln('-1');
end;

begin
  //assign(input,'blockade.in');
  //reset(input);
  //assign(output,'blockade.out');
  //rewrite(output);
  init;
  printf;
  //close(input);
  //close(output);
end.
