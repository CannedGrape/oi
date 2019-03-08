program truck;
var a,n,i:integer;
    m,k,q,j,l,h,ll:longint;
    t,u,bj,x,y,z:array[1..20000] of longint;
    xs,ys:array[1..50000] of longint;
    begin
    assign(input,'truck.in');reset(input);
    assign(output,'truck.out');rewrite(output);
    read(n,m);
    l:=m;
    for i:=1 to m do
    begin
      read(x[i],y[i],z[i]);
     t[i]:=x[i];
     u[i]:=y[i];
     end;
    for i:=1 to m do
     for j:=1 to m do
      if (x[i]=y[j])and(x[j]=y[i]) then if z[i]>=z[j] then
      begin
      x[j]:=0;y[j]:=0;z[j]:=0;
      end

     else
      begin
      x[i]:=0;y[i]:=0;z[i]:=0;
      end;
    read(q);
    for i:=1 to q do
    begin
    read(xs[i]);
    readln(ys[i]);
    end;
    for i:=1 to m do
     for j:=1 to m do
      begin
       if x[i]=y[j] then begin
        inc(l);
        x[l]:=x[j];
        y[l]:=y[i];
         if z[j]>=z[i] then z[l]:=z[i] else z[l]:=z[j];
       for k:=1 to m do
        if ((x[k]=x[l])and(y[k]=y[l])) or ((x[k]=y[l])and(y[k]=x[l])) then
         if z[k]>=z[l] then z[l]:=z[k] else z[k]:=z[l];
         end;
         if x[i]=t[j] then begin
        inc(l);
        x[l]:=x[j];
        y[l]:=t[i];
         if z[j]>=z[i] then z[l]:=z[i] else z[l]:=z[j];end;
       for k:=1 to m do
        if ((x[k]=x[l])and(y[k]=y[l])) or ((x[k]=y[l])and(y[k]=x[l])) then
         if z[k]>=z[l] then z[l]:=z[k] else z[k]:=z[l];
        end;
        ll:=l;
        for i:=1 to ll do
         for j:=1 to ll do
          begin
           if (x[i]=x[j]) and (y[i]=y[j]) then if z[i]>=z[j] then
           begin
           x[j]:=0;y[j]:=0;z[j]:=0;
           end
     else begin
           x[i]:=0;y[i]:=0;z[i]:=0;
           end;
           end;
        for i:=1 to ll do
         for j:=1 to ll do
          begin
           if (x[i]=y[j]) and (x[j]=y[i]) then if z[i]>=z[j] then
           begin
           x[j]:=0;y[j]:=0;z[j]:=0;
           end
     else begin
           x[i]:=0;y[i]:=0;z[i]:=0;
           end;
     end;
     for i:=1 to ll do
      for j:=1 to ll do
       if (x[i]=t[j]) and (y[i]=u[j]) then if z[i]>=z[j] then begin
        x[j]:=0;y[j]:=0;z[j]:=0;
         end
         else begin
          x[i]:=0;y[i]:=0;z[i]:=0;
           end;
    for i:=1 to q do
     for j:=1 to ll do
     begin
      if ((xs[i]=x[j]) and (y[j]=ys[i])) or ((xs[i]=y[j]) and (ys[i]=x[j]))
       then bj[i]:=z[j];
         for k:=1 to q do
      begin
      l:=k;
       for h:=(k+1) to ll do if bj[l]<bj[h] then l:=h;
       a:=bj[k];bj[k]:=bj[l];bj[l]:=a;
      end;
    if bj[1]>0 then writeln(bj[1]) else writeln('-1');
    end;
    close(input);close(output);
    end.






