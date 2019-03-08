var f,n,f2,js,x:longint;s,x2:string;
begin
  assign(input,'count.in');
  reset(input);
  readln(n,x);
  close(input);
  assign(output,'count.out');
  rewrite(output);
  js:=0;
  if (0<=x)and(x<=9) then
  begin
    for f:=1 to n do
    begin
      str(f,s);
      for f2:=1 to length(s) do
      begin
        str(x,x2);
        if (s[f2]=x2) then js:=js+1;
      end;
    end;
  end;
  write(js);
  close(output);
end.
