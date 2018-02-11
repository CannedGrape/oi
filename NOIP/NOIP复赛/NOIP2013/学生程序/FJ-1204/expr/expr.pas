var
  s,z:ansistring;
  fh:array[1..100000]of char;
  lj:array[1..100000]of ansistring;
  f,f2,da,code,cs,x,x2,x3,x4,h,a,b,t:longint;
  xb:array[1..100000]of longint;
begin
  assign(input,'expr.in');
  reset(input);
  read(s);
  close(input);
  assign(output,'expr.out');
  rewrite(output);
  cs:=1;x:=1;x2:=1;x3:=1;
  for f:=1 to length(s) do
  begin
    if (s[f]='*')or(s[f]='+') then
    begin
      for f2:=cs to f-1 do
      lj[x]:=lj[x]+s[f2];
      inc(x);
      cs:=f+1;
      fh[x2]:=s[f];
      inc(x2);
    end;
  end;
  for f:=1 to x2 do
  begin
    if (fh[f]='*') then
    begin
      val(lj[f-1],a,code);
      val(lj[f+1],b,code);
      h:=a*b;
      xb[x3]:=f-1;
      xb[x3+1]:=f+1;
      x3:=x3+2;
    end;
  end;
  for f:=1 to x do
  begin
    val(lj[f],t,code);
    if (f<>xb[x3]) then h:=h+t;
  end;
  str(h,z);
  if (length(z)>4) then
  begin
    for f:=3 downto 0 do
    begin
    if (z[length(z)-f]<>'0') then
    begin
      write(z[length(z)-f]);
    end;
    end;
  end
  else write(z);
  close(output);
end.
