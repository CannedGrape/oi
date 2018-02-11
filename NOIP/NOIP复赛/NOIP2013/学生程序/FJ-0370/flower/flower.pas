program flower;
var
  n,i,sum,t1,t2,w1,w2:longint;
  h:array[0..100000] of longint;
  r1,r2:array[0..100000] of longint;
begin
  assign(input,'flower.in');  reset(input);
  assign(output,'flower.out');  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(h[i]);
  readln;
  sum:=n;
  t1:=1; w1:=1;
  t2:=1; w2:=1;
  r1[1]:=h[1];
  r2[1]:=h[1];
  for i:=2 to n do
    begin
      if (h[i]>r1[w1]) or (h[i]=r1[w1]) and (w1>1) then
        begin
          inc(w1); r1[w1]:=h[i];
        end;
      if (h[i]<r2[w2]) or (h[i]=r2[w2]) and (w2>1) then
        begin
          inc(w2); r2[w2]:=h[i];
        end;
      if (w1>1) and ((h[i]<r1[w1]) or (i=n)) then
        begin
          sum:=sum-w1+2;
          w1:=t1;
          r1[w1]:=h[i];
          r2[t2]:=h[i-1];
          w2:=2;
          r2[w2]:=h[i];
        end;
      if (w2>1) and ((h[i]>r2[w2]) or (i=n)) then
        begin
          sum:=sum-w2+2;
          w2:=t2;
          r2[w2]:=h[i];
          r1[t1]:=h[i-1];
          w1:=2;
          r1[w1]:=h[i];
        end;
    end;
  writeln(sum);
  close(input);  close(output);
end.
