program count;
var
  n,x:longint;
function cou(p:longint):longint;
  var
    a,b:longint;
  begin
    cou:=0;
    if p<10 then
    begin if p>=x then cou:=1; end
    else
    begin
      a:=p div 10;
      b:=p-10*x;
      cou:=cou(a-1)*10+((p+x-1)div 10)+1;
      if (b<10) and (b>0) and (x<>10) then cou:=cou+b;
    end;
  end;
begin
  assign(input,'count.in');
  assign(outpu,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  if x=0 then x:=10;
  writeln(cou(n));
  close(input);
  close(output);
end.
