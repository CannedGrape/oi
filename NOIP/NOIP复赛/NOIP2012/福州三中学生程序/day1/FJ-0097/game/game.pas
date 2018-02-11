program game;  //baoli;

var
  n,i,a,b,max:longint;
  ans,left,right:array [1..1000] of longint;

begin
  assign(input,'game.in');
  reset(input);
  assign(output,'game.out');
  rewrite(output);
  readln(n);
  readln(a,b);
  for i:=1 to n do
    readln(left[i],right[i]);
  ans[1]:=left[1];
  for i:=2 to n do
    ans[i]:=ans[i-1]*left[i];
  for i:=1 to n do
  begin
    ans[i]:=ans[i] div right[i];
    if max<ans[i] then
      max:=ans[i];
  end;
  writeln(max);
end.
