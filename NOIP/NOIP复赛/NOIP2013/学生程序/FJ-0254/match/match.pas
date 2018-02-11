var
  a,b,c,d,e,f:array[1..100000]of longint;
  n,i,ci,j,s,t:longint;

procedure  qp1(x,y:longint);
  var
    i,j,m,t:longint;
  begin
    i:=x;
    j:=y;
    m:=c[(i+j)div 2];
    repeat
      while c[i]>m do inc(i);
      while c[j]<m do dec(j);
        if i<=j then begin
                    t:=c[i]; c[i]:=c[j]; c[j]:=t;
                    t:=d[i]; d[i]:=d[j]; d[j]:=t;
                    inc(i); dec(j);
                    end;
    until i>j;
    if i<y then qp1(i,y);
    if j>x then qp1(x,j);
  end;

begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do c[i]:=a[i];
  for i:=1 to n do d[i]:=i;
  qp1(1,n);
  for i:=1 to n do e[d[i]]:=i;
  for i:=1 to n do c[i]:=b[i];
  for i:=1 to n do d[i]:=i;
  qp1(1,n);
  for i:=1 to n do f[d[i]]:=i;
  ci:=0;
  for i:=1 to n do
    if e[i]<>f[i] then begin
                          s:=d[e[i]];
                          for j:=s downto i+1 do
                            begin
                              d[f[j]]:=j-1; d[f[j-1]]:=j;
                              t:=f[j-1]; f[j-1]:=f[j]; f[j]:=t;
                              ci:=ci+1;
                              if ci>99999997 then ci:=ci-99999997;
                            end;
                        end;
  writeln(ci);
  close(input);
  close(output);
end.
