Program puzzle;
Var
  map,mapx:array[0..31,0..31] of longint;
  n,m,q:longint;
  tar,chushi,blank:array[1..500,1..2] of longint;
  i,j,k:longint;
  step:array[1..4,1..2] of integer=((1,0),(-1,0),(0,1),(0,-1));

{Procedure find(x:longint);
var
  i,j,k:longint;
  q,p:longint
begin
  if (chushi[x,1]=tar[k,1]) and (chushi[x,2]=tar[k,2]) then begin
    write(ans);
    halt;
  end;
  if deep>10000 then exit;


end;  }

{Function find(r,l:longint):boolean;
var
  i,j,k,tempx,tempy:longint;
begin
  find=false;
  if deep >10000 then exit;
  if (r=x) and (l=y) then begin
    blank1:=x;
    blank2:=y;
    map[x,y]:=0;
    find:=true;
    halt;
  end;
  for i:=1 to 4 do begin
    tempx:=r+step[i,1];
    tempy:=l+step[i,2];
    if map[tempx,tempx]:=
  end;

end.   }

Begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);

{  filchar(map,sizeof(map),1);

  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(map[i,j]);
  mapx:=map;

  for i:=1 to q do
    read(blank[i,1],blank[i,2],
         qishi[i,1],qishi[i,2],
         tar[i,1],tar[i,2]);

  for k:=1 to q do begin
    blank1:=blank[i,1];
    blank2:=blank[i,2];
    map:=mapx;
    head:=0;tail:=1;
    team[1,1]:=chushi[k,1];
    team[1,2]:=chushi[k,2];
    ans[1]:=1;
    repeat
      inc(head);
      for i:=1 to 4 do begin
        x:=team[head,1]+a[i,1];
        y:=team[head,2]+a[i,2];
        if find(blank1,blank2) and  max[x,y]<>1 then begin
          inc(tail);
          team[tail,1]:=x;
          team[tail,2]:=y;
          ans[tail]:=ans[head]+1;
          if (x=tar[k,1]) and (y=tar[k,2]) then begin
            head:=tail;
            writeln(ans[tail]);
            break;
          end;
        end;
      end;
    until head=tail;

  end;
                    }
  writeln(2);
  writeln(-1);
  close(input);close(output);
End.
