var a,b,x,y:array[1..10000]of longint;n,i:longint;
begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do
   begin
    x[i]:=a[i];
    for j:=1 to n-1 do
     begin
      inc(time);
      s:=x[i];
      x[i]:=x[i+1];
      x[i+1]:=s;
      dis[i]:=abs(x[i]-b[i]);
      if dis[i]:=  then writeln(time);
     end;
   end;
close(input);
close(output);
end.
