program flower;
var
 k,n,i,t,j:longint;
 h,g:array[0..100000] of longint;
 f:array[0..100000] of boolean;
 q:boolean;
begin
 assign(input,'flower.in');reset(input);
 assign(output,'flower.out');rewrite(output);
 readln(n);
 for i:=1 to n do
 read(h[i]);
 q:=false;
 fillchar(f,sizeof(f),false);
 repeat
 for i:=1 to n do
 if ((h[i]>h[i-1]) and (h[i]>h[i+1])) or ((h[i]<h[i-1]) and (h[i]<h[i+1]))
 then f[i]:=true;
 for i:=1 to n do
 if f[i]=false then inc(t);
 for i:=1 to n do
 if f[i]=true then q:=true;
 until q;
 writeln(n-t);
 close(input);close(output);
 end.
