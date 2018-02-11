var
  i,j,s,n,m,p,max:longint;
  a:Array[0..1001,0..1001] of longint;
  b:Array[0..1001,0..1001] of boolean;
  x:Array[0..1001] of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(b,sizeof(b),false);
  for i:=1 to m do 
  begin
    read(s);
    for j:=1 to s do begin read(a[i,j]);inc(x[a[i,j]]);end;
  end;
  for i:=1 to n do if x[i]>max then max:=x[i];
  write(max);
  close(input);
  close(output);
end.