var n,i,ans:longint;
    a,b:array[1.. 100000]of int64;
procedure swap(var a,b:int64);
var t:int64;
begin
  t:=a;a:=b;b:=t;
end;
begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n-1 do
    begin
      if sqr(a[i+1]-b[i])+sqr(a[i]-b[i+1])<sqr(a[i]-b[i])+sqr(a[i+1]-b[i+1])then
        begin
        swap(a[i],a[i+1]);
        inc(ans);
        end;
    end;
  writeln(ans mod 99999997);
  close(input);
  close(output);
end.
