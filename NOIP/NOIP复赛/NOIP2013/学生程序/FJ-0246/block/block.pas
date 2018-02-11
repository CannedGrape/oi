program block;
var
  n,i,j,maxh,pos,k:longint;
  h,now:array[1..10000000]of longint;
begin
 assign(input,'block.in');
 reset(iuput);
 assign(output,'block.out');
 rewrite(output);
 readln(n);
 for i:=1 to n do
  read(h[i]);
 for i:=1 to n do
  now[i]:=0;
 maxh:=0;
 for i:=1 to n do
  if h[i]>maxh then
   begin
     maxh:=h[i];
     pos:=i;
   end;
  k:=0;
 repeat
   j:=0;
   while now[j]=h[j] do
    inc(j);
   while now[j]<h[j] do
    begin
      inc(now[j]);
      inc(j);
    end;
    inc(k);
 until (now[n]=h[n])and(now[pos]=maxh);
 writeln(k);
 close(input);
 close(output);
end.

