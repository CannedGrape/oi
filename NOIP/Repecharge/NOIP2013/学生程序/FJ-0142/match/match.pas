var
  n,i,j,k,d,jsq:longint;
  a:array[1..2,0..100000]of longint;
begin
  assign(input,'match.in');  reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to 2 do
    for j:=1 to n do
      read(a[i,j]);
  for i:=1 to n do
    k:=(a[1,i]-a[2,i])*(a[1,i]-a[2,i])+k;
  for i:=1 to n do
    for j:=1 to n-1-i+1 do
    begin
      if (k - (a[1,j]-a[2,j])*(a[1,j]-a[2,j]) - (a[1,j+1]-a[2,j+1])*(a[1,j+1]-a[2,j+1]) + (a[1,j]-a[2,j+1])*(a[1,j]-a[2,j+1]) + (a[1,j+1]-a[2,j])*(a[1,j+1]-a[2,j]) < k) and(k>0) then
        begin
          k:=k-(a[1,j]-a[2,j])*(a[1,j]-a[2,j])-(a[1,j+1]-a[2,j+1])*(a[1,j+1]-a[2,j+1])+(a[1,j]-a[2,j+1])*(a[1,j]-a[2,j+1])+(a[1,j+1]-a[2,j])*(a[1,j+1]-a[2,j]);
          d:=a[1,j]; a[1,j]:=a[1,j+1]; a[1,j+1]:=d;
          jsq:=(jsq+1) mod 99999997;
        end;
    end;
  writeln(jsq);
  close(input); close(output);
end.
