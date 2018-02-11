program level;
var a:array[1..1000] of longint;
    b:array[1..1000] of string;
    x,z,n,m,b1,b2,i,t,max,min:longint;
    w:char;
    t1:boolean;
procedure go(l,r:longint);
var i,j:longint;
    x,y:string;
begin
  i:=l;
  j:=r;
  x:=b[(l+r) div 2];
  repeat
    while (length(b[i])>length(x)) or ((length(b[i])=length(x)) and (b[i]>x)) do inc(i);
    while (length(b[j])<length(x)) or ((length(b[j])=length(x)) and (b[j]<x)) do dec(j);
    if not(i>j) then
      begin
        y:=b[i];
        b[i]:=b[j];
        b[j]:=y;
        inc(i);
        dec(j);
      end;
  until i>j;
  if l<j then go(l,j);
  if i<r then go(i,r);
end;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
    readln(n,m);
    for i:=1 to m do
      begin
        read(x);
        readln(b[i]);
        b[i]:=b[i]+' ';
      end;
    go(1,m);
    z:=1;
    for i:=1 to m do
      begin
        t1:=true;
        b1:=2;
        b2:=length(b[i]);
        while b1<=b2 do
          begin
            if (b[i][b1]>='0') and (b[i][b1]<='9') then
              begin
                w:=b[i][b1];
                t:=t*10+ord(w)-48;
              end
            else
              begin
                if a[t]=0 then begin t1:=false; break; end;
                t:=0;
              end;
            inc(b1);
          end;
        if t1=false then
          while b1<=b2 do
          begin
            if (b[i][b1]>='0') and (b[i][b1]<='9') then
              begin
                w:=b[i][b1];
                t:=t*10+ord(w)-48;
              end
            else
              begin
                inc(a[t]);
                t:=0;
              end;
            inc(b1);
          end;
      end;
    min:=maxlongint;
    max:=-maxlongint;
    for i:=1 to n do
      begin
        if a[i]<min then min:=a[i];
        if a[i]>max then max:=a[i];
      end;
    write(max-min+1);
  close(input);
  close(output);
end.
