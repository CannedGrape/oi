program block;
  var h:array[1..100000] of integer;
      hm:integer;
      n,i:longint;
      count:int64;
  procedure pai(l,r:longint);
    var j:longint;
        can,have:boolean;
  begin
    can:=true;
    have:=false;
    for j:=l to r do if h[j]>=hm then begin have:=true;break;end;
    if have then
    begin
      for j:=l to r do
        if h[j]<hm then begin
                          can:=false;
                          pai(l,j-1);
                          pai(j+1,r);
                          break;
                        end;
        if can then begin
                      inc(hm);
                      inc(count);
                      pai(l,r);
                      dec(hm);
                    end;
    end;
  end;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(h[i]);
  hm:=1;
  pai(1,n);
  write(count);
  close(input);close(output);
end.
