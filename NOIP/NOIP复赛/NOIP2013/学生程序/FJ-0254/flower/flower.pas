var
  a,b,c:array[1..100001]of longint;
  n,i,j,maxmax:longint;
function max(x,y:longint):longint;
  begin
    if x>y then max:=x
           else max:=y;
  end;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do b[i]:=1;
  for i:=1 to n do c[i]:=0;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if(a[j]>a[i])and(c[i]=0) then begin
                                     b[j]:=max(b[j],b[i]+1);
                                     c[j]:=1;                end;
        if(a[j]<a[i])and(c[i]=1) then begin
                                     b[j]:=max(b[j],b[i]+1);
                                     c[j]:=0;               end;
      end;
  for i:=1 to n do c[i]:=1;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if(a[j]>a[i])and(c[i]=0) then begin
                                     b[j]:=max(b[j],b[i]+1);
                                     c[j]:=1;                end;
        if(a[j]<a[i])and(c[i]=1) then begin
                                     b[j]:=max(b[j],b[i]+1);
                                     c[j]:=0;               end;
      end;
  maxmax:=0;
  for i:=1 to n do
    if b[i]>maxmax then maxmax:=b[i];
  writeln(maxmax);
  close(input);
  close(output);
end.
