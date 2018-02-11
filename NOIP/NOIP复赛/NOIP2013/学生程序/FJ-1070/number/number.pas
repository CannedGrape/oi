  var
    n,p,i,m,max:longint;
    a,f:array[1..1000000] of longint;
    b:boolean;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(a[i]);
  max:=a[1];
  f[1]:=a[1];
  for i:=2 to n do
    begin
      if f[i-1]<0 then
        f[i]:=a[i]
      else f[i]:=a[i]+f[i-1];
      if f[i-1]>0 then
        begin
          if ((max<0) and (abs(max)>f[i-1])) then
            b:=true;
          if ((max>0) and (f[i-1]>0)) then
            max:=((max mod p)+(f[i-1] mod p)) mod p
          else max:=max+f[i-1];
          if b then
            max:=0-max;
        end;
    end;
  writeln(max);
  close(input);
  close(output);
end.