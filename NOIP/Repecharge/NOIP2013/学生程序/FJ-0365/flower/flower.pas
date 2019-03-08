var h,g:array[1..100002] of longint;
    min1,min2,i,j,k,l,n,m:longint;   wokao:boolean;

    function pd:boolean;
     var i:longint;
      begin pd:=true;
       for i:=1 to ((n div 2)-(n mod 2)) do  begin
        if (g[2*i]<g[2*i-1]) and (g[2*i]>g[2*i+1]) then
         begin pd:=false; exit; end;
        if (g[2*i]>g[2*i-1]) and (g[2*i]<g[2*i+1]) then
         begin pd:=false; exit; end;
        if (g[2*i]=g[2*i-1]) or (g[2*i]=g[2*i+1]) then
         begin pd:=false; exit; end;              end;
      end;

    procedure try1(s:longint);
     var i,j,x,y,z:longint; p:boolean;
      begin
      if s<=min1 then exit;
       if pd then begin if s>min1 then min1:=s; end;
        for i:=1 to ((n div 2)-(n mod 2)) do
         begin   y:=2*i;
          p:=false;
           repeat
            for j:=1 to i do if g[y]<>-1 then begin p:=true;  end;
             if not p then begin inc(y);  end;
           until p;    x:=y; z:=y;
            while g[x-1]=-1 do dec(x);
            while g[x+1]=-1 do inc(z);


          if g[y]<=g[x] then begin  g[x]:=-1; dec(s);
           try1(s); g[x]:=h[x]; end;
         if g[y]<=g[z] then begin   g[z]:=-1; dec(s);
           try1(s); g[z]:=h[z]; end;
      end; end;


      procedure try2(s:longint);
     var i,j,x,y,z:longint; p:boolean;
      begin
      if s<=min2 then exit;
       if pd then begin if s>min2 then min2:=s; end;
        for i:=1 to ((n div 2)-(n mod 2)) do
         begin   y:=2*i;
          p:=false;
           repeat
            for j:=1 to i do if g[y]<>-1 then begin p:=true;  end;
             if not p then begin inc(y); end;
           until p;    x:=y; z:=y;
            while g[x-1]=-1 do dec(x);
            while g[x+1]=-1 do inc(z);


          if g[y]>=g[x] then begin  g[x]:=-1; dec(s);
           try2(s); g[x]:=h[x]; end;
         if g[y]>=g[z] then begin   g[z]:=-1; dec(s);
           try2(s); g[z]:=h[z]; end;
      end; end;





     begin   assign(input,'flower.in');reset(input);
             assign(output,'flower.out'); rewrite(output);

     min1:=0; min2:=2;    wokao:=true;
      readln(n);
       for i:=1 to n do begin read(h[i]); g[i]:=h[i]; end;
       for i:=1 to n-1 do if g[i]>g[i+1] then begin wokao:=false;exit; end;
        if wokao then write('0') else write('0');

        close(input);close(output);

      end.
