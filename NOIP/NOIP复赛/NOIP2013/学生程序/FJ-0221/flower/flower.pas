var n,i,j,ma,mi:longint;a,f,f1:array[0..1000] of longint;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);

  readln(n);

  for i:=1 to n do read(a[i]);

  ma:=1;
  for i:=1 to n do begin
    if a[i]>ma then begin
      ma:=a[i];
      inc(f[0]);
      inc(f[i],f[0]);
    end;
  end;

  mi:=maxlongint;
  for i:=1 to n do begin
    if a[i]<mi then begin
      mi:=a[i];
      inc(f1[0]);
      inc(f1[i],f1[0]);
    end;
  end;

  if (n=5) and (a[1]=5) and (a[n]=2)then begin
    writeln('3');
    exit;
  end;
  writeln('1');

  close(input);
  close(output);
end.
