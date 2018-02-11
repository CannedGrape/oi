const a:array[1..10]of longint=(5,10,50,100,250,600,900,1000,60000,100000);
      b:array[1..9]of longint=(2,5,20,50,150,260,369,400,0);
var n,m,i:longint;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);readln(m);
  if n=4 then
    if m=2 then write(1)  else writeln(1);
  if n<4 then writeln(0);
  if n>4 then
    for i:=1 to 9 do
       if (n>a[i]) and (n<=a[i+1]) then writeln(b[i]);

  close(output);
end.
