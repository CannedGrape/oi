var n,m,q,i,j,p,total:longint;
    lu:array[1..10000,1..10000] of longint;
    a,b,c:array[1..50000] of longint;
    x,y:array[1..100000] of longint;


  procedure max(o,z:longint);
      var t:longint;
       begin

        if o=z then if total<p then begin
          total:=p;exit;end;



           for t:=1 to n do
            if lu[o,t]>0 then
             begin
              if lu[o,t]<p then p:=lu[o,t];
              max(t,z);

             end;

         if total>300000 then writeln('-1') else writeln(total);
       end;


  begin
   assign(input,'truck.in');reset(input);
   assign(output,'truck.out');rewrite(output);
    read(n);readln(m);
     for i:=1 to m do
      begin
       read(a[i]);read(b[i]);read(c[i]);readln;
      end;
    readln(q);
     for i:= 1 to q do
      begin
       read(x[i]);read(y[i]);readln;
      end;

      fillchar(lu,sizeof(lu),0);
     for i:= 1 to m do
      if c[i]>lu[a[i],b[i]] then
       begin
        if c[i]>lu[b[i],a[i]] then
         begin
          lu[a[i],b[i]]:=c[i];
          lu[b[i],a[i]]:=c[i];
         end else lu[a[i],b[i]]:=lu[b[i],a[i]];
       end;


      for i:= 1 to q do
      begin
       if lu[x[i],y[i]]>0 then p:=lu[x[i],y[i]] else p:=300000;

       total:=0;
       max(x[i],y[i]);
      end;
    close(input);close(output);

   end.


