var js,i,n,x1,t1:longint;
    t2,x2:string;
begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 read(n,js);
 if js>0 then
    begin
     x1:=js;js:=0;
     for i:=1 to n do
        begin
        t1:=i;
        while t1>0 do
         begin
          if t1 mod 10 =x1 then js:=js+1;
          t1:=t1 div 10;
        end;
        end;
    end
 else
    begin
     str(js,x2);js:=0;
     for i:=1 to n do
       begin
       str(i,t2);
       while t2<>'' do
        begin
         if t2[1]=x2 then js:=js+1;
         delete(t2,1,1);
        end;
       end;
    end;
 write(js);
 close(input);close(output);
end.
