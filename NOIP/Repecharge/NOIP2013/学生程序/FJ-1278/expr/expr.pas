program expr;
 var a:array[1..100001] of char;
     c,g:char;
     i,j,s,h,x,k:longint;
     y,e:string;
   begin
    assign(input,'expr.in');reset(input);
    assign(output,'expr.out');rewrite(output);
    read(a);
    h:=1;
    c:=' ';
    for i:=1 to 100001 do
       begin
        if a[i]='+' then
           begin
             g:=a[i-1];
              x:=ord(g)-48;
             if (c=' ') and (c='+') then s:=s+x;
             if c='*' then s:=s+k*x;
             c:=a[i];
           end;
         if a[i]='*' then
           begin
            g:=a[i-1];
             if (c=' ') and (c='+') then k:=ord(g)-48;
             if c='*' then
             begin
              x:=ord(g)-48;
              k:=k*x;
             end;
             c:=a[i];
             j:=i;
            end;
        end;
          g:=a[j+1];
          x:=ord(g)-48;
          if c='+' then s:=s+x;
          if c='*' then s:=s+k*x;
          str(s,y);
          if length(y)<=4 then write(y)
          else
          begin
           for i:=length(y)-4+1 to  length(y) do  e:=e+y[1];
           repeat
             if e[1]='0' then delete(e,1,1);
           until e[1]<>'0';
           write(e);
          end;
          close(input);close(output);
        end.