var
  n,p,i,j,k:longint;
  aa,ans:int64;
  a,b,f:array[1..1000000]of int64;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(a[i]);
  f[1]:=a[1];
  for i:=2 to n do
  begin
    for j:=1 to i do
    begin
      aa:=0;
      for k:=j to i do
      begin
        inc(aa,a[k]);
        if(aa>f[i])then f[i]:=aa;
      end;
    end;
  end;
  b[1]:=f[1];
  for i:=2 to n do
  begin
    ans:=-maxlongint;
    for j:=1 to i-1 do
      if(ans<b[j]+f[j])then ans:=b[j]+f[j];
    b[i]:=ans;
  end;
  ans:=-maxlongint;
  for i:=1 to n do
    if(ans<b[i])then ans:=b[i];
  ans:=ans mod p;
  writeln(ans);
  close(input);
  close(output);
end.