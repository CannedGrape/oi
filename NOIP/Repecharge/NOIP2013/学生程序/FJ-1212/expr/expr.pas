program expr;
var t1:boolean;
    t,ans,a1:int64;
    a:array[1..200000] of int64;
    i:longint;
    x:char;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
    t:=0;
    t1:=false;
    while not(eof) do
      begin
        read(x);
        if (x>='0') and (x<='9') then
          t:=t*10+ord(x)-48
        else
          begin
            if t>0 then
              begin
                inc(a1);
                a[a1]:=t mod 10000;
                t:=0;
              end;
            if t1 then
              begin
                a[a1-1]:=(a[a1-1]*a[a1]) mod 10000;
                a[a1]:=0;
                dec(a1);
                t1:=false;
              end;
            if x='*' then t1:=true;
          end;
      end;
    if t>0 then begin inc(a1); a[a1]:=t; end;
    ans:=0;
    for i:=1 to a1 do ans:=(ans+a[i]) mod 10000;
    write(ans);
  close(input);
  close(output);
end.
