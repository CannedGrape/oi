var x:string;i,t,j,t1,t2,t3:longint;a,left,right:qword;
    cz:array[1..10000]of longint;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(x);t:=1;t3:=1;
  for i:=1 to length(x)do
  begin
    t2:=1;left:=0;
    if x[i]='*'then
    begin
    t1:=i-1;
    while x[t1]<>('+')do
    begin
    left:=left*10;
    val(x[t1],t2);
    x[t1]:='!';
    left:=left+t2;
    t1:=t1-1;
    end;
    t:=t1+1;
    t1:=i+1;
    while x[t1]<>('+')do
    begin
    right:=right*10;
    val(x[t1],t2);
    x[t1]:='!';
    right:=right+t2;
    t1:=t1+1;
    end;
    left:=left*right;
    delete(x,t,t1-2);
    cz[t3]:=left;
    t3:=t3+1;
    end;
  end;
  t:=0;right:=0;
  left:=0;
  i:=length(x);
  while i<>0do
  begin
  if x[i]<>'+'then
  begin
  if x[i]<>'!'then
  begin
    right:=right*10;
    t:=t+1;val(x[i],t2);
    right:=right+t2;
    i:=i-1;
  end;
  end
  else
  begin
    left:=left+right;
    right:=0;
    i:=i-1;
  end;
  end;
  left:=left+right;
  for i:=1 to t3 do
  left:=left+cz[i];
  writeln(left);
  close(input);close(output);
end.
