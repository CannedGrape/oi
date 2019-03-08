var a:array[0..1000001]of longint;
    f:array[0..1000001]of boolean;
    n,m,k,x,t:longint;num,num1:int64;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
    fillchar(f,sizeof(f),false);
    readln(n,m,k,x);
    t:=0;
    repeat
      a[t]:=x;
      f[x]:=true;
      x:=(x+m) mod n;
      inc(t);
    until f[x];
    num:=1;num1:=10;
    while k>0 do
    begin
      if k mod 2=1 then num:=num*num1 mod t;
      num1:=num1*num1 mod t;
      k:=k div 2;
    end;
    writeln(a[num]);
  close(input);close(output);
end.
