var
  n,p,i,j,k,sum,sum2,ans:longint;
  a,t,f:array[0..1000400] of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do begin
    sum2:=-maxlongint;
    for j:=1 to i do begin
      sum:=0;
      for k:=j to i do begin
        sum:=sum+a[k];
        if sum2<sum then sum2:=sum;
      end;

    end;
    t[i]:=sum2;
  end;
  f[1]:=t[1]; ans:=f[1];
  for i:=2 to n do begin
    f[i]:=-maxlongint;
    for j:=1 to i-1 do begin
      if f[j]+t[j]>f[i] then f[i]:=f[j]+t[j];
    end;
    if f[i]>ans then ans:=f[i];
  end;
  if ans<0 then write('-');
  writeln(abs(ans) mod p);
  close(input);
  close(output);
end.

