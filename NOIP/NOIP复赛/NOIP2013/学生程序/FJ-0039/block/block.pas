var a:Array[-100..100100]of longint;
    minnum,ans,min,i,j,n:longint;
procedure work(left,right:longint);
begin
  min:=maxlongint;
  for i:=left to right do
    if min>a[i] then begin min:=a[i]; minnum:=i; end;
  for i:=left to right do
    a[i]:=a[i]-min;
  ans:=ans+min;
  for i:=left to right do
    if a[i]=0 then
      begin
        if left<=i-1 then work(left,i-1);
        if i+1<=right then work(i+1,right);
      end;
end;

begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  ans:=0;
  work(1,n);
  writeln(ans);
  close(input);
  close(output);
end.