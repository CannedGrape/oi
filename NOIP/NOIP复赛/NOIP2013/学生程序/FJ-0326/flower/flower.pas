var n,i:longint;
    a,b:array[0..100001] of longint;

procedure down(l,r:longint);
var i:longint;
begin
  for i:=l to r do
    a[i]:=a[i+1];
  for i:=l to r do
    dec(b[i]);
  dec(n);
end;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=i;
  end;
  for i:=1 to n do
    if b[i]*2+1<=n then
    begin
      if (a[b[i]*2]>a[b[i]*2-1]) and (a[b[i]*2]>a[b[i]*2+1])
      or (a[b[i]*2]<a[b[i]*2-1]) and (a[b[i]*2]<a[b[i]*2+1])
      then continue
      else down(i,n);
    end;
  writeln(n);
  close(input);close(output);
end.
