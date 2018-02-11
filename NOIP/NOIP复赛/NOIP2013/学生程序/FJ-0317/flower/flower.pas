var n,i,s,m:longint;
    h:array[1..100002]of longint;
begin
 assign(input,'flower.in');reset(input);
 assign(output,'flower.out');rewrite(output);
 readln(n);
 for i:=1 to n do read(h[i]);
 s:=0;
 for i:=2 to n-1 do
 begin
  if (h[i]>h[i-1])and(h[i]>h[i+1]) then inc(s);
  if (h[i]<h[i-1])and(h[i]<h[i+1]) then inc(s);
 end;
 m:=s mod 2;
 if m=0 then s:=s+1;
 if m=1 then s:=s+2;
 writeln(s);
 close(input);close(output);
end.