var n,i,l,r,max,ans,k,ansi:longint; bo,po:boolean;
    a:array[0..100000]of longint;
begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  bo:=false;


    ans:=0; l:=1; r:=2;
    while (l<=r)and(r<=n) do
    begin
      if bo then
      if a[r]>=a[l] then
      begin
        inc(r); inc(l);
      end else begin
        inc(ans); bo:=not bo;
      end;

      if not bo then
      if a[r]<=a[l] then
      begin
        inc(r); inc(l);
      end else begin
        inc(ans); bo:=not bo;
      end;
    end;

  po:=true;
  ansi:=0; l:=1; r:=2;
    while (l<=r)and(r<=n) do
    begin
      if po then
      if a[r]>=a[l] then
      begin
        inc(r); inc(l);
      end else begin
        inc(ansi); po:=not po;
      end;

      if not po then
      if a[r]<=a[l] then
      begin
        inc(r); inc(l);
      end else begin
        inc(ansi); po:=not po;
      end;
    end;
  max:=ans; if ansi<max then max:=ansi;
  writeln(max+2);
  close(input); close(output);
end.
