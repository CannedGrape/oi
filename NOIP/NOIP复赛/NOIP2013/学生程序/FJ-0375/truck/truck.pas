var i,j,s,t,k,n,m,p:longint;
    head,en:array[1..10000] of longint;
    x,y,z:array[1..10000] of longint;
    min:array[1..10000] of longint;
begin
    assign(input,'truck.in'); reset(input);
    assign(output,'truck.out'); rewrite(output);
    readln(n,m);
    fillchar(min,sizeof(min),$7);
    for i:=1 to m do
     read(x[i],y[i],z[i]);
    readln(p);
    for i:=1 to p do
     read(head[i],en[i]);
    for i:=1 to p do
     begin
       for j:=1 to m do
        if (x[j]=head[i]) or (x[j]=en[i]) or  (y[j]=head[i]) or (y[j]=en[i])
         then
          begin
            if min[i]>z[j] then min[i]:=z[j];
            end
            else min[i]:=-1;
         end;
     for i:=1 to p do
     writeln(min[i]);

    close(input); close(output);
    end.
