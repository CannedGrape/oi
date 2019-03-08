var a,b,c:array[1..1000000]of int64;
i,j,max,most,n,p:longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    begin
      max:=-maxlongint;
      for j:=1 to i do
        begin
          b[i]:=b[i]+a[j];
          if b[i]>max then max:=b[i]
          else b[i]:=max;
        end;
    end;
  c[1]:=b[1];
  for i:=2 to n do
    begin
      max:=-maxlongint;
      for j:=1 to i-1 do
        begin
          c[i]:=b[j]+c[j];
          if c[i]>max then max:=c[i]
          else c[i]:=max;
        end;
    end;
  most:=c[1];
  for i:=2 to n do
    if c[i]>most then most:=c[i];
  if most<0 then write('-');
  most:=abs(most)mod p;
  write(most);
  close(input);
  close(output);
end.
