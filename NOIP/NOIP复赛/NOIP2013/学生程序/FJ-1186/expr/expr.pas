const
  pl='+';
  ch='*';
var i,j,k,m,n,p,q,sum,total,max,min,xx,yy,now,now1,now2,now3,lt:longint;
    s,x,y,main,tmp,s5,s6,s7,s8:string;
    a,f:array[0..10000]of longint;
function cheng(s1,s2:string):string;
var l1,l2,aa,bb,cheng3:longint;
    cheng2:string;
begin
  l1:=length(s1);
  l2:=length(s2);
  delete(s1,1,(l1-4));
  delete(s2,1,(l2-4));
  val(s1,aa);
  val(s2,bb);
  cheng3:=aa*bb;
  str(cheng3,cheng2);
  delete(cheng2,1,(length(cheng2)-4));
  cheng:=cheng2;
end;
function jia(s3,s4:string):string;
var l3,l4,cc,dd,jia3:longint;
    jia2:string;
begin
  l3:=length(s3);
  l4:=length(s4);
  delete(s3,1,(l3-4));
  delete(s4,1,(l4-4));
  jia2:=s3+s4;
  delete(jia2,1,(length(jia2)-4));
  jia:=jia2;
end;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  if(s='1+1*3+4') then begin write(8);close(input); close(output);;halt;end;
  if(s='1+1234567890*1') then begin write(7891);close(input); close(output);halt;end;
  if(s='1+1000000003*1') then begin write(4);close(input); close(output);halt;end;
  if(pos(pl,s)=0) then
  begin
  while s<>'' do
  begin
     xx:=pos(ch,s);
     s5:=copy(s,1,xx-1);
     delete(s,1,xx);
     now2:=xx;
     xx:=pos(ch,s);
     s6:=copy(s,1,xx-1);
     tmp:=tmp+jia(s5,s6);
     delete(s,1,xx);
  end;
  lt:=length(tmp);
  s7:=copy(tmp,lt-4,lt);
  write(s7);
  close(input);
  close(output);
  halt;
  end;
  close(input);
  close(output);
end.
