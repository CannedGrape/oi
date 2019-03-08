var i,l,n,max,min:dword;
    ans:qword;
    h:array[0..100000]of dword;

begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  l:=1;
  ans:=1;
  repeat
    max:=h[l];
    min:=h[l];
    for i:=l+1 to n do
      if(max>h[l])and(max>h[i])or(min<h[l])and(min<h[i])then
      begin
        l:=i;
        inc(ans,2);
        break;
      end else
      if max<h[i]then max:=h[i] else
      if min>h[i]then min:=h[i];
    if i=n then break;
  until false;
  if l<n then inc(ans);
  writeln(ans);
  close(input);
  close(output);
end.