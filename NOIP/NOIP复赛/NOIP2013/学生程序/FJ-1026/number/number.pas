program number;
uses math;
var a,b,c,d:array[0..1000000]of int64; n,p,i:longint; ans,m:int64;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p); m:=-1000000000000;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do b[i]:=a[i]+max(b[i-1],0);
  for i:=1 to n do begin m:=Max(m,b[i]); c[i]:=m; end;
  d[1]:=c[1]; m:=c[1]+d[1];
  for i:=2 to n do begin d[i]:=m; m:=Max(m,c[i]+d[i]); end;
  m:=-1000000000000;
  for i:=1 to n do if m<d[i] then m:=d[i];
  if m>0 then m:=m mod p else m:=-(abs(m) mod p);
  writeln(m);
  close(input); close(output);
end.
