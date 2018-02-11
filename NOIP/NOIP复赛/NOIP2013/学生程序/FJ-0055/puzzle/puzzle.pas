type arr=record
      dep,x1,x2,y1,y2:longint;
     end;
var n,m,q,head,tail,x,y:longint;
    data:array[1..100000]of arr;
    map:array[1..30,1..30]of longint;
    f:boolean;

procedure fopen;
begin
 assign(input,'puzzle.in');
 assign(output,'puzzle.out');
 reset(input);
 rewrite(output);
end;
procedure fclose;
begin
 close(input);
 close(output);
end;

function ff(xx1,yy1,xx2,yy2:longint):boolean;
var i:longint;
begin
 for i:=1 to tail do
  with data[i] do
   if(x1=xx1)and(x2=xx2)and(y1=yy1)and(y2=yy2)then
     exit(false);
end;

procedure expand(i:longint);
var ar:arr;
    d,xx1,yy1,xx2,yy2:longint;
begin
 with data[i] do
  begin
   d:=dep;xx1:=x1;yy1:=y1;xx2:=x2;yy2:=y2;
   if(xx2=x)and(yy2=y)then
    begin
     f:=true;
     writeln(dep);
    end
   else begin
    if(xx1<n)and(map[xx1+1,yy1]=1)then
     begin
      inc(xx1);
      if(xx1=xx2)and(yy1=yy2)then
       begin
        xx2:=xx1-1;
        yy2:=yy1;
       end;
      if ff(xx1,yy1,xx2,yy2) then
       begin
        inc(tail);
        data[tail].dep:=d+1;
        data[tail].x1:=xx1;
        data[tail].x2:=xx2;
        data[tail].y1:=yy1;
        data[tail].y2:=yy2;
       end;
      xx1:=x1;yy1:=y1;xx2:=x2;yy2:=y2;
     end;
    if(xx1>1)and(map[xx1-1,yy1]=1)then
     begin
      if true then write('');
      dec(xx1);
      if(xx1=xx2)and(yy1=yy2)then
       begin
        xx2:=xx1+1;
        yy2:=yy1;
       end;
      if ff(xx1,yy1,xx2,yy2) then
       begin
        inc(tail);
        data[tail].dep:=d+1;
        data[tail].x1:=xx1;
        data[tail].x2:=xx2;
        data[tail].y1:=yy1;
        data[tail].y2:=yy2;
       end;
      xx1:=x1;yy1:=y1;xx2:=x2;yy2:=y2;
     end;
    if(yy1<m)and(map[xx1,yy1+1]=1)then
     begin
      inc(yy1);
      if(xx1=xx2)and(yy1=yy2)then
       begin
        xx2:=xx1;
        yy2:=yy1-1;
       end;
      if ff(xx1,yy1,xx2,yy2) then
       begin
        inc(tail);
        data[tail].dep:=d+1;
        data[tail].x1:=xx1;
        data[tail].x2:=xx2;
        data[tail].y1:=yy1;
        data[tail].y2:=yy2;
      xx1:=x1;yy1:=y1;xx2:=x2;yy2:=y2;
     end;
     end;
    if(yy1>1)and(map[xx1,yy1-1]=1)then
     begin
      dec(yy1);
      if(xx1=xx2)and(yy1=yy2)then
       begin
        xx2:=xx1+1;
        yy2:=yy1;
       end;
      if ff(xx1,yy1,xx2,yy2) then
       begin
        inc(tail);
        data[tail].dep:=d+1;
        data[tail].x1:=xx1;
        data[tail].x2:=xx2;
        data[tail].y1:=yy1;
        data[tail].y2:=yy2;
       end;
      xx1:=x1;yy1:=y1;xx2:=x2;yy2:=y2;
     end;
   end;
  end;
end;

procedure init;
var i,j:longint;
begin
 readln(n,m,q);
 for i:=1 to n do
  for j:=1 to m do
   read(map[i,j]);
 data[1].dep:=0;
 for i:=1 to q do
  begin
   head:=0;
   tail:=1;
   f:=false;
   with data[1] do
    readln(x1,y1,x2,y2,x,y);
   repeat
    inc(head);
    expand(head);
   until(head=tail)or f;
   if not(f) then write(-1);
   writeln;
  end;
end;

begin
 fopen;
 init;
 fclose;
end.


