var
  n,i,x,max,a:longint;
begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(n,x);
  i:=0; max:=0; a:=0;
  repeat
    if (i<=n)and(a=0) then begin i:=i+1; a:=i; end;
    if x=a mod 10 then max:=max+1;
    a:=a div 10;
  until (i=n)and(a=0);
  writeln(max);
  readln;
  close(input);
  close(output);
end.