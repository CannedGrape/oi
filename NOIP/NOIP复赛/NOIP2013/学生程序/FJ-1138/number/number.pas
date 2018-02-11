var
  n,p,i,max:longint;
  f,t,a:array[0..1000001]of longint;
function tz(x:longint):longint;
  var
    j,v,m,k:longint;
  begin
    tz:=-maxlongint;
    for v:=1 to x do
      begin
        for j:=1 to x-v+1 do
          begin
          m:=0;
          for k:=j to j+v-1 do
            m:=m+a[k];
          if m>tz then tz:=m;
          end;
      end;
  end;
function fs(x:longint):longint;
  var
    v,m:longint;
  begin
    fs:=-maxlongint;
    for v:=1 to x-1 do
      begin
        m:=f[v]+t[v];
        if m>fs  then fs:=m;
      end;
  end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(a[i]);
  t[1]:=a[1];
  f[1]:=a[1];
  for i:=2 to n do
    begin
      t[i]:=tz(i);
      f[i]:=fs(i);
    end;
  max:=-maxlongint;
  for i:=1 to n do
    if f[i]>max then max:=f[i];
  max:=max mod p;
  write(max);
  close(input);
  close(output);
end.
