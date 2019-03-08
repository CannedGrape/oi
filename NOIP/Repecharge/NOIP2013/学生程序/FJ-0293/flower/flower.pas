var
  n,i,ans,j:longint;
  x,d:array[1..200000,1..2]of longint;
  a:array[1..200000]of longint;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
  read(n);
  for i:=1 to n do
    begin
      read(a[i]);
      d[i,1]:=1;d[i,2]:=1;
      x[i,1]:=1;x[i,2]:=1;
    end; d[1,2]:=0;x[1,2]:=0;
  for i:=2 to n do
    for j:=1 to i-1 do
      begin
        if a[i]>a[j] then
          begin
            if d[i,1]<x[j,2]+1 then d[i,1]:=x[j,2]+1;
            if d[i,2]<x[j,1]+1 then d[i,2]:=x[j,1]+1;
          end
          else
          if a[i]<a[j]then
            begin
              if x[i,1]<d[j,2]+1 then x[i,1]:=d[j,2]+1;
              if x[i,2]<d[j,1]+1 then x[i,2]:=d[j,1]+1;
            end;
      end;
  ans:=0;
  for i:=1 to n do
    begin
      if ans<d[i,1]then ans:=d[i,1];
      if ans<d[i,2]then ans:=d[i,2];
      if ans<x[i,1]then ans:=x[i,1];
      if ans<x[i,2]then ans:=x[i,2];
    end;
  writeln(ans);
close(input);close(output);
end.
