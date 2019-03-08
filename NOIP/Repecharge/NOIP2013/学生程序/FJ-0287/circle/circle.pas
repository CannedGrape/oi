var k,m,n,x:dword;
    ten,num:qword;

begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input);
  rewrite(output);
  ten:=10;
  num:=1;
  readln(n,m,k,x);
  repeat
    if k and 1=1 then num:=num*ten mod n;
    ten:=sqr(ten)mod n;
    k:=k>>1;
  until k=0;
  writeln((m*num mod n+x)mod n);
  close(input);
  close(output);
end.