type ttt=array[0..100,0..100]of longint;

var n,m,q,a,b:longint;
    map:ttt;
    arr:array[0..31,0..31,0..31,0..31]of boolean;

procedure swap(var a,b:longint);
var k:longint;
begin
 k:=a;a:=b;b:=k;
end;

procedure work;
var a,b,tarx,tary,head,tail:longint;
    q:array[0..100000]of record
     spacex,spacey,posx,posy,time:longint; end; //x~n y~m
begin
 fillchar(arr,sizeof(arr),0);
 q[0].time:=0;
 with q[0] do
  begin
   read(spacex,spacey,posx,posy,tarx,tary);
   arr[spacex,spacey,posx,posy]:=true;
  end;
 head:=0;tail:=0;
 while head<=tail do with q[head mod 100000] do
  begin
   if (posx=tarx)and(posy=tary) then
    begin
     writeln(time);exit;
    end;

   if map[spacex+1,spacey]=1 then //spacex-->spacex+1,spacey-->spacey
    begin
     if (posx=spacex+1)and(posy=spacey) then //posx-->spacex,posy-->spacey
      begin
       if not arr[spacex+1,spacey,spacex,spacey] then
        begin
         arr[spacex+1,spacey,spacex,spacey]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex+1;
           spacey:=q[head mod 100000].spacey;
           posx:=q[head mod 100000].spacex;
           posy:=q[head mod 100000].spacey;
          end;
        end;
      end
     else
      begin
       if not arr[spacex+1,spacey,posx,posy] then
        begin
         arr[spacex+1,spacey,posx,posy]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex+1;
           spacey:=q[head mod 100000].spacey;
           posx:=q[head mod 100000].posx;
           posy:=q[head mod 100000].posy;
          end;
        end;
      end;
    end;
///////////////////////////////////////////////////
   if map[spacex-1,spacey]=1 then //spacex-->spacex-1,spacey-->spacey
    begin
     if (posx=spacex-1)and(posy=spacey) then //posx-->spacex,posy-->spacey
      begin
       if not arr[spacex-1,spacey,spacex,spacey] then
        begin
         arr[spacex-1,spacey,spacex,spacey]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex-1;
           spacey:=q[head mod 100000].spacey;
           posx:=q[head mod 100000].spacex;
           posy:=q[head mod 100000].spacey;
          end;
        end;
      end
     else
      begin
       if not arr[spacex-1,spacey,posx,posy] then
        begin
         arr[spacex-1,spacey,posx,posy]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex-1;
           spacey:=q[head mod 100000].spacey;
           posx:=q[head mod 100000].posx;
           posy:=q[head mod 100000].posy;
          end;
        end;
      end;
    end;
///////////////////////////////////////////////////
   if map[spacex,spacey+1]=1 then //spacex-->spacex,spacey-->spacey+1
    begin
     if (posx=spacex)and(posy=spacey+1) then //posx-->spacex,posy-->spacey
      begin
       if not arr[spacex,spacey+1,spacex,spacey] then
        begin
         arr[spacex,spacey+1,spacex,spacey]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex;
           spacey:=q[head mod 100000].spacey+1;
           posx:=q[head mod 100000].spacex;
           posy:=q[head mod 100000].spacey;
          end;
        end;
      end
     else
      begin
       if not arr[spacex,spacey+1,posx,posy] then
        begin
         arr[spacex,spacey+1,posx,posy]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex;
           spacey:=q[head mod 100000].spacey+1;
           posx:=q[head mod 100000].posx;
           posy:=q[head mod 100000].posy;
          end;
        end;
      end;
    end;
///////////////////////////////////////////////////
   if map[spacex,spacey-1]=1 then //spacex-->spacex,spacey-->spacey-1
    begin
     if (posx=spacex)and(posy=spacey-1) then //posx-->spacex,posy-->spacey
      begin
       if not arr[spacex,spacey-1,spacex,spacey] then
        begin
         arr[spacex,spacey-1,spacex,spacey]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex;
           spacey:=q[head mod 100000].spacey-1;
           posx:=q[head mod 100000].spacex;
           posy:=q[head mod 100000].spacey;
          end;
        end;
      end
     else
      begin
       if not arr[spacex,spacey-1,posx,posy] then
        begin
         arr[spacex,spacey-1,posx,posy]:=true;
         inc(tail);
         with q[tail mod 100000] do
          begin
           time:=q[head mod 100000].time+1;
           spacex:=q[head mod 100000].spacex;
           spacey:=q[head mod 100000].spacey-1;
           posx:=q[head mod 100000].posx;
           posy:=q[head mod 100000].posy;
          end;
        end;
      end;
    end;
///////////////////////////////////////////////////
   inc(head);
  end;
 writeln(-1);
end;

begin
 assign(input,'puzzle.in');
 assign(output,'puzzle.out');
 reset(input);
 rewrite(output);
 read(n,m,q);
 for a:=1 to n do
  for b:=1 to m do
   read(map[a,b]);
 for a:=1 to q do work;
 close(input);
 close(output);
end.
