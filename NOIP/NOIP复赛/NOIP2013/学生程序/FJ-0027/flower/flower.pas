var n,i,x1,x0,b1,b0:longint;
    a:array[0..100010]of longint;
    f:array[0..100010,0..1]of longint;
function max(a,b:longint):longint;
begin max:=a;if a<b then max:=b;end;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);rewrite(output);
  readln(n);x1:=0;x0:=0;f[0,1]:=maxlongint;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    if x0 and 1=1 then
    begin
      if a[i]>f[x0,0]then
      begin
        f[x0,0]:=a[i];
        b0:=1;
      end
      else if a[i]<f[x0,0]then
      begin
        x0:=x0+1;
        f[x0,0]:=a[i];
        b0:=0;
      end;
    end
    else
    begin
      if a[i]<f[x0,0]then
      begin
        f[x0,0]:=a[i];
        b0:=1;
      end
      else if a[i]>f[x0,0]then
      begin
        x0:=x0+1;
        f[x0,0]:=a[i];
        b0:=0;
      end;
    end;
    if x1 and 1=1 then
    begin
      if a[i]<f[x1,1]then
      begin
        f[x1,1]:=a[i];
        b1:=1;
      end
      else if a[i]>f[x1,1]then
      begin
        x1:=x1+1;
        f[x1,1]:=a[i];
        b1:=0;
      end;
    end
    else
    begin
      if a[i]>f[x1,1]then
      begin
        f[x1,1]:=a[i];
        b1:=1;
      end
      else if a[i]<f[x1,1]then
      begin
        x1:=x1+1;
        f[x1,1]:=a[i];
        b1:=0;
      end;
    end;
  end;
//  if x0 and 1=0 then x0:=x0+b0;
//  if x1 and 1=0 then x1:=x1+b1;
  writeln(max(x0,x1));
//  write(x0,':');for i:=1 to x0 do write(f[i,0],' ');writeln;
//  write(x1,':');for i:=1 to x1 do write(f[i,1],' ');writeln;
close(input);close(output);
end.
