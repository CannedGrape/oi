program block;
var
  ans1,zuixiao,w,jian,n,l,i,ans:longint;
  bo:boolean;
  a,dui:array[0..100100]of longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);

  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);

    end;
  l:=0;
  ans1:=0;
  jian:=0;
  for i:=1 to n do
    begin
      if (l=0) or (a[i]>dui[l]) then
        begin
          inc(l);
          dui[l]:=a[i];
          if i=n then
            ans1:=ans1+dui[l]-jian;
        end
      else
        begin

          ans1:=ans1+dui[l]-jian;
          while a[i]<dui[l] do
            begin
              dui[l]:=0;
              dec(l);
            end;
          inc(l);
          dui[l]:=a[i];
          jian:=a[i];
        end;
    end;
  writeln(ans1);
  close(input);
  close(output);
end.
