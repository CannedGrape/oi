var a,b,c,d,f,g:array[0..100000]of int64;
    n,i,j:longint;
    ans:int64;

  procedure kp(l,r:longint);
  var x,y:longint; z,t:int64;
  begin
    x:=l;y:=r; z:=f[(l+r) div 2];
    repeat
      while f[x]<z do inc(x);
      while f[y]>z do dec(y);
      if x<=y then
        begin
          t:=f[x];f[x]:=f[y];f[y]:=t;
          t:=g[x];g[x]:=g[y];g[y]:=t;
          inc(x);dec(y);
        end;
    until x>y;
    if x<r then kp(x,r);
    if l<y then kp(l,y);
  end;

begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      c[i]:=i;
    end;
  readln;
  for i:=1 to n do
    begin
      read(b[i]);
      d[i]:=i;
    end;
  f:=a;g:=c;
  kp(1,n);
  a:=f;c:=g;
  f:=b;g:=d;
  kp(1,n);
  b:=f;d:=g;
  for i:=n downto 1 do
    ans:=(ans+abs(c[i]-d[i])) mod 99999997;
  if ans mod 2=1 then ans:=ans div 2 +1
  else ans:=ans div 2;
  writeln(ans);
  close(input);close(output);
end.
