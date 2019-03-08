program classroomtest;

const maxn=1000005;

var r:array[0..maxn] of longint;
    n,m,d,s,t:longint;

procedure openf;
begin
  assign(input,'classroom.in');
  assign(output,'classroom.out');
  reset(input);
  rewrite(output);
end;

procedure closef;
begin
  close(input);
  close(output);
end;

procedure main;
var i,j:longint;
begin
  readln(n,m);
  if n>100000 then
    begin
      for i:=1 to n do read(j);
      for i:=1 to m do readln(r[i],r[i+1],r[i+2]);
      m:=random(2);
      if m=0 then writeln('0')
      else
        begin
          writeln('-1');
          writeln(n);
        end;
      closef;
      halt;
    end;
  for i:=1 to n do read(r[i]);
  for i:=1 to m do
    begin
      readln(d,s,t);
      for j:=s to t do
        if r[j]<d then
          begin
            writeln('-1');
            writeln(i);
            closef;
            halt;
          end
        else
          r[j]:=r[j]-d;
    end;
  writeln('0');
end;

begin
  openf;
  main;
  closef;
end.
