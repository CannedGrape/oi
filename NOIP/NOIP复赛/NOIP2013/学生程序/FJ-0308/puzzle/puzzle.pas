program puzzle;
  var n,m,q:integer;
      i,j,x1,x2,y1,y2,x3,y3:integer;
      fi,se:array[0..31,0..31,0..31,0..31] of integer;
      p,p1:array[0..31,0..31] of integer;
  function min(a,b,c,d:integer) : integer;
    begin
      if a<b then min:=a else min:=b;
      if c<min then min:=c;
      if d<min then min:=d;
    end;
  function find(a,b,c,d:integer) : integer;
  begin
    if p1[a,b]=0 then  find:=10000
    else begin
    p1[a,b]:=0;
    if (a=c) and (b=d) then  find:=0
    else begin
    find:=min(find(a-1,b,c,d),find(a+1,b,c,d),
                       find(a,b-1,c,d),find(a,b+1,c,d))+1;
    se[a,b,c,d]:=min(find(a-1,b,c,d),find(a+1,b,c,d),
                       find(a,b-1,c,d),find(a,b+1,c,d))+1;
    p1[a,b]:=p[a,b];
    end;
    end;
  end;
  function fe(a,b,c,d,e,f:integer):integer;
  begin
    if (a=c) and (b=d) then f:=0;
    fe:=min(fe(a-1,b,c,d,a,b),fe(a+1,b,c,d,a,b),
                    fe(a,b-1,c,d,a,b),fe(a,b+1,c,d,a,b));
    fe:=fe++fi[c,d,e,f]+1;
  end;
begin
  readln(n,m,q);
  fillchar(p,sizeof(p),0);
  for i:=1 to n do
  begin
    for j:=1 to m do  begin
      read(p[i,j]);p1[i,j]:=p[i,j];end;
    readln;
  end;
  for x1:=1 to n do
    for y1:=1 to m do
      if p[x1,y1]<>0 then
      begin
        if p[x1-1,y1]<>0 then fi[x1,y1,x1-1,y1]:=1;
        if p[x1+1,y1]<>0 then fi[x1,y1,x1+1,y1]:=1;
        if p[x1,y1-1]<>0 then fi[x1,y1,x1,y1-1]:=1;
        if p[x1,y1+1]<>0 then fi[x1,y1,x1,y1+1]:=1;
      end;
  for x1:=1 to n do
    for y1:=1 to m do
      if p[x1,y1]<>0 then
        for x2:=1 to n do
          for y2:=1 to m do
            fi[x1,y1,x2,y2]:=find(x1,y1,x2,y2);
  for i:=1 to q do
  begin
    readln(x1,y1,x2,y2,x3,y3);
    if  ((fi[x2,y2,x3,y3]>=10000) or
         (se[x2,y3,x3,y3]>=10000)) then write('-1')
    else
      write(fe(x2,y2,x3,y3,x1,y1));
  end;
end.
























