var n,x,i,len,ans:longint;
    s:ansistring;
    a:array[1..1000000] of string;
    ch:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  s:='';
  for i:=1 to n do
    str(i,a[i]);
  for i:=1 to n do
    s:=s+a[i];
  len:=length(s);
  str(x,ch);
  for i:=1 to len do
    if s[i]=ch then ans:=ans+1;
  writeln(ans);
  close(input);
  close(output);
end.
