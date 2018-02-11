var
  n,i:longint;
  flower:array[1..100000] of longint;
  flag:array[1..100000] of boolean;

function isok(flag:array of boolean):boolean;
var
  i,k:integer;
  tmp:array[1..100000] of longint;
begin
  fillchar(tmp,sizeof(tmp),0);
  k:=0;
  for i:=1 to n do
    if flag[i] then begin
      inc(k);
      tmp[k]:=flower[i];
    end;

  if k mod 2 = 0 then begin
    isok:=false;
    exit;
  end;

  isok:=true;

  for i:=1 to k div 2 do begin
    if not (((tmp[2*i]>tmp[2*i-1])and(tmp[2*i]>tmp[2*i+1])) or
       ((tmp[2*i]<tmp[2*i-1])and(tmp[2*i]<tmp[2*i+1]))) then
    begin
      isok:=false;
      exit;
    end;
  end;
end;


function dfs( tt,t:longint; flag:array of boolean):boolean;
var
  i:longint;

begin

  if t = tt then begin
    dfs:=isok(flag);
  end else
    for i:=1 to n do begin
      if flag[i] then begin
        flag[i]:=false;
        dfs:=dfs(tt,t+1,flag);
        flag[i]:=true;
        if dfs then exit;
      end;
    end;
end;

begin

  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);

  readln(n);
  for i:=1 to n do read( flower[i] );

  for i:=0 to n do begin
    fillchar(flag,sizeof(flag),true);
    if dfs(i,0,flag) then begin
      writeln(n-i);
      break;
    end;
  end;

  close(input);
  close(output);

end.
