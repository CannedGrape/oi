const filename='mod';
var a,b,c,d,i:int64;
begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);
  read(a,b);
  while a>=b do dec(a,b);
  c:=a;
  i:=1;
  if a<b div 3 then begin
    while c<>1 do begin
      d:=(b-c)div a+1;
      inc(i,d);
      inc(c,a*d);
      while c>=b do dec(c,b);
    end;
  end
  else begin
    while c<>1 do begin
      inc(i);
      inc(c,a);
      while c>=b do dec(c,b);
    end;
  end;
  writeln(i);
  close(input);close(output);
end.
