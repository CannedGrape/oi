var
  a,b:array[1..100000]of longint;
  t,i,m,n,s:longint;
procedure yd(i,m,t:longint);
var
  j:longint;
begin
  if i<>n+1 then
  for j:=1 to 2 do
  begin
    if j=1 then yd(i+1,m-1,t);
    if j=2 then
    begin
      inc(t);
      b[t]:=a[i];
      if t>1 then
      begin
      if t mod 2=0 then
        if b[t]>b[t-1] then yd(i+1,m,t)
        else  begin
        yd(i+1,m-1,t-1);
        end
      else
        if (b[t]<b[t-1]) then yd(i+1,m,t)
        else  begin
        yd(i+1,m-1,t-1);
        end;
        end else yd(i+1,m,t);
      dec(t);
    end;
  end
  else if m>s then s:=m;
end;
procedure ydx(i,m,t:longint);
var
  j:longint;
begin
  if i<>n+1 then
  for j:=1 to 2 do
  begin
    if j=1 then ydx(i+1,m-1,t);
    if j=2 then
    begin
      inc(t);
      b[t]:=a[i];
      if t>1 then begin
      if t mod 2=0 then
        if b[t]<b[t-1] then ydx(i+1,m,t)
        else  begin
        ydx(i+1,m-1,t-1);
        end
      else
        if (b[t]>b[t-1]) then ydx(i+1,m,t)
        else  begin
        ydx(i+1,m-1,t-1);
        end;
        end else ydx(i+1,m,t);
          dec(t);

    end;
  end
  else if m>s then s:=m;
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  read(a[i]);
  m:=n;
  yd(1,m,0);
  t:=m;m:=n;
  ydx(1,m,0);
  writeln(s);
  close(input);close(output);
end.
