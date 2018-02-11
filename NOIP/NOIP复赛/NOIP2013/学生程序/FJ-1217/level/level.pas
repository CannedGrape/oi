program level;
 var i,j,n,m,ans,w:longint;
     k:array[0..1000] of longint;
     e:array[0..1000] of boolean;
 begin
   assign(input,'level.in');reset(input);
   assign(output,'level.out');rewrite(output);
   fillchar(e,sizeof(e),false);
   read(n,m);
   ans:=2;
   read(k[1]);
   for i:=1 to k[1] do
    begin
      read(w);
      e[w]:=true;
    end;
   for i:=2 to m do
    begin
      read(k[i]);
      for j:=1 to k[i] do
       begin
         read(w);
         if e[w]=false then
          begin
            inc(ans);
            e[w]:=true;
          end;
       end;
    end;
   write(ans);
   close(input);
   close(output);
 end.