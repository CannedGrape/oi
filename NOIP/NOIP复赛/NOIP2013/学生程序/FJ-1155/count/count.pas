var
  n,i,temp:longint;
  num,j,x:longint;
  flag:boolean;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  num:=0;
  for i:=1 to n do
  begin
    temp:=i;
    flag:=true;
    for j:=1 to 7 do
    begin
      if ((temp mod 10)=x) and flag then
        num:=num+1;
      temp:=temp div 10;
      if temp=0 then flag:=false;
    end;
  end;
  writeln(num);
  close(input);
  close(output);
end.

