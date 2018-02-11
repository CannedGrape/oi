program flower;
var i,n,m:longint;
h:array[1..100000]of longint;
function dy(a,b:longint):boolean;
begin
  if h[a]>h[b] then dy:=true else dy:=false;
end;
procedure try1(a:longint);
program flower;
var i,n,m:longint;
h:array[1..100000]of longint;
function dy(a,b:longint):boolean;
begin
  if h[a]>h[b] then dy:=true else dy:=false;
end;
procedure try1(a:longint);
var i,j:integer;
begin
  if a>n then exit else
  begin
   i:=1;j:=1;
   if dy(a,a+i)and(dy(a+i+j,a+i)) then
   begin
    inc(a,2);
    try1(a);
   end else
   if dy(a+i,a) then
   begin
    inc(a);inc(m);inc(i);inc(j);
    try1(a+1);
   end
   else
   if dy(a+i,a+i+j) then
   begin
    inc(a);
    inc(m);inc(j);
    try1(a);
   end;
  end;
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  try1(1);
  writeln(m);
  close(input);close(output);
end.