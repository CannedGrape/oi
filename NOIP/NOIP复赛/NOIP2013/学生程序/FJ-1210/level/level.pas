var a,b,c:array[0..1000]of longint;
    s:array[0..1000]of boolean;
    i,j,n,m,num,max:longint;bo:boolean;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
    readln(n,m);num:=1;
    for i:=1 to n do c[i]:=1;
    for i:=1 to m do
    begin
      fillchar(s,sizeof(s),true);
      read(a[i]);bo:=true;
      for j:=1 to a[i] do
      begin
        read(b[j]);s[b[j]]:=false;
      end;
      max:=0;
      for j:=b[1] to b[a[i]] do
        if (s[j])and(c[j]>max) then max:=c[j];
      for j:=1 to a[i] do
      if c[b[j]]<=max then
      begin
        c[b[j]]:=max+1;
        if max+1>num then num:=max+1;
      end;
    end;
    writeln(num);
  close(input);close(output);
end.
