program count;
  var c,n,i,x:longint;
function appear(num,find:longint):longint;
  var cc:longint;
begin
  cc:=0;
  while num>0 do
    begin
      if num mod 10=find then inc(cc);
      num:=num div 10;
    end;
  appear:=cc;
end;

begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  c:=0;
  for i:=1 to n do
    c:=c+appear(i,x);
  writeln(c);
  close(input);
  close(output);
end.