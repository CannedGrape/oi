var n:longint;
    h,tmp:array[0..100001] of longint;
    low,big:longint;
procedure init;
var i,m:longint;
begin
  readln(n);
  fillchar(h,sizeof(h),$ff);
  for i:=1 to n do read(h[i]);
  readln;

  m:=0;
  fillchar(tmp,sizeof(tmp),$ff);
  for i:=1 to n do
  if h[i]<>h[i-1] then
  begin
    m:=m+1;
    tmp[m]:=h[i];
  end;
  n:=m; h:=tmp;
end;
procedure force;
var i:longint;
begin
  low:=0; big:=0;
  for i:=2 to n-1 do if (h[i]<h[i-1]) and (h[i]<h[i+1]) then low:=low+1;
  for i:=2 to n-1 do if (h[i]>h[i-1]) and (h[i]>h[i+1]) then big:=big+1;
end;
procedure print;
begin
  if low>big then writeln(2*low+1)
  else writeln(2*big+1);
end;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  init;
  force;
  print;
  close(input);
  close(output);
end.