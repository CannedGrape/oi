program count;
var i,j ,n,x,k,m,b,c,a,d,e,f:longint;
    s:string;
    o:longint;

procedure flink;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
end;

begin
  flink;
  for i:=1 to n do
    if i=x then inc(k);
  for i:=1 to n do
  begin
    d:=i div 10000;
    e:=i div 100000;
    f:=i div 1000000;
    b:=i div 100;
    c:=i div 1000;
    o:=i mod 10;
    a:=i div 10;
    if (a=x) or (o=x) or (b=x) or (c=x) or (d=x) or (f=x) or (e=x) then inc(k);
  end;

  if n>=100 then
  writeln(k+1)
  else
  writeln(k);
  close(input);
  close(output);
end.









