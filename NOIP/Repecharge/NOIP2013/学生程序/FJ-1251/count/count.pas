var n,i,j,x,t:longint;
    xx,ii:ansistring;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  if n=x then write(1)
  else begin
  str(x,xx);t:=0;
  for i:=1 to n do
  begin
    if i<10 then begin if i=x then inc(t);end
    else begin
    str(i,ii);
    for j:=1 to length(ii) do
    if ii[j]=xx then inc(t);
    end;
  end;
  write(t);
  end;
  close(input);
  close(output);
end.
