Program block;
Var
  a:array[1..100000] of longint;
  i,j,k,n,ans,tail:longint;
Begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);

  ans:=0;

  readln(n);
  for i:=1 to n do read(a[i]);

  for i:=1 to n do
    while a[i]<>0 do begin
      tail:=i;
      while a[tail+1]<>0 do
        inc(tail);
      for j:=i to tail do
        dec(a[j]);
      inc(ans);
    end;

  writeln(ans);

  close(input);close(output);
End.
