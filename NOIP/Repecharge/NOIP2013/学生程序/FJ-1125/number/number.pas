var
  n,p,i,j,k,m,k1,k2:longint;
  a,te,f:array[0..1000000]of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    begin
      read(a[i]);
      if i=1 then begin te[1]:=a[i];f[1]:=te[1];continue;end;
      k:=0;k2:=0;k1:=-maxlongint;
      for j:=1 to i do
        begin
          if a[j]<0 then begin if k>m then begin m:=k;k:=0;end;if a[j]>k1 then k1:=a[j];end;
          if a[j]=0 then k1:=0;
          if a[j]>0 then begin k:=k+a[j];k2:=1;end;
        end;
      if k>m then m:=k;
      if k2=1 then te[i]:=m else te[i]:=k1;
      f[i]:=f[i-1]+te[i-1];
    end;
  m:=-maxlongint;
  for i:=1 to n do
    if f[i]>m then m:=f[i];
  writeln(m mod p);
  close(input);
  close(output);
end.