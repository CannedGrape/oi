program circle;
var
  s,i,j,m,k1,n,k,o,d,t,l:longint;
function che(x:longint):longint;
var
  s:string;
begin
  s:='1';
  for i:=1 to x do
    s:=s+'0';
  val(s,che);
end;
function bj(s1,s2:longint):boolean;
var j:longint;
begin
  for j:=1 to s1 do
    if (j*s2)>n then exit(false);
  exit(true);
end;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,s);
  d:=n mod m;
  t:=m-d;
  l:=n div t; //writeln(l);
  if k<6 then
  begin
    k1:=che(k); //writeln(k1);
    if bj(m,k1) then
      begin
       s:=s+m*k1;
       if s>=n then s:=s-n;
      end
    else
    begin
      if k1>=l then
      begin
        //writeln(k1 mod l);
        s:=s+m*(k1 mod l);
        if s>=n then s:=s-n;
      end
      else
      begin
        //writeln(m*l);
        s:=s+m*l;
        if s>=n then s:=s-n;
      end;
    end;
  end
  else
  begin
    k1:=che(6);
    if bj(m,k1) then
      begin
       s:=s+m*k1;
       if s>=n then s:=s-n;
      end
    else
      if k1>=l then
      begin
        s:=s+m*(k1 mod l);
        if s>=n then s:=s-n;
      end
      else
      begin
        s:=s+m*l;
        if s>=n then s:=s-n;
      end;
  end;
  writeln(s);
  close(input); close(output);
end.