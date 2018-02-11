program number(input,output);
var
  b:array[0..10000]of longint;
  a:array[0..10000]of longint;
  n,p,sum,i,j,g,t:longint;
begin
  assign(input,'number.in'); reset(input);
  assign(output.'number.out'); rewrite(output);

  readln(n,p);

  for i:=1 to n do read(a[i]);
  b[1]:=a[1];

  for i:=2 to n do
  begin
    b[i]:=a[i];
    a[i]:=a[i]+a[i-1];
  end;
  for i:=2 to n do
  begin
    b[i]:=b[i-1]+a[i-1];
    sum:=b[i];
  end;
  if sum>0 then writeln(sum mod p)
  else begin
       if sum<p then writeln(sum)
       else  begin
               sum:=0-sum;
               writeln(sum mod p);
       end;

  end;
  close(input);
  close(output);
end.

