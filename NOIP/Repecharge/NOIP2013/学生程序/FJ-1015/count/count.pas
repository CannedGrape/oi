program a123;
var ans,i,j,l,n,x:longint;
    a,x1:string;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  ans:=0;
  readln(n,x);
  str(x,x1);
  for i:=1 to n do
  begin
    str(i,a);
    l:=length(a);
    for j:=1 to l do
    begin
      if x1=a[j] then begin
        ans:=ans+1;
      end;
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.