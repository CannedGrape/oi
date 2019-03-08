var n,min,i,s:longint;
    h:array[0..100002]of longint;
begin
 assign(input,'block.in');reset(input);
 assign(output,'block.out');rewrite(output);
 readln(n);
 min:=10000;
 for i:=1 to n do
 begin
  read(h[i]);
  if h[i]<min then min:=h[i];
 end;
 for i:=1 to n do h[i]:=h[i]-min;
 s:=min;h[0]:=0;
 for i:=1 to n do
 begin
  if h[i]>h[i-1] then s:=s+h[i]-h[i-1];
 end;
 writeln(s);
 close(input);close(output);
end.