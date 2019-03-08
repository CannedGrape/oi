var n,m,b,c,int:longint;
    a:array[1..1000] of record
      z:longint;
      zd:array[1..100] of longint;
    end;
    tl:array[1..1000] of longint;
    bl:boolean;
function doing(aa,z:longint):boolean;
var i:longint;
begin
  for i:=2 to z do
    if a[aa].zd[i]-a[aa].zd[i-1]<>1 then begin
      doing:=false;
      exit;
    end;
  doing:=true;
end;
procedure doing2;
begin
  close(input);
  close(output);
end;
procedure doing3;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
end;
begin
  doing3;
  readln(n,m);
  for b:=1 to m do
  begin
    read(a[b].z);
    for c:=1 to a[b].z do
      read(a[b].zd[c]);
    readln;
  end;
  bl:=true;
  fillchar(tl,sizeof(tl),0);
  for b:=1 to m do
    if doing(b,a[b].z)=false then bl:=false;
  if bl=true then begin
    writeln(1);
    doing2;
    halt;
  end;
  writeln(m);
  doing2;
end.
