var
  i,j,k,sum:longint;
  s:ansistring;
  s1:string;
  a,b:array[0..100002]of longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  k:=1;j:=1;
  for i:=1 to length(s) do
    begin
      if s[i]<'0' then begin a[k]:=i;inc(k);end else continue;
      if a[k-1]-a[k-2]-1<4 then
        begin
          val(copy(s,a[k-2]+1,a[k-1]-a[k-2]-1),b[j]);
          inc(j);
          continue;
        end
      else
        begin
          val(copy(s,a[k-1]-4,4),b[j]);
          inc(j);
        end;
    end;
  a[k]:=length(s)+1;inc(k);
  if a[k-1]-a[k-2]-1<4 then
    val(copy(s,a[k-2]+1,a[k-1]-a[k-2]-1),b[j])
  else
    val(copy(s,a[k-1]-4,4),b[j]);dec(k);
  for i:=1 to k-1 do
    begin
      if s[a[i]]='*' then
        begin
          b[i+1]:=b[i]*b[i+1];
          b[i]:=0;
          if b[i+1]>9999 then
            begin
              b[i+1]:=b[i+1]mod 10000;
            end;
        end;
    end;
  for i:=1 to k do
    sum:=sum+b[i];
  writeln(sum);
  close(input);
  close(output);
end.