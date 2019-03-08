program circle;
var a,mod1:array[0..1000000]of longint;
    n,m,k,x,i,pre,t:longint;
begin
    assign(input,'circle.in');
    assign(output,'circle.out');
    reset(input);
    rewrite(output);
    readln(n,m,k,x);
    fillchar(a,sizeof(a),0);
    a[0]:=x;
    pre:=x;
    for i:=1 to n do
    begin
      a[i]:=(pre+m) mod n;
      pre:=a[i];
    end;
    fillchar(mod1,sizeof(mod1),0);
    mod1[0]:=1;
    t:=0;
    repeat
      inc(t);
      mod1[t]:=(mod1[t-1]*10) mod n;
    until (mod1[t]=0) or (mod1[t]=mod1[0]) or ((t>1) and (mod1[t]=mod1[1]));
    if mod1[t]=0 then writeln(x)
    else
    begin
      k:=k mod t;
      pre:=1;
      for i:=1 to k do pre:=(pre*10) mod n;
      writeln(a[pre]);
    end;
    close(input);
    close(output);
end.
