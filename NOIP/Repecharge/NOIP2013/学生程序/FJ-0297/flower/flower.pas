{$R+,S+,Q+}
var f:array[0..100000,1..2] of longint;
    h:array[1..100000] of longint;
    i,j,n,ans:longint;

function max(a,b:longint):longint;
 begin
   if a>b then exit(a)
          else exit(b);
 end;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  fillchar(f,sizeof(f),0);
  f[1,1]:=1;f[1,2]:=1;
  for i:=2 to n do
   for j:=1 to i-1 do
    begin
      f[i,1]:=1;f[i,2]:=1;
      if h[i]>h[j] then f[i,1]:=max(f[i,1],1+f[j,2]);
      if h[i]<h[j] then f[i,2]:=max(f[i,2],1+f[j,1]);
    end;
  ans:=0;
  for i:=1 to n do
   ans:=max(ans,max(f[i,1],f[i,2]));
  write(ans);
  close(input);close(output);
end.

