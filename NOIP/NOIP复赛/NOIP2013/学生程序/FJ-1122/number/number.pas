var
  ans,l,k:int64;
  r,x,i,n,p:longint;
begin
assign(input,'number.in');
assign(output,'number.out');
reset(input);
rewrite(output);
  readln(n,p);
  read(r);
  l:=r;
  k:=r;
  ans:=l;
  for i:=2 to n do
    begin
     if l<l+k then l:=l+k;
     if l>ans then ans:=l;
      read(r);
      if k+r>r then k:=r+k else k:=r;
    end;
  writeln(ans mod p);
close(input);
close(output);
end.
