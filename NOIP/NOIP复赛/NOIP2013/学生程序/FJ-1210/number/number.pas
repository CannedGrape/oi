var i,n,p:longint;x,y,max,max1,max2,tez,fen,num:int64;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
    readln(n,p);
    max:=-maxlongint;y:=0;
    read(x);
    if x<0 then y:=0 else y:=x;
    max:=x;num:=x;max1:=x+x;max2:=y;
    for i:=2 to n do
    begin
      read(x);
      if x>max then max:=x;
      y:=y+x;if y<0 then y:=0;
      if y>max2 then max2:=y;
      if max2=0 then tez:=max else tez:=max2;
      fen:=max1;
      if fen>num then num:=fen;
      if tez+fen>max1 then max1:=tez+fen;
    end;
    if num<0 then write('-');
    writeln((abs(num)) mod p);
  close(input);close(output);
end.
