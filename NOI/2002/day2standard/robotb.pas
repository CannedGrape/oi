const inputname='robot.in';
      outputname='robot.out';
var f1,f2:text;
    i,j,k,l,p,q,t,tot1,tot2,tot3:longint;
    d:array[1..1000]of longint;
    zs:array[1..1000]of longint;
    s:array[0..1000]of longint;
    a1:array[1..1000]of longint;
procedure change(var x,y:longint);
var z:longint;
begin
  z:=x;x:=y;y:=z;
end;
begin
  assign(f1,inputname);
  reset(f1);
  assign(f2,outputname);
  rewrite(f2);
  readln(f1,k);
  for i:=1 to k do
    readln(f1,d[i],zs[i]);
  if d[1]=2 then t:=2
    else t:=1;
  fillchar(s,sizeof(s),0);
  s[0]:=1;
  for i:=t to k do
    begin
      for j:=1000 downto 1 do
        begin
          inc(s[j],s[j-1]*(d[i]-1));
          s[j]:=s[j] mod 10000;
        end;
    end;
  tot1:=0;tot2:=0;
  for i:=1 to 1000 do
    if odd(i) then tot1:=(tot1+s[i])mod 10000
      else tot2:=(tot2+s[i])mod 10000;
  t:=k;
  tot3:=1;
  for i:=1 to t do
    begin
      p:=zs[i];q:=0;
      while p<>0 do
        begin
          inc(q);
          a1[q]:=p mod 2;
          p:=p div 2;
        end;
      l:=1;
      for j:=q downto 1 do
        begin
          l:=l*l mod 10000;
          if a1[j]=1 then l:=l*d[i] mod 10000;
        end;
      tot3:=tot3*l mod 10000;
    end;
  tot3:=(tot3+30000-tot1-tot2-1)mod 10000;
  writeln(f2,tot2);
  writeln(f2,tot1);
  writeln(f2,tot3);
  close(f1);
  close(f2);
end.

