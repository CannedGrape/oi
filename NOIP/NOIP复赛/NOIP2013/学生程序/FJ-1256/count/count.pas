var k:ansistring;
    i,n,len,s,x,j:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n);
  read(x);
  s:=0;
  i:=1;
  repeat
    str(i,k);
    len:=length(k);
    for j:=1 to len do
        if ord(k[j])-48=x then inc(s);
    inc(i);
  until i>n;
  writeln(s);
  close(input);
  close(output);
end.

