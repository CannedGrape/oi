program number;
  var a:array[1..1000000]of int64;
      max:array[1..1000000]of int64;
      tez:array[1..1000000]of int64;
      point:array[1..1000000]of int64;
      ans:int64;
      n,i,p:longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(a[i]);
  max[1]:=a[1];
  for i:=2 to n do
    if max[i-1]>=0 then max[i]:=max[i-1]+a[i] else max[i]:=a[i];
  tez[1]:=max[1];
  for i:=2 to n do
    if max[i]>tez[i-1] then tez[i]:=max[i] else tez[i]:=tez[i-1];
  ans:=-maxlongint;
  point[1]:=tez[1];ans:=point[1]+tez[1];
  for i:=2 to n do
    begin
      point[i]:=ans;
      if point[i]+tez[i]>ans then ans:=point[i]+tez[i];
    end;
  ans:=-maxlongint;
  for i:=1 to n do
    if point[i]>ans then ans:=point[i];
  writeln(ans mod p);
  close(input);
  close(output);
end.
