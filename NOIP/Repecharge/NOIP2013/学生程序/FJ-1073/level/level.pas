program level;
var n,m,i,j:word;
    a:array[1..1000,1..1001] of word;
begin
 assign(input,'level.in');
 assign(output,'level.out');
 reset(input);
 rewrite(output);
 read(n,m);
 for i:=1 to n do
  begin
   for j:=1 to 1001 do
    read(a[i][j]);
   readln;
  end;
 write(n);
 close(input);
 close(output);
end.