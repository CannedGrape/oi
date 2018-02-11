program circle;
var i,j,n,m,k,x,rp,p:longint;
    next:array[0..999999]of longint;
function mi(k:longint):longint;
var t:longint;
begin
  if k=1 then begin mi:=10;exit;end;
  if k mod 2=0then
  begin
    t:=mi(k div 2)mod p;
    mi:=t mod p*t mod p;
    exit;
  end;
  if k mod 2=1then
  begin
    t:=mi(k div 2)mod p;
    mi:=t*10mod p*t mod p;
    exit;
  end;
end;
procedure print(x:longint);
begin
  write(x);close(input);close(output);halt;end;
  begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  for i:=0 to n-m-1 do next[i]:=i+m;
  for i:=n-m to n-1 do next[i]:=i-n+m;
  i:=x;
  while true do
  begin
    inc(p);
    i:=next[i];
    if i=x then break;
  end;
  rp:=mi(k)mod p;
  if rp>0then
  begin
    i:=x;
    while true do
    begin
      rp:=rp-1;
      i:=next[i];
      if rp=0then print(i);
    end;
  end else print(x);
close(input);close(output);
end.
