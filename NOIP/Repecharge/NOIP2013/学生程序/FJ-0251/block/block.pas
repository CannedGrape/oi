program block;
 var
  a,g,h:array[1..10000]of longint;
  n,i,t,max,ss,o1,p,tt:longint;
procedure find(t:longint);
  var m:longint;
begin
  m:=t;
  g[ss]:=a[m];
  repeat
    inc(m);
    max:=a[m];
    t:=m;
  until a[m]>=a[m+1];
   h[ss]:=max;
   inc(ss);
  find(t+1);
end;

begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  i:=1;ss:=1;a[n+1]:=0;
  find(1);
  for i:=1 to ss do
    if g[i]<o1 then
       o1:=g[i];
  for i:=1 to ss do
    h[i]:=h[i]-o1;
  for i:=1 to ss do
    p:=p+h[i];
  p:=p+o1;
  write(p);
  close(input);
  close(output);
end.



