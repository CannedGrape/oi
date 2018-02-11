var i,n:dword;
    ans:qword;
    h:array[0..100000]of dword;

procedure doit(l,r,num:dword);
var i,j:dword;

begin
  if l>=r then
  begin
    if l=r then inc(ans,h[l]-num);
    exit;
  end;
  j:=l;
  for i:=l+1 to r do
    if h[i]<h[j]then j:=i;
  inc(ans,h[j]-num);
  for i:=l to r do
    if h[i]=h[j]then
    begin
      doit(l,i-1,h[i]);
      l:=i+1;
    end;
  doit(l,r,h[j]);
end;

begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  doit(1,n,0);
  writeln(ans);
  close(input);
  close(output);
end.