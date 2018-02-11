program e2;
var s:ansistring;
    a,c:array[0..100000] of string;
    i,j,k,t,y,p,b:longint;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(s);
  j:=length(s);
  for i:=1 to j do
  begin
    if(s[i]<>'+')and(s[i]<>'*')then a[k]:=a[k]+s[i];
    if(s[i]='+')or(s[i]='*')then
    begin
      c[k]:=s[i];
      inc(k);
    end;
  end;
  i:=1;j:=0;val(a[0],b,p);
  while i<=k do
  begin
    if c[j]='*' then
    begin
      val(a[i],t,p);
      t:=t mod 10000;
      b:=(b*t) mod 10000;
      i:=i+1;
      j:=j+1;
    end;
    if((c[j]='+')and(c[j+1]='+'))or((c[j]='+')and(c[j+1]=''))then
    begin
      val(a[i],t,p);
      t:=t mod 10000;
      b:=(b+t) mod 10000;
      inc(i);inc(j);
    end;
    if(c[j]='+')and(c[j+1]='*')then
    begin
      val(a[i],t,p);
      t:=t mod 10000;
      val(a[i+1],y,p);
      y:=y mod 10000;
      b:=(b+t*y) mod 10000;
      i:=i+2;
      j:=j+2;
    end;
  end;
  write(b);
  close(input);close(output);
end.
