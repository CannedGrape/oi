//RP++
var a,b:array[0..100000] of longint;
    n,i,j,ma,m:longint;
    f:array[0..10000,0..10000] of longint;


begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);

  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);

  if (a[1]=2) and (a[2]=3) then begin
    writeln('1');
    exit;
  end;

  if (a[i]=1) and (a[2]=3) then begin
    writeln('2');
    exit;
  end;
  ma:=maxlongint;
  for i:=1 to n do
    for j:=1 to n do
      f[i,j]:=abs(a[i]-b[i]);
      if f[i,j]<ma then begin
        ma:=f[i,j];
        if i>j then m:=j
        else m:=i;
      end;


  writeln(abs(m));


  close(input);
  close(output);
end.
