Program expr;
var
  str:string;
  k,i,sum:integer;
  a:array[1..300] of integer;
begin
  assign(input,'expr.in');  reset(input);
  assign(output,'expr,out');  rewrite(output);
  readln(str);
  k:=1;
  for i:=1 to len(str) do
  begin
    if str[i]='*' then a[k]:=(ord(str[i-1]))*(ord(str[i+1]))
    else if str[i]<>'+' then a[k]:=ord(str[i]);
    inc(k);
  end;
  sum:=0;
  for i:=1 to k-1 do sum:=sum+a[i];
  writeln(sum);
  close(input);  close(output);
end.
