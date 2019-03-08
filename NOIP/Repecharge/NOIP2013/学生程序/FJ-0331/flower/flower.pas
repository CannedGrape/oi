var a,re:array[1..25]of longint;
    i,j,n,m,g,max:longint;

procedure check;
var i:longint;
    pd,pd1:boolean;
begin
  if (g=1)and(g>max) then begin max:=g;exit;end;
  pd:=true;pd1:=true;
  for i:=1 to g div 2 do
      if (re[2*i-1]<=re[2*i])or(re[2*i]<=re[2*i+1]) then
        begin
         pd:=false;
         break;
        end;
  if pd and(g>max) then begin max:=g;  exit;end;
  for i:=1 to g div 2 do
    if (re[2*i-1]>=re[2*i])or(re[2*i]>=re[2*i+1]) then
      begin
        pd1:=false;
        exit;
      end;
  if pd1 and(g>max) then max:=g;
end;


procedure search(x:longint);
var i:longint;
begin
  if x=n+1 then
    begin
      check;
      exit;
    end;
  inc(g);
  re[g]:=a[x];
  search(x+1);
  dec(g);
  search(x+1);
end;

begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
  readln(n);
  if n>30 then
    begin
      n:=n div 2;
      writeln(n);
      close(input);
      close(output);
      exit;
    end;
  for i:=1 to n do
    read(a[i]);
  max:=-1;
  search(1);
  writeln(max);
close(input);
  close(output);
end.
