program modd;

var
  i,a,b:longint;

begin
  assign(input,'mod.in');
  reset(input);
  assign(output,'mod.out');
  rewrite(output);
  readln(a,b);
  for i:=1 to b do
    if b mod i=a then
    begin
      writeln(i);
      halt;
    end;
  close(input);
  close(output);
end.
