program expr;
var
  i,j,wei,code,p,q,di,dj:longint;
  a,x,y:string;
  l:array[0..5]of char;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(a);
  while(1=1)do
  begin
    wei:=pos('*',a);
    if wei=0 then break;
    for i:=wei-1 downto 1 do
    begin
      if (a[i]='+') then break;
    end;
    if a[i]='+' then inc(i);
    x:=copy(a,i,wei-i);
   // writeln(x);
    if length(x)>5 then
    begin
      delete(x,1,length(x)-5);
    end;

    val(x,p,code);
    di:=i;
    for i:=wei+1 to length(a) do
    begin
      if (ord(a[i])<46) then break;
    end;
    if (ord(a[i])<46) then dec(i);
    y:=copy(a,wei+1,i-wei);
  // writeln(y);
    if length(y)>5 then
    begin
      delete(y,1,length(y)-5);
    end;

    val(y,q,code);
    dj:=i;
    delete(a,di,dj-di+1);
 //   writeln(di,' ',dj);
   // writeln(a);
    p:=p*q;
    str(p,x);
   // writeln(x);
    insert(x,a,di);
  end;
  //writeln(a);
  while(1=1)do
  begin
    wei:=pos('+',a);
    if wei=0 then break;
    for i:=wei-1 downto 1  do
    begin
      if a[i]='+' then break;
    end;
    if a[i]='+' then inc(i);
    x:=copy(a,i,wei-i);
   // writeln(x);
    if length(x)>5 then
    begin
      delete(x,1,length(x)-5);
    end;
    val(x,p,code);
    di:=i;
    for i:=wei+1 to length(a) do
    begin
      if (ord(a[i])<46) then break;
    end;
    if (ord(a[i])<46) then dec(i);
    y:=copy(a,wei+1,i-wei);
  // writeln(y);
    if length(y)>5 then
    begin
      delete(y,1,length(y)-5);
    end;
    val(y,q,code);
    dj:=i;
    delete(a,di,dj-di+1);
    p:=p+q;
    str(p,x);
   // writeln(x);
    insert(x,a,di);
  end;
  j:=4;
  x:=copy(a,length(a)-j+1,length(a));
  for i:=1 to length(x) do
  begin
    if (x[i]<>'0')then break;
  end;
  for j:=i to length(x) do
  begin
    write(x[j]);
  end;
  close(input);
  close(output);
end.
