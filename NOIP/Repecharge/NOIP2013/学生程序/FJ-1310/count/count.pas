program count;
type
  shuzu1=array[1..1000000] of integer;
var
  shuzu:shuzu1;
  x:integer;
  n,i,j,k,sum:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(n,x);
  sum:=0;
  for i:=1 to n do
    shuzu[i]:=i;
  for i:=1 to n do
    begin
      if shuzu[i] mod 10=x then
        begin
          inc(sum);
          shuzu[i]:=shuzu[i]-x
        end else
      if shuzu[i] div 10=x then
        begin
          inc(sum);
          shuzu[i]:=0;
          shuzu[i]:=shuzu[i] div 10
        end
    end;
  write(sum);
  close(input);
  close(output)
end.
