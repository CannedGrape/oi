program ex04;
var l:array[1..10005] of longint;
    a:array[1..10005] of longint;
    c:array[1..10005] of boolean;
    n,m,min,max,i,j,x:longint;
    q:boolean;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
readln(n,m);
for i:=1 to n do l[i]:=1;
max:=1;
for i:=1 to m do
  begin
  read(x);
  fillchar(c,sizeof(c),false);
  fillchar(a,sizeof(a),0);
  min:=maxlongint;
  for j:=1 to x do
      begin
      read(a[j]);
      c[a[j]]:=true;
      if l[a[j]]<min then min:=l[a[j]];
      end;

  q:=true;
  for j:=a[1]+1 to a[x]-1 do
    if (l[j]>=min)and(c[j]=false) then
      begin
      q:=false;
      break;
      end;

  if q=false then
    begin
    inc(max);
    for j:=1 to x do l[a[j]]:=max;
    end;
  if i<>m then readln;
  end;
write(max);
close(input);
close(output);
end.


