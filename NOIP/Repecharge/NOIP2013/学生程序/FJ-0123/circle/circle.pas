var n,m,k,x,x1:int64;
function merge(p1:int64):int64;
begin
  merge:=p1*p1;
end;
function work(p1:int64):int64;
var p2:int64;
begin
  if p1=0 then work:=1
  else
  begin
  if p1 mod 2=1 then
    work:=(merge(work(p1 div 2))mod n)*10 mod n
  else
    work:=merge(work(p1 div 2))mod n;
  end;
end;
begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input);
  rewrite(output);
  readln(n,m,k,x);
  x1:=work(k);
  x1:=(x1*m)mod n;
  x1:=(x1+x)mod n;
  writeln(x1);
  close(input);
  close(output);
end.



