program circle;
  var a,b,c,n,m,k,x:int64;
      i,j:longint;
  procedure cnm(l:longint);
  begin
    if l=0 then exit;
    cnm(l div 2);
    a:=(a*a) mod n;
    if l mod 2=1 then a:=(a*10) mod n;
  end;
  begin
    assign(input,'circle.in');assign(output,'circle.out');
    reset(input);rewrite(output);
    read(n,m,k,x);
    a:=1;
    cnm(k);
    b:=(m*a)mod n;
    c:=(x+b)mod n;
    write(c);
    close(input);close(output);
  end.