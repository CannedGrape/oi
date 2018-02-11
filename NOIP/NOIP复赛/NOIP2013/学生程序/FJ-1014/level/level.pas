var a,b:array[1..1000] of integer;
    v,c:array[1..1000] of boolean;
    hh,max,i,j,m,n,s,h,t,q,min:integer;
    flag:boolean;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);rewrite(output);
  read(m,n);
  for i:=1 to m do
   a[i]:=m;
  for i:=1 to n do
  begin
    fillchar(c,sizeof(c),true);
    read(s);min:=maxint;flag:=true;
    fillchar(v,sizeof(v),true);
    for j:=1 to s do
    begin
      read(b[j]);
      v[b[j]]:=false;
      if a[b[j]]<min then min:=a[b[j]];
    end;
    {for j:=1 to m do
     if v[j] then  write('1 ') else write('0 ');  }

     //writeln(min);
    h:=b[1];t:=b[s];hh:=0;
    for j:=h to t do
    begin
      if (v[j]) and (a[j]>=min) then
      begin
        a[j]:=a[j]-1;
        c[j]:=false;
        for q:=1 to m do
         if (c[q]) and (v[q]) and (a[q]<=a[j]) then begin c[q]:=false;dec(a[q]); end;
      end;
    end;
    {for j:=1 to m do
      write(a[j],' ');
    writeln; }
  end;
  {for i:=1 to m do write(a[i],' ');  }
  //writeln;
  max:=0;min:=maxint;
  for i:=1 to m do
  begin
   if a[i]>max  then max:=a[i];
   if a[i]<min then min:=a[i];
  end;
  writeln(max-min+1);
  close(input);close(output);
end.
