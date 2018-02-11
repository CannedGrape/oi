var
  n,i,s:longInt;
  x:integer;

function cs(aa:longInt):integer;
  var
    ii,ss:longInt;
begin
  ss:=0;
  while aa>0 do
  begin
    ii:=aa mod 10;
    if ii=x then ss:=ss+1;
    aa:=aa div 10;
  end;
  cs:=ss;
end;

begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(n,x);
  s:=0;
  for i:=1 to n do
    s:=s+cs(i);
  write(s);
  close(input);
  close(output);
end.


