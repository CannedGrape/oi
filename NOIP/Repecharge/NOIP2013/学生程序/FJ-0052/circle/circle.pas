program circle;
var
  weiwei,ans,i,u,wei,lp,cishu,n,m,x:longint;
  y,k,lt:int64;

function gcd(x,y:longint):longint;
begin
  if y=0 then exit(x);
  exit(gcd(y,x mod y));
end;


begin

  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  cishu:=n div gcd(n,m);
  u:=cishu;
  //writeln(cishu);
  while u<>0 do
    begin
      u:=u div 10;
      inc(wei);
    end;
  //writeln(wei);
  lt:=1;
  weiwei:=wei;
  while weiwei<>0 do
    begin
      lt:=lt*10;
      dec(weiwei);
    end;
  //writeln(lt);
  lp:=1;
  while k>=wei do
    begin
      k:=k-wei;
      lp:=(lp*lt) mod cishu;
      if lp=0 then
        break;
    end;
  lt:=1;
  weiwei:=k;
  while weiwei<>0 do
    begin
      lt:=lt*10;
      dec(weiwei);
    end;
  lp:=(lp*lt) mod cishu;
  ans:=x;
  for i:=1 to lp do
    ans:=(ans+m) mod n;
  writeln(ans);
  close(input);
  close(output);
end.
