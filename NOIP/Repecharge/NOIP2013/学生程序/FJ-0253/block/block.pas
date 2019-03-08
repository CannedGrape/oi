program block;
var
  n,i,j,z:longint;
  a:array[0..100000] of longint;
procedure zhao(x,y:longint);
begin
  if x>y then exit;
  for z:=x to y do
  begin
    dec(a[z]);
    if a[z]<0 then break;
  end;
  if z>x then
  begin
    inc(j);
    if (z=y) then
      if a[z]>0 then zhao(x,y)
      else zhao(x,y-1)
    else if (z<y) then
    begin
      zhao(z+1,y);
      zhao(x,z-1);
    end;
  end
  else if z=x then
    if a[z]>=0 then
    begin
      inc(j);
      zhao(x,z);
    end
    else zhao(z+1,y);
end;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  zhao(1,n);
  writeln(j);
  close(input);
  close(output);
end.



