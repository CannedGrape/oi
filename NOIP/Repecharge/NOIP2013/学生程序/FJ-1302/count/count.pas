program count1;

var
  a:array[1..10000000] of longint;
  i,j,x,sum,n:longint;

begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
    a[i]:=i;
  i:=1;
  begin
    repeat
      if a[i] mod 10=x then
        begin
          inc(sum);
          a[i]:=a[i] div 10;
        end
        else
          a[i]:=a[i] div 10;
      if a[i]=0 then
        inc(i);
    until i>n;
  end;
  write(sum);
  close(input);
  close(output);
end.
