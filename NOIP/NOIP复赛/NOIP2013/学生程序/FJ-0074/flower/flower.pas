var a:array[1..1000] of integer;
    i,n,t,time,ans:integer;

//____________________________________
procedure iin;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
end;
procedure oout;
begin
  close(input);
  close(output);
end;
//____________________________________
procedure sear(x:integer);
var i:integer;
begin
  if time+1>ans then ans:=time+1;
  if t=-1 then
   for i:=x+1 to n do
    if a[i]>a[x] then begin inc(time); t:=1; sear(i); time:=time-1; t:=-1; end;
  if t=1 then
   for i:=x+1 to n do
    if a[i]<a[x] then begin inc(time); t:=-1; sear(i); time:=time-1; t:=1; end;
end;
//____________________________________
begin
  iin;
  readln(n);
  for i:=1 to n do read(a[i]);

  ans:=0;
  for i:=1 to n-1 do
   begin
    time:=0; t:=1; sear(i);
    time:=0; t:=-1; sear(i);
   end;
  write(ans);
  oout;
end.
