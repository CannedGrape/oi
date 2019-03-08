var
  n,m,k,x,p,w,t,i:longint;
  s:string;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  readln(n,m,k,x);
  t:=m;
  while k<>0 do
    begin
      s:=chr(t);
      p:=length(s);
      w:=9-p;
      if k>=w then k:=k-w
              else begin
                     w:=k;
                     k:=0;
                   end;
      for i:=1 to w do
        t:=t*10;
      t:=t mod n;
    end;
  x:=(x+t)mod n;
  if x=n then x:=0;
  writeln(x);
  close(input);
  close(output);
end.
