program number;
var
  n,i,j,max:longint;
  p,t:int64;
  a,f,s:array[0..1000005] of int64;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  f[1]:=a[1];
  for i:=2 to n do
    if f[i-1]>0 then f[i]:=f[i-1]+a[i]
    else begin f[i]:=a[i]; end;
  s[1]:=f[1];
  max:=f[1];
  for i:=2 to n do begin
    if abs(s[i])>=p then
    if s[i]>=0 then s[i]:=s[i] mod p
    else begin
      t:=abs(s[i]);
      s[i]:=t mod p;
      s[i]:=0-s[i];
    end;
    s[i]:=s[i-1]+f[i-1];
    if max<s[i] then max:=s[i];
  end;
  writeln(max);
  close(input);
  close(output);
end.
