var n,i,j,k,p,max:longint;
    a,s,t:array[1..1000000]of longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
    readln(n,p);
    for i:=1 to n do
    begin
      read(a[i]);
      s[i]:=a[i];
    end;
    max:=a[1];s[1]:=a[1];t[1]:=a[1];
    for i:=2 to n do
      if s[i-1]+a[i]>s[i] then s[i]:=(s[i-1]+a[i]) mod p;
    for i:=2 to n do t[i]:=(t[i-1]+s[i-1]) mod p;
    for i:=1 to n do
      if t[i]>max then max:=t[i] mod p;
    writeln(max);
  close(input);close(output);
end.
