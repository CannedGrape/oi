program a4(input,output);
var
  n,i,j:integer;
  a:array[1..100] of 0..9;
procedure ppp(k:integer);
  var
    i,j,w,s:integer;
  begin
    a[1]:=1;
    w:=0;
    for i:=1 to k do
      for j:=1 to 100 do
        begin
          s:=a[j]*2+w;
          a[j]:=s mod 10;
          w:=s div 10;
        end;
  end;
begin
  assign(input,'hanoi.in');
  assign(output,'hanoi.out');
  reset(input);
  rewrite(output);
  readln(n);
  ppp(n+1);
  if a[1]>=2 then
    a[1]:=a[1]-2
  else
    begin
      a[1]:=a[1]+8;
      a[2]:=a[2]-1;
    end;
  i:=100;
  while a[i]=0 do i:=i-1;
  for j:=i downto 1 do write(a[j]);
  writeln;
  close(input);
  close(output);
end.