program block;
var
 k,n,max,i,j,t:longint;
 h:array[1..100000] of longint;
 f:array[0..1000,0..1000] of boolean;
 begin
 assign(input,'block.in');reset(input);
 assign(output,'block.out');rewrite(output);
 max:=-maxlongint;
 fillchar(f,sizeof(f),false);
 readln(n);
 for i:=1 to n do
 begin
 read(h[i]); if max<h[i] then max:=h[i];
 for j:=1 to h[i] do
 f[i,j]:=true;
 end;
 for j:=1 to max do
 begin
 for i:=1 to n do
 if (f[i,j]=false) and (f[i-1,j]=true)then
 begin for k:=i to n do if f[k,j]=true then inc(t); end;
 inc(t);
 end;
 writeln(t);
 close(input);close(output);
 end.
