program number;
var t,i,j,n,p,ans:longint;s,a,b:array[1..1000000]of longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);//读入
  for i:=1 to n do
  read(a[i]);
  b[1]:=a[1];//特征值
  for i:=2 to n do
   b[i]:=b[i-1]+a[i];
  s[1]:=b[1];//分数
  for i:=2 to n do
   s[i]:=s[i-1]+b[i-1];
  for i:=1 to n do//排序
  for j:=1 to n-i do
  if s[j]<s[j+1]then
  begin
   t:=s[j];
   s[j]:=s[j+1];
   s[j+1]:=t;
  end;
  ans:=s[1]mod p;
  writeln(ans);
  close(input);
  close(output);
end.

