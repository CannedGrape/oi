var f,d:array[0..100000]of longint;
    max,n,i:longint;

  procedure st1(k:longint);
  begin
    if k>n then
      begin
        if d[0]>max then max:=d[0];
        exit;
      end;
    if n-k+1+d[0]<max then exit;
    if (d[0]+1) mod 2=0 then
      begin
        if f[k]>d[d[0]] then
          begin
            inc(d[0]);
            d[d[0]]:=f[k];
            st1(k+1);
            dec(d[0]);
          end;
      end
    else if f[k]<d[d[0]] then
         begin
           inc(d[0]);
           d[d[0]]:=f[k];
           st1(k+1);
           dec(d[0]);
         end;
    st1(k+1);
  end;

  procedure st2(k:longint);
  begin
    if k>n then
      begin
        if d[0]>max then max:=d[0];
        exit;
      end;
    if n-k+1+d[0]<max then exit;
    if (d[0]+1) mod 2=0 then
      begin
        if f[k]<d[d[0]] then
          begin
            inc(d[0]);
            d[d[0]]:=f[k];
            st2(k+1);
            dec(d[0]);
          end;
      end
    else if f[k]>d[d[0]] then
         begin
           inc(d[0]);
           d[d[0]]:=f[k];
           st2(k+1);
           dec(d[0]);
         end;
    st2(k+1);
  end;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(f[i]);
  max:=1;
  for i:=1 to n-1 do
  begin
    fillchar(d,sizeof(d),0);
    inc(d[0]);
    d[1]:=f[i];
    st1(i+1);st2(i+1);
  end;
  writeln(max);
  close(input);close(output);
end.
