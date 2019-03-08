const dx : array[1..4] of integer=(0,0,1,-1);
      dy : array[1..4] of integer=(1,-1,0,0);
var m, n, i, q, j: integer;
    map : array[1..30, 1..30] of integer;
    a : array[1..90000] of record
                           e1, e2, s1, s2 : integer;
                           t :longint;
                         end;
function visited(u1, u2, u3, u4, b : integer) : boolean;
var l : integer;
begin
    visited := false;
    for l := 1 to b - 1 do
        if (a[l].e1 = u1)and(a[l].e2 = u2)and(a[l].s1 = u3)and(a[l].s2 = u4)then
        visited := true;
end;


procedure search;
var  ex, ey, sx, sy, tx, ty, x1, y1, x2, y2 : integer;
     flag : boolean;
     k, head, tail : longint;
begin
    for k := 1 to 90000 do a[k].t := 0;
    flag := false;
    readln(ex, ey, sx, sy, tx, ty);
    head := 0; tail :=1;
    a[tail].e1 := ex;
    a[tail].e2 := ey;
    a[tail].s1 := sx;
    a[tail].s2 := sy;
    a[tail].t := 0;
    while (head < tail) and (not flag) do
    begin
        inc(head);
        for k := 1 to 4 do
        begin
            x1 := a[head].e1 + dx[k];
            y1 := a[head].e2 + dy[k];
            x2 := a[head].s1;
            y2 := a[head].s2;
            if (x1 <= n)and(x1 > 0)and(y1 > 0)and(y1 <= m)and(map[x1,y1] = 1)then
            begin
                if (x1 = x2) and ( y1= y2) then
                begin
                    x2 := a[head].e1;
                    y2 := a[head].e2;
                end;
                if (not visited(x1, y1, x2, y2, tail))then
                begin
                    inc(tail);
                    a[tail].e1 := x1;
                    a[tail].e2 := y1;
                    a[tail].s1 := x2;
                    a[tail].s2 := y2;
                    a[tail].t := a[head].t + 1;
                    if  (x2 = tx) and (y2 = ty) then
                    begin
                        writeln(a[tail].t);
                        flag := true;
                        break;
                    end;
                end;
            end;
        end;
    end;
    if not flag then writeln(-1);
end;


begin
    assign(input,'puzzle.in'); reset(input);
    assign(output,'puzzle.out'); rewrite(output);
    readln(n, m, q);
    for i := 1 to n do
        begin
            for j := 1 to m do read(map[i, j]);
            readln;
        end;
    for i := 1 to q do search;
    close(input); close(output);
end.






