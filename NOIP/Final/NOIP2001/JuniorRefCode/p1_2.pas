const
  maxn = 1000;
var
  n:longint;
  h:array[0..1000] of longint;

  procedure dfs(m:longint);
  var i:integer;
  begin
  	if h[m]<>-1 then exit;
  	h[m]:=1;
    for i:=1 to m div 2 do
    begin
      dfs(i);
      inc(h[m],h[i]);
    end;
  end;
  
  var i:integer;
  begin
  	read(n);
  	for i:=1 to n do h[i]:=-1;
  	dfs(n);
    writeln(h[n]);
  end.
