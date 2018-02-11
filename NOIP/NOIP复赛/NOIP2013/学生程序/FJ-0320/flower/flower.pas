var n,i,j,k,top,ans:longint;
    a:array[0..100001] of longint;
    bo,fuck:boolean;
begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  top:=2; ans:=1; if a[2]>a[1] then bo:=true else bo:=false;
  while top<=n do
  begin
    if top=n then begin inc(ans); break; end;
    while (a[top]<a[top-1]) and (a[top]>a[top+1]) and not bo do
    begin
      inc(top);
      if top=n then
      begin
        inc(ans);
        fuck:=true;
        break;
      end;
    end;
    if fuck then break;
    while (a[top]>a[top-1]) and (a[top]<a[top+1]) and bo do
    begin
      inc(top);
      if top=n then
      begin
        inc(ans);
        fuck:=true;
        break;
      end;
    end;
    if fuck then break;
    if top<=n then
    begin
      inc(ans);
      inc(top);
      bo:=not bo;
    end;
  end;
  writeln(ans);
  close(input); close(output);
end.
