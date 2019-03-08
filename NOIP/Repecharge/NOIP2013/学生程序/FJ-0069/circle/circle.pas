var n,m,k,x:int64;
    sum:int64;
function get(x:longint):int64;
var sax:int64;
begin
  if x=1 then exit(10 mod n);
  if odd(x) then
  begin
    sax:=get(x div 2);
    get:=((sax*sax)mod n)*10 mod n;
  end else
  begin
    sax:=get(x div 2);
    get:=sax*sax mod n;
  end;
end;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  readln(n,m,k,x);
  sum:=((get(k)*m mod n)+x)mod n;
  writeln(sum);
  close(input);close(output);
end.