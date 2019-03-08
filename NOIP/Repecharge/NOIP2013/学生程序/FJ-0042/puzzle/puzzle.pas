type qq= record
        rc,ru,dc,du,z:longint;
end;
var n,m,q,i,j,temx,temy,EX,EY,SX,SY,TX,TY,head,tail,wx,wy:longint;
flag:boolean;
h:array[1..1000000] of qq;
a:array[1..30,1..30] of 0..1;
d:array[1..4] of -1..1=(-1,0,1,0);
f:array[1..4] of -1..1=(0,-1,0,1);
g:array[1..30,1..30,1..30,1..30] of boolean;
begin
        assign(input,'puzzle.in');reset(input);
        assign(output,'puzzle.out');rewrite(output);
        read(n,m,q);
        for i:=1 to n do
                for j:=1 to m do
                        read(a[i,j]);
        for q:=1 to q do
                begin
                        read(EX,EY,SX,SY,TX,TY);
                        fillchar(g,sizeof(g),false);
                        head:=0;
                        tail:=1;
                        flag:=false;
                        h[tail].rc:=EX;
                        h[tail].ru:=EY;
                        h[tail].dc:=SX;
                        h[tail].du:=SY;
                        g[EX,EY,SX,SY]:=true;
                        h[tail].z:=0;
                        while(head<>tail) do
                        begin
                                inc(head);
                                for i:=1 to 4 do
                                begin
                                        temx:=h[head].rc+d[i];
                                        temy:=h[head].ru+f[i];
                                        if (temx in [1..n]) and (temy in [1..m]) then
                                        begin
                                                if (temx=h[head].dc) and (temy=h[head].du) then
                                                begin
                                                        wx:=h[head].rc;
                                                        wy:=h[head].ru;
                                                end else
                                                begin
                                                        wx:=h[head].dc;
                                                        wy:=h[head].du;
                                                end;
                                                if a[temx,temy]=1 then
                                                begin
                                                        if g[temx,temy,wx,wy]=false then
                                                        begin
                                                                inc(tail);
                                                                h[tail].rc:=temx;
                                                                h[tail].ru:=temy;
                                                                h[tail].z:=h[head].z+1;
                                                                h[tail].dc:=wx;
                                                                h[tail].du:=wy;
                                                                g[temx,temy,Wx,wy]:=true;
                                                                if(wx=TX)and(wy=TY)then
                                                                begin
                                                                        flag:=true;
                                                                        writeln(h[tail].z);
                                                                        break;
                                                                end;
                                                        end;
                                                end;
                                        end;
                                end;
                                if flag then break;
                        end;
                        if not flag then writeln(-1);
                end;
        close(input);close(output);
end.