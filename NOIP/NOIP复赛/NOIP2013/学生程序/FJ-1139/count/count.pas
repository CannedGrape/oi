var
  a:array[0..9]of longint;
  nn,i,j,k,x,di,na,st,nl:longint;
  n:string;
  co:integer;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(na,x);
  str(na,n);
  if x=0 then
    begin
      for i:=1 to length(n)-1 do
        begin
          a[0]:=a[0]+na div 10;
          na:=na div 10;
        end;
      writeln(a[0]);
    end else begin
  for i:=length(n) downto 1 do
    begin
      val(n[i],nn,co);
      nl:=0;
      di:=1;
      val(copy(n,1,i-1),nl,co);
      for j:=1 to length(n)-i do
        di:=di*10;
      for j:=0 to 9 do
        a[j]:=a[j]+nl*di;
      val(n[i+1],na,co);
      for j:=0 to nn do
        for k:=0 to na do
          inc(a[j]);
    end;
  writeln(a[x]);
  end;
  close(input);
  close(output);
end.
