var n,i,s1,s2:longint;
    a:array[0..100000]of longint;
begin
assign(input,'flower.in'); reset(input);
assign(output,'flower.out'); rewrite(output);

  readln(n);
  for i:=1 to n do read(a[i]);
  if n<=2 then writeln(n) else
  if n=3 then
    begin
      if ((a[1]>a[2])and(a[2]<a[3]))or((a[1]<a[2])and(a[2]>a[3]))
        then writeln(3) else writeln(2);
    end
  else
    begin
      s1:=0; s2:=0;
      for i:=1 to n-1 do
        if a[i]<a[i+1] then s1:=s1+1
        else if a[i]>a[i+1] then s2:=s2+1;
      if (s1=0)or(s2=0) then writeln(2) else
      if s1>s2 then writeln(n-s1+s2)
      else if s1<s2 then writeln(n-s2+s1)
           else writeln(n);
    end;

close(input);
close(output);
end.