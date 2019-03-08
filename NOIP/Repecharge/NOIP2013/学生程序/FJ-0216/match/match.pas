var
  a,b,f,s,p,q:array[0..100000]of longint;
  n,i,j,k,c1,c2,c3:longint;

function c(x,y:longint):longint;
begin
  exit(sqr(a[x]-b[y]) mod 99999997);
end;

begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do begin
    read(a[i]);
    a[i]:=a[i] mod 99999997;
  end;
  for i:=1 to n do begin
    read(b[i]);
    b[i]:=b[i] mod 99999997;
  end;
  f[0]:=0;
  s[0]:=0;
  f[1]:=c(1,1);
  s[1]:=0;
  for i:=1 to n do begin
    p[i]:=i;
    q[i]:=i;
  end;
  for i:=2 to n do begin
    c1:=c(i,i);
    c2:=c(i-1,i)+c(i,p[i-1]);
    c3:=c(q[i-1],i)+c(i,i-1);
    f[i]:=f[i-1]+c1;
    s[i]:=s[i-1];
    if (f[i-1]+c2<f[i]) or
    ((f[i-2]+c2=f[i]) and (s[i-2]+1<s[i])) then begin
      f[i]:=f[i-2]+c2;
      s[i]:=s[i-2]+1;
      p[i]:=p[i-1];
      p[i-1]:=i;
    end;
    if (f[i-2]+c3<f[i]) or
    ((f[i-2]+c3=f[i]) and (s[i-2]+1<s[i])) then begin
      f[i]:=f[i-2]+c3;
      s[i]:=s[i-2]+1;
      q[i]:=q[i-1];
      q[i-1]:=i;
    end;
    if (f[i-2]+c2+c3<f[i]) or
    ((f[i-2]+c2+c3=f[i]) and (s[i-2]+2<s[i])) then begin
      f[i]:=f[i-2]+c2+c3;
      s[i]:=s[i-2]+2;
      p[i]:=p[i-1];
      p[i-1]:=i;
      q[i]:=q[i-1];
      q[i-1]:=i;
    end;
    f[i]:=f[i] mod 99999997;
  end;
  writeln(s[n]);
  close(input);
  close(output);
end.
