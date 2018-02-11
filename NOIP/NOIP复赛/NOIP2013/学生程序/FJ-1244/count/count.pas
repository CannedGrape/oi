program hhlfiw;
var  a:array[1..1000000]of longint;
    i,n,j,num,h:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(n);
  read(j);
  for i:=1 to n do
  begin
    a[i]:=i;
    h:=a[i];
    while a[i]>=10 do
    begin
      h:=a[i] mod 10;
      if h=j then inc(num);
      a[i]:=a[i] div 10;
    end;
    if a[i]=j then inc(num);
  end;
    write(num);
    close(input);
    close(output);
end.
