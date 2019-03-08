var n,i,j,sum:longint;
    a:array[0..100100]of longint;
function shangsheng(x:longint):longint;
begin
  if a[x]<=a[x+1] then shangsheng(x+1)
  else
    begin
      shangsheng:=x;
      exit;
    end;
end;
function xiajiang(x:longint):longint;
begin
  if (a[x]>=a[x+1]) and (x<n) then xiajiang(x+1)
    else
      begin
        xiajiang:=x;
        exit;
      end;
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  j:=1;sum:=0;
  repeat
    while a[j]=a[j+1] do inc(j);
    if (a[j]<a[j+1]) and (j<n) then begin j:=shangsheng(j);inc(sum);end;
    if (a[j]>a[j+1]) and (j<n) then begin j:=xiajiang(j);inc(sum);end;

  until j>=n;
  writeln(sum+1);
  close(input);close(output);
end.
