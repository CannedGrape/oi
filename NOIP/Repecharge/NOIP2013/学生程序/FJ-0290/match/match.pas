type arr=array[1..100000] of longint;
Var n,i,j,ans,t:longint;
    a,b,c,d,f:arr;
Procedure kuaipai1(l,r:longint);
 var i,j,mid,t:longint;
  begin
    i:=l; j:=r; mid:=a[(i+j) div 2];
    repeat
     while a[i]<mid do inc(i);
     while a[j]>mid do dec(j);
     if i<=j then
      begin
       t:=a[i]; a[i]:=a[j]; a[j]:=t;
       t:=c[i]; c[i]:=c[j]; c[j]:=t;
       inc(i); dec(j);
      end;
    until i>j;
    if i<r then kuaipai1(i,r);
    if l<j then kuaipai1(l,j);
  end;
Procedure kuaipai2(l,r:longint);
 var i,j,mid,t:longint;
  begin
    i:=l; j:=r; mid:=b[(i+j) div 2];
    repeat
     while b[i]<mid do inc(i);
     while b[j]>mid do dec(j);
     if i<=j then
      begin
       t:=b[i]; b[i]:=b[j]; b[j]:=t;
       t:=d[i]; d[i]:=d[j]; d[j]:=t;
       inc(i); dec(j);
      end;
    until i>j;
    if i<r then kuaipai2(i,r);
    if l<j then kuaipai2(l,j);
  end;
Begin
        Assign(Input,'match.in');Reset(Input);
        Assign(Output,'match.out');Rewrite(Output);
 readln(n);
 for i:=1 to n do read(a[i]); readln;
 for i:=1 to n do read(b[i]);
 for i:=1 to n do begin c[i]:=i; d[i]:=i; end;
 kuaipai1(1,n); kuaipai2(1,n);
 for i:=1 to n do f[d[i]]:=i;
 for i:=1 to n do
    if c[i]<>d[i] then
     begin
      f[d[i]]:=f[c[i]];
      t:=d[i]; d[i]:=d[f[c[i]]]; d[f[c[i]]]:=t;
      f[c[i]]:=i;
      inc(ans);
     end;
 writeln(ans);
        Close(Input);Close(Output);
End.
