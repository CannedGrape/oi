var
  s:string;
  jl,k,j,i,t,k1:longint;
  a:array[1..1000000] of int64;
  b:array[1..1000000] of 1..2;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(s);
  jl:=1;
  k:=0;
  j:=0;
  for i:=1 to length(s) do
    if (s[i]='+') or (s[i]='*') then
      begin
        k:=k+1;
        if s[i]='*' then
          b[k]:=1
        else b[k]:=2;
        j:=j+1;
        val(copy(s,jl,i-jl),a[j]);
        jl:=i+1;
      end;
  j:=j+1;
  val(copy(s,jl,length(s)-jl+1),a[j]);
  k1:=1;
  while k1<=k do
    if b[k1]=1 then
      begin
        a[k1]:=a[k1]*a[k1+1];
        for t:=k1 to (k-1) do
          b[t]:=b[t+1];
        k:=k-1;
        for t:=k1+1 to (j-1) do
          a[t]:=a[t+1];
        j:=j-1;
      end
    else
      k1:=k1+1;
  for i:=2 to j do
    a[1]:=a[1]+a[i];
  str(a[1],s);
  s:=copy(s,length(s)-3,4);
  for i:=1 to length(s) do
    if s[i]<>'0' then write(s[i]);
  close(input);close(output);
end.
