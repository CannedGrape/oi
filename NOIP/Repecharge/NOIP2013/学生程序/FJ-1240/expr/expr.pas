program expr;
var a,b:string;
    c:array[1..100000] of longint;
    i,j,al,p:longint;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(a);
  al:=length(a);
  j:=0;
  for i:=1 to al+1 do
  begin
    if (a[i]>='0') and (a[i]<='9') then b:=b+a[i]
    else
    begin
      inc(j);
      val(b,c[j]);
      inc(j);
      if a[i]='*' then c[j]:=-1;
      if a[i]='+' then c[j]:=-2;
      b:='';
    end;
  end;
  for i:=1 to al do
    if c[i]=-1 then
    begin
      c[i]:=c[i-1]*c[i+1];
      if c[i]>9999 then c[i]:=c[i] mod 10000;
      c[i-1]:=c[i];
      c[i+1]:=c[i];
    end;
  for i:=1 to al do
    if c[i]=-2 then
    begin
      c[i]:=c[i-1]+c[i+1];
      if c[i]>9999 then c[i]:=c[i] mod 10000;
      p:=1;
      while (i-p>0) and (c[i-p]>0) do
      begin
        c[i-p]:=c[i];
        inc(p);
      end;
      p:=1;
      while (i+p<al) and (c[i+p]>0) do
      begin
        c[i+p]:=c[i];
        inc(p);
      end;
    end;
  write(c[1]);
  close(input);
  close(output);
end.