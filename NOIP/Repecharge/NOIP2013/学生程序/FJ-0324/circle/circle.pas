var n,m,i:longint;x,h,k,t:int64;
    input,output:text;
procedure jisuan(f,t:longint);
var w,i,k:longint;
begin
  k:=m*n;
  while f<k do
  begin
    if t=0 then begin h:=f; exit; end;
    f:=f*10;
    dec(t);
  end;
  w:=f mod k;
  if w<>0 then jisuan(w,t) else exit;
end;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(input,n,m,k,x);
  t:=k;h:=0;
  jisuan(1,t);
  x:=(x+m*h) mod n;
  writeln(output,x);
  close(input);close(output);
end.
