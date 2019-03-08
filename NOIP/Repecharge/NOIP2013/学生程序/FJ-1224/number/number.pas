var a,b,c:array[1..1000000]of longint;
    n,p,i,j,k,x,max,ans:longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  b[1]:=a[1];c[1]:=b[1];max:=c[1];
  for i:=2 to n do
    begin
      for j:=1 to i do
        begin
          x:=a[j];
          if x>b[i] then b[i]:=x;
          for k:=j+1 to i do
            begin
              x:=x+a[k];
              if x>b[i] then b[i]:=x;
            end
        end;
      c[i]:=b[1]+c[1];
      for j:=2 to i-1 do
        if b[j]+c[j]>c[i] then
          c[i]:=b[j]+c[j];
      if c[i]>max then max:=c[i];
    end;
  ans:=abs(max) mod p;
  if max<0 then writeln('-',ans)
  else writeln(ans);
  close(input);close(output);
end.
