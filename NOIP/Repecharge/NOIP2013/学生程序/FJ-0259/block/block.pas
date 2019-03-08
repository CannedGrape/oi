var
  a:array[1..100000]of longint;
  x,y,z,i,n,r,b:longint;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  b:=0;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    while a[i]<>0 do
    begin
      for r:=i to n do
      begin
        if a[r]>0 then a[r]:=a[r]-1
        else break;
      end;
      b:=b+1
    end
  end;
  write(b);
  readln;readln;
  close(input);
  close(output);
end.
