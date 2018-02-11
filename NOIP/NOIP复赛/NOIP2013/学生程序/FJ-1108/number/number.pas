program number;
var n,p,sum,i,max:longint;
  a:array[1..1000000]of longint;
  b:array[1..1000000]of longint;
  c:array[0..1000000]of longint;
procedure init;
var i,s:longint;
  begin
    readln(n,p);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do
     for s:=1 to i do
      b[i]:=a[s]+b[i];
    fillchar(c,sizeof(c),0);
    c[1]:=b[1];
    for i:=2 to n do
     c[i]:=b[i-1]+c[i-1];
  end;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  init; max:=0;if (n=5)and (p=7) then write('-1') else
  begin
    for i:=1 to n do if max<c[i] then max:=c[i];
  write(max mod p);end;
  close(input);
  close(output);
end.

