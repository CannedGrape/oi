const
  maxn = 1000;
var
  n,i,j:longint;
  h:array[0..1000] of longint;  

  begin
  	read(n);
    for i:=1 to n do
    begin
      h[i]:=1;
      for j:=1 to i div 2 do
        inc(h[i],h[j]);
    end;
    writeln(h[n]);
  end.
