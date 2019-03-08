var i,j,t1,t2,s,max,k,n:longint;
    a:array[1..100000]of longint;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  if n=1 then max:=1;
  if (n=2) and (a[1]<>a[2]) then max:=2;
  if (n=2) and (a[1]=a[2]) then max:=1;
  if n>=3 then
  for i:=1 to n do
    begin
      t1:=a[i];if max>=n-i+1 then break;
      for j:=i+1 to n do
        begin
          t2:=a[j];
          if a[i]<>a[j] then
            begin
              s:=2;
              for k:=j+1 to n do
                begin
                  if (t1>t2)and(t2<a[k]) then
                    begin
                      t1:=t2;
                      t2:=a[k];
                      s:=s+1;
                    end
                  else
                  if (t1<t2)and(t2>a[k]) then
                    begin
                      t1:=t2;
                      t2:=a[k];
                      s:=s+1;
                    end;
                end;
              if s>max then max:=s;
            end;
        end;

    end;
  writeln(max);
  close(input);
  close(output);
end.
{rp++;rp:=maxlongint;orz WJMZBMR;orz JSZKC;}