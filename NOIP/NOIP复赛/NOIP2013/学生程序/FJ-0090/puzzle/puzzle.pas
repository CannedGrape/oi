program ywt52;
  const dx:array[1..4] of longint=(1,-1,0,0);
        dy:array[1..4] of longint=(0,0,1,-1);
  var used:array[-1..35,-1..35,-1..35,-1..35] of boolean;
      map:array[-1..35,-1..35] of longint;
      t:array[1..1000000,1..5] of longint;
      n,m,q,endx,endy,ans,top,tail:longint;
procedure add(a,b,c,d,e:longint);
  begin
    inc(tail);
    t[tail,1]:=a;
    t[tail,2]:=b;
    t[tail,3]:=c;
    t[tail,4]:=d;
    t[tail,5]:=e;
  end;
procedure bfs;
  var i,j,x1,x2,y1,y2,step,x,y:longint; check:boolean;
  begin
    top:=0; tail:=1; check:=false; ans:=0;
    repeat
      inc(top);
      x1:=t[top,1]; y1:=t[top,2]; x2:=t[top,3]; y2:=t[top,4]; step:=t[top,5];
      for i:=1 to 4 do
        begin
          x:=x1+dx[i]; y:=y1+dy[i];
          if map[x,y]=1 then
            begin
              if (x=x2) and (y=y2) and (used[x,y,x1,y1]=false) then
                begin
                  used[x,y,x1,y1]:=true;
                  add(x,y,x1,y1,step+1);
                  if (x1=endx) and (y1=endy) then begin check:=true; ans:=t[tail,5]; end;
                end;
              if not((x=x2) and (y=y2)) and (used[x,y,x2,y2]=false) then
                begin
                  used[x,y,x2,y2]:=true;
                  add(x,y,x2,y2,step+1);
                end;
            end;
        end;
      if check then exit;
    until top>=tail;
    ans:=-1;
  end;
procedure init;
  var i,j:longint;
  begin
    readln(n,m,q);
    fillchar(map,sizeof(map),0);
    for i:=1 to n do
      for j:=1 to m do
        read(map[i,j]);
  end;
procedure main;
  var i,j,x1,x2,y1,y2:longint;
  begin
    for i:=1 to q do
      begin
        fillchar(t,sizeof(t),0);
        readln(t[1,1],t[1,2],t[1,3],t[1,4],endx,endy);
        fillchar(used,sizeof(used),false);
        t[1,5]:=0; used[t[1,1],t[1,2],t[1,3],t[1,4]]:=true;
        bfs;
        writeln(ans);
      end;
  end;
  begin
    assign(input,'puzzle.in'); reset(input);
    assign(output,'puzzle.out'); rewrite(output);
    init;
    main;
    close(input);
    close(output);
  end.
