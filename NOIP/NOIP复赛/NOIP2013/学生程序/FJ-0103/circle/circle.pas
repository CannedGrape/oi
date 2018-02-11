var i,j,n,m,k,x,c,h,ans:longint;
    a:array[0..10000] of longint;
    t:boolean;

procedure round(m,h,x:longint);
begin
  if h<>0 then
    begin
      x:=x+m;
      if x>n-1 then x:=x-n;
      dec(h);
      round(m,h,x);
    end
  else ans:=x;
end;

begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input);
  rewrite(output);
  readln(n,m,k,x);
  fillchar(a,sizeof(a),0);
  if (n mod m=0) then c:=n div m
  else c:=n;
  i:=0;
  j:=1;
  t:=false;
  ans:=x;
  if (c mod 10<>0) then
    if c<>1 then
      begin
        repeat
          a[i]:=j mod c;
          if (a[i]=a[1]) and (i<>1) then t:=true else t:=false;
          inc(i);
          j:=j*10;
        until (i<>1) and (t);
        i:=i-2;
        h:=k mod i;
        round(m,a[h],x);
      end
    else round(m,1,x);
  writeln(ans);
  close(input);
  close(output);
end.
