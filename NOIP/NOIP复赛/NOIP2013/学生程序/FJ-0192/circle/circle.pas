const Ln=1000000+20;
var c:array[0..Ln]of longint;
    n,m,k,x:longint;
    i:longint;
//
Function calc(x:longint):int64;
  begin
    if x=0 then exit(1);
    if x=1 then exit(10);
    calc:=sqr(calc(x div 2)) mod (i*2);
    if x and 1=1 then calc:=(calc*10) mod (i*2);
  end;
//
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  //
  readln(n,m,k,x);
  c[0]:=x; i:=0;
  repeat
    inc(i);
    c[i]:=(c[i-1]+m)mod n;
  until c[i]=x;
  writeln(c[calc(k)mod i]);
  //
  close(input);close(output);
end.
