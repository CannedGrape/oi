var
  n,m,k,x,i,j,t,tk:longint;
  a:array[0..9]of longint;
begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input); rewrite(output);
  readln(n,m,k,x);t:=0;
  for i:=1 to 10 do t:=(t+m)mod n;   m:=t; a[0]:=t;
  for i:=1 to 9 do
    begin
      t:=1;
      for j:=1 to 10 do t:=(t*a[i-1])mod n;
      a[i]:=t;
    end;
  t:=0;  tk:=-1;
  while k<>0 do
    begin
      tk:=tk+1;
      t:=t+a[tk]*(k mod 10)mod n;
      k:=k div 10;
    end;
  writeln((t+x)mod n);readln(n);
  close(input); close(output);
end.
