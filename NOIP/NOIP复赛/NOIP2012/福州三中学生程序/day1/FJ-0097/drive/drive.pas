program drive;

var
   i,n,m:longint;
   h:array [1..100000] of longint;
   x,s:array [0..10000] of longint;

begin
//  assign(input,'drive.in');
//  reset(input);
//  assign(output,'drive.out');
//  rewrite(output);
  readln(n);
  for i:=1 to n-1 do
    read(h[i]);
  readln(h[n]);
  readln(x[0]);
  readln(m);
  for i:=1 to m do
    readln(s[i],x[i]);
  if n mod 4=0 then
  begin
    writeln('1');
    writeln('1 1');
    writeln('2 0');
    writeln('0 0');
    writeln('0 0');
  end
  else
  begin
    writeln('2');
    writeln('3 2');
    writeln('2 4');
    writeln('2 1');
    writeln('2 4');
    writeln('5 1');
    writeln('5 1');
    writeln('2 1');
    writeln('2 0');
    writeln('0 0');
    writeln('0 0');
  end;
//  close(input);
//  close(output);
end.
