program ex3;
  var i,n,p,maxx:longint;
      a,f,fs:array[0..1000000] of longint;
  function max(a,b:longint):longint;
    begin
    if a>b then max:=a
    else max:=b;
    end;
  begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  read(n,p);
  for i:=1 to n do
    begin
    read(a[i]);
    f[i]:=a[i];

    end;
  for i:=1 to n do

    f[i]:=max(f[i],f[i-1]+f[i]);

  fs[1]:=f[1];
  maxx:=fs[1];
  for i:=2 to n do
    begin
    fs[i]:=max(f[i-1]+fs[i-1],f[i-1]);
    if  fs[i]>maxx then maxx:=fs[i];
    end;
  if maxx<0 then write('-');
  maxx:=abs(maxx);
  write(maxx mod p);
  close(input);
  close(output);
  end.
