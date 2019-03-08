program count;
var n,l:longint;x,ans,i,code,j:integer;a,c:array[1..1000000]of longint;
  s,b:string;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);
  a[1]:=1;
  for i:=2 to n do
  a[i]:=a[i-1]+1;
  for i:=1 to n do
  begin
  str(a[i],b);
  s:=s+b;
  end;
  l:=length(s);
  ans:=0;
  for i:=1 to l do
  begin
  val(s[i],c[i],code);
  if c[i]=x then ans:=ans+1;
  end;
  writeln(ans);
  close(input);
  close(output);
end.

