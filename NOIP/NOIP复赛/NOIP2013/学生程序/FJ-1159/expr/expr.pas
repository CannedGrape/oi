var i,j,k:longint;
    x,y:array[-10000..1000001] of int64;
    sum,s2,l,r,n,m:int64;
    s,p:ansistring;
    h,t:char;
function pd(ii:longint):boolean;
begin
  if ((ord(s[ii+1])-48)>-1) and (ord(s[ii+1])-48<10) then exit(true) else exit(false);
end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  k:=length(s);
  s:=' '+s+' ';
  repeat
    for i:=s2 to k do
    begin
      if (pd(i)=true) and (pd(i-1)=false) then begin l:=i+1;end;
      if (pd(i)=true) and (pd(i+1)=false) and (i+1>=l) then
      begin
      r:=i+1;h:=s[l-1];break;
      end;
    end;
    for i:=l to r do
    begin
      p:=p+s[i];
    end;
    inc(n);
    for i:=1 to length(p) do
    begin
      x[n]:=10*x[n]+ord(p[i])-48;
    end;
    if (h='*') then x[n]:=x[n]*x[n-1];
    if (h='+') then begin inc(m);y[m]:=x[n-1];end;
    if (l=2) then begin inc(m);y[m]:=x[n];end;
    s2:=r;
    p:='';
  until r>=k+1;
  for i:=2 to m do
  begin
    inc(sum,y[i]);
    sum:=sum mod 10000;
  end;
  sum:=(sum+x[n]) mod 10000;
  writeln(sum);
  close(input);
  close(output);
end.
