const
  maxn = 1000;
var
  n,i:longint;
  h:array[0..maxn] of longint;  
  sum:array[0..maxn] of longint; { sum[k]=h[1]+h[2]+...h[k] }

  begin
  	read(n);
    for i:=1 to n do
    begin
      h[i]:=1 + sum[i div 2];
      sum[i]:=sum[i-1]+h[i];
    end;
    writeln(h[n]);
  end.
