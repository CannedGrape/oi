var
  a:array[1..100000]of char;
  ans:array[1..100000]of integer;
  x,y:array[1..10]of integer;
  i,l,j,jx,jy,xk,yk,xx,yy,ss,ansk:longInt;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  for i:=1 to 100000 do read(a[i]);
  for i:=1 to 100000 do
    if ord(a[i])=0 then
    begin
      l:=i-1;
      break;
    end;
  for i:=1 to l do
    if a[i]='*' then
    begin

      xk:=1;
      yk:=1;

      for j:=i-1 downto i-5 do
      begin
        if (a[j]>='0') and (a[j]<='9') then
        begin
          x[xk]:=ord(a[j])-48;
          xk:=xk+1;
        end;
        if (a[j]='+') or (a[j]='*') then break;
      end;
      for j:=i-1 downto 1 do
        if (a[j]='+') or (a[j]='*') then break;
      if j=1 then jx:=j else jx:=j+1;

      for j:=i+1 to i+5 do
      begin
        if (a[j]>='0') and (a[j]<='9') then
        begin
          y[yk]:=ord(a[j])-48;
          yk:=yk+1;
        end;
        if (a[j]='+') or (a[j]='*') then break;
      end;
      for j:=i+1 to i+5 do
        if (a[j]='+') or (a[j]='*') then break;
      if j=l then jy:=j else jy:=j-1;

      xx:=0;
      for j:=10 downto 1 do
        if (x[j]>=0) and (x[j]<=9) then xx:=xx*10+x[j];
      yy:=0;
      for j:=10 downto 1 do
        if (y[j]>=0) and (y[j]<=9) then yy:=yy*10+y[j];

      ss:=xx*yy;
      while ss>0 do
      begin
        a[jx]:=chr((ss mod 10)+48);
        jx:=jx+1;
        ss:=ss div 10;
      end;
      if jx<jy then
      for j:=jx to jy do
        a[j]:=chr(0);

    end;

  for i:=1 to l do
    if a[i]='+' then
    begin

      xk:=1;
      yk:=1;
      for j:=1 to 10 do x[j]:=0;
      for j:=1 to 10 do y[j]:=0;

     for j:=i-1 downto i-5 do
      begin
        if (a[j]>='0') and (a[j]<='9') then
        begin
          x[xk]:=ord(a[j])-48;
          xk:=xk+1;
        end;
        if (a[j]='+') or (a[j]='*') then break;
      end;
      for j:=i-1 downto 1 do
        if (a[j]='+') or (a[j]='*') then break;
      if j=1 then jx:=j else jx:=j+1;

      for j:=i+1 to i+5 do
      begin
        if (a[j]>='0') and (a[j]<='9') then
        begin
          y[yk]:=ord(a[j])-48;
          yk:=yk+1;
        end;
        if (a[j]='+') or (a[j]='*') then break;
      end;
      for j:=i+1 to i+5 do
        if (a[j]='+') or (a[j]='*') then break;
      if j=l then jy:=j else jy:=j-1;


      xx:=0;
      for j:=10 downto 1 do
        if (x[j]>=0) and (x[j]<=9) then xx:=xx*10+x[j];
      yy:=0;
      for j:=10 downto 1 do
          if (y[j]>=0) and (y[j]<=9) then yy:=yy*10+y[j];

      ss:=xx+yy;
      while ss>0 do
      begin
        a[jx]:=chr((ss mod 10)+48);
        jx:=jx+1;
        ss:=ss div 10;
      end;
      if jx<jy then
      for j:=jx to jy do
        a[j]:=chr(0);

    end;
  ansk:=1;
  for i:=1 to l do
    if (ord(a[i])>=49) and (ord(a[i])<=57) and (ansk<=4) then
    begin
      ans[ansk]:=ord(a[i])-48;
      ansk:=ansk+1;
    end;
  for i:=ansk-1 downto 1 do
  write(ans[i]);
  close(input);
  close(output);
end.