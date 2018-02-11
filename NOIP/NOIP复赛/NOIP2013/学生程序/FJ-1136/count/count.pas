program count;
var
  i,j,k,t,n,x:longint;
  a:array[0..9] of longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
   begin
     t:=i;
     while t>0 do
      begin
        k:=t mod 10;
        if k=x then a[k]:=a[k]+1;
        t:=t div 10;
      end;
   end;
  writeln(a[x]);
  close(input);
  close(output);
end.