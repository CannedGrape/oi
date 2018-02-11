var
  n,m,k,x,point,last,t:int64;
  i:longint;
  xh:array[0..20000000]of longint;

procedure workitnow;
begin
  point:=0;
  last:=-50;
  xh[0]:=m mod n;
  while (xh[0]<>last) and (last<>0) do
   begin
     inc(point);
     xh[point]:=(xh[point-1]*10) mod n;
     last:=xh[point];
   end;
end;

function make:longint;
var
  i,ans:longint;
begin
  ans:=1;
  for i:=1 to k do ans:=ans*10;
  exit(ans);
end;

begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  if k<=7 then begin t:=make;
  writeln((m*t+x)mod n); end else
  begin
  workitnow;
  if xh[point]=0 then
   begin
     if k>=point then writeln(x) else writeln((x+xh[k])mod n);
   end
    else
   begin

     writeln((x+xh[k mod point])mod n);
   end;
   end;
  close(input); close(output);
end.
