var
  n,m,k,x:longint;

function calculate( a:longint ):longint;
begin
  if a = 1 then
    calculate:= 10 mod n
  else begin
    calculate:=(calculate(a div 2)*calculate(a-a div 2)) mod n;
  end;
end;

begin

  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);

  readln( n,m,k,x );

  writeln( (x mod n + ((m mod n)*calculate(k)) mod n ) mod n );


  close(input);
  close(output);

end.
