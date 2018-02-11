var a:ansistring;
    i,j,x,y,la,o,ans:longint;
    pp,tt:int64;
    p,t,nn:string;
    op:boolean;
function doit(d:string;q:boolean):int64;
var l,r,i,bb:longint;
begin
  doit:=0;bb:=0;
  if q then
   while d<>''do
     begin
      l:=pos('*',d);if l=0 then break;
      for i:=1 to l-1 do doit:=doit*10+(ord(d[i])-48);
      delete(d,1,l);r:=pos('*',d);
      for i:=1 to r-1 do bb:=bb*10+(ord(d[i])-48);
      doit:=doit*bb;delete(d,1,r);
     end;
   if not q then
    while d<>''do
     begin
      l:=pos('+',d);if l=0 then break;
      for i:=1 to l-1 do doit:=doit*10+(ord(d[i])-48);
      delete(d,1,l);r:=pos('+',d);
      for i:=1 to r-1 do bb:=bb*10+(ord(d[i])-48);
      doit:=doit+bb;delete(d,1,r);
     end;
end;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  read(a);
  la:=length(a);
  for i:=1 to la do
    begin
      x:=pos('*',a);y:=pos('+',a);
      p:=t+copy(a,1,y);
      if i=1 then t:=t+copy(a,y+1,x-y)
        else t:=t+'+'+copy(a,y+1,x-y);
      delete(a,1,x);o:=pos('+',a);
      t:=t+copy(a,1,o-1);delete(a,1,o-1);
      tt:=tt+doit(t,true);
      if a='' then break;
      t:='';
    end;
  pp:=doit(p,false);
  pp:=pp mod 1000;tt:=tt mod 1000;
  ans:=pp+tt;ans:=ans mod 1000;
  for i:=1 to 5 do begin
    nn[i]:=chr(ans mod 10);
    ans:=ans div 10; end;
  op:=true;
  for i:=length(nn) downto 2 do
    if (nn[i]<>'0') and (op) then begin op:=false;write(nn[i]);end;
  close(input);close(output);
end.






