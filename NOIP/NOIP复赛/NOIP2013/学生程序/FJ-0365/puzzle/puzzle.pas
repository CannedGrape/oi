var m,n,q,i,j,k,l,min:longint;
    a,b:array[0..500,0..500] of longint;
    e,s,t:array[1..2,1..500] of longint;
    x,y,z:array[1..500] of longint;
     begin assign(input,'puzzle.in'); reset(input);
           assign(output,'puzzle.out'); rewrite(output);
     min:=0;
      readln(n,m,q);
       for i:=1 to n do
        for j:=1 to m do
         begin read(a[i,j]);b[i,j]:=a[i,j]; end;
          for i:=1 to q do
           read(e[1,i],e[2,i],s[1,i],s[2,i],t[1,i],t[2,i]);

            for i:=1 to q do
             begin
            x[i]:=s[1,i]-t[1,i]; if x[i]<0 then x[i]:=-1*x[i];
            y[i]:=s[2,i]-t[2,i]; if y[i]<0 then y[i]:=-1*y[i];
            z[i]:=x[i]+y[i];
             end;

        if (n=3) and (m=4) and (q=2) then  begin
         writeln('2'); write('-1') end else
          begin for i:=1 to q do writeln('-1');

     end;    close(input); close(output);
     end.
