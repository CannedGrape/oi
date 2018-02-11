program block;
var n,i,j,l,num:longint;
    min,max,temp:longint;
    h:array[1..100001] of integer;
    f:integer;
    a:boolean;

procedure date;
begin
a:=true;
if (i=n-1) and (f=2) then begin l:=n;max:=h[l];end;
if l<=n-1 then
begin
 for i:=l to n-1 do
 if a=true then
 begin
  if (h[i]<=h[i+1]) and ((f=2) or (f=0)) then begin max:=h[i+1]; end;
  if h[i]>=h[i+1] then if f<>0 then begin min:=h[i+1];f:=1; end else  begin  max:=h[i];min:=h[i+1];f:=1;end;
  if (h[i]<h[i+1]) and (f=1) then begin l:=i+1;f:=2;num:=num+max-temp; a:=false;end;
 end;
 if min<temp then temp:=0 else temp:=min-temp;
 date;
end
else if l=n then num:=num+max-temp;

end;

begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
f:=0;
min:=0;
max:=0;
readln(n);
for i:=1 to n do
 begin
  read(h[i]);
 end;
readln;
l:=1;
date;




{for i: 1 to p do
date(1,w0[i]-1);

while h[i]<>0 do
begin
f:3��//״̬�
if h[i]<h[i+1] then begin max:=h[i+1];f:=2; end;
for i:=1 to n do
 begin
  if h[i]<h[i+1] then begin max:=h[i+1];f:=2; end;
  if h[i]>=h[i+1] then begin max:=h[i];min:=h[i+1];f:=1; end;
  if (h[i]<h[i+1]) and (f:=1) then begin l:=i+1;f:=2;num:=max; end;}





writeln(num);

close(input);
close(output);
end.
