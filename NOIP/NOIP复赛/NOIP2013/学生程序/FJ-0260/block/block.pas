function lzx(n:integer):integer;
  var
  n,i,m,s:integer;
  h:array[1..1000] of integer;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  readln(n);
  begin
  s:=0;
  for i:=1 to n do
   readln(h[i]);
   begin
   for m:=1 to n do
   if h[2i]>h[2i-1] and h[2i]>h[2i+1] then
   s:=s+1;
   end;
  end;
  close(input);
  rewrite(output);
  begin
  writeln(lzx(n));
  close(output);
  end;
end.
