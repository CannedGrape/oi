Program truck;
Var road:array[0..100001,1..3]of longint;
    be,tail:array[0..10001]of longint;
    next:array[0..100001]of longint;
    judge:array[0..10001]of boolean;
    dl:array[0..1000001]of longint;
    i,n,m,q,max,min,tarx,tary,z,num:longint;

function bfs(x,y,limit:longint):boolean;
var head,tail,ty,temp:longint;
begin
    head:=0;  tail:=1;
    fillchar(judge,sizeof(judge),true);
    dl[1]:=x;  judge[x]:=false;
    repeat
        inc(head);  head:=head mod 1000000;
        temp:=be[dl[head]];
        while temp<>0 do
        begin
            if road[temp,3]<limit then
            begin
                temp:=next[temp];
                continue;
            end;

            ty:=road[temp,2];
            if judge[ty] then
            begin
                inc(tail);  tail:=tail mod 1000000;
                dl[tail]:=ty;
                judge[ty]:=false;
                if ty=y then
                begin
                    bfs:=true;  exit;
                end;
            end;
            temp:=next[temp];
        end;
    until head=tail;
    bfs:=false;  exit;
end;


function divide(l,r:longint):longint;
var mid:longint;
begin
    if l=r then
    begin
        divide:=l;  exit;
    end;

    if l+1=r then
    begin
        divide:=l;  exit;
    end;

    mid:=(l+r)shr 1;

    if bfs(tarx,tary,mid) then
        divide:=divide(mid,r) else
        divide:=divide(l,mid);
end;


Begin
    assign(input,'truck.in');  reset(input);
    assign(output,'truck.out');  rewrite(output);

    readln(n,m);  num:=0;  min:=maxlongint;  max:=-maxlongint;

    for i:=1 to n do be[i]:=0;

    for i:=1 to m do
    begin
        readln(tarx,tary,z);

        if min>z then min:=z;  if max<z then max:=z;

        inc(num);
        if be[tarx]=0 then
        begin
            be[tarx]:=num;
            next[num]:=0;
            tail[tarx]:=num;
        end else
        begin
            next[tail[tarx]]:=num;
            tail[tarx]:=num;
        end;

        road[num,1]:=tarx;  road[num,2]:=tary;  road[num,3]:=z;

        inc(num);
        if be[tary]=0 then
        begin
            be[tary]:=num;
            tail[tary]:=num;
            next[num]:=0;
        end else
        begin
            next[tail[tary]]:=num;
            tail[tary]:=num;
        end;

        road[num,1]:=tary;  road[num,2]:=tarx;  road[num,3]:=z;
    end;

    readln(q);

    for i:=1 to q do
    begin
        readln(tarx,tary);
        if not bfs(tarx,tary,min) then
        begin
            writeln('-1');
            continue;
        end;
        writeln(divide(min,max+1));
    end;

    close(input);
    close(output);
End.
