uses math;
var n,m,k,i,j,l,z,x,c,o:longint;
    s:array[1..10000,1..10000] of longint;
    op,ed:array[1..30000] of longint;
 begin
assign(input,'truck.in');reset(input);
 assign(output,'truck.out');rewrite(output);
 read(n,m);
 for i:=1 to n do for j:=1 to n do s[i,j]:=-1;

 for i:=1 to m do begin read(z,x,c); s[z,x]:=c;s[x,z]:=c;end;
 for o:=1 to 1000 do
 for i:=n downto 1 do
   for j:=1  to n do
    for l:=n downto 1 do
    s[i,j]:=max(s[i,j],min(s[i,l],s[l,j]));
 read(k);
 for i:=1 to k do read(op[i],ed[i]);
 for i:=1 to k do writeln(s[op[i],ed[i]]);
close(input);
close(output);
 end.
