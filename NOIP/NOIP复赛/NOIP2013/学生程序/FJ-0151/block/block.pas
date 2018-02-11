Program block;
  var n,o,p,r:longint;
      hi,i:array[0..100000]of integer;
  begin
    assign(input,'block.in');
    reset(input);
    assign(output,'block.out');
    rewrite(output);
    read(n);
    fillchar(hi,sizeof(hi),0);
    for o:=1 to n do
      read(hi[o]);
    fillchar(i,sizeof(i),0);
    p:=1;
    r:=0;
    repeat
      if i[p]<hi[p] then
      begin
      inc(i[p]);
      if ((i[p]=hi[p]) and (p<>0)) then
      if i[p+1]=hi[p+1] then
      begin
        inc(r);
        p:=0;
      end;
      end
      else
      if i[p]=hi[p] then
      begin
        if i[p-1]<hi[p-1] then begin
        inc(r);
        p:=0;                 end;
      end;
      if p=n then inc(r);
      inc(p);
      if p>n then p:=1;
    until i[n]=hi[n];
    writeln(r);
    close(input);
    close(output);
  end.
