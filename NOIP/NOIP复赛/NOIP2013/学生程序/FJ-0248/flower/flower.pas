program flower;
var
  i,n,s,t,ans:longint;
  a,h:array[1..10000000] of longint;
procedure xuan;
var
  i:longint;
begin
  i:=2;
  while i<n do
  begin
    if (h[i-1]<h[i]) and (h[i+1]<h[i]) then
      inc(i,2)
    else begin
      a[i]:=a[i-1];
      s:=s-1;
      inc(i);
    end;
  end;
  i:=2;
  while i<n do
  begin
    if (h[i-1]>h[i]) and (h[i+1]>h[i]) then
      inc(i,2)
    else begin
      h[i]:=h[i-1];
      t:=t-1;
      inc(i);
    end;
end;
end;

begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(h[i]);
  for i:=1 to n do
    a[i]:=h[i];
  s:=n;t:=n;
  if n=1 then ans:=1 else
     xuan;
  if s>t then ans:=s
  else ans:=t;
  writeln(ans);
  close(input);
  close(output);
end.
