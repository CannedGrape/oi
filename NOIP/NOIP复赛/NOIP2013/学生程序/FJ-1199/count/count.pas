program count;
var
  n,m,num,i:longint;
function tot(x:longint):longint;
var
  s:ansistring;
  c,i:longint;
begin
  str(x,s);
  c:=0;
  for i:=1 to length(s) do
    begin
      if s[i] = chr(ord(m)+ord('0')) then
        inc(c);
    end;
  exit(c);
end;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,m);

  num:=0;
  for i:=1 to n do
    begin
      num:=num+tot(i);
    end;

  writeln(num);
  close(input);close(output);
end.
