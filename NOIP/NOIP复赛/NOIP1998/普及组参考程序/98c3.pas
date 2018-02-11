var
  n:integer;

procedure bin(k:integer);
var
  b:array[0..15] of integer;
  i,p:integer;
  first:boolean;
begin
  p:=-1;
  if k=0 then
    write(0)
  else begin
    while k>0 do
    begin
      inc(p);
      b[p]:=k mod 2;
      k:=k div 2;
    end;
    first:=true;
    for i:=p downto 0 do
      if b[i]=1 then
      begin
        if first then first:=false else write('+');
        if i=1 then write('2')
        else begin
          write('2(');
          bin(i);
          write(')');
        end;
      end;
  end;
end;

begin
  write('n=');
  readln(n);
  bin(n);
  writeln;
end.
