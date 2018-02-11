program circle;
var i,j,n,m,k,z,y,x:longint;
    t,l,r:int64;
    a:array[0.. 100]of longint;
    f:array[0.. 50]of int64;
    function gcd(a,b:longint):int64;
    begin
      if b=0 then exit(a);
      exit(gcd(b,a mod b));
    end;
    function lcm(a,b:longint):int64;
    var t,x,y,z:int64;
    begin
      t:=gcd(a,b);
      x:=a div t;
      y:=b div t;
      z:=x*y*t;
      exit(z);
    end;
    procedure zh(n:longint);
    var i,j,t:longint;
    begin
      i:=0;
      while n>0 do
      begin
        inc(i);
        a[i]:=n mod 2;
        n:=n div 2;
      end;
      z:=i;
    end;
    function qmi(a,b,m:int64):int64;
    var i,j:longint;
        t:int64;
    begin
      t:=1;
      for i:=1 to z do
      begin
        t:=t*a;
        f[i]:=t;
        if t>m then break;
      end;
      f[i]:=f[i] mod m;
      j:=i;
      for i:=j+1 to z do
      begin
        f[i]:=f[i-1]*f[i-1];
        f[i]:=f[i] mod m;
      end;
    end;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  readln(n,m,k,x);
  t:=lcm(n,m);
  zh(k);
  y:=qmi(10,k,t);
  l:=0;
  for i:=1 to z do if a[i]=1 then l:=(l+f[i])mod t;
  l:=(l+x)mod n;
  writeln(l);
  close(input);
  close(output);
end.
