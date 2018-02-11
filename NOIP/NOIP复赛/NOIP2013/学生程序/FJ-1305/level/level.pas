program level;
var
  t,i,j,s,s2,num,n,m:longint;
  lv:array[1..1000] of longint;
  b:array[1..1000,-1..1000] of longint;
  xu:array[1..1000] of longint;
function max:longint;
var i,t:longint;
begin
  t:=-maxlongint;
  for i:=s+1 to s2-1 do
    if lv[i]>t then
      t:=lv[i];
  max:=t;
end;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do
    lv[i]:=1;
  for i:=1 to m do
    begin
      read(num,s2);
      for j:=1 to num-1 do
        begin
          s:=s2;
          read(s2);
          m:=max;
          lv[s]:=m+1;
          lv[s2]:=m+1;
        end;
    end;
  s:=0;s2:=n+1;
  writeln(max);
  close(input);close(output);
end.
