var
  i,len,ans,zsum:longint;
  dr,a:string;
  z,zhan:array [0..100000] of longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(dr);
  len:=length(dr);
  dr:=dr+'+';
  i:=1;
  while i<=len do
    begin
      inc(zsum);
      if (dr[i]<>'+')and(dr[i]<>'*') then
        begin
          a:='';
          while (dr[i]<>'+')and(dr[i]<>'*') do
            begin
              a:=a+dr[i];
              inc(i);
            end;
          if length(a)>4 then a:=copy(a,length(a)-3,4);
          val(a,z[zsum]);
        end
      else
        begin
          if dr[i]='+' then z[zsum]:=-1
          else z[zsum]:=-2;
          inc(i);
        end;
    end;
  i:=1;
  while i<=zsum do
    begin
      inc(zhan[0]);
      zhan[zhan[0]]:=z[i];
      if (z[i]=-1)and(zhan[0]>3) then
        begin
          zhan[1]:=(zhan[1]+zhan[3]) mod 10000;
          zhan[0]:=2;
        end;
      if z[i]=-2 then
        begin
          zhan[zhan[0]-1]:=(zhan[zhan[0]-1]*z[i+1]) mod 10000;
          dec(zhan[0]);
          inc(i);
        end;
      inc(i);
    end;
  writeln((zhan[1]+zhan[3]) mod 10000);
  close(input);
  close(output);
end.
