program flower;
  var
    a:array[1..100]of longint;
    f:array[1..100,1..100,1..100]of longint;
    n,m,i,j,k,l,ans:longint;


begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    f[1,i,1]:=1;
  for i:=1 to m-1 do
    for j:=1 to n do
      for k:=1 to a[j] do
        begin
          if k+1<=a[j]
            then f[i+1,j,k+1]:=(f[i,j,k]+f[i+1,j,k+1]) mod 1000007;
          for l:=j+1 to n do
            f[i+1,l,1]:=(f[i,j,k]+f[i+1,l,1]) mod 1000007;
        end;
  for i:=1 to n do
    for j:=1 to a[i] do
      ans:=(ans+f[m,i,j]) mod 1000007;
  writeln(ans);
  close(input);
  close(output);
end.
