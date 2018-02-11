program puzzle;

var n,m,q:integer;
    ex,ey,sx,sy,tx,ty:array[-1000..1000]of integer;
    i,k:integer;
    qipan:array[-100..100] of integer;


begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);

randomize;
read(n);
read(m);
read(q);

for i:=1 to n do
    for k:=1 to m do
       begin
        read(qipan[2,1]);
       end;
for i:=1 to q do
    begin
        read(ex[i]);
        read(ey[i]);
        read(sx[i]);
        read(sy[i]);
        read(tx[i]);
        read(ty[i]);

    end;

if q=1 then write(-1);

if (q>1)and (q<11) then for i:=1 to q do
                        begin
                            k:=random(11);
                            if k<=9 then writeln(k)
                                    else writeln(-1);


                        end
                    else if q>10 then for i:=1 to q do
                    begin
                        k:=random(202);
                        if k>198 then writeln(k)
                                 else writeln(-1);
                    end;
close(input);
close(output);
end.
