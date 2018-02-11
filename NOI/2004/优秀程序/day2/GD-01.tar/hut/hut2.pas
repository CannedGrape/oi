{$I-,Q-,R-,S-,V-,X-}
PROGRAM Joshua;
VaR
  dp:array[0..100,0..100,0..100]of longint;
  sa,sb:array[0..100,0..100,0..100]of integer;
  db2:array[0..100,0..100]of longint;
  a,b:real;
  m,n,k1,k2:longint;
Function small(a,b:longint):longint;
  begin
    if a<b then small:=a else small:=b;
  end;
Procedure solve;
  var
    i,j,k,a,b:longint;
  begin
    for i:=1 to 100 do
    begin
      db2[i,1]:=sqr(i)*k2;
      for j:=2 to i do
      begin
        db2[i,j]:=2000000000;
        for k:=1 to i-j+1 do
          if sqr(k)*k2+db2[i-k,j-1]<db2[i,j] then
            db2[i,j]:=sqr(k)*k2+db2[i-k,j-1];
      end;
    end;
    for i:=0 to 100 do
      for j:=0 to 100 do
        for k:=0 to 100 do
          dp[i,j,k]:=1000000000;
    dp[0,0,0]:=0;
    for i:=1 to 100 do
      for j:=1 to small(i,m) do
        for k:=1 to small(i,n) do
          for a:=1 to i-j+1 do
            for b:=1 to small(a,k) do
              if dp[i-a,j-1,k-b]+db2[a,b]+sqr(a)*k1<dp[i,j,k] then
              begin
                dp[i,j,k]:=dp[i-a,j-1,k-b]+db2[a,b]+sqr(a)*k1;
//                sa[i,j,k]:=a;
//                sb[i,j,k]:=b;
              end;
    writeln(dp[100,m,n]*0.1:0:1);
  end;
BeGiN
  assign(input,'hut.in'); reset(input);
//  assign(output,'hut.out');rewrite(output);
  readln(a,b,m,n);
  k1:=round(a*10);
  k2:=round(b*10);
{  if (100 mod n=0)and(n mod m=0) then
    writeln(sqr(100 div n)*k2*n+sqr(100 div m)*k1*m:0:1)
  else} solve;
  close(input);
  close(output);
EnD.
nD.
