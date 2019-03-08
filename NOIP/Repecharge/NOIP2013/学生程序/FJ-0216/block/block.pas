var
  a:array[0..100000]of longint;
  n,i,j,k,min:longint;
  ans:int64;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  i:=2;
  min:=a[1];
  ans:=a[1];
  a[0]:=0;
  while i<=n do begin
    if a[i]>a[i-1] then ans:=ans+a[i]-a[i-1]
    else if a[i]<min then min:=a[i];
    inc(i);
  end;
  writeln(ans);
  close(input);
  close(output);
end.

