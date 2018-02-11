var max:array[0..100050] of longint;
    min:array[0..100050] of longint;
    h:array[0..100050] of longint;
    n,i,t,s:longint;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
  readln(n);
  h[0]:=123456;t:=0;
  for i:=1 to n do
    begin
      read(h[i]);
      if h[i]>h[i-1] then max[t]:=h[i]
     else begin inc(t);min[t]:=h[i];max[t]:=h[i]; end;
    end;
  {for i:=1 to t do write(max[i],' ');
  writeln;
  for i:=1 to t do write(min[i],' ');}
  s:=0;
  for i:=1 to t do s:=s+max[i];
  for i:=2 to t do s:=s-min[i];
  writeln(s);
close(input);close(output); 
end.


