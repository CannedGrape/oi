
 var
  n,m,k,x:longint;
  i,a,b,c,p,t,j1:longint;
  j:int64;


 procedure open;
 begin
   assign(input,'circle.in');
   reset(input);
   assign(output,'circle.out');
   rewrite(output);
 end;

 procedure clo;
 begin
   close(input);
   close(output);
 end;

 procedure datain;
 begin
   readln(n,m,k,x);
 end;

 function find(n,m,k,x:longint):longint;
 var
  a,b,c:longint;
 begin
   i:=0;
   t:=x;
   while i<j do
   begin
     inc(i);
     t:=t+m;
     if t=x then
     begin
       exit(i);
     end;
     if t>n-1 then
     begin
       t:=t-(n-1)-1;
     end;
     if t=x then
     begin
       exit(i);
     end;
   end;
 end;

 begin
   open;
   datain;
   if k>5 then
   begin
     j:=1;
     for p:=1 to 10 do j:=int64(j)*10;
     i:=find(n,m,k,x);
     b:=j mod i;
     writeln(x+b);
   end
   else
   begin
      i:=0;
      j1:=1;
      for p:=1 to k do j1:=j1*10;
      t:=x;

      while i<j1 do
      begin
        inc(i);
        t:=t+m;
        if t>n-1 then
        begin
          t:=t-(n-1)-1;
        end;
      end;
      writeln(t);
   end;
   clo;
 end.






















