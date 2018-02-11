program flower;
  var n:longint;
      h:array[1..100000] of longint;
      f:array[1..100000,1..2] of longint;
      i,j,t,max1:longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(h[i]);
  f[1,1]:=1;f[1,2]:=1;
  for i:=2 to n do
    begin
      for j:=1 to i-1 do
        begin
          if (h[j]<h[i]) and (f[j,1]+1>f[i,2]) then
            f[i,2]:=f[j,1]+1;
          if (h[j]>h[i]) and (f[j,2]+1>f[i,1]) then
            f[i,1]:=f[j,2]+1;
        end;
      if f[i,1]>max1 then max1:=f[i,1];
      if f[i,2]>max1 then max1:=f[i,2];
    end;
  write(max1);
  close(input);
  close(output);
end.
