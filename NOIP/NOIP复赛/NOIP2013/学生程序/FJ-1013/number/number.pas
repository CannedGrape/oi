program number;
var
  n,p,r,a,b,i,max:longint;
  q:array[0..2000] of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  b:=0;
  max:=0;
  for i:=1 to n do
  begin
    read(a);
    if a<0 then q[i]:=max+a
    else
    begin
      max:=max+a;
      q[i]:=max;
    end;
  end;
  max:=q[1];
  for i:=2 to n do
    if max+q[i-1]>max then max:=max+q[i-1];
  writeln(max mod p);
  close(input);
  close(output);
end.
