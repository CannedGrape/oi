type zuhe=record
          up:longint;
          down:longint;
     end;
var input,output:text;
    time, n:longint;
    line1,line2:array[1..1000000] of longint;
    start:array[1..1000000] of zuhe;
procedure qs1(var l,h:longint);
 var m,t,i,j:longint;
 begin
  i:=l;j:=h;
  m:=line1[(i+j) div 2];
  repeat
   while line1[i]<m do inc(i);
   while line1[j]>m do dec(j);
   if i<=j then begin
    t:=line1[i];line1[i]:=line1[j];line1[j]:=t;
    inc(i);dec(j);
   end;
  until i>j;
  if i<h then qs1(i,h);
  if l<j then qs1(l,j);
 end;

procedure qs2(var l2,h2:longint);
 var m2,t2,i2,j2:longint;
 begin
  i2:=l2;j2:=h2;
  m2:=line2[(i2+j2) div 2];
  repeat
   while line2[i2]<m2 do inc(i2);
   while line2[j2]>m2 do dec(j2);
   if i2<=j2 then begin
    t2:=line2[i2];line2[i2]:=line2[j2];line2[j2]:=t2;
    inc(i2);dec(j2);
   end;
  until i2>j2;
  if i2<h2 then qs2(i2,h2);
  if l2<j2 then qs2(l2,j2);
 end;

procedure putin;
 var p:integer;
begin
 readln(input,n);
 for p:=1 to n do read(input,line1[p]);
 readln(input);
 for p:=1 to n do read(input,line2[p]);
end;

procedure main;
 var zuo,you,canshu1,canshu2,dif:longint;
     ok:boolean;
begin
 dif:=n;
 for canshu1:=1 to n do begin
  start[canshu1].up:=line1[canshu1];
  start[canshu1].down:=line2[canshu1];
 end;
 zuo:=1;you:=n;
 qs1(zuo,you);
 qs2(zuo,you);
 for canshu1:=1 to n do begin
  canshu2:=0;
  ok:=false;
  repeat
   inc(canshu2);
   if ((line1[canshu1]=start[canshu2].up) and (line2[canshu1]=start[canshu2].down)) then begin
    dec(dif);
    ok:=true;
   end;
  until (ok or (canshu2=n));
 end;
 if (dif mod 2=1) then time:=((dif+1)div 2) mod 99999997 else time:=(dif div 2) mod 99999997;
end;

procedure putout;
begin
 writeln(output,time);
end;

begin
 assign(input,'e:\FJ-0381\match\match.in');
 assign(output,'e:\FJ-0381\match\match.out');
 reset(input);
 rewrite(output);
 putin;
 main;
 putout;
 close(input);
 close(output);
end.
