program block(input,output);
var
h:array[1..100000] of longint;
n,i,l,r,t,j,k,maxs:longint;
p:boolean;

function pd(b:array of longint):boolean;
var
i:integer;
begin
  p:=false;
  for i:=1 to n do
    if b[i]>0 then p:=true;
  if p then pd:=false;
end;

procedure tryy(a,b:longint);
var
i,j,s:longint;
begin
  s:=0;
  i:=a;
  while (h[i]>0) and (i<=b) do
    begin
      inc(s);
      inc(i);
    end;
  if s>maxs then begin l:=a; r:=i-1; maxs:=s; end;
  if i<b then tryy(i+1,b);
end;

begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(h[i]);
  while not pd(h) do
  begin
  tryy(1,n);
  for k:=l to r do
      dec(h[k]);
  t:=t+1;
  maxs:=0;
  end;
  writeln(t);
  close(input);
  close(output);
end.
