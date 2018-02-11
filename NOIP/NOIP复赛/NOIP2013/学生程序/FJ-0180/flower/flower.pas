var h:array [0..100001] of longint;
    n,i,j,k,ans,max:longint;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);

  readln(n);
  read(h[1]);
  ans:=1;
  j:=1;
  for i:=2 to n do
    begin
      read(k);
      if k<>h[j]
      then
        begin
          inc(j);
          h[j]:=k;
        end;
    end;
  n:=j;
  if n<=2
  then ans:=n
  else
    begin
      if h[1]<h[2]
      then
        begin
          i:=2;
          while i<=n do
            begin
              while (i<=n) and (h[i]>h[i-1]) do inc(i);
              inc(ans);
              if i>n then break;
              while (i<=n) and (h[i]<h[i-1]) do inc(i);
              inc(ans);
            end;
        end
      else
        begin
          i:=2;
          while i<=n do
            begin
              while (i<=n) and (h[i]<h[i-1]) do inc(i);
              inc(ans);
              if i>n then break;
              while (i<=n) and (h[i]>h[i-1]) do inc(i);
              inc(ans);
            end;
        end;
    end;
  writeln(ans);

close(input);
close(output);
end.
