program flower;
var
  n,k,i,x,z,a1,a2:longint;
  a:array[0..100000] of longint;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  k:=2;
  for i:=1 to n-2 do
    begin
      z:=i+1;
      a1:=a[i];
      a2:=a[i+1];
      repeat
      if a2>a1 then
      begin
        while (a2<=a[z]) and (z<n) do inc(z);
        if a2>a[z] then
        begin
          a1:=a[z];
          inc(k);
        end;
      end
      else if a2<a1 then
      begin
        while (a2>=a[z]) and (z<n) do inc(z);
        if a2<a[z] then
        begin
          a1:=a[z];
          inc(k);
        end;
      end
      else break;
      until z=n;
      if k>x then x:=k;
    end;
  writeln(x);
  close(input);
  close(output);
end.

