var a,b,c,d,n,m,i,j,x,y,z:longint;
    ab:array [0..2000000] of longint;
begin
 assign(input,'count.in');
 assign(output,'count.out');
 reset(input);
 rewrite(output);
 read(n,m);
 for i:=1 to n do
  begin
   x:=i div 10;
   y:=i mod 10;
   ab[i]:=ab[x];
   if y=m then inc(ab[i]);
   z:=z+ab[i];
  end;
 writeln(z);
 close(input);
 close(output);
end.
